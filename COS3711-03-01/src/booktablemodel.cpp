#include "booktablemodel.h"
#include "book.h"


BookTableModel::BookTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

BookTableModel::~BookTableModel()
{
    qDeleteAll(books);
}

int BookTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }
    return books.size();
}

int BookTableModel::columnCount(const QModelIndex &parent) const
{

    if (parent.isValid())
    {
        return 0;
    }
    return 4;   // title, author, publication date, isbn
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

        if (col == 0) { return books.at(row)->getTitle(); }
        if (col == 1) { return books.at(row)->getAuthors(); }
        if (col == 2) { return books.at(row)->getPublicationDate(); }
        if (col == 3) { return books.at(row)->getIsbn(); }
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
            return QString("Title");
            break;
        case 1:
            return QString("Author");
            break;
        case 2:
            return QString("Publication Date");
            break;
        case 3:
            return QString("ISBN");
            break;
        }
    }
    else if (orientation == Qt::Vertical)
    {
        return section + 1; // row numbers
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
            books.at(row)->setTitle(value.toString());
            break;
        case 1:
            books.at(row)->setAuthors(value.toStringList());
            break;
        case 2:
            books.at(row)->setPublicationDate(value.toDate());
            break;
        case 3:
            books.at(row)->setIsbn(value.toString());
            break;
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
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    }
    else
    {
        return Qt::NoItemFlags;
    }
}

void BookTableModel::addBook(Book *book)
{
    int row = books.size();
    beginInsertRows(QModelIndex(), row + 1, row + 1);
    books.append(book);
    endInsertRows();
}