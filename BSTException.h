/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#ifndef BSTEXCEPTION_H
#define BSTEXCEPTION_H

#include <string>
#include "RuntimeException.h"

class BSTException : public RuntimeException
{
public:
    /**
     * default constructor
     */
    BSTException();
    /**
     * variable constructor
     * @param err - the error message
     */
    explicit BSTException(const std::string& err);
    /**
     * copy constructor
     * @param exception - the exception to copy over
     */
    BSTException(const BSTException& exception);
    /**
     * destructor
     * NOTE: trivial
     */
    ~BSTException() override;
};

#endif // BSTEXCEPTION_H