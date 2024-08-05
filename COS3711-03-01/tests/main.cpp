#include "tst_author.h"
#include "testbook.h"
#include "testbooktablemodel.h"

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

    return status;
}
