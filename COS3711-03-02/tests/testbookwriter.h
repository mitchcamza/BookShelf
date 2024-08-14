/**
 * @file testbookwriter.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the TestBookWriter class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef TESTBOOKWRITER_H
#define TESTBOOKWRITER_H

#include "book.h"
#include "bookwriter.h"

#include <QObject>
#include <QtTest/QtTest>


/**
 * @class TestBookWriter
 * @brief The TestBookWriter class contains tests for the BookWriter class.
 */
class TestBookWriter : public QObject
{
    Q_OBJECT

private slots:
    void testWriteSingleBook();
    void testWriteMultipleBooks();
    void testWriteEmptyBookList();
    void cleanupTestCase();
};

#endif // TESTBOOKWRITER_H
