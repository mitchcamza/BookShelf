#include "testbookfactory.h"
#include "book.h"
#include "bookfactory.h"


void TestBookFactory::testCreateBook()
{
    BookFactory &bookFactory = BookFactory::getInstance();

    QString title = "Test Book";
    QStringList authors = { "Author one", "Author two" };
    QString isbn = "123-4-123456-1";
    QDate publicationDate = QDate(2024, 7, 25);

    Book *book = bookFactory.createBook(title, authors, isbn, publicationDate);

    QVERIFY(book != nullptr);
    QCOMPARE(book->getTitle(), title);
    QCOMPARE(book->getAuthors(), authors);
    QCOMPARE(book->getIsbn(), isbn);
    QCOMPARE(book->getPublicationDate(), publicationDate);

    delete book;
}

void TestBookFactory::testCreateBookInvalidData()
{
    BookFactory &bookFactory = BookFactory::getInstance();

    // Test with empty title
    QString title = "";
    QStringList authors = { "Author One" };
    QString isbn = "123-4567890123";
    QDate publicationDate = QDate(2024, 7, 25);

    Book *book = bookFactory.createBook(title, authors, isbn, publicationDate);
    QVERIFY(book == nullptr);

    // Test with empty authors
    title = "Test Book";
    authors = {};
    isbn = "123-4567890123";

    book = bookFactory.createBook(title, authors, isbn, publicationDate);
    QVERIFY(book == nullptr);

    // Test with empty ISBN
    authors = { "Author One" };
    isbn = "";

    book = bookFactory.createBook(title, authors, isbn, publicationDate);
    QVERIFY(book == nullptr);

    // Test with invalid publication date
    isbn = "123-4567890123";
    publicationDate = QDate();

    book = bookFactory.createBook(title, authors, isbn, publicationDate);
    QVERIFY(book == nullptr);
}

void TestBookFactory::testSingletonInstance()
{
    BookFactory &factory1 = BookFactory::getInstance();
    BookFactory &factory2 = BookFactory::getInstance();

    QCOMPARE(&factory1, &factory2); // expect same address
}

#include "testbookfactory.moc"
