/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef STUDENTEXCEPTION_H
#define STUDENTEXCEPTION_H

#include <string>
#include "RuntimeException.h"

class StudentException : public RuntimeException
{
public:
    /**
     * default constructor
     */
    StudentException();
    /**
     * variable constructor
     * @param err - the error message
     */
    explicit StudentException(const std::string& err);
    /**
     * copy constructor
     * @param exception - the exception to copy over
     */
    StudentException(const StudentException& exception);
    /**
     * destructor
     * NOTE: trivial
     */
    ~StudentException() override;
};

#endif // STUDENTEXCEPTION_H