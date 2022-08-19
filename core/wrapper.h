#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;
using namespace sql;

#include "dal/dal.h"
#include "controllers/controller.h"
#include "views/views.h"

struct userDetails {
    string fName = "", lName = " ", userName = " ", password = " ";
    char gender = 'M';
    int accountNumber = 0, amount = 0;
    bool isFound = false, isActive = false;

};

struct transactionDetails {
    string type, who, whom;
    int amount = 0;
};



struct loginDetail {
    string username, password;
};
struct Response {
    int status = 400;
    bool error = false;
    string errMsg;
};


