/**
 * @file mainwindow.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the MainWindow class.
 * @date 2024-07-25
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H


class BookProxyModel;
class BookTableModel;
class BookView;
class QLineEdit;
class QPushButton;
class QTableView;

#include <QMainWindow>


/**
 * @class MainWindow
 * @brief This class is the main window of the application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new MainWindow object
     * 
     * @param parent The parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroy the MainWindow object
     * 
     */
    ~MainWindow();

private:
    /**
     * @brief This method sets up the user interface.
     * @details It creates the main appication window, the menu bar, the tool bar, the status bar, the serach bar, the table view, and the central widget.
     */
    void setupUI();

private slots:
    /**
     * @brief This method opens the BookInput dialog to enter the information required to add a new book.
     * 
     */
    void addBook();

    /**
     * @brief This method opens a file dialog to allow the list of books to be exported an XML file. It uses the BookWriter class to handle the serialization.
     * 
     */
    void exportBooks();

    /**
     * @brief This method clears the text in the search bar. The text in the search bar is connected to the filter in the BookProxyModel which filters the books displayed in the table by title.
     * 
     */
    void clearFilter();

private:
    BookTableModel *bookTableModel; /**< The table model for the books. */
    BookProxyModel *bookProxyModel; /**< The proxy model for the books. */
    QTableView *bookTableView;      /**< The table view for the books. */
    QAction *actionAddBook;         /**< The action to add a new book. */
    QAction *actionExportBooks;     /**< The action to export the books. */
    QAction *actionClose;           /**< The action to close the application. */
    QLineEdit *lineEditSearch;      /**< The line edit for searching the books. */
    QPushButton *pushButtonClear;   /**< The push button to clear the search filter. */
};
#endif // MAINWINDOW_H
