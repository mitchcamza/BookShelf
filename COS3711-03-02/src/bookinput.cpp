/**
 * @file bookinput.cpp
 * @author Mitch Campbell
 * @brief This file contains the implementation of the BookInput class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "book.h"
#include "bookinput.h"
#include "booktablemodel.h"
#include "bookfactory.h"

#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QRegularExpression>
#include <QRegularExpressionMatch>


BookInput::BookInput(BookTableModel *model, QWidget *parent)
    : QDialog{parent},
    bookTableModel(model),
    mainLayout(new QGridLayout(this)),
    gridLayoutBook(new QGridLayout()),
    gridLayoutAuthor(new QGridLayout()),
    groupBoxBook(new QGroupBox("Book", this)),
    groupBoxAuthor(new QGroupBox("Author", this)),
    lineEditTitle(new QLineEdit(this)),
    lineEditIsbn(new QLineEdit(this)),
    dateEditPublicationDate(new QDateEdit(this)),
    lineEditFirstName(new QLineEdit(this)),
    lineEditLastName(new QLineEdit(this)),
    pushButtonAddAuthor(new QPushButton("Add", this)),
    listWidgetAuthors(new QListWidget(this)),
    pushButtonRemoveAuthor(new QPushButton(QIcon(":/icons/removeAuthor"), "", this)),
    pushButtonSave(new QPushButton("Save", this)),
    pushButtonCancel(new QPushButton("Cancel", this))
{
    setupUI();

    // Connect signals and slots
    connect(pushButtonAddAuthor, &QPushButton::clicked, this, &BookInput::addAuthor);
    connect(pushButtonRemoveAuthor, &QPushButton::clicked, this, &BookInput::removeAuthor);
    connect(pushButtonSave, &QPushButton::clicked, this, &BookInput::saveBook);
    connect(pushButtonCancel, &QPushButton::clicked, this, &BookInput::close);
}

BookInput::~BookInput()
{

}

void BookInput::addAuthor()
{
    if (lineEditFirstName->text().isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a first name for the author.");
        lineEditFirstName->setFocus();
        return;
    }
    if (lineEditLastName->text().isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a last name for the author.");
        lineEditLastName->setFocus();
        return;
    }

    QString author = lineEditLastName->text().toUpper() + ", " + lineEditFirstName->text().toUpper();
    listWidgetAuthors->addItem(author);
    lineEditFirstName->clear();
    lineEditLastName->clear();
    lineEditFirstName->setFocus();
}

void BookInput::removeAuthor()
{
    listWidgetAuthors->takeItem(listWidgetAuthors->currentRow());
}

void BookInput::saveBook()
{
    if (!isValidInput())
    {
        return;
    }

    // Add book and author to model
    QString title = lineEditTitle->text();
    QStringList authors;
    for (int i = 0; i < listWidgetAuthors->count(); i++)
    {
        QListWidgetItem *item = listWidgetAuthors->item(i);
        if (item)
        {
            authors.append(item->text());
        }
    }
    QString isbn = lineEditIsbn->text();
    QDate publicationDate = dateEditPublicationDate->date();

    // Create the new book using the book factory
    BookFactory &bookFactory = BookFactory::getInstance();
    Book *newBook = bookFactory.createBook(title, authors, isbn, publicationDate);

    // Add the new book to the model
    bookTableModel->addBook(newBook);

    // Close the dialog
    accept();

}

void BookInput::cancel()
{
    close();
}

void BookInput::setupUI()
{
    // Window Attributes
    setWindowTitle("New Book");
    setWindowModality(Qt::ApplicationModal);
    resize(410, 472);

    setupBookGroup();
    setupAuthorGroup();
    setupButtons();
}

void BookInput::setupBookGroup()
{
    // Title
    QLabel *labelTitle = new QLabel("Title", this);
    lineEditTitle->setToolTip("The book's title");
    gridLayoutBook->addWidget(labelTitle, 0, 0);
    gridLayoutBook->addWidget(lineEditTitle, 0, 1, 1, 3);

    // ISBN
    QLabel *labelIsbn = new QLabel("ISBN", this);
    lineEditIsbn->setInputMask("999-9-99-999999-9;_");
    lineEditIsbn->setPlaceholderText("978-3-16-148410-0");
    gridLayoutBook->addWidget(labelIsbn, 1, 0);
    gridLayoutBook->addWidget(lineEditIsbn, 1, 1, 1, 3);

    // Publication Date
    QLabel *labelPublicationDate = new QLabel("Date Published", this);
    dateEditPublicationDate->setDate(QDate::currentDate());
    dateEditPublicationDate->setCalendarPopup(true);
    dateEditPublicationDate->setMaximumDate(QDate::currentDate());
    gridLayoutBook->addWidget(labelPublicationDate, 2, 0);
    gridLayoutBook->addWidget(dateEditPublicationDate, 2, 1);

    groupBoxBook->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    groupBoxBook->setLayout(gridLayoutBook);
    mainLayout->addWidget(groupBoxBook, 0, 0, 1, 4);
}

void BookInput::setupAuthorGroup()
{
    // First name
    QLabel *labelFirstName = new QLabel("First Name");
    lineEditFirstName->setToolTip("Author's first name");
    gridLayoutAuthor->addWidget(labelFirstName, 0, 0);
    gridLayoutAuthor->addWidget(lineEditFirstName,0 , 1, 1, 3);

    // Last name
    QLabel *labelLastName = new QLabel("Last Name");
    lineEditLastName->setToolTip("Author's last name");
    gridLayoutAuthor->addWidget(labelLastName, 1, 0);
    gridLayoutAuthor->addWidget(lineEditLastName, 1, 1, 1, 3);

    // Add author button
    gridLayoutAuthor->addWidget(pushButtonAddAuthor, 2, 0, 1, 4);

    // List widget
    gridLayoutAuthor->addWidget(listWidgetAuthors, 3, 0, 1, 4);

    // Remove author button
    pushButtonRemoveAuthor->setFixedSize(30, 30);
    gridLayoutAuthor->addWidget(pushButtonRemoveAuthor, 3, 4, 1, 1);
    // pushButtonRemoveAuthor->setIcon(QIcon(":/icons/removeAuthor"));
    pushButtonRemoveAuthor->setIconSize(pushButtonRemoveAuthor->size());
    gridLayoutAuthor->addWidget(pushButtonRemoveAuthor, 3, 4, Qt::AlignRight, 1);

    // Group box and layout
    groupBoxAuthor->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    groupBoxAuthor->setLayout(gridLayoutAuthor);
    mainLayout->addWidget(groupBoxAuthor, 1, 0, 1, 4);
}

void BookInput::setupButtons()
{
    pushButtonSave->setToolTip("Save the book to the list");
    mainLayout->addWidget(pushButtonSave, 3, 0, 1, 4);
    mainLayout->addWidget(pushButtonCancel, 4, 0, 1, 4);
}

bool BookInput::isValidInput()
{
    // Check if title is empty
    if (lineEditTitle->text().isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a title for the book.");
        lineEditTitle->setFocus();
        return false;
    }
    // Check if ISBN is empty
    if (lineEditIsbn->text().isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter an ISBN.");
        lineEditIsbn->setFocus();
        return false;
    }

    // Check if at least one author is added
    if (listWidgetAuthors->count() == 0)
    {
        QMessageBox::warning(this, "Input Error", "Please add at least one author.");
        lineEditFirstName->setFocus();
        return false;
    }

    // If all checks pass
    return true;
}
