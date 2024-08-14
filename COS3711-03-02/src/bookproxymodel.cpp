/**
 * @file bookproxymodel.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the BookProxyModel class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "bookproxymodel.h"

#include <QRegularExpression>


BookProxyModel::BookProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{}

void BookProxyModel::setFilter(const QString &filterText)
{
    QRegularExpression titleRegex(filterText, QRegularExpression::CaseInsensitiveOption);
    setFilterRegularExpression(titleRegex);
}
