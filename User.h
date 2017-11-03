#pragma once
#include <iostream>
#include<string>
using namespace std;

class User
{
	
public:
	User();
	void setFirstName(string firstName);
	string getFirstName();
	void setLastName(string lastName);
	string getLastName();
	void setUsername(string username);
	string getUsername();
	void setPassword(string password);
	string getPassword();
	void setMobileNumber(string mobileNumber);
	string getMobileNumber(); 
	void setAddress(string address);
	string getAddress(); 
	void setAge(string age);
	string getAge(); 
	void setId(string id);
	string getId(); 
	void loginUser();
	void userDisplay();
	void RegisterUser();

private:
	
	string firstName;
	string lastName;
	string username;
	string password;
	string mobileNumber;
	string address;
	string age;
	string id;
	
};