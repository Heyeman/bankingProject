#include "controller.h"


Response login(struct loginDetail user, string role) {
	Response res;
	userDetails currUser = fetchUser(user.username, role);
	if (currUser.isFound && currUser.isActive) {
		if (currUser.password != user.password) {
			res.errMsg = "Credentials error";
			res.error = true;
			return res;
		}
		res.status = 200;
	}
	else {
		res.error = true;
		res.errMsg = "User not found";
	}
	return res;
	
}

 Response userCreate(struct userDetails user, string role) {
	 Response res;
	 if (user.fName == "" || user.lName == "" || user.password == "") {
		 res.errMsg = "Please fill in all the fields";
		 res.error = true;
		 return res;
	 }
	 bool isCreated = createUser(user, role);
	 if (isCreated) {
		 res.status = 201;

	 }
	 else {
		 res.errMsg = "cannot create user";
		 res.error = true;
	 }
	 return res;	
}

 Response userDelete(string userName, string role) {
	 Response res;

	 userDetails currUser = fetchUser(userName, role);
	 if (!currUser.isFound || (currUser.isFound && !currUser.isActive)) {
		 res.error = true;
		 res.errMsg = "User not found";
		 return res;
	 }
	 if (deleteUser(userName, role)) {
		 res.status = 203;
		 return res;
	 }
	 else {
		 return res;
	 }
	  
 }

 Response addTransaction(struct transactionDetails transaction) {
	 userDetails owner, target;
	 Response res;
	 if (transaction.type == "deposit" || transaction.type == "withdraw" || transaction.type == "ATM" ) {
		 owner = fetchUser(transaction.whom);
		 if (!owner.isFound ||  !owner.isActive) {
			 res.errMsg = "Invalid user";
			 res.error = true;
			 return res;

		 }
	 }
	 else if (transaction.type == "transfer" || transaction.type == "airtime") {
		 owner = fetchUser(transaction.who);
		 if (!owner.isFound || !owner.isActive) {
			 res.errMsg = "Invalid owner";
			 res.error = true;
			 return res;

		 }
		 target = fetchUser(transaction.whom);
		 if (transaction.type != "airtime" && (!target.isFound || !target.isActive)) {
			 res.errMsg = "Invalid user";
			 res.error = true;
			 return res;

		 }
	 }
	 if (transaction.type != "deposit"){
		 if (transaction.amount > owner.amount) {

			 res.errMsg = "Amount above what the user has";
			 res.error = true;
			 return res;
		 }
		 else {
			 owner.amount -= transaction.amount;
			 
		 }
	 }
	 else {
		 owner.amount += transaction.amount;

	 }
	 if (transaction.type == "transfer") {
		 target.amount += transaction.amount;
		 bool updateT = updateUser(target.accountNumber, "amount", to_string(target.amount));
	 }
	 bool updateU = updateUser(owner.accountNumber, "amount", to_string(owner.amount));
	
	 createTransaction(transaction);
	 res.status = 201;
	 res.error = false;

	 return res;

 }

