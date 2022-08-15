#include "core/wrapper.h"
int main()
{

   

    cout << "Function is gonna start now" << endl;
   
    
    //bool createUser(userDetails user, string role);
    userDetails heyo = { "heyeman", "abdia", "", "", 'M', 0, 50, false, false };
    createUser(heyo, "user");



    system("pause");
    return 0;
}

