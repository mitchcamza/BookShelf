/**
 * @file testfilewriter.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the TestFileWriter class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef TESTFILEWRITER_H
#define TESTFILEWRITER_H

#include "filewriter.h"

#include <QObject>
#include <QtTest/QtTest>


/**
 * @class TestFileWriter
 * @brief The TestFileWriter class contains tests for the FileWriter class.
 */
class TestFileWriter : public QObject
{
    Q_OBJECT

private slots:
    void testWriteToFile();
    void testWriteToInvalidFile();
    void testWriteEmptyContent();
    void cleanupTestCase();
};

#endif // TESTFILEWRITER_H
