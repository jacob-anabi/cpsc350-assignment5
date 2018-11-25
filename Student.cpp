/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include "Student.h"

// default constructor
Student::Student()
: id(999999999), name("Frodo Baggins"), level("Hobbit"), studyMajor("Destroying the One Ring"), gpa(10.0), adviserId(1000000000)
{
}

// variable constructor
Student::Student(int id, const std::string& name, const std::string& level, const std::string& studyMajor, double gpa, int adviserId)
: id(id), name(name), level(level), studyMajor(studyMajor), gpa(gpa), adviserId(adviserId)
{
}

// copy constructor
Student::Student(const Student& student)
: id(student.id), name(student.name), level(student.level), studyMajor(student.studyMajor), gpa(student.gpa), adviserId(student.adviserId)
{
}

// destructor (is trivial)
Student::~Student()
= default;

// gets the adviser's id
int Student::getAdvierId()
{
    return adviserId;
}

// change student's adviser given the id
void Student::changeAdvisor(int adviserId)
{
    this->adviserId = adviserId;
}

// = operator
Student &Student::operator=(const Student& student)
{
    if (this != &student) // not the same students
    {
        this->id = student.id;
        this->name = student.name;
        this->level = student.level;
        this->studyMajor = student.studyMajor;
        this->gpa = student.gpa;
        this->adviserId = student.adviserId;
    }
    return *this;
}

// == operator
bool Student::operator==(const Student& student)
{
    return (this->id == student.id);
}

// < operator
bool Student::operator<(const Student& student)
{
    return (this->id < student.id);
}

// > operator
bool Student::operator>(const Student& student)
{
    return (this->id > student.id);
}

// <=  operator
bool Student::operator<=(const Student& student)
{
    return (this->id <= student.id);
}

// >= operator
bool Student::operator>=(const Student& student)
{
    return (this->id >= student.id);
}

// != operatpor
bool Student::operator!=(const Student& student)
{
    return (this->id != student.id);
}

// << operator
std::ostream &operator<<(std::ostream& os, const Student& student)
{
    os << "Student id: " << student.id << "\n" <<
    "Student name: " << student.name << "\n" <<
    "Student level: " << student.level << "\n" <<
    "Student major: " << student.studyMajor << "\n" <<
    "Student GPA: " << student.gpa << "\n" <<
    "Student Adviser ID: " << student.adviserId << std::endl;

    return os;
}