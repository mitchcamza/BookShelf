/**
 * @file mainwindow.cpp
 * @author Mitch Campbell
 * @date 2024-07-25
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "mainwindow.h"
// #include "bookproxymodel.h"
// #include "bookinput.h"
// #include "bookview.h"

#include <QFileDialog>
#include <QGridLayout>
#include <QHeaderView>
#include <QIcon>
#include <QLineEdit>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QStatusBar>
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    menuBar(new QMenuBar(this)),
    statusBar(new QStatusBar(this)),
    toolBar(new QToolBar(this)),
    actionAddBook(new QAction(this)),
    actionExportBooks(new QAction(this)),
    actionClose(new QAction(this)),
    lineEditSearch(new QLineEdit(this)),
<<<<<<< Updated upstream
    pushButtonClear(new QPushButton(this))
=======
    pushButtonClear(new QPushButton("Clear Filter", this))
{
    // Proxy Model
    bookProxyModel->setSourceModel(bookTableModel);
    bookProxyModel->setFilterKeyColumn(0);
    bookProxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
>>>>>>> Stashed changes

{
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
    this->resize(1000, 600);

    // Menu Bar
    menuBar = new QMenuBar(this);
    menuBar->setGeometry(QRect(0, 0, 800, 24));
    setMenuBar(menuBar);

    // File Menu
    QMenu *fileMenu = menuBar->addMenu(tr("&File"));
    fileMenu->addAction(actionExportBooks);
    actionExportBooks->setToolTip("Exports existing books to file.");
    fileMenu->addSeparator();
    fileMenu->addAction(actionClose);

    // Edit Menu
    QMenu *editMenu = menuBar->addMenu(tr("Edit"));
    editMenu->addAction(actionAddBook);

    // Status Bar
    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    // Tool Bar
    toolBar = new QToolBar(this);
    toolBar->addAction(actionAddBook);
    toolBar->addSeparator();
    toolBar->addAction(actionExportBooks);

    // Central Widget and Layout
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout(centralWidget);
    setCentralWidget(centralWidget);

    // Search Bar
    lineEditSearch->setPlaceholderText("Search book name");
    gridLayout->addWidget(lineEditSearch, 0, 0, 1, 3);
    gridLayout->addWidget(pushButtonClear, 0, 3, 1, 1);

    // Proxy Model
    // TODO

}

void MainWindow::addBook()
{
<<<<<<< Updated upstream
    // TODO
=======
    BookInput *bookInputDialog = new BookInput(bookTableModel, this);
    bookInputDialog->show();
>>>>>>> Stashed changes
}

void MainWindow::exportBooks()
{
    // TODO
}

void MainWindow::clearFilter()
{
    // TODO
}

