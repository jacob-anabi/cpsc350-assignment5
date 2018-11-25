/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "InvalidStackOperationException.h"
#include "DoublyLinkedList.h"

template <class T>
class GenStack
{
public:
    /**
     * default constructor
     */
    GenStack();
    /**
     * copy constructor
     * @param genStack - the stack to copy over
     */
    GenStack(const GenStack& genStack);
    /**
     * destructor
     */
    ~GenStack();

    /**
     * pushes an element on the top of the stack
     * @param elem - the element to push
     */
    void push(T elem);

    /**
     * pops the top element off of the stack
     * @return - the top element that is pushed off
     */
    T pop();

    /**
     * peeks at the top element of the stack
     * @return - the top element of the stack
     */
    T peek();

    /**
     * removes element from bottom of stack, bumping the stack down one
     */
    void bumpDown();

    /**
     * checks if the stack is empty
     * @return - a boolean value that returns true if the stack is empty, false otherwise
     */
    bool isEmpty();

    /**
     * gets the size of the stack
     * @return - an unsigned int which represents the size of the stack
     */
    unsigned int getSize();

    // TODO: implement -- operator overload

private:
    DoublyLinkedList<T>* list; // the linked list to use
    unsigned int size; // the size of the stack
};

// default constructor
template<class T>
GenStack<T>::GenStack()
: list(new DoublyLinkedList<T>()), size(list->getSize())
{
}

// copy constructor
template<class T>
GenStack<T>::GenStack(const GenStack& genStack)
{
// TODO: implement this
}

// destructor
template<class T>
GenStack<T>::~GenStack()
{
    delete list;
}

// pushes an element on the top of the stack
template<class T>
void GenStack<T>::push(T elem)
{
    ++size;
    list->insertBack(elem); // pushing elem to the top of the stack
}

// pops the top element off of the stack
template<class T>
T GenStack<T>::pop()
{
    if (isEmpty())
    {
        throw InvalidStackOperationException("Pop operation performed on empty stack.");
    }
    --size;
    return list->removeBack(); // return the element at the top, then decrement the top
}

// peeks at the top element of the stack
template<class T>
T GenStack<T>::peek()
{
    if (isEmpty())
    {
        throw InvalidStackOperationException("Peek operation performed on empty stack.");
    }
    return list->peekBack(); // return the element at the top of the stack
}

template<class T>
void GenStack<T>::bumpDown()
{
    if (isEmpty())
    {
        throw InvalidStackOperationException("Peek operation performed on empty stack.");
    }
    --size;
    list->removeFront();
}

// checks if the stack is empty
template<class T>
bool GenStack<T>::isEmpty()
{
    return (size == 0);
}

// gets the size of the stack
template<class T>
unsigned int GenStack<T>::getSize()
{
    return size;
}

#endif // GENSTACK_H