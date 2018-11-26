/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include "DoublyLinkedList.h"
#include "BSTException.h"

template <class T>
struct treeNode
{
    /**
     * default constructor
     */
    treeNode()
    : left(nullptr), right(nullptr)
    {
    }
    /**
     * variable constructor
     * @param key - the key for the node
     */
    explicit treeNode (T key)
    : key(key), left(nullptr), right(nullptr)
    {
    }
    /**
     * destructor
     */
    ~treeNode()
    {
        left = nullptr;
        right = nullptr;
    }
    T key;
    treeNode<T>* left;
    treeNode<T>* right;
};

template <class T>
class BST
{
public:
    /**
     * default constructor
     */
    BST();
    /**
     * destructor
     */
    virtual ~BST();

    /**
     * Insert value into tree
     * @param value - the value to insert
     */
    void insert(T value);
    /**
     * Checks if the tree contains a value
     * @param value - the value to check
     * @return - a boolean value that represents if the tree contains the value
     */
    bool contains(T value);
    /**
     * Searches the tree for a value
     * @param value - the value to search for
     * @return - the node
     */
    T* search(T value);
    /**
     * Delete a node with the specified value
     * @param value - the value of the node to delete
     * @return - a boolean value if the node was deleted
     */
    bool deleteNode(T value);
    /**
     * Checks if the tree is empty
     * @return - a boolean value if the tree is empty
     */
    bool isEmpty();
    /**
     * Prints the tree in-order
     */
    void printTree();
    /**
     * Return linked list of preorder nodes
     * @return - the preorder nodes
     */
    DoublyLinkedList<T> preOrderNodes();
    /**
     * Reset preorder list of nodes
     */
    void resetPreOrderNodes();

private:
    treeNode<T>* root;
    DoublyLinkedList<T> preOrderNode;

    /**
     * Prints the tree recursively using an in-order traversal
     * @param root - the root node
     */
    void recPrint(treeNode<T>* root);
    /**
     * Get the successor of a deleted node
     * @param d - the deleted node
     * @return - the successor node
     */
    treeNode<T>* getSuccessor(treeNode<T>* delNode);

    /**
     * Delete BST recursively
     * @param root - the root node
     */
    void destructRec(treeNode<T>* root);

    /**
     * Make linked list of preorder nodes
    * @param root - the root node
    */
    void recPreOrderNodes(treeNode<T>* root);
};

// default constructor
template<class T>
BST<T>::BST()
: root(nullptr)
{
}

// destructor
template<class T>
BST<T>::~BST()
{
    destructRec(root);
}

// insert a treeNode
template<class T>
void BST<T>::insert(T value)
{
    if (contains(value))  // check for duplicates
    {
        return;
    }

    auto* insertNode = new treeNode<T>(value);
    if (isEmpty())
    {
        root = insertNode;
    }
    else // not an empty tree
    {
        treeNode<T>* current = root;
        treeNode<T>* parent; // empty treeNode
        while (true) // begin search for insertion point
        {
            parent = current;
            if (value < current->key) // go left
            {
                current = current->left;
                if (current == nullptr) // we found the insertion point
                {
                    parent->left = insertNode;
                    break;
                }
            }
            else // go right
            {
                current = current->right;
                if (current == nullptr)
                {
                    parent->right = insertNode;
                    break;
                }
            }
        }
    }
}

// check if the tree contains a treeNode
template<class T>
bool BST<T>::contains(T value)
{
    if (isEmpty())
    {
        return false;
    }
    else // not an empty tree continue to search
    {
        treeNode<T>* current = root;
        while (current->key != value)
        {
            if (value < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
            if (current == nullptr)
            {
                return false;
            }
        }
    }
    return true;
}

// searches the tree for a node
template<class T>
T* BST<T>::search(T value)
{
    if (isEmpty())
    {
        throw BSTException("Value not found");
    }
    else // not an empty tree continue to search
    {
        treeNode<T>* current = root;
        while (current->key != value)
        {
            if (value < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
            if (current == nullptr)
            {
                throw BSTException("Value not found");
            }
        }
        return &current->key;
    }
}

// delete a treeNode (oh boy)
template<class T>
bool BST<T>::deleteNode(T value)
{
    if (!contains(value))
    {
        return false;
    }

    // let's proceed to find the tree treeNode
    treeNode<T>* current = root;
    treeNode<T>* parent = root;
    bool isLeft = true;
    // let's look for the tree treeNode
    while (current->key != value)
    {
        parent = current;
        if (value < current->key)
        {
            isLeft = true;
            current = current->left;
        }
        else
        {
            isLeft = false;
            current = current->right;
        }
    }
    // at this point we found the treeNode to delete

    // let's check whether a leaf or not
    if (current->left == nullptr && current->right == nullptr) // then it's a leaf
    {
        if (current == root)
        {
            root = nullptr;
        }
        else if (isLeft)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
    }
    // check if it has one child
    else if (current->right == nullptr) // no right child, must be isLeft
    {
        if (current == root)
        {
            root = current->left;
        }
        else if (isLeft)
        {
            parent->left = current->left;
        }
        else // right child
        {
            parent->right = current->left;
        }
    }
    else if (current->left == nullptr) // no left child, must be right child
    {
        if (current == root)
        {
            root = current->right;
        }
        else if (isLeft)
        {
            parent->left = current->right;
        }
        else // right child
        {
            parent->right = current->right;
        }
    }
    else // it has two children
    {
        treeNode<T>* successor = getSuccessor(current);
        if (current == root)
        {
            root = successor;
        }
        else if (isLeft)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }
        successor->left = current->left;
    }
    delete current; // point left, right = nullptr in treeNode destructor
    return true;
}

// checks if the tree is empty
template<class T>
bool BST<T>::isEmpty()
{
    return (root == nullptr);
}

// prints the tree in-order
template<class T>
void BST<T>::printTree()
{
    recPrint(root);
}

// return a random node
template<class T>
void BST<T>::recPreOrderNodes(treeNode<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    this->preOrderNode.insertBack(root->key);
    recPreOrderNodes(root->left);
    recPreOrderNodes(root->right);
}

// return list of preorder nodes
template<class T>
DoublyLinkedList<T> BST<T>::preOrderNodes()
{
    recPreOrderNodes(root);
    return this->preOrderNode;
}

// reset list of preorder nodes
template<class T>
void BST<T>::resetPreOrderNodes()
{
    delete preOrderNode;
}

// recursively print the tree in-order
template<class T>
void BST<T>::recPrint(treeNode<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    recPrint(root->left);
    std::cout << root->key << std::endl;
    recPrint(root->right);
}

// get a deleted treeNode's successor
template<class T>
treeNode<T> *BST<T>::getSuccessor(treeNode<T>* delNode)
{
    treeNode<T>* sp = delNode;
    treeNode<T>* successor = delNode;
    treeNode<T>* current = delNode->right;

    while (current != nullptr)
    {
        sp = successor;
        successor = current;
        current = current->left;
    }
    if (successor != delNode->right) // descendent of right child, left most of right
    {
        sp->left = successor->right;
        successor->right = delNode->right;
    }
    return successor;
}

// delete BST recursively
template<class T>
void BST<T>::destructRec(treeNode<T>* root)
{
    if (root != nullptr)
    {
        // post-order traversal
        destructRec(root->left);
        destructRec(root->right);
        delete root;
    }
}

#endif // BST_H