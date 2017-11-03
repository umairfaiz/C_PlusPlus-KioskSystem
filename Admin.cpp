#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <fstream>
#include "Admin.h"
#include "User.h"
#include "hall.h"
#include "Event.h"
using namespace std;

Event *evnt =  new Event;
hall *haul = new hall;

Admin::Admin()
{
}

Admin::~Admin()
{
}

//admin loging in
void Admin::adminLogin(){

	string admin_fname;
	string admin_lname;
	string admin_age;
	string admin_contactno;
	string fileadmin_name;
	string fileadmin_password;

	bool login_success = false;

	cout << "\t     *******************| Admin Login |******************"
		<< "\n********************************************************************************";

	cout << "\n\t          Username: ";
	cin >> adminInputName;


	cout << "\n\t          Password: ";
	cin >> adminInputPassword;

	//while (CustPassword[i - 1] != '\r')
	//{
	//	CustPassword[i] = getch();
	//	cout << "*";
	//	i++;
	//}

	ifstream inAdminFile("AdminRegistration.txt", ios::in);

		while (true) {

			inAdminFile >>  admin_fname;
			if (inAdminFile.eof()) {
				break;
			}
			inAdminFile >> admin_lname>> admin_age>> admin_contactno>> file_adminname >>file_adminpassword;
			//setting the values
			this->setFirstName(admin_fname);
			this->setLastName(admin_lname);
			this->setAge(admin_age);
			this->setMobileNumber(admin_contactno);
			this->setUsername(file_adminname);
			this->setPassword(file_adminpassword);

			//checking user input with the file data
			if (adminInputName == getUsername()&& adminInputPassword == getPassword()) {
				system("CLS");
				login_success = true;
				adminMenu();
				break;
				
			}
			

		}
		//if condition wasn't satisfied
		if (!login_success)
		{
			system("cls");
			cout << "\n                                -***-                                   \n";
			cout << "    Invalid login details. Please enter the correct details and try again.\n";
			cout << "                                -***-                                   \n";
			cout << "\n\n";
			adminLogin();
		}
		inAdminFile.close();
		system("pause>null");

		
}
//---------------------------------------------------------------------------------------------------------------------------------
//registering new admins
void Admin::regAdmin() {
	
	cout << "\n";
	cout << "\t*****************| New user registration window |****************"
		<< "\n********************************************************************************";
	
		ofstream outadminFile;
		outadminFile.open("AdminRegistration.txt", ios::app);


		if (!outadminFile) {
			cout << "\n                                -***-                                   \n";
			cerr << "\t  Error : There was an error in opening the file.\n";
			cout << "                                -***-                                   \n";
			exit(1);// terminate due to an error
		}
		else {
			/*		cout << "Your customer ID: C" << generateID()<<endl;*/
			cout << "\n\t          Enter your first name: ";
			cin >> adminfname;
			cout << "\n\t          Enter your last name: ";
			cin >> adminlname;
			cout << "\n\t          Enter your Age: ";
			cin >> adminage;
			cout << "\n\t          Enter your Contact number: ";
			cin >> admincontactno;
			cout << "\n\t          Enter a Username for your future proceedings: ";
			cin >> file_adminname;
			cout << "\n\t          Enter a password for your future proceedings: ";
			cin >> file_adminpassword;

			outadminFile << adminfname << '\t' << adminlname << '\t' << adminage << '\t' << admincontactno << '\t' << file_adminname << '\t' << file_adminpassword << endl;
			cout << "\n";
			outadminFile.close();
		}

		cout << "\n    Congratulation!! " << adminfname << " you have successfully registered to the system!\n";
		cout << "\n\t          Enter 9 to go to the main menu:" << endl;
		cin >> option;
		if (option == 9) {
		
		}
		else {
			exit(0);
		}
}
//---------------------------------------------------------------------------------------------------------------------------------
//admin menu
void Admin::adminMenu() {
	cout << "\n";
	cout << "\t  *******************| Adminstration menu |******************"
		<< "\n********************************************************************************";
	cout << "\n\t          Select an option...";
	cout << "\n";
	cout << "\n\t               1. Ticket sales                                                 ";
	cout << "\n\t               2. Manage hall reservation                                                ";
	cout << "\n\t               3. View log                                                     ";
	cout << "\n\t               4. Hall summary                                                  ";
	cout << "\n";
	cin >> option;

		switch (option)
		{
		case 1:
			system("cls");
			cout << "\n";
			cout << "\t    *******************| Ticket sales |******************"
				<< "\n********************************************************************************";
			cout << "\n";
			ticketSales();
			break;

		case 2:
			system("cls");
			cout << "\n";
			cout << "\t*******************| Manage Hall Reservation |******************"
				<< "\n********************************************************************************";
			cout << "\n";
			haul->modifyHallReservation();
			break;
			
			
		case 3:
			system("cls");
			cout << "\n";
			cout << "\t    *******************| Log details |******************"
				<< "\n********************************************************************************";
			cout << "\n";
			readFromlogFile();
			break;
		case 4:
			system("cls");
			cout << "\n";
			cout << "\t    *******************| Hall Summary |******************"
				<< "\n********************************************************************************";
			cout << "\n";
			haul->viewHallReservation();
			cout << "\n\t          Press ENTER to go back to menu" << endl;
			system("pause>null");
			system("cls");
			return adminMenu();
			break;

		default:
			cout << "\n                                -***-                                   \n";
			cout << "\t  Error : Incorrect option entered. Enter a valid choice!.\n";
			cout << "                                -***-                                   \n";
			cout << "\n\t          Press ENTER to go back to menu" << endl;
			system("pause>null");
			system("cls");
			return adminMenu();
			break;
		}
	
}
//-------------------------------------------------------------------------------------------------------------------------------
//get the necessary log data to  be written to a file so it can be read
void Admin::writetologFile(string name, string evenid, int tickets)
{

	//creating an array to hold ddate and time
	char date[9];
	char time[9];
	
	_strdate_s(date);//Getting the current date
	_strtime_s(time);//Getting time of the system

	sysDate = date;
	sysTime = time;
	cout << "";
	ofstream outLogFile;
	outLogFile.open("LogFile.txt", ios::app);

	if (!outLogFile) {
		cout << "\n                                -***-                                   \n";
		cerr << "\t  Error : There was an error in opening the file.\n";
		cout << "                                -***-                                   \n";
		exit(1);// terminate due to an error
	}
	outLogFile << '\n' << sysDate << '\t' << sysTime << '\t' << name << '\t' << evenid << '\t' << tickets;
	
	outLogFile.close();
}
//-------------------------------------------------------------------------------------------------------------------------------
//reading the log data for admin viewing
void Admin::readFromlogFile()
{
	string logName;
	string logEvntID;
	string logtickets;

	//reading from the file
	ifstream inLogFile;
	inLogFile.open("LogFile.txt", ios::in);
	cout << "\n";

	cout << left << setw(18) << "Accessed date" << setw(18) << "Accessed time" 
		<< setw(12) << "User" << setw(12) << "Event" << setw(7) << "#tickets" << endl << fixed << showpoint;
	cout << "\n";

	if (!inLogFile) {
		cout << "\n                                -***-                                   \n";
		cerr << "\t  Error : There was an error in opening the file.\n";
		cout << "                                -***-                                   \n";
		exit(1);// terminate due to an error
	}
	while (inLogFile >> sysDate >> sysTime >> logName >> logEvntID >> logtickets) {
		cout << "\n";
		cout << left <<"  "<< setw(19) << sysDate << setw(15) << sysTime << setw(13) << logName
			<< setw(14) << logEvntID << setw(7) << logtickets << endl;
	}

	inLogFile.close();
	cout << "\n";
	cout << "\n\t          Press ENTER to go back" << endl;
	system("pause>null");
	system("cls");
	return adminMenu();
}
//-------------------------------------------------------------------------------------------------------------------------------
//admin  viewing ticket sales
void Admin::ticketSales() {
	evnt->viewEvent();

	string custName, Eventid, title, hall, Eventstarttime, Eventendtime, reference, tname, peventid, cardtype, cardnumber;
	int month, date, year, price, Eventticketnos, noticket;
	int totalTickets = 0;
	int totalSales = 0;
	int count = 0;
	string eventumber;
	bool flagsuccess = false;


	ifstream CheckFile1;
	CheckFile1.open("AddEvent.txt", ios::in);
	ifstream CheckFile3;



	//checking for corrupted files
	if (CheckFile1.fail()) {
		cerr << "File cannot be opened!";
	}
	
	cout << "\n\t               Enter the Event ID :  ";
	cin >> eventumber;
	bool status = evnt->validateEventid(eventumber);
	cout << "";
	if (status == false) {
		system("cls");
		cout << "\n";
		cout << "                                -***-                                   \n";
		cout << "\t         Error : Invalid Event ID. Try again.\n";
		cout << "                                -***-                                   \n";
		cout << "\n";
		cout << "";
		return ticketSales();
	}

	while (true) {
		CheckFile1 >> custName>> Eventid >> title >> hall >> month >> date >> year >> Eventstarttime >> Eventendtime >> price >> Eventticketnos;
	
		if (eventumber == Eventid) {
			flagsuccess = true;
			cout << "";
			break;
		}
	}//end of while	
	CheckFile1.close();
	CheckFile1.clear();
	cout << "";
	
	CheckFile3.open("ticketPurchase.txt", ios::in);
	if (CheckFile3.fail()) {
		cerr << "File cannot be opened!";
	}

	while (true) {
		CheckFile3 >> reference;
		
		if (CheckFile3.eof()) {
			break;
		}
	
		CheckFile3 >> tname >> peventid >> noticket >> cardtype >> cardnumber;
		if (eventumber == peventid) {
			flagsuccess = true;
			totalTickets += noticket;//getting the total of number of tickets of the relevant event ID
			++count;
			cout << "";

		}

	}//end of while	

	if (flagsuccess = true) {
		totalSales = totalTickets*price;
		cout << "\n\t               Total Ticket Sales of "<< eventumber <<"= Rs." << totalSales<<endl;

	}

	CheckFile3.close();
	CheckFile3.clear();

	if (flagsuccess = false)
	{
		cout << "";
		system("CLS");
		cout << "\n                                -***-                                   \n";
		cout << "    Invalid event ID. Please enter the correct ID and try again.\n";
		cout << "                                -***-                                   \n";
		ticketSales();

	}
	cout << "\n";
	cout << "\n\t          Press ENTER to go back" << endl;
	system("pause>null");
	system("cls");
	return adminMenu();

}
//-------------------------------------------------------------------------------------------------------------------------------

