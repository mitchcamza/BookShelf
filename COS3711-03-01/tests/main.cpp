#include "tst_author.h"
#include "testbook.h"
#include "testbooktablemodel.h"
#include "testbookproxymodel.h"
#include "testbookfactory.h"


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

    return status;
}
