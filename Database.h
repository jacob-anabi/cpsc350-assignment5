/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include "BST.h"
#include "DoublyLinkedList.h"
#include "GenStack.h"
#include "Student.h"
#include "Faculty.h"

class Database
{
public:
    /**
     * Default constructor
     */
    Database();
    /**
     * Destructor
     */
    ~Database();

    /**
     * Prints the students
     */
    void printStudents();
    /**
     * Prints the faculty
     */
    void printFaculty();
    /**
     * Display student information given student id
     * @param id - the student id
     */
    void displayStudent(int id);
    /**
     * Display faculty information given faculty id
     * @param id - the faculty id
     */
    void displayFaculty(int id);
    /**
     * Prints a student's faculty adviser
     * @param id - the student id
     */
    void printAdviser(int id);
    /**
     * Prints a faculty member's advisee
     * @param id - the faculty member id
     */
    void printAdvisees(int id);
    /**
     * Add a student
     */
    void addStudent();
    /**
     * Remove a student given their id
     * @param id - the student's id
     */
    void removeStudent(int id);
    /**
     * Add a faculty
     */
    void addFaculty();
    /**
     * Remove a faculty given their id
     * @param id - the faculty member's id
     */
    void removeFaculty(int id);
    /**
     * Change a student's adviser
     * @param studentId - the student id
     * @param adviserId - the new adviser's id
     */
    void changeAdviser(int studentId, int adviserId);
    /**
     * Removes an advisee from a faculty member
     * @param id - the student id
     */
    void removeAdvisee(int sId, int fId);
    /**
     * Undo modification of database
     */
    void rollback();
    /**
     * Save and exit
     */
    void exit();

private:
    BST<Student>* students;
    BST<Faculty>* faculty;
    GenStack<BST<Student>>* studentUndo;
    GenStack<BST<Faculty>>* facultyUndo;

    /**
     * Set random adviser
     * @param id - the student id
     */
    void setRandomAdviser(int id);
};

#endif // DATABASE_H