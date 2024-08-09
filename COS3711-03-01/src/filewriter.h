/**
 * @file filewriter.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the FileWriter class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef FILEWRITER_H
#define FILEWRITER_H


#include <QString>


/**
 * @class FileWriter
 * @brief The FileWriter class is responsible for writing a string to a file.
 */
class FileWriter
{
public:
    /**
     * @brief Construct a new FileWriter object
     * 
     * @param fileName The name of the file to write to.
     */
    FileWriter(const QString &fileName);

    /**
     * @brief Write a string to the file.
     * 
     * @param contents The string to write.
     * @return true If the write operation was successful.
     * @return false If the write operation failed.
     */
    bool write(const QString &contents);

private:
    QString m_FileName;     /**< The name of the file to write to. */
};

#endif // FILEWRITER_H
