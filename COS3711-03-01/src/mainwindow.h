/**
 * @file mainwindow.h
 * @author Mitch Campbell
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUI();

private slots:
    void addBook();
    void exportBooks();
    void clearFilter();

private:
    BookTableModel *bookTableModel;
    BookProxyModel *bookProxyModel;
    QTableView *bookTableView;
    QAction *actionAddBook;
    QAction *actionExportBooks;
    QAction *actionClose;
    QLineEdit *lineEditSearch;
    QPushButton *pushButtonClear;
};
#endif // MAINWINDOW_H
