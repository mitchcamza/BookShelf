/**
 * @file bookinput.h
 * @author Mitch Campbell
 * @brief This file contains the declaration of the BookInput class.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QDialog>

class QDateEdit;
class QGridLayout;
class QGroupBox;
class QLineEdit;
class QListWidget;
class QPushButton;
class BookTableModel;

/**
 * @class BookInput
 * @brief The BookInput class is a dialog that allows the user to input a new book.
 * 
 */
class BookInput : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief Construct a new BookInput object
     * 
     * @param model The model that contains the books.
     * @param parent The parent widget.
     */
    explicit BookInput(BookTableModel *model, QWidget *parent = nullptr);

    /**
     * @brief Destroy the BookInput object
     * 
     */
    ~BookInput();

private slots:
    /**
     * @brief Add an author to the list widget
     * 
     */
    void addAuthor();       

    /**
     * @brief Remove selected author from the list widget.
     * 
     */
    void removeAuthor();    

    /**
     * @brief Add the book to the model.
     * @details This method creates a new book object and adds it to the model. It also adds the authors to the book object.
     */
    void saveBook();

    /**
     * @brief Cancel the input dialog.
     * 
     */
    void cancel();

private:
    /**
     * @brief Set up the user interface.
     * @details This method sets up the dialog layout and components. It calls the setupBookGroup, setupAuthorGroup, and setupButtons methods to set up their respective components.
     */
    void setupUI();

    /**
     * @brief Set up the UI components in the book group box.
     * @details This method sets up the book title, ISBN, and publication date components.
     */
    void setupBookGroup();

    /**
     * @brief Set up the UI components in the author group box.
     * @details This method sets up the author first name, last name, and a list widget of authors.
     */
    void setupAuthorGroup();

    /**
     * @brief Set up the buttons to save or cancel the input dialog.
     * @details This method sets the properties of the save and cancel buttons and adds them to the dialog layout.
     */
    void setupButtons();

    /**
     * @brief Validate user input.
     * 
     * @return true if input is valid.
     * @return false if input is invalid.
     */
    bool isValidInput();

    BookTableModel *bookTableModel;         /**< The model that contains the books. */
    QLineEdit *lineEditTitle;               /**< The line edit for the book title. */
    QLineEdit *lineEditIsbn;                /**< The line edit for the book ISBN. */
    QDateEdit *dateEditPublicationDate;     /**< The date edit for the book publication date. */
    QLineEdit *lineEditFirstName;           /**< The line edit for the author first name. */
    QLineEdit *lineEditLastName;            /**< The line edit for the author last name. */
    QPushButton *pushButtonAddAuthor;       /**< The button to add an author. */
    QListWidget *listWidgetAuthors;         /**< The list widget for the authors. */
    QPushButton *pushButtonRemoveAuthor;    /**< The button to remove an author. */
    QPushButton *pushButtonSave;            /**< The button to save the book. */
    QPushButton *pushButtonCancel;          /**< The button to cancel the input dialog. */
    QGridLayout *mainLayout;                /**< The main layout for the dialog. */
    QGridLayout *gridLayoutBook;            /**< The layout for the book group box. */    
    QGridLayout *gridLayoutAuthor;          /**< The layout for the author group box. */
    QGroupBox *groupBoxBook;                /**< The group box for the book. */
    QGroupBox *groupBoxAuthor;              /**< The group box for the author. */
};

#endif // BOOKINPUT_H
