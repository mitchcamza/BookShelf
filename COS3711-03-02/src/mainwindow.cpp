/**
 * @file mainwindow.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the MainWindow class.
 * @date 2024-07-25
 * @copyright Copyright (c) 2024 
 */


#include "bookinput.h"
#include "bookproxymodel.h"
#include "booktablemodel.h"
#include "bookwriter.h"
#include "mainwindow.h"

#include <QFileDialog>
#include <QGridLayout>
#include <QHeaderView>
#include <QIcon>
#include <QLineEdit>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QStatusBar>
#include <QTableView>
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    bookTableModel(new BookTableModel(this)),
    bookProxyModel(new BookProxyModel(this)),
    bookTableView(new QTableView(this)),
    actionAddBook(new QAction(QIcon(":/icons/addBook"), tr("New Book"), this)),
    actionExportBooks(new QAction(QIcon(":/icons/export"), tr("Export Books"), this)),
    actionClose(new QAction(QIcon(":/icons/exit"), tr("Exit Application"), this)),
    lineEditSearch(new QLineEdit(this)),
    pushButtonClear(new QPushButton("Clear Filter", this))
{
    // Proxy Model
    bookProxyModel->setSourceModel(bookTableModel);
    bookProxyModel->setFilterKeyColumn(0);
    bookProxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    // Signals and Slots connections
    connect(actionAddBook, &QAction::triggered, this, &MainWindow::addBook);
    connect(actionExportBooks, &QAction::triggered, this, &MainWindow::exportBooks);
    connect(lineEditSearch, &QLineEdit::textEdited, bookProxyModel, &BookProxyModel::setFilter);
    connect(pushButtonClear, &QPushButton::clicked, this, &MainWindow::clearFilter);
    connect(actionClose, &QAction::triggered, this, &MainWindow::close);

    setupUI();
}

MainWindow::~MainWindow() {}


void MainWindow::setupUI()
{
    // Main Application Window
    setWindowTitle("Book Shelf");
    resize(1000, 600);

    // Menu Bar
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // File Menu
    QMenu *fileMenu = menuBar->addMenu(tr("&File"));
    fileMenu->addAction(actionExportBooks);
    actionExportBooks->setToolTip("Exports existing books to file.");
    fileMenu->addSeparator();
    fileMenu->addAction(actionClose);

    // Edit Menu
    QMenu *editMenu = menuBar->addMenu(tr("&Edit"));
    editMenu->addAction(actionAddBook);

    // Status Bar
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    // Tool Bar
    QToolBar *toolBar = new QToolBar(this);
    actionAddBook->setIcon(QIcon(":/icons/addBook"));
    toolBar->addAction(actionAddBook);
    toolBar->addSeparator();
    toolBar->addAction(actionExportBooks);
    addToolBar(Qt::TopToolBarArea, toolBar);

    // Central Widget and Layout
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout(centralWidget);
    setCentralWidget(centralWidget);

    // Search Bar
    lineEditSearch->setPlaceholderText("Search book name");
    gridLayout->addWidget(lineEditSearch, 0, 0, 1, 3);
    gridLayout->addWidget(pushButtonClear, 0, 3, 1, 1);

    // Book table view
    bookTableView->setModel(bookProxyModel);
    bookTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    bookTableView->setSortingEnabled(true);
    gridLayout->addWidget(bookTableView, 1, 0, 1, 4);
}

void MainWindow::addBook()
{
    BookInput *bookInputDialog = new BookInput(bookTableModel, this);
    bookInputDialog->show();
}

void MainWindow::exportBooks()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export Book List"), "", tr("XML Files (*.xml);; All Files (*)"));
    if (fileName.isEmpty())
    {
        return;
    }

    BookWriter writer(fileName);
    if (writer.write(bookTableModel->getBookList()))
    {
        QMessageBox::information(this, tr("Export Successful"), tr("The book list was exported successfully."));
    }
    else
    {
        QMessageBox::warning(this, tr("Export Failed"), tr("Failed to export book list."));
    }
}

void MainWindow::clearFilter()
{
    lineEditSearch->clear();
    lineEditSearch->setFocus();
    bookProxyModel->setFilter(lineEditSearch->text());
}

