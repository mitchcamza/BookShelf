#ifndef TESTBOOKWRITER_H
#define TESTBOOKWRITER_H

#include "book.h"
#include "bookwriter.h"

#include <QObject>
#include <QtTest/QtTest>


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
