/**
 * @file testauthor.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the TestAuthor class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef TESTAUTHOR_H
#define TESTAUTHOR_H

#include <QObject>
#include <QtTest/QtTest>

/**
 * @class TestAuthor
 * @brief The TestAuthor class contains tests for the Author class.
 */
class TestAuthor : public QObject
{
    Q_OBJECT

private slots:
    void testConstructor();
    void testGetFirstName();
    void testGetLastName();
    void testToString();
};

#endif // TESTAUTHOR_H
