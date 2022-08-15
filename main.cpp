#include "core/wrapper.h"

int main()
{

    //delete con;

    cout << "Function is gonna start now" << endl;
    // create("dbdbdb");
    //checkRun();


    //create("Heyeman");
    //fetch("user", "users");
    

   bool res =  insertInto("user", "users");

   if (res) {
       cout << "was succ" << endl;
   }
   else {

   }

    system("pause");
    return 0;
}