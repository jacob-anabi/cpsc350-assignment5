/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include <string>
#include "RuntimeException.h"

// default constructor
RuntimeException::RuntimeException()
: err("Default error message.")
{
}

// variable constructor
RuntimeException::RuntimeException(const std::string& err)
: err(err)
{
}

RuntimeException::RuntimeException(const RuntimeException& exception)
: err(exception.err)
{
}

// destructor (is trivial)
RuntimeException::~RuntimeException()
= default;

// getter for the error message
std::string RuntimeException::getErr()
{
    return err;
}