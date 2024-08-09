/**
 * @file testbookproxymodel.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the TestBookProxyModel class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "testbookproxymodel.h"
#include "booktablemodel.h"
#include "bookproxymodel.h"
#include "book.h"


void TestBookProxyModel::testFilter()
{
    // Create source model and add books
    BookTableModel sourceModel;
    sourceModel.addBook(new Book("C++ Primer", {"Lippman"}, "123456", QDate(2020, 1, 1)));
    sourceModel.addBook(new Book("Effective Modern C++", {"Meyers"}, "789012", QDate(2016, 5, 15)));
    sourceModel.addBook(new Book("Clean Code", {"Martin"}, "345678", QDate(2008, 8, 11)));
    sourceModel.addBook(new Book("Design Patterns", {"Gamma"}, "901234", QDate(1994, 11, 10)));

    // Create proxy model and set source model
    BookProxyModel proxyModel;
    proxyModel.setSourceModel(&sourceModel);

    // Check initial row count
    QCOMPARE(proxyModel.rowCount(), 4);

    // Set filter to match books with "C++" in title
    proxyModel.setFilter("C\\+\\+");
    QCOMPARE(proxyModel.rowCount(), 2);

    // Check that the correct books are filtered
    QModelIndex index = proxyModel.index(0, 0);
    QCOMPARE(proxyModel.data(index, Qt::DisplayRole).toString(), QString("C++ Primer"));

    index = proxyModel.index(1, 0);
    QCOMPARE(proxyModel.data(index, Qt::DisplayRole).toString(), QString("Effective Modern C++"));

    // Set filter to match books with "Clean" in title
    proxyModel.setFilter("Clean");
    QCOMPARE(proxyModel.rowCount(), 1);

    index = proxyModel.index(0, 0);
    QCOMPARE(proxyModel.data(index, Qt::DisplayRole).toString(), QString("Clean Code"));

    // Set filter to match books with "Patterns" in title
    proxyModel.setFilter("Patterns");
    QCOMPARE(proxyModel.rowCount(), 1);

    index = proxyModel.index(0, 0);
    QCOMPARE(proxyModel.data(index, Qt::DisplayRole).toString(), QString("Design Patterns"));

    // Set filter to match books with no match
    proxyModel.setFilter("Non-Existent Title");
    QCOMPARE(proxyModel.rowCount(), 0);
}

#include "testbookproxymodel.moc"
