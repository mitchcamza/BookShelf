#include "tst_author.h"
#include "author.h"

void TestAuthor::testConstructor()
{
    Author author("John", "Doe");
    QCOMPARE(author.getFirstName(), QString("John"));
    QCOMPARE(author.getLastName(), QString("Doe"));
}

void TestAuthor::testGetFirstName()
{
    Author author("Jane", "Smith");
    QCOMPARE(author.getFirstName(), QString("Jane"));
}

void TestAuthor::testGetLastName()
{
    Author author("Jane", "Smith");
    QCOMPARE(author.getLastName(), QString("Smith"));
}

void TestAuthor::testToString()
{
    Author author("John", "Doe");
    QCOMPARE(author.toString(), QString("DOE, JOHN"));
}

QTEST_MAIN(TestAuthor)
#include "tst_author.moc"
