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
