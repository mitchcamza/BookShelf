#ifndef BOOKPROXYMODEL_H
#define BOOKPROXYMODEL_H

#include <QSortFilterProxyModel>

class BookProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit BookProxyModel(QObject *parent = nullptr);

public slots:
    void setFilter(const QString &filterText);
};

#endif // BOOKPROXYMODEL_H
