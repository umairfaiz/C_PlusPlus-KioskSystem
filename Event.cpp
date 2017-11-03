#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <sstream>//fro stringstream
#include <iomanip>
#include "Event.h"
#include "hall.h"
#include "Admin.h"
#include "Ticket.h"
#include "Customer.h"


Customer *customer= new Customer;
hall *Hall = new hall;
Ticket *tick = new Ticket;
Admin *admin = new Admin;

Event::Event()
{
}

Event::~Event()
{
}

void Event::setCustName(string custName) {
	this->custName = custName;
}

string Event::getCustName()
{
	return this->custName;
}

void Event::setHallType(string hallType)
{
	this->hallType = hallType;
}

string Event::getHallType()
{
	return this->hallType;
}

void Event::setEventID(string eventID)
{
	this->eventID = eventID;
}

string Event::getEventID()
{
	return this->eventID;
}

void Event::setEventName(string eventName)
{
	this->eventName = eventName;

}

string Event::getEventName()
{
	return this->eventName;
}

void Event::setEventMonth(int eventmonth)
{
	this->eventMonth = eventmonth;
}

int Event::getEventMonth()
{
	return this->eventMonth;
}

void Event::setEventDate(int eventDate)
{
	this->eventDate = eventDate;
}

int Event::getEventDate()
{
	return this->eventDate;
}

void Event::setEventYear(int eventYear)
{
	this->eventYear = eventDate;
}

int Event::getEventYear()
{
	return this->eventYear;
}

void Event::setEventStartTime(string eventStartTime)
{
	this->eventStarTime = eventStarTime;

}

string Event::getEventStartTime()
{
	return this->eventStarTime;
}

void Event::setEventEndTime(string eventEndTime)
{
	this->eventEndTime = eventEndTime;
}

string Event::getEventEndTime()
{
	return this->eventEndTime;
}

void Event::setEventTicketPrice(int eventTicketprice)
{
	this->eventTicketPrice = eventTicketprice;
}

int Event::getEventTicketPrice()
{
	return this->eventTicketPrice;
}

void Event::setNoOFTickets(int noOfTickets)
{
	this->noOfTickets = noOfTickets;

}

int Event::getNoOFTickets()
{
	return this->noOfTickets;
}

//------------------------------------------------------------------------------------------------------------------------------
//after checking for reserved hall adding item to the file
void Event::addEvent() {

	if (option1 == 1) {
		hallType = "Auditorium_A";
	}
	else if (option1 == 2) {
		hallType = "Auditorium_B";
	}
	else if (option1 == 3) {
		hallType = "Convention_A";
	}
	else if (option1 == 4) {
		hallType = "Convention_B";
	}
	
	cout << "";
	ofstream outEventsFile;
	outEventsFile.open("AddEvent.txt", ios::app);

	
	if (!outEventsFile) {
		cout << "\n                                -***-                                   \n";
		cerr << "\t      Error : There was an error in opening the file.\n";
		cout << "                                -***-                                   \n";
		cout<<"\n " << endl;
		exit(1);
	}
	else {
		string EventId;
		string userName;
		EventId = "E" + to_string(this->generateID());

		//getting user input
		
		cout << "\n\t          Your event ID: " <<EventId;
		cout << "\n";
		cout << "\n\t          Enter event name: " ;
		cin >> eventName;
		cout << "\n\t          Hall  selected: "<<hallType;
		cout << "\n";
		cout << "\n\t          Selected month (MM): "<< HReventMonth;
		cout << "\n";
		cout << "\n\t          Selected date (DD): "<< HReventDate;
		cout << "\n";
		cout << "\n\t          Selected year (YYYY): "<< HReventYear;
		cout << "\n";
		cout << "";
		cout << "\n\t          Enter start time (24 hour format/HHMM): ";
		cin >> eventStarTime;
		cout << "\n";
		cout << "\n\t          Enter end time (24 hour format/HHMM): " ;
		cin >> eventEndTime;
		timeValidation(eventStarTime, eventEndTime);
		cout << "\n";
		cout << "\n\t          Enter event ticket price: " ;
		cin >> eventTicketPrice;
		cout << "\n";
		cout << "\n\t          Enter the number of ticket available: ";
		cin >> noOfTickets;
		cout << "\n";

		outEventsFile << getCustName() << '\t' << EventId<< '\t' << eventName << '\t' << hallType<< '\t' << HReventMonth << '\t' << HReventDate <<'\t'<< HReventYear << '\t' << eventStarTime << '\t' << eventEndTime << '\t' << eventTicketPrice << '\t' << noOfTickets << endl;
		outEventsFile.close();
		cout << "";
		system("CLS");
		cout << "\n                                -***-                                   ";
		cout << "\n\t          Your event was successfully added!!\n";
		cout << "                                -***-                                   \n\n";
		cout << "\tGenerated Reciept for confirming your reservation.\n\n";
		cout << "\n                                -***-                                   \n";
		cout << "                 Organizer                       : " << getCustName();
		cout << "\n";
		cout << "                 Hall                            : " << hallType;
		cout << "\n";
		cout << "                 Event Name                      : " << eventName;
		cout << "\n";
		cout << "                 Time                            : " << eventStarTime<<" to "<< eventEndTime;
		cout << "\n";
		cout << "                 Date                            : " << HReventMonth<<"/" << HReventDate <<"/"<< HReventYear;
		cout << "\n";
		cout << "                 Amount of tickets ordered       : " << noOfTickets;
		cout << "\n";
		cout << "                 Price per ticket                : " << eventTicketPrice;
		cout << "\n";
		cout << "                                -***-                                   \n";
		admin->writetologFile(getCustName(), EventId, noOfTickets);
		cout << "\nPress ENTER for more options...\n\n";
		system("pause > null");
		system("CLS");
		customer->RegCustMenu();
	}
}
//------------------------------------------------------------------------------------------------------------------------------
//show all events added to the file logic
void Event::viewEvent() {

	ifstream eventDetails("AddEvent.txt", ios::in);
	//setting the columns to out put read data
	cout << left << setw(8) << "ID" << setw(11) << "Name"
		 << setw(11) << "Hall" << setw(9) << "Month"<< setw(8)<<"Date"<<setw(7)<<"Year" << setw(6) << "Start" << setw(7) << "End"
		<< setw(8) << "Price" << setw(5) << "nos" << endl << fixed << showpoint;
	cout << "\n";

	string line;
	if (eventDetails.fail()) {
		cerr << "File cannot be opened!" << endl;
	}
	else {

		while (eventDetails>> eventCustName >> eventID >> eventName >> hallType >> eventMonth >> eventDate >> eventYear >> eventStarTime >> eventEndTime >> eventTicketPrice >> noOfTickets)
		{
			
			cout << left << setw(9) << eventID << setw(7) << eventName
				<< setw(16) << hallType << setw(8) << eventMonth << setw(7) << eventDate << setw(7) << eventYear << setw(6) << eventStarTime << setw(7) << eventEndTime
				<< setw(6) << eventTicketPrice << setw(5) << right << noOfTickets << endl;
			
		}
		
	}
	eventDetails.close();
}

//------------------------------------------------------------------------------------------------------------------------------
//checking if halls are available on a particular date
void Event::hallReservation() {

	string Event_id;
	string Event_custName;
	string Event_name;
	string Event_halltype;
	int Event_month;
	int Event_date;
	int Event_year;
	string Event_starttime;
	string Event_endtime;
	int Event_ticketprice;
	int Event_ticketnos;
	string audA = "Auditorium_A";
	string audB = "Auditorium_B";
	string conA = "Convention_A"; 
	string conB = "Convention_B";


	cout << "\t*******************| Hall reservation menu |******************"
		<< "\n********************************************************************************";

	bool check_success = false;

	Hall ->hallPlan();
	cout << "\n\t          Enter your name: ";
	cin >> Event_custName;
	cout << "\n\t      Enter event date to reserver a hall\n";
	cout << "\n\t          Enter event month (MM): ";
	cin >> HReventMonth;
	cout << "\n\t          Enter event date (DD): ";
	cin >> HReventDate;
	cout << "\n\t          Enter event year (YYYY): ";
	cin >> HReventYear;
	dateValidation(HReventMonth, HReventDate, HReventYear);
	cout << "\n\n\t     Select a hall suiting your event requirments\n";
	cout << "\n\t         1. Auditorium A";
	cout << "\n\t         2. Auditorium B";
	cout << "\n\t         3. Convention A";
	cout << "\n\t         4. Convention B";
	cout << "\n\n";

	cin >> option1;
	cout << "";
	this->setCustName(Event_custName);

	//reading from the file
	ifstream inEventFile("AddEvent.txt", ios::in);
	if (inEventFile.fail()) {
		cerr << "File cannot be opened!";
	}
	while (true) {
		inEventFile >> Event_custName;

		if (inEventFile.eof()) {
			break;
		}

		inEventFile>> Event_id >> Event_name >> Event_halltype >>Event_month>> Event_date>>Event_year >> Event_starttime >> Event_endtime >> Event_ticketprice >> Event_ticketnos;
		cout << "";
		switch (option1) {
		case 1:
			if (audA == Event_halltype && HReventMonth == Event_month && HReventDate== Event_date&& HReventYear== Event_year) {
				check_success = true;
				system("cls");
				cout << "                                -***-                                   \n";
				cout << "   Hall is reserved for now. Select another hall suiting your requirement\n";
				cout << "                                -***-                                   \n";
				cout << "                                                                             \n";
				hallReservation();
				cout << "";
			}
			break;
		case 2:
			if (audB == Event_halltype && HReventMonth == Event_month && HReventDate == Event_date && HReventYear == Event_year) {
				check_success = true;
				system("cls");
				cout << "                                -***-                                   \n";
				cout << "   Hall is reserved for now. Select another hall suiting your requirement\n";
				cout << "                                -***-                                   \n";
				cout << "                                                                             \n";
				hallReservation();
			}
			break;
		case 3:
			cout << "";
			if (conA == Event_halltype && HReventMonth == Event_month && HReventDate == Event_date&& HReventYear == Event_year) {
				check_success = true;
				system("cls");
				cout << "                                -***-                                   \n";
				cout << "   Hall is reserved for now. Select another hall suiting your requirement\n";
				cout << "                                -***-                                   \n";
				cout << "                                                                             \n";
				hallReservation();
			}
			break;
		case 4:
			cout << "";
			if (conB == Event_halltype && HReventMonth == Event_month && HReventDate == Event_date&& HReventYear == Event_year) {
				check_success = true;
				system("cls");
				cout << "                                -***-                                   \n";
				cout << "   Hall is reserved for now. Select another hall suiting your requirement\n";
				cout << "                                -***-                                   \n";
				cout << "                                                                             \n";
				hallReservation();
			}
			break;
		default: // catch all other characters
			system("cls");
			cout << "                                -***-                                   \n";
			cout << "\t              Error : Enter a valid choice!\n";
			cout << "                                -***-                                   \n";
			cout << "                                                                            \n";
			hallReservation();
			break;
		}//end switch

	}//end while



	if (!check_success) {
		cout << "";
		system("cls");
		cout << "\nYou have successfully reserved the hall!\n";
		addEvent();

	}
	inEventFile.close();
	system("pause");
}
//------------------------------------------------------------------------------------------------------------------------------
//only views upcoming events logic
void Event::viewupcomingEvents() {

	string Event_id;
	string Event_custName;
	string Event_name;
	string Event_halltype;
	int Event_month;
	int Event_date;
	int Event_year;
	string Event_starttime;
	string Event_endtime;
	int Event_ticketprice;
	int Event_ticketnos;
	int n = 1900;
	
	//getting the system time
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int year = n + ltm->tm_year; //current year of the system
	int month = 1 + ltm->tm_mon; //current month of the system
	int day = ltm->tm_mday;	//current day of the system


	
	cout << left << setw(10) << "ID" << setw(13) << "Name" <<setw(14) << "Hall" << setw(16) <<"Start(24HR)"<< setw(15) <<"End(24HR)"<< setw(15) << "Price(Rs)" << endl << fixed << showpoint;
	cout << "\n";
	/*cout << left  << setw(11) << "Name"
		<< setw(15) << "Hall" << endl << fixed << showpoint;*/
	cout << "\n";

	ifstream eventViewDetails("AddEvent.txt", ios::in);
	if (eventViewDetails.fail()) {
		cerr << "File cannot be opened!" << endl;
	}
	else {
		while (!eventViewDetails.eof()) {

			eventViewDetails >> Event_custName; 

				if (eventViewDetails.eof()) {
					break;
				}
				eventViewDetails >> Event_id >> Event_name >> Event_halltype >> Event_month >> Event_date >> Event_year >> Event_starttime >> Event_endtime >> Event_ticketprice >> Event_ticketnos;
				cout << "";
				if (Event_year < year) {
					continue;
				}
				else if (Event_year == year) {
					if (Event_month < month) {
						continue;
					}
				else if (Event_month == month) {
					if (Event_date < day) {
							continue;
					}
						//checking if the event date is greater than than the system
					else {
						cout << left << setw(11) << Event_id << setw(9) << Event_name << setw(19) << Event_halltype << setw(16) <<Event_starttime << setw(15) <<Event_endtime << setw(20) <<Event_ticketprice<< endl << fixed << showpoint;
					}
				}
					//checking if the event month is greater than than the system
				else {				
					cout << left << setw(11) << Event_id << setw(9) << Event_name << setw(19) << Event_halltype << setw(16) << Event_starttime << setw(15) << Event_endtime << setw(20) << Event_ticketprice << endl << fixed << showpoint;
				}
			}
				//checking if the event year is greater than than the system
			else {
				cout << left << setw(11) << Event_id << setw(9) << Event_name << setw(19) << Event_halltype << setw(16) << Event_starttime << setw(15) << Event_endtime << setw(20) << Event_ticketprice << endl << fixed << showpoint;
			}
			cout << "" << endl;

		}//end inner while
	}//end else
	eventViewDetails.close();
}//end functiion
//generate a random two to three digit number for ID
int Event::generateID() {

	srand((unsigned)time(0));
	int random_integer;
	int lowest = 10, highest = 1000;
	int range = (highest - lowest) + 1;
	for (int index = 0; index < 20; index++) {
		random_integer = lowest + int(range*rand() / (RAND_MAX + 1.0));
	}
	return random_integer;
}
//cancels all ready booked reservations
void Event::cancelHallReservations()
{	
	bool checkFlag = false;
	//variables

	string PEventid;
	string PEventCustName;
	string PEvent_name;
	string PEvent_halltype;
	int PEvent_month;
	int PEvent_date;
	int PEvent_year;
	string PEvent_starttime;
	string PEvent_endtime;
	int PEvent_ticketprice;
	int PEvent_ticketnos;
	int x = 0;
	string TEvent_id;

	reservationRelatedtoCust();
	cout << "\n";
	//reading from the file
	ifstream inEventFile("AddEvent.txt", ios::in);
	ofstream temp("temp.txt", ios::in); //opening a file to input existing file information except the cancelling event info

	cout << "\n\t          Enter event ID to cancel the event : ";
	cin >> TEvent_id;

	while (inEventFile>> PEventCustName >> PEventid >> PEvent_name >> PEvent_halltype >> PEvent_month >> PEvent_date >> PEvent_year >> PEvent_starttime >> PEvent_endtime >> PEvent_ticketprice >> PEvent_ticketnos) {
		//event ID wasnt found so no line was deleted
		if (TEvent_id != PEventid) {
			temp<< PEventCustName << '\t' << PEventid << '\t' << PEvent_name << '\t' << PEvent_halltype << '\t' << PEvent_month << '\t' << PEvent_date << '\t' << PEvent_year << '\t' << PEvent_starttime << '\t' << PEvent_endtime << '\t' << PEvent_ticketprice << '\t' << PEvent_ticketnos << endl;
			cout << "";
		}
		if(TEvent_id == PEventid) {
			x = 1;
		}
	}//end of outer while

	inEventFile.clear();
	inEventFile.seekg(0, ios::beg);
	inEventFile.close();
	temp.close();
	remove("AddEvent.txt");
	rename("temp.txt", "AddEvent.txt");

	
	//event ID wasnt found so no line was deleted
	if (x == 0) {
		checkFlag = true;
		system("cls");
		cout << "\n";
		cout << "                                  -***-                                   \n";
		cout << "\t         Error : The entered event does not exist!\n";
		cout << "                                  -***-                                   \n";
		cout << "                                                                            ";
		cout << "\t                 Press ENTER to try again with a valid ID\n";
		cout << "                                                                            \n";

		
	}
	//Event successfully removed from file
	else {
		cout << "                                -***-                                   \n";
		cout << "\t             Event was successfully cancelled\n";
		cout << "                                -***-                                   \n";
		cout << "                                                                            \n";

	}
	//creating a temp file AGAIN if deleting another event
	ofstream Ttemp;
	Ttemp.open("temp.txt");
	Ttemp.close();
	if (checkFlag == true) {
		system("pause>null");
		return cancelHallReservations();
	}
	else {
		cout << "\n\t          Press ENTER to go back to homepage...\n\n";
		system("pause > null");
		system("CLS");
		customer->RegCustMenu();
	}
	
}
//gets only reservation made by a particular customer when deleting
void Event::reservationRelatedtoCust()
{
	string P_Eventid;
	string P_EventCustName;
	string P_Event_name;
	string P_Event_halltype;
	int P_Event_month;
	int P_Event_date;
	int P_Event_year;
	string P_Event_starttime;
	string P_Event_endtime;
	int P_Event_ticketprice;
	int P_Event_ticketnos;
	string TEvent_custName;
	bool flag = false;

	ifstream in_EventFile("AddEvent.txt", ios::in);
	if (in_EventFile.fail()) {
		cerr << "File cannot be opened!";
	}

	cout << "\n\t          Enter your username : ";
	cin >> TEvent_custName;
	cout << "";
	cout << "\n\t  These are the events that you have reserved...";
	cout << "\n\n";
	cout << left << setw(8) << "ID" << setw(11) << "Name"
		<< setw(11) << "Hall" << setw(9) << "Month" << setw(8) << "Date" << setw(7) << "Year" << setw(6) << "Start" << setw(7) << "End"
		<< setw(8) << "Price" << setw(5) << "nos" << endl << fixed << showpoint;
	cout << "\n";
	cout << "";
	while (true) {//!in_EventFile.eof()
		in_EventFile >> P_EventCustName;

		if (in_EventFile.eof()) {
			break;
		}
		in_EventFile >> P_Eventid >> P_Event_name >> P_Event_halltype >> P_Event_month >> P_Event_date >> P_Event_year >> P_Event_starttime >> P_Event_endtime >> P_Event_ticketprice >> P_Event_ticketnos;
		
		this->setCustName(P_EventCustName);
		this->setEventID(P_Eventid);
		this->setEventName(P_Event_name);
		this->setHallType(P_Event_halltype);
		this->setEventMonth(P_Event_month);
		this->setEventDate(P_Event_date);
		this->setEventYear(P_Event_year);
		this->setEventStartTime(P_Event_starttime);
		this->setEventEndTime(P_Event_endtime);
		this->setEventTicketPrice(P_Event_ticketprice);
		this->setNoOFTickets(P_Event_ticketnos);

		if (TEvent_custName == P_EventCustName) {
			flag = true;
			cout << left << setw(9) << P_Eventid << setw(7) << P_Event_name
				<< setw(16) << P_Event_halltype << setw(8) << P_Event_month << setw(7) << P_Event_date << setw(7) << P_Event_year << setw(6) << P_Event_starttime << setw(7) << P_Event_endtime
				<< setw(6) << P_Event_ticketprice << setw(5) << right << P_Event_ticketnos << endl;
			cout << "";

		}
		cout << "";
	}
	cout << "";
	if (!flag) {
		/*cout << left << setw(9) << P_Eventid << setw(7) << P_Event_name
			<< setw(16) << P_Event_halltype << setw(8) << P_Event_month << setw(7) << P_Event_date << setw(7) << P_Event_year << setw(6) << P_Event_starttime << setw(7) << P_Event_endtime
			<< setw(6) << P_Event_ticketprice << setw(5) << right << P_Event_ticketnos << endl;
		cout << "";*/
		system("cls");
		cout << "\n                                -***-                                   \n";
		cout << "    There are no events under your name! or try entering a correct username.\n";
		cout << "                                -***-                                   \n";
		cout << "\n\n";
		reservationRelatedtoCust();
		cout << "";
	}
	/*if (flag) {

		cout << "\n\t  These are the events that you have reserved...";
		cout << "\n\n";
		cout << left << setw(8) << "ID" << setw(11) << "Name"
			<< setw(11) << "Hall" << setw(9) << "Month" << setw(8) << "Date" << setw(7) << "Year" << setw(6) << "Start" << setw(7) << "End"
			<< setw(8) << "Price" << setw(5) << "nos" << endl << fixed << showpoint;
		cout << "\n";
		cout << "";

		cout << left << setw(9) << P_Eventid << setw(7) << P_Event_name
		<< setw(16) << P_Event_halltype << setw(8) << P_Event_month << setw(7) << P_Event_date << setw(7) << P_Event_year << setw(6) << P_Event_starttime << setw(7) << P_Event_endtime
		<< setw(6) << P_Event_ticketprice << setw(5) << right << P_Event_ticketnos << endl;
		cout << "";
	}*/

		in_EventFile.clear();
		in_EventFile.close();

}
//ticket purchasing
void Event::ticketPurchase() {

	viewupcomingEvents();
	cout << "\n";

	string evnt_id, payment_mode, ticketName;
	int card_number=0, numberOf_tickets;
	string customer_card[16];

	int referenceNumber;
	referenceNumber = this->generateID();

	ofstream ticketPurchFile;
	ticketPurchFile.open("ticketPurchase.txt", ios::app);


	if (!ticketPurchFile) {
		cout << "\n                                -***-                                   \n";
		cerr << "\t      Error : There was an error in opening the file.\n";
		cout << "                                -***-                                   \n";
		cout << "\n " << endl;
		exit(1);
	}
	else {
		cout << "Select an event you would like to purchase tickets..\n";
	cout << "\n\t          Reference number for this transaction : " <<referenceNumber<< endl;
	cout << "\n\t          Enter Event ID : ";
	cin >> evnt_id;
	cout << "\n\t          Enter your name : ";
	cin >> ticketName;

	cout << "\n\t          Number of ticket(s) : " ;
	while (!(cin >> numberOf_tickets)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n\t          Invalid input!";
		cout << "\n\t          Enter number of tickets again: ";
	}

	do
	{
		cout << "\n\t          Payment card type (Debit/Credit) : ";
		cin >> payment_mode;
		if (payment_mode == "Debit" || payment_mode == "Credit")
			break;
		else
			cout << "\n";
		cout << "                                -***-                                   \n";
		cout << "\t         Error : Invalid card type. Try again.\n";
		cout << "                                -***-                                   \n";
		cout << "\n";
	} while (1);



	//Customer Card number input validation
	do 
	{
		cout << "\n\t          Enter the 16 digit card number : ";
		cin >> customer_card[card_number];
		if (customer_card[card_number].size() == 16)
			break;
		else
		cout << "\n";
		cout << "                                -***-                                   \n";
		cout << "\t         Error : Invalid card number. Try again.\n";
		cout << "                                -***-                                   \n";
		cout << "\n";
	} while (1);

	ticketPurchFile << referenceNumber << '\t' <<ticketName << '\t' << evnt_id << '\t' << numberOf_tickets << '\t' << payment_mode << '\t' << customer_card[card_number] << endl;
	ticketPurchFile.close();

	system("CLS");
	}//end of else

	secondaryMenu();

}//end of ticketPurchase function
 //provides options to the customer two generate ticket or purchase more
void Event::secondaryMenu() {
	int selection =0;
	cout << "\n\t          Select an option...";
	cout << "\n";
	cout << "\n\t               1. Generate ticket(s) now                                                 ";
	cout << "\n\t               2. Purchase ticket(s) for another event                                                  ";
	cin >> selection;

	switch (selection)
	{
	case 1: 
		system("CLS");
		tick->generateTicket();
		break;
	case 2:
		system("CLS");
		ticketPurchase();
		
		break;
	default:
		cout << "\n                                -***-                                   \n";
		cout << "\t  Error : Incorrect option entered. Enter a valid choice!.\n";
		cout << "                                -***-                                   \n";
		secondaryMenu();
		break;
	}
}
//validate date when customer reserves a hall
void Event::dateValidation(int mnth, int date,int yr) {
	int n = 1900;

	//getting the system time
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int year = n + ltm->tm_year; //current year of the system

	while (!(yr >= year)) {
		system("cls");
		cout << "                                -***-                                   \n";
		cout << "\t  Error : Please enter valid inputs for the date with relevent values!!\n";
		cout << "                                -***-                                   \n";
		cout << "                                                                            \n";
		hallReservation();

	}
	while (!((mnth >= 1 && mnth <= 12) && (date >= 1 && date <= 31))) {
		system("cls");
		cout << "                                -***-                                   \n";
		cout << "\t  Error : Please enter valid inputs for the date with relevent values!!\n";
		cout << "                                -***-                                   \n";
		cout << "                                                                            \n";
		hallReservation();

	}
}
//validate time when customer reserves a hall
void Event::timeValidation(string stime, string etime) {

	while (!(stime.size() == 5 || etime.size() == 5)) {
		system("cls");
		cout << "                                -***-                                   \n";
		cout << "\t  Error : Please enter valid inputs for time with relevent values!!\n";
		cout << "                                -***-                                   \n";
		cout << "                                                                            \n";
		break;
	}

}
//validating the event ID
vector<string> Event::split(const string &str, char delimit) {
	string item;
	vector<string> data;
	stringstream stream(str);
	
	while (getline(stream, item, delimit)) {
		data.push_back(item);
	}
	return data;
}
//validating the event ID
bool Event::validateEventid(string eventId) {
	vector<string> file;
	string event_Id;
	string line;
	bool idFlag = false;
	ifstream checkEvent;
	checkEvent.open("AddEvent.txt", ios::in);

	while (getline(checkEvent, line))
	{
		file.push_back(line);
	}
	try {
		for (int i = 1; i < file.size(); i++) {
			vector<string> column = split(file.at(i), '\t');

			event_Id = column.at(1);//since event ID is the second column

			if (eventId == event_Id) {
				idFlag = true;
				break;
			}

			cout << "";
		}
	}
	catch (exception ex) {
		cout << "error";
	}
	
	checkEvent.close();
	return idFlag;
}




