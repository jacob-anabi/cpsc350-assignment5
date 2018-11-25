/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student
{
public:
    /**
     * Default constructor
     */
    Student();
    /**
     * Variable constructor
     * @param id - student id
     * @param name - student name
     * @param level - student level
     * @param studyMajor - student major
     * @param gpa - student gpa
     * @param adviserId - id of student faculty adviser
     */
    Student(int id, const std::string& name, const std::string&level, const std::string& studyMajor, double gpa, int adviserId);
    /**
     * Copy constructor
     * @param student - the student to copy over
     */
    Student(const Student& student);
    /**
     * Destructor
     * NOTE: trivial
     */
    ~Student();

    /**
     * Gets the adviser's id
     * @return - the adviser's id
     */
    int getAdvierId();
    /**
     * Change a student's adviser given their id
     * @param adviserId - the adviser's id
     */
    void changeAdvisor(int adviserId);

    // operator overloading
    /**
     * Overloads the = operator
     * @param student - the student to set this student equal to
     * @return - our student with the copied over values
     */
    Student& operator=(const Student& student);
    /**
     * Overloads the == operator
     * @param student - the student to check == for
     * @return - a boolean value that is true if they equal each other, false other wise
     */
    bool operator==(const Student& student);
    /**
     * Overloads the < operator
     * @param student - the student to check < for
     * @return - a boolean value that is true if this is less than the student, false other wise
     */
    bool operator<(const Student& student);
    /**
     * Overloads the > operator
     * @param student - the student to check > for
     * @return - a boolean value that is true if this is greater than the student, false other wise
     */
    bool operator>(const Student& student);
    /**
     * Overloads the <= operator
     * @param student - the student to check <= for
     * @return - a boolean value that is true if this is less than or equal to the student, false other wise
     */
    bool operator<=(const Student& student);
    /**
     * Overloads the >= operator
     * @param student - the student to check >= for
     * @return - a boolean value that is true if this is greater than or equal to the student, false other wise
     */
    bool operator>=(const Student& student);
    /**
     * Overloads the != operator
     * @param student - the student to check != for
     * @return - a boolean value that is true if they don't equal each other, false other wise
     */
    bool operator!=(const Student& student);
    /**
     * Overloads the << operator
     * @param os - the ostream object
     * @param student - the student for the ostream
     * @return - the ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const Student& student);

private:
    int id;
    std::string name;
    std::string level;
    std::string studyMajor;
    double gpa;
    int adviserId;
};

#endif // STUDENT_H