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
    QCOMPARE(book.property("title"), QString());
    QCOMPARE(book.property("authors"), QStringList());
    QCOMPARE(book.property("isbn"), QString());
    QCOMPARE(book.property("publicationDate"), QDate::currentDate());
}

void TestBook::testConstructorWithParameters()
{
    Author author("JK", "Rowling");
    QStringList authorList;
    authorList.append(author.toString());

    QDate publicationDate(2000, 1, 1);
    Book book("Harry Potter and the Chamber of Secrets", authorList, "123456789", publicationDate);

    QCOMPARE(book.property("title"), QString("Harry Potter and the Chamber of Secrets"));
    QCOMPARE(book.property("authors"), authorList);
    QCOMPARE(book.property("isbn"), QString("123456789"));
    QCOMPARE(book.property("publicationDate"), publicationDate);
}

void TestBook::testSetTitle()
{
    Book book;
    book.setProperty("title", "The Lion King");
    QCOMPARE(book.property("title"), QString("The Lion King"));
}

void TestBook::testSetAuthors()
{
    Book book;
    Author author1("JK", "Rowling");
    Author author2("John", "Doe");
    QStringList authorList;
    authorList.append(author1.toString());
    authorList.append(author2.toString());

    book.setProperty("authors", authorList);
    QCOMPARE(book.property("authors"), authorList);
}

void TestBook::testSetIsbn()
{
    Book book;
    QString newIsbn("987654321");
    book.setProperty("isbn", newIsbn);
    QCOMPARE(book.property("isbn"), newIsbn);
}

void TestBook::testSetPublicationDate()
{
    Book book;
    QDate newDate(2020, 1, 1);
    book.setProperty("publicationDate", newDate);
    QCOMPARE(book.property("publicationDate"), newDate);
}

void TestBook::testGetTitle()
{
    Book book;
    QString title("Harry Potter and the Chamber of Secrets");
    book.setProperty("title", title);
    QCOMPARE(book.property("title"), title);
}

void TestBook::testGetAuthors()
{
    Book book;
    Author author("JK", "Rowling");
    QStringList authorList;
    authorList.append(author.toString());

    book.setProperty("authors", authorList);
    QCOMPARE(book.property("authors"), authorList);
}

void TestBook::testGetIsbn()
{
    Book book;
    QString isbn("123456789");
    book.setProperty("isbn", isbn);
    QCOMPARE(book.property("isbn"), isbn);
}

void TestBook::testGetPublicationDate()
{
    Book book;
    QDate publicationDate(2020, 1, 1);
    book.setProperty("publicationDate", publicationDate);
    QCOMPARE(book.property("publicationDate"), publicationDate);
}

#include "testbook.moc"
