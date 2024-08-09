/**
 * @file testbookproxymodel.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the TestBookProxyModel class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef TESTBOOKPROXYMODEL_H
#define TESTBOOKPROXYMODEL_H

#include <QObject>
#include <QtTest/QtTest>


/**
 * @class TestBookProxyModel
 * @brief The TestBookProxyModel class contains tests for the BookProxyModel class. 
 */
class TestBookProxyModel : public QObject
{
    Q_OBJECT

private slots:
    void testFilter();
};

#endif // TESTBOOKPROXYMODEL_H
