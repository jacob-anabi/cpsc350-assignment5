/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "BST.h"
#include "DoublyLinkedList.h"
#include "GenStack.h"
#include "Student.h"
#include "Faculty.h"
#include "DatabaseException.h"
#include "Database.h"

// default constructor
Database::Database()
: students(new BST<Student>()), faculty(new BST<Faculty>()), studentUndo(new GenStack<BST<Student>>()), facultyUndo(new GenStack<BST<Faculty>>())
{
}

// destructor
Database::~Database()
{
    if (students != nullptr)
    {
        delete students;
    }
    if (faculty != nullptr)
    {
        delete faculty;
    }
    delete studentUndo;
    delete facultyUndo;
}

// prints the students
void Database::printStudents()
{
    students->printTree();
}

// prints the faculty
void Database::printFaculty()
{
    faculty->printTree();
}

// display a student
void Database::displayStudent(int id)
{
    Student tempStudent(id, " ", " ", " ", 5.0, 10);
    if (students->contains(tempStudent))
    {
        std::cout << *students->search(tempStudent) << std::endl;
    }
}

// display a faculty member
void Database::displayFaculty(int id)
{
    Faculty tempFaculty(id, " ", " ", " ");
    if (faculty->contains(tempFaculty))
    {
        std::cout << *faculty->search(tempFaculty) << std::endl;
    }
}

// prints a students adviser
void Database::printAdviser(int id)
{
    Student tempStudent(id, " ", " ", " ", 5.0, 10);
    if (students->contains(tempStudent))
    {
        int adviserId = students->search(tempStudent)->getAdvierId();
        displayFaculty(adviserId);
    }
    else
    {
        throw DatabaseException("Student not found");
    }
}
 // print a faculty's advisee
void Database::printAdvisees(int id)
{
    Faculty tempFaculty(id, " ", " ", " ");
    if (faculty->contains(tempFaculty))
    {
        DoublyLinkedList<int> adviseeIds = faculty->search(tempFaculty)->getAdviseeIds();
        for (unsigned int i = 0; i < adviseeIds.getSize(); ++i)
        {
            displayStudent(adviseeIds.peekPos(i));
        }
    }
    else
    {
        throw DatabaseException("Faculty member not found");
    }
}

// add a student
void Database::addStudent()
{
    int id = rand() % (499999999 - 100000000 + 1) + 100000000; // random 9 digit number
    Student tempStudent(id, " ", " ", " ", 5.0, 10);
    while (students->contains(tempStudent)) // duplicate id
    {
        id = rand() % (499999999 - 100000000 + 1) + 100000000; // random 9 digit number
        Student tempStudent1(id, " ", " ", " ", 5.0, 10);
        tempStudent = tempStudent1;
    }
    std::string name;
    std::string level;
    std::string studyMajor;
    double gpa = 0.0;
    int adviserId = 0;

    std::cout << "Enter student name: ";
    std::cin >> name;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cout << "\nEnter student level: ";
    std::cin >> level;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cout << "\nEnter student major: ";
    std::cin >> studyMajor;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    bool gpa_good = false;
    while (!gpa_good)
    {
        std::cout << "\nEnter student GPA: ";
        std::cin >> gpa;
        if (std::cin.fail())
        {
            std::cout << "\nInvalid student GPA" << std::endl;
        }
        else
        {
            gpa_good = true;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    if (!faculty->isEmpty())
    {
        bool a_id_good = false;
        while (!a_id_good)
        {
            std::cout << "\nEnter student adviser ID: ";
            std::cin >> adviserId;
            if (std::cin.fail())
            {
                std::cout << "\nInvalid student adviser ID" << std::endl;
            }
            else
            {
                Faculty tempFaculty(adviserId, " ", " ", " ");
                if (faculty->contains(tempFaculty))
                {
                    faculty->search(tempFaculty)->addAdviseeId(id);
                    a_id_good = true;
                }
            }
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }

    Student student(id, name, level, studyMajor, gpa, adviserId);
    students->insert(student);
}

// remove a student
void Database::removeStudent(int id)
{
    Student tempStudent(id, " ", " ", " ", 5.0, 10);
    if (students->contains(tempStudent))
    {
        int facultyID = students->search(tempStudent)->getAdvierId();
        students->deleteNode(tempStudent);
        if (facultyID != 0)
        {
            Faculty tempFaculty(facultyID, " ", " ", " ");
            faculty->search(tempFaculty)->removeAdviseeId(id);
        }
    }
}

// add faculty member
void Database::addFaculty()
{
    int id = rand() % (999999999 - 500000000 + 1) + 500000000; // random 9 digit number
    Faculty tempFaculty(id, " ", " ", " ");
    while (faculty->contains(tempFaculty)) // duplicate id
    {
        id = rand() % (999999999 - 500000000 + 1) + 500000000; // random 9 digit number
        Faculty tempFaculty1(id, " ", " ", " ");
        tempFaculty = tempFaculty1;
    }
    std::string name;
    std::string level;
    std::string department;

    std::cout << "Enter faculty name: ";
    std::cin >> name;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cout << "\nEnter faculty level: ";
    std::cin >> level;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cout << "\nEnter faculty department: ";
    std::cin >> department;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    Faculty faculty(id, name, level, department);
    this->faculty->insert(faculty);
}

// remove faculty member
void Database::removeFaculty(int id)
{
    int aId = 0;
    Faculty tempFaculty(id, " ", " ", " ");
    if (faculty->contains(tempFaculty))
    {
        DoublyLinkedList<int> ids = faculty->search(tempFaculty)->getAdviseeIds();
        int size = ids.getSize();
        for (unsigned int i = 0; i < size; ++i)
        {
            aId = ids.peekPos(i);
            setRandomAdviser(aId);
        }
        faculty->deleteNode(tempFaculty);
    }
}

// change student adviser
void Database::changeAdviser(int studentId, int adviserId)
{
    Student tempStudent(studentId, " ", " ", " ", 5.0, 10);
    Faculty tempFaculty(adviserId, " ", " ", " ");
    int modAdID = 0;
    if (students->contains(tempStudent) && faculty->contains(tempFaculty))
    {
        modAdID = students->search(tempStudent)->getAdvierId();
        students->search(tempStudent)->changeAdvisor(adviserId);
        faculty->search(tempFaculty)->addAdviseeId(studentId);
    }
    Faculty modFaculty(modAdID, " ", " ", " ");
    faculty->search(modFaculty)->removeAdviseeId(studentId);

}

// set random adviser
void Database::setRandomAdviser(int id)
{
    unsigned int pos = 0;
    int adId = 0;
    Student tempStudent(id, " ", " ", " ", 5.0, 10);

    while (true)
    {
        DoublyLinkedList<Faculty> preOrderFaculty = faculty->preOrderNodes();
        pos = rand() % ((preOrderFaculty.getSize() - 1) - 0 + 1) + 0; // random number bounded [0, size-1]
        adId = preOrderFaculty.peekPos(pos).getId();
        if (adId != students->search(tempStudent)->getAdvierId())
        {
            break;
        }
    }
    Faculty tempFaculty(adId, " ", " ", " ");
    changeAdviser(id, adId);
}

// remove advisee
void Database::removeAdvisee(int sId, int fId)
{
    Student tempStudent(sId, " " , " ", " ", 5.0, 10);
    Faculty tempFaculty(fId, " ", " ", " ");
    if (faculty->contains(tempFaculty))
    {
        faculty->search(tempFaculty)->removeAdviseeId(sId);
    }
    if (students->contains(tempStudent))
    {
        setRandomAdviser(sId);
    }
}

// rollback
void Database::rollback()
{
    if (!studentUndo->isEmpty() && !facultyUndo->isEmpty())
    {
        delete students;
        delete faculty;
        students = studentUndo->peekPointer();
        faculty = facultyUndo->peekPointer();
        studentUndo->pop();
        facultyUndo->pop();
    }
}

// save and exit
void Database::exit()
{
    std::ofstream studentFile;
    std::ofstream facultyFile;
    DoublyLinkedList<Student> preOrderStudents = students->preOrderNodes();
    DoublyLinkedList<Faculty> preOrderFaculty = faculty->preOrderNodes();

    studentFile.open("studentTable.txt");
    facultyFile.open("facultyTable.txt");

    for (unsigned int i = 0; i < preOrderStudents.getSize(); ++i)
    {
        preOrderStudents.peekPos(i).serialize(studentFile);
        studentFile.close();
        studentFile.open("studentTable.txt", std::ios::app);
    }
    for (unsigned int i = 0; i < preOrderFaculty.getSize(); ++i)
    {
        preOrderFaculty.peekPos(i).serialize(facultyFile);
        facultyFile.close();
        facultyFile.open("facultyTable.txt", std::ios::app);
    }

    studentFile.close();
    facultyFile.close();
}