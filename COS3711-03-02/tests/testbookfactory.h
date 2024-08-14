/**
 * @file testbookfactory.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the TestBookFactory class. 
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef TESTBOOKFACTORY_H
#define TESTBOOKFACTORY_H

#include <QObject>
#include <QtTest/QtTest>


/**
 * @class TestBookFactory
 * @brief The TestBookFactory class contains tests for the BookFactory class.
 */
class TestBookFactory : public QObject
{
    Q_OBJECT

private slots:
    void testCreateBook();
    void testCreateBookInvalidData();
    void testSingletonInstance();
};

#endif // TESTBOOKFACTORY_H
