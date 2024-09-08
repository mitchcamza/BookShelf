/**
 * @file bookwriter.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the BookWriter class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "bookwriter.h"


BookWriter::BookWriter(const QString &fileName)
    : m_FileName(fileName), m_FileWriter(fileName)
{

}

bool BookWriter::write(const QList<Book*> bookList)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("booklist");
    doc.appendChild(root);

    for (const Book *book : bookList)
    {
        QDomElement bookElement = createBookElement(doc, book);
        root.appendChild(bookElement);
    }

    QString xmlString = doc.toString();
    return m_FileWriter.write(xmlString);
}

QDomElement BookWriter::createBookElement(QDomDocument &doc, const Book *book)
{
    // Book
    QDomElement bookElement = doc.createElement("book");

    // Title
    if (book->property("title").canConvert<QString>())
    {
        QDomElement titleElement = doc.createElement("title");
        titleElement.appendChild(doc.createTextNode(book->property("title").toString()));
        bookElement.appendChild(titleElement);
    }

    // Authors
    if (book->property("authors").canConvert<QStringList>())
    {
        QDomElement authorsElement = doc.createElement("authors");
        QStringList authors = book->property("authors").toStringList();
        QString authorsString = authors.join("; ");
        authorsElement.appendChild(doc.createTextNode(authorsString));
        bookElement.appendChild(authorsElement);
    }


    // Publication Date
    if (book->property("publicationDate").canConvert<QString>())
    {
        QDomElement publicationDateElement = doc.createElement("date");
        publicationDateElement.appendChild(doc.createTextNode(book->property("publicationDate").toString()));
        bookElement.appendChild(publicationDateElement);
    }


    // ISBN
    if (book->property("isbn").canConvert<QString>())
    {
        QDomElement isbnElement = doc.createElement("isbn");
        isbnElement.appendChild(doc.createTextNode(book->property("isbn").toString()));
        bookElement.appendChild(isbnElement);
    }

    return bookElement;
}
