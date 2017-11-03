#pragma once
#include <iostream>
#include<string>
#include "User.h"




using namespace std;

class Admin :public User {
public:
	Admin();
	~Admin();
	/*void setAdminName(string name);
	string getAdminName();

	void setAdmintID(string id);
	string getAdminID();

	void setAdminPassword(string adminpassword);
	string getAdminPassword();

	void setAdminFName(string adminfname);
	string getAdminFName();

	void setAdminLName(string adminlname);
	string getAdminLName();

	void setAdminAge(string adminage);
	string getAdminAge();

	void setAdminContactNo(string admincontactno);
	string getAdminContactNo();

	void setfileAdminname(string fileadminname);
	string getfileAdminname();

	void setfileAdminpassword(string fileadminpassword);
	string getfileAdminpassword();*/

	
	void adminLogin();
	void regAdmin();
	void adminMenu();
	void writetologFile(string name, string evenid, int tickets);
	void readFromlogFile();
	void ticketSales();

private:
	string adminnameFile, adminpasswordFile, adminInputName, adminInputPassword;
	string adminname, adminid, adminpassword, adminfname, adminlname, adminage, admincontactno, file_adminname, file_adminpassword, line;
	int option;
	string sysDate;
	string sysTime;


};
