/**
 * @file booktablemodel.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the BookTableModel class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef BOOKTABLEMODEL_H
#define BOOKTABLEMODEL_H

#include <QAbstractTableModel>

class Book;


/**
 * @class BookTableModel
 * @brief The BookTableModel class is a table model that stores a list of books.
 */
class BookTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief Construct a new Book Table Model object
     * 
     * @param parent The parent object.
     */
    explicit BookTableModel(QObject *parent = nullptr);

    /**
     * @brief Destroy the Book Table Model object
     * 
     */
    ~BookTableModel();

    /**
     * @brief Returns the number of rows in the model.
     * 
     * @param parent The parent index.
     * @return int The number of rows in the model.
     */
    int rowCount(const QModelIndex &parent) const override;

    /**
     * @brief Returns the number of columns in the model.
     * 
     * @param parent The parent index.
     * @return int The number of columns in the model.
     */
    int columnCount(const QModelIndex &parent) const override;

    /**
     * @brief Returns the data stored under the given role for the item referred to by the index.
     * 
     * @param index The index of the item.
     * @param role The role for which to return data.
     * @return QVariant The data stored under the given role for the item referred to by the index.
     */
    QVariant data(const QModelIndex &index, int role) const override;

    /**
     * @brief Returns the data for the given role and section in the header with the specified orientation.
     * 
     * @param section The section of the header.
     * @param orientation The orientation of the header.
     * @param role The role for which to return data.
     * @return QVariant The data for the given role and section in the header with the specified orientation.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    /**
     * @brief Sets the role data for the item at index to value.
     * 
     * @param index The index of the item.
     * @param value The value to set.
     * @param role The role to set.
     * @return true If the data was set successfully.
     * @return false If the data was not set successfully.
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    /**
     * @brief Returns the item flags for the given index.
     * 
     * @param index The index of the item.
     * @return Qt::ItemFlags The item flags for the given index.
     */
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    /**
     * @brief Adds a book to the model.
     * 
     * @param book The book to add.
     */
    void addBook(Book *book);

    /**
     * @brief Returns the list of books in the model.
     * 
     * @return QList<Book *> The list of books in the model.
     */
    QList<Book *> getBookList() const;

private:
    QList<Book*> bookList;  /**< The list of books in the model. */

};

#endif // BOOKTABLEMODEL_H
