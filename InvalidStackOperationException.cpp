/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include "InvalidStackOperationException.h"

// default constructor
InvalidStackOperationException::InvalidStackOperationException()
: RuntimeException()
{
}

// variable constructor
InvalidStackOperationException::InvalidStackOperationException(const std::string& err)
: RuntimeException(err)
{
}

// copy constructor
InvalidStackOperationException::InvalidStackOperationException(const InvalidStackOperationException& invalidStackOperationException)
: RuntimeException(invalidStackOperationException)
{
}

// destructor (is trivial)
InvalidStackOperationException::~InvalidStackOperationException()
= default;
