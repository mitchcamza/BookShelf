/**
 * @file bookwriter.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the BookWriter class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "filewriter.h"
#include "book.h"

#include <QDomDocument>

class QString;


/**
 * @class BookWriter
 * @brief The BookWriter class is responsible for serializing a list of books to an XML file.
 * It uses the FileWriter class to handle the file writing.
 */
class BookWriter
{
public:
    /**
     * @brief Construct a new BookWriter object
     * 
     * @param fileName The name of the file to write to.
     */
    BookWriter(const QString &fileName);

    /**
     * @brief Write a list of books to the file.
     * 
     * @param bookList The list of books to write.
     * @return true If the write operation was successful.
     * @return false If the write operation failed.
     */
    bool write(const QList<Book*> bookList);

private:
    /**
     * @brief Create a Book Element object
     * 
     * @param doc The QDomDocument object.
     * @param book The book object.
     * @return QDomElement The QDomElement representing the book.
     */
    QDomElement createBookElement(QDomDocument &doc, const Book *book);


    QString m_FileName;         /**< The name of the file to write to. */
    FileWriter m_FileWriter;    /**< The FileWriter object used to write to the file. */
};

#endif // BOOKWRITER_H
