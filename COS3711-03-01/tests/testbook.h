#ifndef TESTBOOK_H
#define TESTBOOK_H

#include <QObject>
#include <QtTest/QtTest>

class TestBook : public QObject
{
    Q_OBJECT

private slots:
    void testDefaultConstructor();
    void testConstructorWithParameters();
    void testSetTitle();
    void testSetAuthors();
    void testSetIsbn();
    void testSetPublicationDate();
    void testGetTitle();
    void testGetAuthors();
    void testGetIsbn();
    void testGetPublicationDate();
};

#endif // TESTBOOK_H
