#ifndef TESTBOOKTABLEMODEL_H
#define TESTBOOKTABLEMODEL_H

#include <QObject>
#include <QtTest/QtTest>


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
