#include "User.h"
#include <iostream>
#include <string>

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer :public User {

public:
	Customer();
	~Customer();

	void login();
	void loginMenu();
	int generateCustomerID();
	void regCustomer();
	void validateCustomer();
	void RegCustMenu();
	void viewAllEvents();
	void upcomingEvents();
	void customer_Event();
	string custInputName, CustInputPassword;

	//const string Event;

private:
	string custname, custid, custpassword, custfname, custlname, custcontactno, filecustname, filecustpassword;
	string line;
	int custage;

	int option;



};
#endif 
