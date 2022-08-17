#pragma once
#include "../wrapper.h"



struct userDetails fetchUser (string userName, string role = "user");

bool createUser(struct userDetails user, string role);

bool deleteUser(string userName, string role = "user");


bool updateUser(int accNumber, string field, string value);

bool createTransaction(struct transactionDetails transaction);