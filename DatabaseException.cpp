/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include <string>
#include "DatabaseException.h"

// default constructor
DatabaseException::DatabaseException()
: RuntimeException()
{
}

// variable constructor
DatabaseException::DatabaseException(const std::string& err)
: RuntimeException(err)
{
}

// copy constructor
DatabaseException::DatabaseException(const DatabaseException& exception)
: RuntimeException(exception)
{
}

// destructor (is trivial)
DatabaseException::~DatabaseException()
= default;