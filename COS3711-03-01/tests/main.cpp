
#include "testbook.h"
#include "testbookfactory.h"
#include "testbookproxymodel.h"
#include "testbooktablemodel.h"
#include "testbookwriter.h"
#include "testfilewriter.h"
#include "tst_author.h"

int main(int argc, char *argv[])
{
    int status = 0;
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
