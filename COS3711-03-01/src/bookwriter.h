#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "filewriter.h"
#include "book.h"

#include <QDomDocument>

class QString;


class BookWriter
{
public:
    BookWriter(const QString &fileName);
    bool write(const QList<Book*> bookList);

private:
    QDomElement createBookElement(QDomDocument &doc, const Book *book);

    QString m_FileName;
    FileWriter m_FileWriter;
};

#endif // BOOKWRITER_H
