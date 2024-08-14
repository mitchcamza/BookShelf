/**
 * @file testbook.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the TestBook class. 
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */

#ifndef TESTBOOK_H
#define TESTBOOK_H

#include <QObject>
#include <QtTest/QtTest>


/**
 * @class TestBook
 * @brief The TestBook class contains tests for the Book class. It tests the constructors, setters, and getters of the Book class.
 */
class TestBook : public QObject
{
    Q_OBJECT

private slots:
    void testDefaultConstructor();
    void testConstructorWithParameters();
    void testSetTitle();
    void testSetAuthors();
    void testSetIsbn();
    void testSetPublicationDate();
    void testGetTitle();
    void testGetAuthors();
    void testGetIsbn();
    void testGetPublicationDate();
};

#endif // TESTBOOK_H
