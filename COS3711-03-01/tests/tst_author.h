#ifndef TST_AUTHOR_H
#define TST_AUTHOR_H

#include <QObject>
#include <QtTest/QtTest>

class TestAuthor : public QObject
{
    Q_OBJECT

private slots:
    void testConstructor();
    void testGetFirstName();
    void testGetLastName();
    void testToString();
};

#endif // TST_AUTHOR_H
