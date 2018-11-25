/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "LinkedListException.h"

/**
 * node struct
 * @tparam T - nodes data
 */
template <class T>
struct listNode
{
    /**
     * variable constructor
     * @param data - the data of the node
     */
    explicit listNode(T data)
    : next(nullptr), prev(nullptr), data(data)
    {
    }
    /**
     * destructor
     */
    ~listNode()
    {
        next = nullptr;
        prev = nullptr;
    }
    listNode* next;
    listNode* prev;
    T data;
};

/**
 * Doubly Linked List Class
 * @tparam T - types of nodes in list
 */
template <class T>
class DoublyLinkedList
{
public:
    /**
     * Default Constructor
     */
    DoublyLinkedList();
    /**
     * Variable constructor
     * @param data - the data of the first node in the doubly linked list
     */
    explicit DoublyLinkedList(T data);
    /**
     * Copy constructor
     * @param list - the doubly linked list to copy over
     */
    DoublyLinkedList(const DoublyLinkedList& list);
    /**
     * Destructor
     */
    ~DoublyLinkedList();

    // unique methods
    // back operations
    /**
     * Insert node with data in the back of the doubly linked list
     * @param data - data to be inserted
     */
    void insertBack(T data);
    /**
     * Delete back node
     * @return - the data of the deleted node
     */
    T removeBack();
    /**
     * Returns the data in the node at the back
     * @return - the data of the back node
     */
    T peekBack() const;

    // overridden operations
    // front operations
    /**
     * Insert node with data in the front of the list
     * @param data - data to be inserted
     */
    void insertFront(T data);
    /**
     * Delete front node
     * @return - the data of the deleted node
     */
    T removeFront();
    /**
     * Returns the data in the node at the front
     * @return - the data of the front node
     */
    T peekFront() const;

    // miscellaneous operations
    /**
     * Removes node at the specified position
     * @param pos - the position of the node to remove
     * @return - the removed node
     */
    T removePos(unsigned int pos);
    /**
     * Removes first node of specified value
     * @param value - the value of the node to remove
     * @return - the removed node
     */
    T remove(T value);
    /**
     * Searches for a specific value in the list
     * @param val - the value to search for
     * @return - the position the value is at (-1 if it is not in the list)
     */
    int search(T val) const;
    /**
     * Prints the list
     */
    void printList() const;
    /**
     * Returns the date of the node at the specified position
     * @param pos - the position to check at
     * @return - the data at the specified node
     */
    T peekPos(unsigned int pos) const;
    /**
     * Checks if the list is empty
     * @return - a boolean value that returns true if the list is empty false otherwise
     */
    bool isEmpty() const;
    /**
     * Gets the size of the linked list
     * @return - the size of the linked list
     */
    unsigned int getSize() const;

    // operator overloading
    /**
     * Overloads the = operator
     * @param list - the list to set this list equal to
     * @return - our list with the copied over values
     */
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& list);
private:
    unsigned int size;
    listNode<T>* front;
    listNode<T>* back;
};

// default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
: size(0), front(nullptr), back(nullptr)
{
}

// variable constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T data)
: size(1)
{
    auto* initNode = new listNode<T>(data);
    initNode->next = nullptr;
    initNode->prev = nullptr;
    front = initNode;
    back = initNode;
}

// copy constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& list)
{
    if (list.getSize() > 0)
    {
        auto* initNode = new listNode<T>(list.peekPos(0));
        initNode->next = nullptr;
        initNode->prev = nullptr;
        front = initNode;
        back = initNode;
        for (unsigned int i = 1; i < list.getSize(); ++i)
        {
            insertBack(list.peekPos(i));
        }
        size = list.getSize();
    }
    else
    {
        size = 0;
        front = nullptr;
        back = nullptr;
    }
}

// destructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (!isEmpty())
    {
        removeFront();
    }
}

// unique methods
// inserts listNode of data in the back of the linked list
template<class T>
void DoublyLinkedList<T>::insertBack(T data)
{
    auto* tempNode = new listNode<T>(data);
    if (isEmpty()) // empty list
    {
        front = tempNode;
    }
    else // not an empty list
    {
        back->next = tempNode;
        tempNode->prev = back;
    }
    back = tempNode;
    ++size;
}

// removes the back listNode
template<class T>
T DoublyLinkedList<T>::removeBack()
{
    listNode<T>* oldNode = back;
    if (isEmpty()) // empty list
    {
        throw LinkedListException("Remove operation attempted on empty list");
    }
    if (back->prev == nullptr) // only listNode in the list
    {
       front = nullptr;
    }
    else // not the only listNode in the list
    {
        back->prev->next = nullptr;
    }
    back = back->prev;
    oldNode->prev = nullptr;
    T delData = oldNode->data;
    delete oldNode;
    --size;

    return delData;
}

// returns the data of the back listNode
template<class T>
T DoublyLinkedList<T>::peekBack() const
{
    return back->data;
}

// overridden operations
// insert listNode of data in the front of the linked list
template<class T>
void DoublyLinkedList<T>::insertFront(T data)
{
    auto* tempNode = new listNode<T>(data);
    if (isEmpty()) // if the linked list is empty
    {
        back = tempNode;
    }
    else // it's not empty
    {
        front->prev = tempNode;
        tempNode->next = front;
    }
    front = tempNode;
    ++size;
}

// remove front listNode from the linked list
template<class T>
T DoublyLinkedList<T>::removeFront()
{
    listNode<T>* oldNode = front;
    if (isEmpty()) // if the linked list is empty
    {
        throw LinkedListException("Remove operation attempted on empty list");
    }
    if (front->next == nullptr) // only listNode in the list
    {
        back = nullptr;
    }
    else // more than one listNode in the list
    {
        front->next->prev = nullptr;
    }
    front = front->next;
    oldNode->next = nullptr;
    T delData = oldNode->data;
    delete oldNode;
    --size;

    return  delData;
}

// returns the data of the front listNode
template<class T>
T DoublyLinkedList<T>::peekFront() const
{
    return front->data;
}

// removes listNode at specified position
template<class T>
T DoublyLinkedList<T>::removePos(unsigned int pos)
{
    if (pos >= size) // remove at position greater than the size of the list
    {
        throw  LinkedListException("Linked List index out of bounds error");
    }
    // position < size
    int currentPos = 0;
    listNode<T>* currentNode = front;
    while (currentPos != pos)
    {
        currentNode = currentNode->next;
        ++currentPos;
    }
    // we found it
    // front
    if (currentNode == front)
    {
        front = currentNode->next;
    }
    else
    {
        currentNode->prev->next = currentNode->next;
    }
    // back
    if (currentNode == back)
    {
        back = currentNode->prev;
    }
    else
    {
        currentNode->next->prev = currentNode->prev;
    }
    currentNode->next = nullptr;
    currentNode->prev = nullptr;
    T delData = currentNode->data;
    delete currentNode;
    --size;

    return delData;
}

// removes listNode of specified value
template<class T>
T DoublyLinkedList<T>::remove(T value)
{
    if (search(value) == -1) // value not found
    {
        throw LinkedListException("Linked List has no such value");
    }
    // position < size
    listNode<T>* currentNode = front;
    while (currentNode->data != value)
    {
        currentNode = currentNode->next;
    }
    // we found it
    // front
    if (currentNode == front)
    {
        front = currentNode->next;
    }
    else
    {
        currentNode->prev->next = currentNode->next;
    }
    // back
    if (currentNode == back)
    {
        back = currentNode->prev;
    }
    else
    {
        currentNode->next->prev = currentNode->prev;
    }
    currentNode->next = nullptr;
    currentNode->prev = nullptr;
    T delData = currentNode->data;
    delete currentNode;
    --size;

    return delData;
}

// searches for the position of some specified value (-1 if not found)
template<class T>
int DoublyLinkedList<T>::search(T val) const
{
    if (isEmpty())
    {
        return -1;
    }
    int currentPos = 0;
    listNode<T>* currentNode = front;
    while (currentNode->data != val)
    {
        currentNode = currentNode->next;
        ++currentPos;
        if (currentNode == nullptr) // value not found
        {
            return -1;
        }
    }
    return currentPos;
}

// prints each listNode in the list
template<class T>
void DoublyLinkedList<T>::printList() const
{
    listNode<T>* currentNode = front;
    while (currentNode != nullptr)
    {
        // this part is not necessary, you can just print out the data, but I want to make the printing look nice
        if (currentNode->next == nullptr && currentNode->prev == nullptr) // only treeNode in the list
        {
            std::cout << "||--" << "(" << currentNode->data << ")" << "--||";
        }
        else if (currentNode->next == nullptr) // last treeNode in the list
        {
            std::cout << "(" << currentNode->data << ")" << "--||";
        }
        else if (currentNode->prev == nullptr) // first treeNode in the list
        {
            std::cout << "||--" << "(" << currentNode->data << ")" << "<-->";
        }
        else // some treeNode that isn't first and/or last
        {
            std::cout << "(" << currentNode->data << ")" << "<-->";
        }
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

// returns the data of the listNode at the specified position
template<class T>
T DoublyLinkedList<T>::peekPos(unsigned int pos) const
{
    if (pos >= size) // remove at position greater than the size of the list
    {
        throw  LinkedListException("Linked List index out of bounds error");
    }
    // position < size
    int currentPos = 0;
    listNode<T>* currentNode = front;
    while (currentPos != pos)
    {
        currentNode = currentNode->next;
        ++currentPos;
    }

    // we found it
    return currentNode->data;
}

// determines if the list is empty or not
template<class T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return (size == 0);
}

// gets the size of the linked list
template<class T>
unsigned int DoublyLinkedList<T>::getSize() const
{
    return size;
}

// = operator
template<class T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &list)
{
    if (list.getSize() > 0)
    {
        auto* initNode = new listNode<T>(list.peekPos(0));
        initNode->next = nullptr;
        initNode->prev = nullptr;
        this->front = initNode;
        this->back = initNode;
        for (unsigned int i = 1; i < list.getSize(); ++i)
        {
            insertBack(list.peekPos(i));
        }
        this->size = list.getSize();
    }
    else
    {
        this->size = 0;
        this->front = nullptr;
        this->back = nullptr;
    }
    return *this;
}

#endif // DOUBLYLINKEDLIST_H