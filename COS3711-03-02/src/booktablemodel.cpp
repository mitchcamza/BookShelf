/**
 * @file booktablemodel.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the BookTableModel class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "booktablemodel.h"
#include "book.h"


BookTableModel::BookTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

BookTableModel::~BookTableModel()
{
    qDeleteAll(bookList);
}

int BookTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }
    return bookList.size();
}

int BookTableModel::columnCount(const QModelIndex &parent) const
{

    if (parent.isValid())
    {
        return 0;
    }
    return 4;   // title, authors, publication date, isbn
}

QVariant BookTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        int col = index.column();
        int row = index.row();

        switch (col)
        {
            case 0:
            {
                return bookList.at(row)->property("title");
                break;
            }
            case 1:
            {
                if (bookList.at(row)->property("authors").toList().count() == 1)
                {
                    return bookList.at(row)->property("authors");
                }
                else if (bookList.at(row)->property("authors").toList().count() > 1)
                {
                    QStringList authors = bookList.at(row)->property("authors").toStringList();
                    return authors.join("; ");
                }
                break;
            }
            case 2:
            {
                return bookList.at(row)->property("publicationDate");
                break;
            }
            case 3:
            {
                return bookList.at(row)->property("isbn");
                break;
            }
        }
    }
    return QVariant();
}

QVariant BookTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal)
    {
        switch(section)
        {
            case 0:
            {
                return QString("Title");
                break;
            }
            case 1:
            {
                return QString("Author");
                break;
            }
            case 2:
            {
                return QString("Publication Date");
                break;
            }
            case 3:
            {
                return QString("ISBN");
                break;
            }
        }
    }
    return QVariant();
}

bool BookTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        int col = index.column();
        int row = index.row();

        switch (col)
        {
            case 0:
            {
                if (bookList.at(row)->property("title").canConvert<QString>())
                {
                    bookList.at(row)->setProperty("title", value.toString());
                    break;
                }
            }
            case 1:
            {
                if (bookList.at(row)->property("authors").canConvert<QStringList>())
                {
                    bookList.at(row)->setProperty("authors", value.toStringList());
                    break;
                }
            }
            case 2:
            {
                if (bookList.at(row)->property("publicationDate").canConvert<QDate>())
                {
                    bookList.at(row)->setProperty("publicationDate", value.toDate());
                    break;
                }
            }
            case 3:
            {
                if (bookList.at(row)->property("isbn").canConvert<QString>())
                {
                    bookList.at(row)->setProperty("isbn", value.toString());
                    break;
                }
            }
        }
        emit dataChanged(index, index, { role });
        return true;
    }
    return false;
}

Qt::ItemFlags BookTableModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
    {
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    }
    else
    {
        return Qt::NoItemFlags;
    }
}

void BookTableModel::addBook(Book *book)
{
    int row = bookList.size();
    beginInsertRows(QModelIndex(), row, row);
    bookList.append(book);
    endInsertRows();
}

QList<Book *> BookTableModel::getBookList() const
{
    return bookList;
}
