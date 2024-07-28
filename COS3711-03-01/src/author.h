#ifndef AUTHOR_H
#define AUTHOR_H

#include <QString>


class Author
{
public:
    Author(const QString &firstName, const QString &lastName);
    QString getFirstName() const;
    QString getLastName() const;
    QString toString() const;

private:
    QString firstName;
    QString lastName;
};

#endif // AUTHOR_H
