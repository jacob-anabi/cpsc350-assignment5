/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include <iostream>
#include "DoublyLinkedList.h"
#include "GenStack.h"
#include "BST.h"

int main(int argc, char** argv)
{
    auto* tree = new BST<int>();
    tree->insert(5);
    tree->insert(10);
    tree->insert(3);
    tree->insert(40);
    tree->insert(56);
    tree->deleteNode(10);
    tree->printTree();
    delete tree;
    tree->printTree();
    tree->printTree();
}