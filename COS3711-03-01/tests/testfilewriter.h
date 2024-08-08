#ifndef TESTFILEWRITER_H
#define TESTFILEWRITER_H

#include "filewriter.h"

#include <QObject>
#include <QtTest/QtTest>


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
