/**
 * @file author.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the Author class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "author.h"


Author::Author(const QString &firstName, const QString &lastName)
    : firstName(firstName), lastName(lastName)
{

}

QString Author::getFirstName() const
{
    return firstName;
}

QString Author::getLastName() const
{
    return lastName;
}

QString Author::toString() const
{
    return lastName.toUpper() + ", " + firstName.toUpper();
}
