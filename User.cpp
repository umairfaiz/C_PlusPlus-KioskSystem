#include <iostream>
#include <conio.h>
#include "User.h"
#include "Customer.h"
#include "Admin.h"
using namespace std;


int select;
User::User()
{
}
//------------------------------------------------------------------------------------------------------------
void User::setFirstName(string firstName)
{
	this->firstName = firstName;
}
//------------------------------------------------------------------------------------------------------------
string User::getFirstName()
{
	return this->firstName;
}
//------------------------------------------------------------------------------------------------------------
void User::setLastName(string lastName)
{
	this->lastName = lastName;
}
//------------------------------------------------------------------------------------------------------------
string User::getLastName()
{
	return this->lastName;
}
//------------------------------------------------------------------------------------------------------------
void User::setUsername(string username)
{
	this->username = username;
}
//------------------------------------------------------------------------------------------------------------
string User::getUsername()
{
	return this->username;
}
//------------------------------------------------------------------------------------------------------------
void User::setPassword(string password)
{
	this->password = password;
}
//------------------------------------------------------------------------------------------------------------
string User::getPassword()
{
	return this->password;
}
//------------------------------------------------------------------------------------------------------------
void User::setMobileNumber(string mobileNumber)
{
	this->mobileNumber = mobileNumber;
}
//------------------------------------------------------------------------------------------------------------
string User::getMobileNumber()
{
	return this->mobileNumber;
}
//------------------------------------------------------------------------------------------------------------
void User::setAddress(string address)
{
	this->address = address;

}	
//------------------------------------------------------------------------------------------------------------
string User::getAddress()
{
	return this->address;
}
//------------------------------------------------------------------------------------------------------------
void User::setAge(string age)
{
	this->age = age;
}
//------------------------------------------------------------------------------------------------------------
string User::getAge()
{
	return this->age;
}
//------------------------------------------------------------------------------------------------------------
void User::setId(string id)
{
	this->id = id;


}
//------------------------------------------------------------------------------------------------------------
string User::getId()
{
	return this->id;
}
//------------------------------------------------------------------------------------------------------------
//display to select either customer or admin
void User::userDisplay() {

	cout << "\n\tHello!! Please select your option to continue...\n";
	cout << "\n\t               1. If you are a Customer..                                                ";
	cout << "\n\t               2. If you are an Admin...                                                 ";
	cout << "\n\n";


}
//------------------------------------------------------------------------------------------------------------
//allows users to login according to their user type
void User::loginUser(){

	userDisplay();

	Customer cust;
	Admin admin;

	while ((select = cin.get())){
		
		switch (select){
		case '1':
			system("CLS");
			cust.login();

			break;
		case '2':
			system("CLS");
			admin.adminLogin();
			break;
		case '\n': // ignore newlines,
		case '\t': // tabs,
		case ' ': // and spaces in input
			break; // exit switch
		default: // catch all other characters
			cout << "\n                                -***-                                   \n";
			cout << "\t  Error : Incorrect option entered. Enter a valid choice!.\n";
			cout << "                                -***-                                   \n";
			break;
		}
	}
}
//------------------------------------------------------------------------------------------------------------
//allows to register new users
void User::RegisterUser() {

	userDisplay();

	Customer cust;
	Admin admin;

	while ((select = cin.get())) {
		switch (select) {
		case '1':
			system("cls");
			cust.regCustomer();
			break;
		case '2':
			system("cls");
			admin.regAdmin();
			break;
		case '\n': // ignore newlines,
		case '\t': // tabs,
		case ' ': // and spaces in input
			break; // exit switch
		default: // catch all other characters
			cout << "\n                                -***-                                   \n";
			cout << "\t  Error : Incorrect option entered. Enter a valid choice!.\n";
			cout << "                                -***-                                   \n";
			break;
		}
	}
	system("cls");
}
