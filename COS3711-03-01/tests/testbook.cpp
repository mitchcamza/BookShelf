/**
 * @file testbook.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the TestBook class. 
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "testbook.h"
#include "book.h"
#include "author.h"


void TestBook::testDefaultConstructor()
{
    Book book;
    QCOMPARE(book.getTitle(), QString());
    QCOMPARE(book.getAuthors(), QStringList());
    QCOMPARE(book.getIsbn(), QString());
    QCOMPARE(book.getPublicationDate(), QDate::currentDate());
}

void TestBook::testConstructorWithParameters()
{
    Author author("JK", "Rowling");
    QStringList authorList;
    authorList.append(author.toString());

    QDate publicationDate(2000, 1, 1);
    Book book("Harry Potter and the Chamber of Secrets", authorList, "123456789", publicationDate);

    QCOMPARE(book.getTitle(), QString("Harry Potter and the Chamber of Secrets"));
    QCOMPARE(book.getAuthors(), authorList);
    QCOMPARE(book.getIsbn(), QString("123456789"));
    QCOMPARE(book.getPublicationDate(), publicationDate);
}

void TestBook::testSetTitle()
{
    Book book;
    book.setTitle("The Lion King");
    QCOMPARE(book.getTitle(), QString("The Lion King"));
}

void TestBook::testSetAuthors()
{
    Book book;
    Author author1("JK", "Rowling");
    Author author2("John", "Doe");
    QStringList authorList;
    authorList.append(author1.toString());
    authorList.append(author2.toString());

    book.setAuthors(authorList);
    QCOMPARE(book.getAuthors(), authorList);
}

void TestBook::testSetIsbn()
{
    Book book;
    QString newIsbn("987654321");
    book.setIsbn(newIsbn);
    QCOMPARE(book.getIsbn(), newIsbn);
}

void TestBook::testSetPublicationDate()
{
    Book book;
    QDate newDate(2020, 1, 1);
    book.setPublicationDate(newDate);
    QCOMPARE(book.getPublicationDate(), newDate);
}

void TestBook::testGetTitle()
{
    Book book;
    QString title("Harry Potter and the Chamber of Secrets");
    book.setTitle(title);
    QCOMPARE(book.getTitle(), title);
}

void TestBook::testGetAuthors()
{
    Book book;
    Author author("JK", "Rowling");
    QStringList authorList;
    authorList.append(author.toString());

    book.setAuthors(authorList);
    QCOMPARE(book.getAuthors(), authorList);
}

void TestBook::testGetIsbn()
{
    Book book;
    QString isbn("123456789");
    book.setIsbn(isbn);
    QCOMPARE(book.getIsbn(), isbn);
}

void TestBook::testGetPublicationDate()
{
    Book book;
    QDate publicationDate(2020, 1, 1);
    book.setPublicationDate(publicationDate);
    QCOMPARE(book.getPublicationDate(), publicationDate);
}

#include "testbook.moc"
