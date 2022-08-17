#pragma once
#include "../wrapper.h"


struct Response login(struct loginDetail user, string role = "user");

Response userCreate(struct userDetails user, string role = "user");

Response userDelete(string userName, string role = "user");

Response addTransaction(struct transactionDetails transaction);