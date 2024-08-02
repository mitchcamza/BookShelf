#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QDialog>

class QDateEdit;
class QGridLayout;
class QGroupBox;
class QLineEdit;
class QListWidget;
class QPushButton;


class BookInput : public QDialog
{
    Q_OBJECT
public:
    explicit BookInput(QWidget *parent = nullptr);
    // TODO: inject model into constructor

    ~BookInput();

private slots:
    void addAuthor();
    void removeAuthor();
    void saveBook();
    void cancel();

private:
    void setupUI();
    void setupBookGroup();
    void setupAuthorGroup();
    void setupButtons();
    bool isValidInput();

    QLineEdit *lineEditTitle;
    QLineEdit *lineEditIsbn;
    QDateEdit *dateEditPublicationDate;
    QLineEdit *lineEditFirstName;
    QLineEdit *lineEditLastName;
    QPushButton *pushButtonAddAuthor;
    QListWidget *listWidgetAuthors;
    QPushButton *pushButtonRemoveAuthor;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QGridLayout *mainLayout;
    QGridLayout *gridLayoutBook;
    QGridLayout *gridLayoutAuthor;
    QGroupBox *groupBoxBook;
    QGroupBox *groupBoxAuthor;
};

#endif // BOOKINPUT_H
