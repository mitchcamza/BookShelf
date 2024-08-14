/**
 * @file testbooktablemodel.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the TestBookTableModel class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef TESTBOOKTABLEMODEL_H
#define TESTBOOKTABLEMODEL_H

#include <QObject>
#include <QtTest/QtTest>


/**
 * @class TestBookTableModel
 * @brief The TestBookTableModel class contains tests for the BookTableModel class.
 */
class TestBookTableModel : public QObject
{
    Q_OBJECT

private slots:
    void testRowCount();
    void testColumnCount();
    void testData();
    void testHeaderData();
    void testSetData();
    void testAddBook();
};

#endif // TESTBOOKTABLEMODEL_H
