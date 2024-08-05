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
