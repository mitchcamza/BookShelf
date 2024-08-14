/**
 * @file bookfactory.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the BookFactory class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "bookfactory.h"
#include "book.h"


BookFactory::BookFactory() {}

BookFactory &BookFactory::getInstance()
{
    static BookFactory bookFactoryInstance;
    return bookFactoryInstance;
}

Book *BookFactory::createBook(const QString &title, const QStringList &authors, const QString &isbn, const QDate &publicationDate)
{
    if (title.isEmpty() || authors.isEmpty() || isbn.isEmpty() || !publicationDate.isValid())
    {
        return nullptr;
    }
    return new Book(title, authors, isbn, publicationDate);
}
