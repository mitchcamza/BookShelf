/**
 * @file mainwindow.cpp
 * @author Mitch Campbell
 * @date 2024-07-25
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "mainwindow.h"
// #include "bookproxymodel.h"
#include "bookinput.h"
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
#include <QTableView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    // menuBar(new QMenuBar(this)),
    // statusBar(new QStatusBar(this)),
    // toolBar(new QToolBar(this)),
    // bookProxyModel(new BookProxyModel(this)),
    // bookView(new BookView(this)),
    actionAddBook(new QAction(QIcon(":/icons/addBook"), tr("New Book"), this)),
    actionExportBooks(new QAction(QIcon(":/icons/export"), tr("Export Books"), this)),
    actionClose(new QAction(QIcon(":/icons/exit"), tr("Exit Application"), this)),
    lineEditSearch(new QLineEdit(this)),
    pushButtonClear(new QPushButton("Clear", this))
{
    connect(actionAddBook, &QAction::triggered, this, &MainWindow::addBook);
    connect(actionExportBooks, &QAction::triggered, this, &MainWindow::exportBooks);
    // connect(lineEditSearch, &QLineEdit::textEdited, bookProxyModel, &BookProxyModel::setFilterText);
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
    // TODO: Decide if status bar is required

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

    // Proxy Model
    // TODO: Replace tableView with bookView
    gridLayout->addWidget(new QTableView(), 1, 0, 1, 4);
}

void MainWindow::addBook()
{
    BookInput *bookInputDialog = new BookInput(this);
    bookInputDialog->show();
}

void MainWindow::exportBooks()
{
    // TODO
}

void MainWindow::clearFilter()
{
    // TODO
}

