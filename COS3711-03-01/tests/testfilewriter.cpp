#include "testfilewriter.h"

#include <QFile>


void TestFileWriter::testWriteToFile()
{
    QString fileName = "testfile.txt";
    QString content = "Hello, World!";

    FileWriter writer(fileName);
    bool result = writer.write(content);

    // Verify the write operation was successful
    QVERIFY(result);

    // Verify the file contains the correct content
    QFile file(fileName);
    QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(&file);
    QString fileContent = in.readAll();
    QCOMPARE(fileContent, content);

    file.close();
}

void TestFileWriter::testWriteToInvalidFile()
{
    QString invalidFileName = "/invalidpath/testfile.txt";
    QString content = "This should fail.";

    FileWriter writer(invalidFileName);
    bool result = writer.write(content);

    // Verify the write operation failed
    QVERIFY(!result);
}

void TestFileWriter::testWriteEmptyContent()
{
    QString fileName = "emptyfile.txt";
    QString emptyContent = "";

    FileWriter writer(fileName);
    bool result = writer.write(emptyContent);

    // Verify the write operation was successful
    QVERIFY(result);

    // Verify the file is empty
    QFile file(fileName);
    QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(&file);
    QString fileContent = in.readAll();
    QCOMPARE(fileContent, emptyContent);

    file.close();
}

void TestFileWriter::cleanupTestCase()
{
    QFile::remove("testfile.txt");
    QFile::remove("emptyfile.txt");
}

#include "testfilewriter.moc"
