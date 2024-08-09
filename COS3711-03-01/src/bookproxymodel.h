/**
 * @file bookproxymodel.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the BookProxyModel class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef BOOKPROXYMODEL_H
#define BOOKPROXYMODEL_H

#include <QSortFilterProxyModel>

/**
 * @class BookProxyModel
 * @brief The BookProxyModel class is a proxy model that filters the book table model.
 * 
 */
class BookProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    /**
     * @brief Construct a new BookProxyModel object
     * 
     * @param parent The parent object.
     */
    explicit BookProxyModel(QObject *parent = nullptr);

public slots:
    /**
     * @brief Set the filter text for the proxy model
     * 
     * @param filterText The text to filter the model by.
     */
    void setFilter(const QString &filterText);
};

#endif // BOOKPROXYMODEL_H
