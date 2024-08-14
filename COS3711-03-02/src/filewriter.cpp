/**
 * @file filewriter.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the FileWriter class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "filewriter.h"

#include <QFile>
#include <QString>
#include <QTextStream>


FileWriter::FileWriter(const QString &fileName)
    : m_FileName(fileName)
{

}

bool FileWriter::write(const QString &contents)
{
    QFile file(m_FileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QTextStream out(&file);
    out << contents;
    out.flush();
    file.close();
    return true;
}
