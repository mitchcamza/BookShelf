/**
 * @file book.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the Book class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "book.h"

Book::Book()
    : Book(QString(), QStringList(), QString(), QDate::currentDate())
{

}

Book::Book(const QString &title, const QStringList &authors, const QString &isbn, const QDate &publicationDate)
    : m_title(title), m_authors(authors), m_isbn(isbn), m_publicationDate(publicationDate)
{

}


void Book::setTitle(const QString &title)
{
    m_title = title;
}

void Book::setAuthors(const QStringList &authors)
{
    m_authors = authors;
}

void Book::setIsbn(const QString &isbn)
{
    m_isbn = isbn;
}

void Book::setPublicationDate(const QDate &publicationDate)
{
    m_publicationDate = publicationDate;
}

QString Book::getTitle() const
{
    return m_title;
}

QStringList Book::getAuthors() const
{
    return m_authors;
}

QString Book::getIsbn() const
{
    return m_isbn;
}

QDate Book::getPublicationDate() const
{
    return m_publicationDate;
}
