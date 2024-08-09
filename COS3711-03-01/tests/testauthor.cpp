/**
 * @file testauthor.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the TestAuthor class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "testauthor.h"
#include "author.h"


void TestAuthor::testConstructor()
{
    Author author("John", "Doe");
    QCOMPARE(author.getFirstName(), QString("John"));
    QCOMPARE(author.getLastName(), QString("Doe"));
}

void TestAuthor::testGetFirstName()
{
    Author author("Jane", "Smith");
    QCOMPARE(author.getFirstName(), QString("Jane"));
}

void TestAuthor::testGetLastName()
{
    Author author("Jane", "Smith");
    QCOMPARE(author.getLastName(), QString("Smith"));
}

void TestAuthor::testToString()
{
    Author author("John", "Doe");
    QCOMPARE(author.toString(), QString("DOE, JOHN"));
}

#include "testauthor.moc"
