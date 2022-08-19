#include "views.h"


extern userDetails User;


void loginpage()
{
	User = {};
	
	cout << "                                                       ********************************" << endl;
	cout << "                                                       **********LOGIN||PANEL**********" << endl;
	cout << "                                                       ********************************" << endl;
	cout << "                                                       *  Press 1 For User Login      *" << endl;
	cout << "                                                       *  Press 2 For ATM Service     *" << endl;
	cout << "                                                       *  Press 3 To  Exit            *" << endl;
	cout << "                                                       ********************************" << endl;
	cout << "                                                       ********************************" << endl;
	cout << "\n"
		<< endl;
	cout << "                                                       Enter Your Choice : ";
}

loginDetail loginRequest(string role)
{

	loginDetail login_data;
	if (role != "user") {
		cout << "Username: ";
	}
	else {
		cout << "Account number: ";
	}
	cin >> login_data.username;
	cout << "Password: ";
	cin >> login_data.password;

	return login_data;
}

void admin_menu()
{
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       *************ADMIN|||PANEL*************" << endl;
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       *  Press 1 To Create Staff Account    *" << endl;
	cout << "                                                       *  Press 2 To Activate Account        *" << endl;
	cout << "                                                       *  Press 3 To Delete Account          *" << endl;
	cout << "                                                       *  Press 4 To Go Back to Main Menu    *" << endl;
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       Enter an Option : ";
}

int create_staff()
{
	userDetails user;

	cout << "Enter Staff First Name: ";
	cin >> user.fName;
	cout << "Enter Staff Last Name: ";
	cin >> user.lName;
	int res = createUser(user, "staff");

	return res;
}

void deleteAccount()
{
	int account_type;
	string accountNo, staff_username;
	cout << "Press 1 To Delete User Account  " << endl;
	cout << "Press 2 To Delete Staff Account " << endl;
	cin >> account_type;

	if (account_type == 1)
	{
		cout << "Enter Account Number: ";
		cin >> accountNo;
		Response res = userDelete(accountNo, "user");
		if (res.error) {
			cout << res.errMsg << endl;
		}
		else {
			cout << "Deleted successfully" << endl;
		}
	}
	else if (account_type == 2)
	{
		cout << "Enter username: ";
		cin >> staff_username;
		Response res = userDelete(staff_username, "staff");
		if (res.error) {
			cout << res.errMsg << endl;
		}
		else {
			cout << "Deleted successfully" << endl;
		}
	}
	else
	{
		cout << "Invalid input";
	}
}



void activate_acc()
{
	int accountNo;
	cout << "Enter account number: ";
	cin >> accountNo;
	userDetails user = fetchUser(to_string(accountNo));
	if (!user.isFound) {
		cout << "No user found with this account number" << endl;
	}
	else if (user.isActive) {
		cout << "Account is already activated" << endl;
	}
	else {
		if (updateUser(accountNo, "isActive", "1")) {
			cout << "Account activated successfully" << endl;
		}
		else {
			cout << "Retry"<<endl;
		}
	}


}

void editAccount()
{
	int accountNo;
	cout << "Enter accout number: ";
	cin >> accountNo;
}


void staff_menu()
{

	cout << "                                                       ***************************************" << endl;
	cout << "                                                       *************STAFF|||PANEL*************" << endl;
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       *  Press 1 To Transfer                *" << endl;
	cout << "                                                       *  Press 2 To Deposit Cash            *" << endl;
	cout << "                                                       *  Press 3 To With_Draw Cash          *" << endl;
	cout << "                                                       *  Press 4 To Check Logs of User      *" << endl;
	cout << "                                                       *  Press 5 To Create new user account *" << endl;
	cout << "                                                       *  Press 6 To Go Back to Main Menu    *" << endl;

	cout << "                                                       ***************************************" << endl;
	cout << "                                                       Enter an Option : ";
}

void checkLog()
{
	int accountNo;
	cout << "Enter accout number: ";
	cin >> accountNo;
}



void user_menu()
{

	cout << "                                                       ***************************************" << endl;
	cout << "                                                       *************USER|||PANEL*************" << endl;
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       *  Press 1 To Transfer                *" << endl;
	cout << "                                                       *  Press 2 To Buy Air time            *" << endl;
	cout << "                                                       *  Press 3 To Check ballance          *" << endl;
	cout << "                                                       *  Press 4 To Check Logs              *" << endl;
	cout << "                                                       *  Press 5 To Go Back to Main Menu    *" << endl;
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       Enter an Option : ";
}

void atm_menu()
{
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       *******************ATM*****************" << endl;
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       *  Press 1 To Check Balance          *" << endl;
	cout << "                                                       *  Press 2 To Withdaraw cash          *" << endl;
	cout << "                                                       *  Press 3 To Go Back to Main Menu    *" << endl;
	cout << "                                                       ***************************************" << endl;
	cout << "                                                       Enter an Option : ";
}

void transfer_form()
{
	transactionDetails transaction;
	 transaction.type = "transfer";
	
	transaction.who = to_string(User.accountNumber);
	cout << " Enter receiver account number";
	cin >> transaction.whom;
	cout << "Enter amount: ";
	cin >> transaction.amount;

	Response res = addTransaction(transaction);
	if (res.error) {
		cout << "Transaction can not be processed" <<res.errMsg<<transaction.who<< endl;

	}
	else {
		cout << "Transaction processed successfully" << endl;
	}

}

void deposit_form()
{
	transactionDetails transaction;

	transaction.type = "deposit";
	transaction.who = "staff";
	cout << "Enter account number";
	cin >> transaction.whom;
	cout << "Enter amount: ";
	cin >> transaction.amount;

	Response res = addTransaction(transaction);
	if (res.error) {
		cout << "Transaction can not be processed" << endl;
	}
	else {
		cout << "Transaction processed successfully" << endl;
	}
}

void withdraw_form(string actor)
{
	transactionDetails transaction;

	transaction.type = "withdraw";
	transaction.who = "staff";
	if (actor != "atm") {
		cout << "Enter account number";
	}
 transaction.whom = to_string(User.accountNumber);

	cout << "Enter amount: ";
	cin >> transaction.amount;

	
	Response res = addTransaction(transaction);
	if (res.error) {
		cout << "Transaction can not be processed" << transaction.amount<<endl;
		cout << res.errMsg<<endl;
	}
	else {
		cout << "Transaction processed successfully" << endl;
	}
}

void by_airTime()

{
	transactionDetails transaction;

	transaction.type = "airtime";
	transaction.who = to_string(User.accountNumber);
	cout << "Enter Phone number";
	cin >> transaction.whom;

	cout << "Enter amount: ";
	cin >> transaction.amount;
	Response res = addTransaction(transaction);
	if (res.error) {
		cout << "Transaction can not be processed" << endl;
		cout << res.errMsg << endl;
	}
	else {
		cout << "Transaction processed successfully" << endl;
	}
}

userDetails createAccount() {
	userDetails user;
	cout << "Enter first name: ";
	cin >> user.fName;
	cout << "Enter last name: ";
	cin >> user.fName;
	cout << "Enter gender: ";
	cin >> user.gender;
	cout << "Amount of money to deposit initially: ";
	cin >> user.amount;
	return user;
}
