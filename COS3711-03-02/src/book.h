/**
 * @file book.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the Book class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QStringList>
#include <QDate>


/**
 * @class Book
 * @brief The Book class represents a book object.
 */
class Book  : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QStringList authors READ getAuthors WRITE setAuthors NOTIFY authorsChanged)
    Q_PROPERTY(QString isbn READ getIsbn WRITE setIsbn NOTIFY isbnChanged)
    Q_PROPERTY(QDate publicationDate READ getPublicationDate WRITE setPublicationDate NOTIFY publicationDateChanged)

public:
    /**
     * @brief Construct a new Book object
     * 
     */
    Book();

    /**
     * @brief Construct a new Book object
     * 
     * @param title The title of the book.
     * @param authors The author(s) of the book.
     * @param isbn The ISBN of the book.
     * @param publicationDate The publication date of the book.
     */
    Book(const QString &title, const QStringList &authors, const QString &isbn, const QDate &publicationDate);

private:
    /**
     * @brief Set the book's title
     * 
     * @param title The title of the book.
     */
    void setTitle(const QString &title);

    /**
     * @brief Set the book's author(s).
     * 
     * @param authors A list of the author(s) of the book.
     */
    void setAuthors(const QStringList &authors);

    /**
     * @brief Set the book's ISBN.
     * @details The ISBN line edit used an input mask to ensure that the ISBN is entered in the correct format.
     * @param isbn The ISBN of the book.
     */
    void setIsbn(const QString &isbn);

    /**
     * @brief Set the book's Publication Date.
     * 
     * @param publicationDate The publication date of the book.
     */
    void setPublicationDate(const QDate &publicationDate);

    /**
     * @brief Get the book's title
     * 
     * @return QString The title of the book.
     */
    QString getTitle() const;

    /**
     * @brief Get the book's author(s)
     * 
     * @return QStringList A list of the author(s) of the book.
     */
    QStringList getAuthors() const;

    /**
     * @brief Get the book's ISBN.
     * 
     * @return QString 
     */
    QString getIsbn() const;

    /**
     * @brief Get the book's Publication Date.
     * 
     * @return QDate 
     */
    QDate getPublicationDate() const;

signals:
    void titleChanged(const QString &newTitle);
    void authorsChanged(const QStringList &newAuthorsList);
    void isbnChanged(const QString &newIsbn);
    void publicationDateChanged(const QDate &newPublicationDate);


private:
    QString m_title;            /**< The title of the book. */
    QStringList m_authors;      /**< The author(s) of the book. */
    QString m_isbn;             /**< The ISBN of the book. */
    QDate m_publicationDate;    /**< The publication date of the book. */
};

#endif // BOOK_H
