#include "core/wrapper.h"
userDetails User;

int main()
{

	char log, countinuee;

	do
	{

	login_p:
		loginpage();
		cin >> log;

		switch (log)
		{
		case '1':
		{
			int user_fail = 0;

		logReq:

			loginDetail req = loginRequest("user");
			Response res = login(req, "user");
			if (res.status == 200)
			{
				char option_user;
				User = fetchUser(req.username, "user");
				do {
					user_menu();
					cin >> option_user;

					switch (option_user)
					{
					case '1':
						transfer_form();
						break;
					case '2':
						by_airTime();
						break;
					case '3':
						cout << "The amount in your accont is "<<User.amount <<endl ;
						break;
					case '4':
						checkLog();
						break;
					case '5':
						goto login_p;
						break;
					default:
						cout << "Invalid input";
					}
				} while (option_user != '5');
			}
			else
			{

				cout << "Login failed"<<endl;
				++user_fail;

				if (user_fail == 3)
				{
					cout << " too many login attempts.";
					goto login_p;
				}
				else
				{
					goto logReq;
				}
			}
			
		}
			break;
			// ATM
		case '2':
		{
			int atm_fail = 0;
		atm_logReq:
			loginDetail user = loginRequest("user");
			Response res = login(user, "user");
			if (res.status == 200)
			{
				User = fetchUser(user.username, "user");
				goto atm_menu;
			}
			else
			{

				cout << "Login failed" << endl;
				++atm_fail;

				if (atm_fail == 3)
				{
					cout << " too many login attempts."<<endl;
					goto login_p;
				}
				else
				{
					goto atm_logReq;
				}
			}
		atm_menu:
			{
				atm_menu();
				char option_atm;
				cin >> option_atm;
				switch (option_atm)
				{
				case '1':
					cout << "The amount in your accont is " << User.amount << endl;
					break;
				case '2':
					withdraw_form("atm");
					break;
				case '3':
					goto login_p;
				default:
					cout << "Invalid input";
					goto atm_menu;
				}
			}
			break;
		}
		case '3':
			return 0;
			break;

		case 's':
		{
			int staff_fail = 0;
		staff_logReq:
			loginDetail req = loginRequest("staff");
			Response res = login(req, "staff");
			if (res.status == 200)
			{
				User = fetchUser(req.username, "staff");
				staff_menu();
				int option_staff;
				cin >> option_staff;

				switch (option_staff)
				{
				case '1':
					transfer_form();
					break;
				case '2':
					deposit_form();
					break;
				case '3':
					withdraw_form();
					break;
				case '4':
					checkLog();
					break;
				case '5':
				{
					userDetails req = createAccount();
					Response res = userCreate(req, "user");
					if (res.error) {
						cout << res.errMsg << endl;
					}
					else {
						cout << "Account created successfully" << endl;
					}
					break;
				}

				case '6':
					goto login_p;
					break;
				default:
					cout << "Invalid input";

				}
			}
			else
			{

				cout << "Login failed";
				++staff_fail;

				if (staff_fail == 3)
				{
					cout << " too many login attempts.";
					goto login_p;
				}
				else
				{
					goto staff_logReq;
				}
			}
		
			break;

		}
		case 'a':
		{
			int admin_fail = 0;
		admin_logReq:
			loginDetail user = loginRequest("admin");
			Response res = login(user, "admin");
			if (res.status == 200)
			{
				char option_admin;
				do {
				admin_menu();
					cin >> option_admin;

					switch (option_admin)
					{
					case '1':
						if (create_staff() == 0) {
							cout << "Cannot create staff" << endl;
						}
						else {
							cout << "Staff created successfully." << endl;
						}
						break;
					case '2':
						activate_acc();
						break;
					case '3':
						deleteAccount();
						break;
					case '4':
						goto login_p;
						break;
					default:
						cout << "Invalid input";
					}
				} while (option_admin != '4');
			}
			else
			{

				cout << "Login failed"<<endl;
				cout << res.errMsg<<endl;
				++admin_fail;

				if (admin_fail == 3)
				{
					cout << " too many login attempts.";
					goto login_p;
				}
				else
				{
					goto admin_logReq;
				}
			}
		
			

			break;
		}

		default:
			cout << "Invalid input";
			goto login_p;
		}

		cout << "countinue? [y/n]: ";
		cin >> countinuee;
	} while (countinuee != 'n' || countinuee != 'N');




     
   


   
    return 0;
}

