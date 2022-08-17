#include "core/wrapper.h"
int main()
{

   

    cout << "Function is gonna start now" << endl;
   
    
 /*struct transactionDetails {
    string type, who, whom;
    int amount;
};

    */

    transactionDetails transaction = {"airtime", "4", "090990990", 5};
    Response res = addTransaction(transaction);
    cout << res.status<<endl;
    cout << res.errMsg << endl;


     
   



    system("pause");
    return 0;
}

