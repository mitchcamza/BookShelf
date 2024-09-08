/**
 * @file main.cpp
 * @author Mitch Campbell
 * @brief This file contains the main entry point for the application.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "mainwindow.h"

#include <QApplication>


/**
 * @brief The main entry point for the application.
 * 
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return int The exit code.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
