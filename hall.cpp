#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <fstream>
#include "hall.h"
#include "Event.h"
#include "Admin.h"
#include "Customer.h"
using namespace std;

Customer *hallCustomer = new Customer;
Event *hallEvent = new Event;
Admin *adm = new Admin;

hall::hall()
{
}
hall::~hall() {

}
//----------------------------------------------------------------------------------------------------------
//Hall plan logic
void hall::hallPlan() {
	cout << "\n";
	cout << "          -----------------------------------------------";
	cout << "\n          |     Hall     |     Capacity   |     Price   |";
	cout << "\n          ----------------------------------------------";
	cout << "\n          | Auditorium A |        900     |    100,0000 |";
	cout << "\n          | Auditorium B |        800     |     50,0000 |";
	cout << "\n          | Convention A |       1100     |    150,0000 |";
	cout << "\n          | Convention B |       1000     |     90,0000 |";
	cout << "\n\nFor further information simply give us a call!! - 0777 1233456\n\n";


}
//----------------------------------------------------------------------------------------------------------
//creates an object for admin to view events
void hall::viewHallReservation()
{
	hallEvent->viewEvent();
}
//----------------------------------------------------------------------------------------------------------
//allows to modify events
void hall::modifyHallReservation()
{
	hallEvent->viewEvent();
	//variables
	string PEventCustName;
	string PEventid;
	string PEvent_name, newEvent_name;
	string PEvent_halltype;
	int PEvent_month;
	int PEvent_date;
	int PEvent_year;
	string PEvent_starttime;
	string PEvent_endtime;
	int PEvent_ticketprice = 0;
	int newEvent_ticketprice = 0;
	int PEvent_ticketnos;
	int newEvent_ticketnos = 0;
	int x = 0;
	string TEvent_id;
	bool check_Flag1 = false;
	bool check_Flag = false;

	//reading from the file
	ifstream oldEventFile("AddEvent.txt", ios::in);
	ofstream modiTemp("modiTemp.txt", ios::app); //opening a file to input existing file information except the modifying event info

	cout << "\n\t          Enter event ID to select and modify an event : ";
	cin >> TEvent_id;

	while (true) {
		oldEventFile >> PEventCustName;
		if (oldEventFile.eof()) {
			break;
		}
		oldEventFile >> PEventid >> PEvent_name >> PEvent_halltype >> PEvent_month >> PEvent_date >> PEvent_year >> PEvent_starttime >> PEvent_endtime >> PEvent_ticketprice >> PEvent_ticketnos;

		if (TEvent_id != PEventid) {
			modiTemp << PEventCustName << '\t' << PEventid << '\t' << PEvent_name << '\t' << PEvent_halltype << '\t' << PEvent_month << '\t' << PEvent_date << '\t' << PEvent_year << '\t' << PEvent_starttime << '\t' << PEvent_endtime << '\t' << PEvent_ticketprice << '\t' << PEvent_ticketnos << endl;
			cout << "";

		}
		if (TEvent_id == PEventid) {
			check_Flag1 = true;
			cout << "\n\t          Enter new event name : ";
			cin >> newEvent_name;
			cout << "\n\t          Enter new event ticket price : ";
			cin >> newEvent_ticketprice;
			cout << "\n\t          Enter new event number of tickets : ";
			cin >> newEvent_ticketnos;

			modiTemp << PEventCustName << '\t' << PEventid << '\t' << newEvent_name << '\t' << PEvent_halltype << '\t' << PEvent_month << '\t' << PEvent_date << '\t' << PEvent_year << '\t' << PEvent_starttime << '\t' << PEvent_endtime << '\t' << newEvent_ticketprice << '\t' << newEvent_ticketnos << endl;
			
			cout << "";
		}
		
	}
	cout << "";

	oldEventFile.clear();
	oldEventFile.seekg(0, ios::beg);
	oldEventFile.close();
	modiTemp.close();
	cout << "";
	remove("AddEvent.txt");
	rename("modiTemp.txt", "AddEvent.txt");

	if (!check_Flag1) {
		check_Flag = true;
		system("cls");
		cout << "\n";
		cout << "                                  -***-                                   \n";
		cout << "\t         Error : The entered event does not exist!\n";
		cout << "                                  -***-                                   \n";
		cout << "                                                                            ";
		cout << "\t                 Press ENTER to try again with a valid ID\n";
		cout << "                                                                            \n";
		cout << "";

	}
	//Event successfully removed from file

	else {
		cout << "                                -***-                                   \n";
		cout << "\n\t             Event was successfully updated\n";
		cout << "                                -***-                                   \n";
		cout << "                                                                            \n";

	}
	//creating a temp file AGAIN if deleting another event
	/*ofstream Newtemp;
	Newtemp.open("modiTemp.txt");
	Newtemp.close();*/

	if (check_Flag == true) {
		system("pause>null");
		cout << "";
		return modifyHallReservation();
	}

	else {
		cout << "\n\t          Press ENTER to go back to homepage...\n\n";
		system("pause > null");
		system("CLS");
		adm->adminMenu();
	}
	cout << "";
}
