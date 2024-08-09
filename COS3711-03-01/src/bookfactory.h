/**
 * @file bookfactory.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the BookFactory class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

class Book;         
class QDate;
class QString;

#include <QStringList>


/**
 * @class BookFactory
 * @brief The BookFactory class is a factory class for creating Book objects.
 */
class BookFactory
{
public:
    /**
     * @brief Get the Instance object
     * @details This is a singleton class, so this method is used to get the instance of the BookFactory.
     * @return BookFactory& The instance of the BookFactory
     */
    static BookFactory &getInstance();

    /**
     * @brief Create a Book object
     * 
     * @param title The title of the book.
     * @param authors A list of the author(s) of the book.
     * @param isbn The ISBN of the book.
     * @param publicationDate The publication date of the book.
     * @return Book* A pointer to the created Book object.
     */
    Book *createBook(const QString &title, const QStringList &authors, const QString &isbn, const QDate &publicationDate);

private:
    BookFactory();                                          // Private constructor
    BookFactory(const BookFactory&) = delete;               // Prevent copy-construction
    BookFactory &operator=(const BookFactory&) = delete;    // Prevent assignment
};

#endif // BOOKFACTORY_H
