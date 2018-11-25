/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef DATABASEEXCEPTION_H
#define DATABASEEXCEPTION_H

#include <string>
#include "RuntimeException.h"

class DatabaseException : public RuntimeException
{
public:
    /**
     * default constructor
     */
    DatabaseException();
    /**
     * variable constructor
     * @param err - the error message
     */
    explicit DatabaseException(const std::string& err);
    /**
     * copy constructor
     * @param exception - the exception to copy over
     */
    DatabaseException(const DatabaseException& exception);
    /**
     * destructor
     * NOTE: trivial
     */
    ~DatabaseException() override;
};

#endif // DATABASEEXCEPTION_H