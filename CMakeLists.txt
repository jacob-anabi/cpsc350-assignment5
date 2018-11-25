cmake_minimum_required(VERSION 3.12)
project(RegistrarDatabase)

set(CMAKE_CXX_STANDARD 17)

add_executable(RegistrarDatabase main.cpp RuntimeException.cpp RuntimeException.h BSTException.cpp BSTException.h DatabaseException.cpp DatabaseException.h StudentException.cpp StudentException.h FacultyException.cpp FacultyException.h BST.h GenStack.h InvalidStackOperationException.cpp InvalidStackOperationException.h LinkedListException.cpp LinkedListException.h DoublyLinkedList.h Student.cpp Student.h Faculty.cpp Faculty.h)