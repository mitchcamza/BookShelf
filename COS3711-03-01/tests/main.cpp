
/**
 * @file main.cpp
 * @author Mitch Campbell
 * @brief This file contains the main function for the tests.
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 */


#include "testauthor.h"
#include "testbook.h"
#include "testbookfactory.h"
#include "testbookproxymodel.h"
#include "testbooktablemodel.h"
#include "testbookwriter.h"
#include "testfilewriter.h"


/**
 * @brief The main function for the tests.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The status of the tests.
 */
int main(int argc, char *argv[])
{
    int status = 0; // 0 = success, 1 = failure
    
    {
        TestAuthor tc;  
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestBook tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestBookTableModel tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestBookProxyModel tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestBookFactory tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestFileWriter tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestBookWriter tc;
        status |= QTest::qExec(&tc, argc, argv);
    }

    return status;
}
