/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

class Faculty
{
public:
    /**
     * Default constructor
     */
    Faculty();
    /**
     * Variable constructor
     * @param id - faculty id
     * @param name - faculty name
     * @param level - faculty level
     * @param department - faculty department
     */
    Faculty(int id, const std::string& name, const std::string& level, const std::string& department);
    /**
     * Copy constructor
     * @param faculty - the faculty member to copy over
     */
    Faculty(const Faculty& faculty);
    /**
     * Destructor
     */
    ~Faculty();

    /**
     * Gets an advisee ids
     * @return - the adviser's id
     */
    DoublyLinkedList<int> getAdviseeIds();
    /**
     * Add a faculty's advisee given their id
     * @param adviserId - the adviser's id
     */
    void addAdviseeId(int adviseeId);
    /**
     * Remoces a faculty's advisee given their id
     * @param adviseeId
     */
    void removeAdviseeId(int adviseeId);
    /**
     * Returns id
     * @return - the id
     */
    int getId();
    /**
     * Serilaize the object
     * @param file - the output file
     */
    void serialize(std::ofstream& file);

    // operator overloading
    /**
     * Overloads the = operator
     * @param faculty - the faculty to set this faculty equal to
     * @return - our student with the copied over values
     */
    Faculty& operator=(const Faculty& faculty);
    /**
     * Overloads the == operator
     * @param faculty - the faculty to check == for
     * @return - a boolean value that is true if they equal each other, false other wise
     */
    bool operator==(const Faculty& faculty);
    /**
     * Overloads the < operator
     * @param student - the student to check < for
     * @return - a boolean value that is true if this is less than the student, false other wise
     */
    bool operator<(const Faculty& faculty);
    /**
     * Overloads the > operator
     * @param faculty - the faculty to check > for
     * @return - a boolean value that is true if this is greater than the student, false other wise
     */
    bool operator>(const Faculty& faculty);
    /**
     * Overloads the <= operator
     * @param faculty - the faculty to check <= for
     * @return - a boolean value that is true if this is less than or equal to the student, false other wise
     */
    bool operator<=(const Faculty& faculty);
    /**
     * Overloads the >= operator
     * @param faculty - the faculty to check >= for
     * @return - a boolean value that is true if this is greater than or equal to the student, false other wise
     */
    bool operator>=(const Faculty& faculty);
    /**
     * Overloads the != operator
     * @param faculty - the faculty to check != for
     * @return - a boolean value that is true if they don't equal each other, false other wise
     */
    bool operator!=(const Faculty& faculty);
    /**
     * Overloads the << operator
     * @param os - the ostream object
     * @param faculty - the faculty for the ostream
     * @return - the ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const Faculty& faculty);

private:
    int id;
    std::string name;
    std::string level;
    std::string department;
    DoublyLinkedList<int>* adviseesIds;
};


#endif // FACULTY_H
