#pragma once
#include "../wrapper.h"

struct userDetails {
    string fName = "", lName = " ", userName = " ", password = " ";
    char gender = 'M';
    int accountNumber = 0, amount = 0;
    bool isFound = false, isActive = false;
    
};


userDetails userFetch(string userName, string role);
bool createUser(userDetails user, string role);