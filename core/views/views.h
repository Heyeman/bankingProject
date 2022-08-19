#pragma once
#include "../wrapper.h"
void admin_login();
void staff_login();
void user_login();
void atm_login();

void admin_menu();
void user_menu();
void staff_menu();
void atm_menu();

void transfer_form();
void deposit_form();
void withdraw_form(string actor = "staff");
void by_airTime();


void loginpage();
struct loginDetail loginRequest(string role);

void checkLog();

void activate_acc();
void editAccount();
void deleteAccount();
 int create_staff();
 userDetails createAccount();