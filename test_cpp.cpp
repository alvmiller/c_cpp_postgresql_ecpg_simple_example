#include "test_mod.h"

/*
https://www.instaclustr.com/support/documentation/postgresql/using-postgresql/connect-to-postgresql-with-c-plus-plus/
https://www.postgresql.org/docs/7.2/libpqplusplus.html
https://www.tutorialspoint.com/postgresql/postgresql_c_cpp.htm
https://www.postgresql.org/docs/current/ecpg-cpp.html
https://www.digitalocean.com/community/tutorials/how-to-install-postgresql-on-ubuntu-20-04-quickstart
https://www.postgresql.org/download/linux/ubuntu/
https://www.devart.com/dbforge/postgresql/how-to-install-postgresql-on-ubuntu/
https://stackoverflow.com/questions/56724622/how-to-fix-postgres-h-file-not-found-problem
https://www.postgresql.org/message-id/d331f2ee0909071432g1d2308dw50ba0171654d857d@mail.gmail.com
https://www.postgresql.org/docs/current/ecpg.html
https://www.cybertec-postgresql.com/en/embedded-sql-in-c-for-postgresql-with-ecpg-blog/
https://postgrespro.com/docs/postgresql/14/app-ecpg
https://www.postgresql.fastware.com/blog/adding-support-to-declare-statement-in-ecpg
https://postgresql.kr/docs/9.5/ecpg.html
https://pgdocptbr.sourceforge.io/pg74/ecpg.html

sudo apt install libecpg-dev
sudo apt install postgresql
sudo apt install postgresql-contrib postgresql-client
sudo systemctl status postgresql
sudo -u postgres psql
\password postgres
\q
sudo apt install postgresql-server-dev-all
sudo apt install postgresql-server-dev-14

ecpg sample.pgc
cc -I/usr/include/postgresql -c sample.c
cc -o sample sample.o -L/usr/lib/x86_64-linux-gnu -lecpg

ecpg -o test_mod.c test_mod.pgc
cc -I/usr/include/postgresql -c test_mod.c -o test_mod.o
c++ -c test_cpp.cpp -o test_cpp.o
c++ test_cpp.o test_mod.o -L/usr/lib/x86_64-linux-gnu -lecpg -o test_cpp
*/

class TestCpp
{
  public:
    TestCpp();
    void test();
    ~TestCpp();
};

TestCpp::TestCpp()
{
    db_connect();
}

void
TestCpp::test()
{
    db_test();
}

TestCpp::~TestCpp()
{
    db_disconnect();
}

int
main(void)
{
    TestCpp *t = new TestCpp();

    t->test();
    return 0;
}
