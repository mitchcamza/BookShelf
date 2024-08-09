#ifndef BOOKTABLEMODEL_H
#define BOOKTABLEMODEL_H

#include <QAbstractTableModel>

class Book;


class BookTableModel : public QAbstractTableModel
{
public:
    explicit BookTableModel(QObject *parent = nullptr);
    ~BookTableModel();
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void addBook(Book *book);

    QList<Book *> getBookList() const;

private:
    QList<Book*> bookList;

};

#endif // BOOKTABLEMODEL_H
