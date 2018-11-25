/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include <string>
#include "FacultyException.h"

// default constructor
FacultyException::FacultyException()
: RuntimeException()
{
}

// variable constructor
FacultyException::FacultyException(const std::string& err)
: RuntimeException(err)
{
}

// copy constructor
FacultyException::FacultyException(const FacultyException& exception)
: RuntimeException(exception)
{
}

// destructor (is trivial)
FacultyException::~FacultyException()
= default;