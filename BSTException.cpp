/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include <string>
#include "BSTException.h"

// default constructor
BSTException::BSTException()
: RuntimeException()
{
}

// variable constructor
BSTException::BSTException(const std::string& err)
: RuntimeException(err)
{
}

// copy constructor
BSTException::BSTException(const BSTException& exception)
: RuntimeException(exception)
{
}

// destructor (is trivial)
BSTException::~BSTException()
= default;