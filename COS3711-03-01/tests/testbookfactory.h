#ifndef TESTBOOKFACTORY_H
#define TESTBOOKFACTORY_H

#include <QObject>
#include <QtTest/QtTest>


class TestBookFactory : public QObject
{
    Q_OBJECT

private slots:
    void testCreateBook();
    void testCreateBookInvalidData();
    void testSingletonInstance();
};

#endif // TESTBOOKFACTORY_H
