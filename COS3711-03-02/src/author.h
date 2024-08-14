/**
 * @file author.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the Author class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */

#ifndef AUTHOR_H
#define AUTHOR_H

#include <QString>


/**
 * @class Author
 * @brief The Author class represents an author of a book. 
 * Authors have a first name and a last name.
 */
class Author
{
public:
    /**
     * @brief Construct a new Author object
     * 
     * @param firstName The first name of the author.
     * @param lastName The last name of the author.
     */
    Author(const QString &firstName, const QString &lastName);

    /**
     * @brief Returns the first name of the author.
     * 
     * @return QString The first name of the author.
     */
    QString getFirstName() const;

    /**
     * @brief Returns the last name of the author.
     * 
     * @return QString The last name of the author.
     */
    QString getLastName() const;

    /**
     * @brief Returns a string representation of the author in the format "LASTNAME, FIRSTNAME".
     * 
     * @return QString The string representation of the author.
     */
    QString toString() const;

private:
    QString firstName;  /**< The first name of the author. */
    QString lastName;   /**< The last name of the author. */
};

#endif // AUTHOR_H
