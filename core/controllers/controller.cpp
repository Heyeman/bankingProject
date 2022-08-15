#include "controller.h"


struct loginDetail {
	string username, password;
};

struct Response {
	int status = 500;
	bool error = false;
	string errMsg;
};


Response login(string role, struct loginDetail) {
	//search for an account with the loginDetail username


	//check if it's password is similar to it

	//return the response
}