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
    QDomElement titleElement = doc.createElement("title");
    titleElement.appendChild(doc.createTextNode(book->getTitle()));
    bookElement.appendChild(titleElement);

    // Authors
    QDomElement authorsElement = doc.createElement("authors");
    QStringList authors = book->getAuthors();
    QString authorsString = authors.join("; ");
    authorsElement.appendChild(doc.createTextNode(authorsString));
    bookElement.appendChild(authorsElement);


    // Publication Date
    QDomElement publicationDateElement = doc.createElement("date");
    publicationDateElement.appendChild(doc.createTextNode(book->getPublicationDate().toString(Qt::ISODate)));
    bookElement.appendChild(publicationDateElement);


    // ISBN
    QDomElement isbnElement = doc.createElement("isbn");
    isbnElement.appendChild(doc.createTextNode(book->getIsbn()));
    bookElement.appendChild(isbnElement);

    return bookElement;
}
