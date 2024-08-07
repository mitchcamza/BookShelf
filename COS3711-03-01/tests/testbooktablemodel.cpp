#include "testbooktablemodel.h"
#include "booktablemodel.h"
#include "book.h"


void TestBookTableModel::testRowCount()
{
    BookTableModel model;
    QCOMPARE(model.rowCount(QModelIndex()), 0);

    Book *book1 = new Book("Title1", {"Author1"}, "ISBN1", QDate(2023, 1, 1));
    model.addBook(book1);
    QCOMPARE(model.rowCount(QModelIndex()), 1);

    Book *book2 = new Book("Title2", {"Author2"}, "ISBN2", QDate(2023, 2, 2));
    model.addBook(book2);
    QCOMPARE(model.rowCount(QModelIndex()), 2);
}

void TestBookTableModel::testColumnCount()
{
    BookTableModel model;
    QCOMPARE(model.columnCount(QModelIndex()), 4);
}

void TestBookTableModel::testData()
{
    BookTableModel model;
    Book *book = new Book("Title", {"Author1", "Author2"}, "ISBN", QDate(2023, 1, 1));
    model.addBook(book);

    QModelIndex index = model.index(0, 0);
    QCOMPARE(model.data(index, Qt::DisplayRole).toString(), QString("Title"));

    index = model.index(0, 1);
    QCOMPARE(model.data(index, Qt::DisplayRole).toStringList(), QStringList({"Author1", "Author2"}));

    index = model.index(0, 2);
    QCOMPARE(model.data(index, Qt::DisplayRole).toDate(), QDate(2023, 1, 1));

    index = model.index(0, 3);
    QCOMPARE(model.data(index, Qt::DisplayRole).toString(), QString("ISBN"));
}

void TestBookTableModel::testHeaderData()
{
    BookTableModel model;
    QCOMPARE(model.headerData(0, Qt::Horizontal, Qt::DisplayRole).toString(), QString("Title"));
    QCOMPARE(model.headerData(1, Qt::Horizontal, Qt::DisplayRole).toString(), QString("Author"));
    QCOMPARE(model.headerData(2, Qt::Horizontal, Qt::DisplayRole).toString(), QString("Publication Date"));
    QCOMPARE(model.headerData(3, Qt::Horizontal, Qt::DisplayRole).toString(), QString("ISBN"));
    QCOMPARE(model.headerData(0, Qt::Vertical, Qt::DisplayRole).toInt(), 1);
}

void TestBookTableModel::testSetData()
{
    BookTableModel model;
    Book *book = new Book("Title", {"Author1"}, "ISBN", QDate(2023, 1, 1));
    model.addBook(book);

    QModelIndex index = model.index(0, 0);
    QVERIFY(model.setData(index, QVariant("New Title"), Qt::EditRole));
    QCOMPARE(model.data(index, Qt::DisplayRole).toString(), QString("New Title"));

    index = model.index(0, 1);
    QVERIFY(model.setData(index, QVariant(QStringList{"New Author1", "New Author2"}), Qt::EditRole));
    QCOMPARE(model.data(index, Qt::DisplayRole).toStringList(), QStringList({"New Author1", "New Author2"}));

    index = model.index(0, 2);
    QVERIFY(model.setData(index, QVariant(QDate(2023, 2, 2)), Qt::EditRole));
    QCOMPARE(model.data(index, Qt::DisplayRole).toDate(), QDate(2023, 2, 2));

    index = model.index(0, 3);
    QVERIFY(model.setData(index, QVariant("New ISBN"), Qt::EditRole));
    QCOMPARE(model.data(index, Qt::DisplayRole).toString(), QString("New ISBN"));
}

void TestBookTableModel::testAddBook()
{
    BookTableModel model;
    QCOMPARE(model.rowCount(QModelIndex()), 0);

    Book *book = new Book("Title", {"Author"}, "ISBN", QDate(2023, 1, 1));
    model.addBook(book);
    QCOMPARE(model.rowCount(QModelIndex()), 1);

    QModelIndex index = model.index(0, 0);
    QCOMPARE(model.data(index, Qt::DisplayRole).toString(), QString("Title"));
}

#include "testbooktablemodel.moc"
