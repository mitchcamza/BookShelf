#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

class Book;
class QDate;
class QString;

#include <QStringList>


class BookFactory
{
public:
    static BookFactory &getInstance();
    Book *createBook(const QString &title, const QStringList &authors, const QString &isbn, const QDate &publicationDate);

private:
    BookFactory();
    BookFactory(const BookFactory&) = delete;
    BookFactory &operator=(const BookFactory&) = delete;
};

#endif // BOOKFACTORY_H
