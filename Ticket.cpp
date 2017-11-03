#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <fstream>
#include "Ticket.h"
#include "Event.h"
#include "Admin.h"
#include "Customer.h"
using namespace std;

Event *event1 = new Event;
Customer *cust1 = new Customer;
Admin *adminlog = new Admin;

Ticket::Ticket()
{
}

Ticket::~Ticket()
{
}
//generates tickets
void Ticket::generateTicket()
{
	cout << "\n";
	cout << "          *******************| Generate Ticket |******************"
		<< "\n********************************************************************************";
	bool flag_success = false;
	string  evnumber;
	int rnumber;
	int totalCost = 0;

	event1->viewupcomingEvents();

	cout << "\n\t               Enter your reference number : ";
	while (!(cin >> rnumber)) {
		cout << "";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//restricting non numeric values
		cout << "\n\t          Invalid input!Enter a numeric number";
		cout << "\n\t          Enter reference number again: ";
		cin >> rnumber;
		cout << "";
		break;
	}
	cout << "\n\t               Enter the Event ID : ";
	cin >> evnumber;
	cout << "";
	bool status = event1->validateEventid(evnumber);
	if (status == false) {
		system("cls");
		cout << "\n";
		cout << "                                -***-                                   \n";
		cout << "\t         Error : Invalid Event ID. Try again.\n";
		cout << "                                -***-                                   \n";
		cout << "\n";
		cout << "";
		return generateTicket();
	}
	cout << "";
	//opening files
	ifstream CheckFile1("AddEvent.txt", ios::in);
	ifstream CheckFile3;


	//checking for corrupted files
	if (CheckFile1.fail()) {
		cerr << "File cannot be opened!";
	}

	while (true) {
		CheckFile1 >> EventcustName>> Eventid >> title >> hall >> month >> date >> year >> Eventstarttime >> Eventendtime >> price >> Eventticketnos;
		cout << "";
		if (evnumber == Eventid) {
			flag_success = true;
			break;
		}
	}//end of while	
	CheckFile1.close();
	CheckFile1.clear();
	CheckFile3.open("ticketPurchase.txt", ios::in);
	cout << "";
	if (CheckFile3.fail()) {
		cerr << "File cannot be opened!";
	}
	while (true) {
	
		CheckFile3 >> reference >> tname >> peventid >> noticket >> cardtype >> cardnumber;

		if (rnumber == reference) {
			flag_success = true;
			cout << "";
			break;
		}
	}//end of while	
	CheckFile3.close();
	CheckFile3.clear();



	if (flag_success=true)
	{

		system("CLS");
		cout << "\n";
		cout << "\n                                -***-                                   \n";
		cout << "                 Reference Number : " << reference;
		cout << "\n";
		cout << "                 Event ID         : " << Eventid;
		cout << "\n";
		cout << "                 Event Name       : " << title;
		cout << "\n";
		cout << "                 Event held at    : " << hall;
		cout << "\n";
		cout << "                 Username         : " << tname;
		cout << "\n";
		cout << "                 Event held on    : " << month << "/" << date << "/" << year;
		cout << "\n";
		cout << "                                -***-                                   \n";

		cout << "\n\t           Total  ticket(s) printed : " << noticket;
		cout << "";
	}
	totalCost = noticket*price;
	cout << "\n\t           Amount deducted from your account : Rs." << totalCost;

	if (!flag_success)
	{
		system("CLS");
		cout << "\n                                -***-                                   \n";
		cout << "    Invalid event ID. Please enter the correct ID and try again.\n";
		cout << "                                -***-                                   \n";
	}
	adminlog->writetologFile(tname, Eventid, noticket);
	cout << "\n\nPress ENTER to go back to homepage...\n\n";
	system("pause > null");
	system("CLS");
	cust1->RegCustMenu();

}