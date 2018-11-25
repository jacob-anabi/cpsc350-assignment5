/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef FACULTYEXCEPTION_H
#define FACULTYEXCEPTION_H

#include <string>
#include "RuntimeException.h"

class FacultyException : public RuntimeException
{
public:
    /**
     * default constructor
     */
    FacultyException();
    /**
     * variable constructor
     * @param err - the error message
     */
    explicit FacultyException(const std::string& err);
    /**
     * copy constructor
     * @param exception - the exception to copy over
     */
    FacultyException(const FacultyException& exception);
    /**
     * destructor
     * NOTE: trivial
     */
    ~FacultyException() override;
};

#endif // FACULTYEXCEPTION_H