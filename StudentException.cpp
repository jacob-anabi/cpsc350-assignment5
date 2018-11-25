/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include <string>
#include "StudentException.h"

// default constructor
StudentException::StudentException()
: RuntimeException()
{
}

// variable constructor
StudentException::StudentException(const std::string& err)
: RuntimeException(err)
{
}

// copy constructor
StudentException::StudentException(const StudentException& exception)
: RuntimeException(exception)
{
}

// destructor (is trivial)
StudentException::~StudentException()
= default;