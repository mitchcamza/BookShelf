#ifndef TESTBOOKPROXYMODEL_H
#define TESTBOOKPROXYMODEL_H

#include <QObject>
#include <QtTest/QtTest>


class TestBookProxyModel : public QObject
{
    Q_OBJECT

private slots:
    void testFilter();
};

#endif // TESTBOOKPROXYMODEL_H
