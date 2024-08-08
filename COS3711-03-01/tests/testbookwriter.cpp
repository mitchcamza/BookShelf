#include "testbookwriter.h"

#include <QFile>
#include <QDate>


void TestBookWriter::testWriteSingleBook()
{
    QString fileName = "singlebook.xml";

    // Mocking a Book object
    Book book1;
    book1.setTitle("Harry Potter");
    book1.setAuthors({"J.K. Rowling"});
    book1.setPublicationDate(QDate(2024, 8, 8));
    book1.setIsbn("999-9-99-999999-9");

    BookWriter writer(fileName);
    bool result = writer.write({&book1});

    // Verify the write operation was successful
    QVERIFY(result);

    // Verify the file contains the correct XML structure
    QFile file(fileName);
    QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QString fileContent = file.readAll();

    QString expectedContent =
        "<booklist>\n"
        " <book>\n"
        "  <title>Harry Potter</title>\n"
        "  <authors>J.K. Rowling</authors>\n"
        "  <date>2024-08-08</date>\n"
        "  <isbn>999-9-99-999999-9</isbn>\n"
        " </book>\n"
        "</booklist>\n";

    QCOMPARE(fileContent, expectedContent);

    file.close();
}

void TestBookWriter::testWriteMultipleBooks()
{
    QString fileName = "multiplebooks.xml";

    // Mocking Book objects
    Book book1, book2;
    book1.setTitle("Book 1");
    book1.setAuthors({"Author One"});
    book1.setPublicationDate(QDate(2023, 1, 1));
    book1.setIsbn("123-4-56-789012-3");

    book2.setTitle("Book 2");
    book2.setAuthors({"Author Two", "Author Three"});
    book2.setPublicationDate(QDate(2024, 2, 2));
    book2.setIsbn("234-5-67-890123-4");

    BookWriter writer(fileName);
    bool result = writer.write({&book1, &book2});

    // Verify the write operation was successful
    QVERIFY(result);

    // Verify the file contains the correct XML structure
    QFile file(fileName);
    QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QString fileContent = file.readAll();

    QString expectedContent =
        "<booklist>\n"
        " <book>\n"
        "  <title>Book 1</title>\n"
        "  <authors>Author One</authors>\n"
        "  <date>2023-01-01</date>\n"
        "  <isbn>123-4-56-789012-3</isbn>\n"
        " </book>\n"
        " <book>\n"
        "  <title>Book 2</title>\n"
        "  <authors>Author Two; Author Three</authors>\n"
        "  <date>2024-02-02</date>\n"
        "  <isbn>234-5-67-890123-4</isbn>\n"
        " </book>\n"
        "</booklist>\n";

    QCOMPARE(fileContent, expectedContent);

    file.close();
}

void TestBookWriter::testWriteEmptyBookList()
{
    QString fileName = "emptybooklist.xml";

    BookWriter writer(fileName);
    bool result = writer.write({});

    // Verify the write operation was successful
    QVERIFY(result);

    // Verify the file contains the correct XML structure for an empty book list
    QFile file(fileName);
    QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QString fileContent = file.readAll();

    QString expectedContent =
        "<booklist/>\n";

    QCOMPARE(fileContent, expectedContent);

    file.close();
}

void TestBookWriter::cleanupTestCase()
{
    // Clean up the files created during testing
    QFile::remove("singlebook.xml");
    QFile::remove("multiplebooks.xml");
    QFile::remove("emptybooklist.xml");
}

#include "testbookwriter.moc"
