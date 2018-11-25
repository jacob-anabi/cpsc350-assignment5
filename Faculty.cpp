/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */


#include "Faculty.h"

// default constructor
Faculty::Faculty()
: id(1000000000), name("Bilbo Baggins"), level("Professor"), department("Literature")
{
    adviseesIds = new DoublyLinkedList<int>();
}

// variable constructor
Faculty::Faculty(int id, const std::string& name, const std::string& level, const std::string& department)
: id(id), name(name), level(level), department(department)
{
    adviseesIds = new DoublyLinkedList<int>();
}

// copy constructor
Faculty::Faculty(const Faculty& faculty)
: id(faculty.id), name(faculty.name), level(faculty.level), department(faculty.department)
{
    adviseesIds = faculty.adviseesIds;
}

// destructor
Faculty::~Faculty()
{
    delete adviseesIds;
}

// gets the advisee ids
DoublyLinkedList<int> Faculty::getAdviseeIds()
{
    return *adviseesIds;
}

// add an advisee id
void Faculty::addAdviseeId(int adviseeId)
{
    adviseesIds->insertFront(adviseeId);
}

// remove an advisee id
void Faculty::removeAdviseeId(int adviseeId)
{
    if (adviseesIds->search(adviseeId) != -1) // contains the id
    {
        adviseesIds->remove(adviseeId);
    }
}

// = operator
Faculty &Faculty::operator=(const Faculty& faculty)
{
    if (this != &faculty) // not the same faculty
    {
        this->id = faculty.id;
        this->name = faculty.name;
        this->level = faculty.level;
        this->department = faculty.department;
        this->adviseesIds = faculty.adviseesIds;
    }
    return *this;
}

// == operator
bool Faculty::operator==(const Faculty& faculty)
{
    return (id == faculty.id);
}

// < operator
bool Faculty::operator<(const Faculty& faculty)
{
    return (id < faculty.id);
}

// > operator
bool Faculty::operator>(const Faculty& faculty)
{
    return (id > faculty.id);
}

// <= operator
bool Faculty::operator<=(const Faculty& faculty)
{
    return (id <= faculty.id);
}

// >= operator
bool Faculty::operator>=(const Faculty& faculty)
{
    return (id >= faculty.id);
}

// != operator
bool Faculty::operator!=(const Faculty& faculty)
{
    return (id != faculty.id);
}

// << operator
std::ostream& operator<<(std::ostream& os, const Faculty& faculty)
{
    os << "Faculty id: " << faculty.id << "\n" <<
       "Faculty name: " << faculty.name << "\n" <<
       "Faculty level: " << faculty.level << "\n" <<
       "Faculty department: " << faculty.department << "\n" <<
       "Faculty advisee's ids: " << std::endl;
    faculty.adviseesIds->printList();

    return os;
}
