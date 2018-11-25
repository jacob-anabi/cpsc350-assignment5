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
#include "Student.h"
#include "Faculty.h"

int main(int argc, char** argv)
{
    Faculty* faculty = new Faculty();
    faculty->addAdviseeId(5091);
    std::cout << *faculty << std::endl;
}