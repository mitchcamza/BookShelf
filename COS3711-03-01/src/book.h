#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QStringList>
#include <QDate>


class Book
{
public:
    Book();
    Book(const QString &title, const QStringList &authors, const QString &isbn, const QDate &publicationDate);
    void setTitle(const QString &title);
    void setAuthors(const QStringList &authors);
    void setIsbn(const QString &isbn);
    void setPublicationDate(const QDate &publicationDate);
    QString getTitle() const;
    QStringList getAuthors() const;
    QString getIsbn() const;
    QDate getPublicationDate() const;

private:
    QString m_title;
    QStringList m_authors;
    QString m_isbn;
    QDate m_publicationDate;
};

#endif // BOOK_H
