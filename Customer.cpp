#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Customer.h"
#include "Admin.h"
#include "hall.h"
#include "Event.h"
#include "Ticket.h"

using namespace std;

Event *event=new Event;
hall *hal = new hall;
Ticket *tickets = new Ticket;

Customer::Customer()
{

}
//------------------------------------------------------------------------------------------------------------------
Customer::~Customer()
{
}
//------------------------------------------------------------------------------------------------------------------
//void Customer::setCustName(string custname)
//{
//	this->custname = custname;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getCustName()
//{
//	return this->custname;
//}
////------------------------------------------------------------------------------------------------------------------
//void Customer::setCustID(string custid)
//{
//	this->custid = custid;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getCustID()
//{
//	return this->custid;
//
//}
////------------------------------------------------------------------------------------------------------------------
//void Customer::setCustPassword(string custpassword)
//{
//	this->custpassword = custpassword;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getCustPassword()
//{
//	return this->custpassword;
//}
////------------------------------------------------------------------------------------------------------------------
//void Customer::setCustFName(string custfname)
//{
//	this->custfname = custfname;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getCustFName()
//{
//	return this->custfname;
//}
////------------------------------------------------------------------------------------------------------------------
//void Customer::setCustLName(string custlname)
//{
//	this->custlname = custlname;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getCustLName()
//{
//	return this->custlname;
//}
////------------------------------------------------------------------------------------------------------------------
//void Customer::setCustAge(string custage)
//{
//	this->custage = custage;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getCustAge()
//{
//	return this->custage;
//}
////------------------------------------------------------------------------------------------------------------------
//void Customer::setCustContactNo(string custcontactno)
//{
//	this->custcontactno = custcontactno;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getCustContactNo()
//{
//	return this->custcontactno;
//}
////------------------------------------------------------------------------------------------------------------------
//void Customer::setfilecustname(string filecustname)
//{
//	this->filecustname = filecustname;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getfilecustname()
//{
//	return this->filecustname;
//}
////------------------------------------------------------------------------------------------------------------------
//void Customer::setfilecustpassword(string filecustpassword)
//{
//	this->filecustpassword = filecustpassword;
//}
////------------------------------------------------------------------------------------------------------------------
//string Customer::getfilecustpassword()
//{
//	return this->filecustpassword;
//}

//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
//void Customer::displayMenu(){
//	
//	cout << "\n********************************************************************************\n" << endl
//		<< "\t\t\t**** Welcome to BMCH kiosk system ****" << endl
//		<< "\n********************************************************************************\n" << endl;
//	cout << "Please select an option to proceed...\n\n\n"
//		"1. Login\n\n"
//		"2. Customer registrations\n\n"
//		"3. View Exhibition event times\n\n"
//		"4. View new and upcoming events\n\n"
//		"9. Exit\n\n\n\n" << endl;
//
//	Reservation Event;// creating an object of reservation class
//	User loginSelect;
//
//
//	while ((option = cin.get()) != EOF){
//		switch (option)
//		{
//		case '1':
//			loginSelect.loginUser();
//			break;
//		case '2':
//			regCustomer();
//			break;
//		case '3':
//				Event.viewEvent();
//			break;
//		case '4':
//			upcomingEvents();
//			break;
//		case '\n': // ignore newlines,
//		case '\t': // tabs,
//		case ' ': // and spaces in input
//			break; // exit switch
//		default: // catch all other characters
//			cout << "Incorrect option entered."
//				<< " Enter a valid choice!." << endl;
//			break;
//		}
//	}
//
//} // end function displayMenu


//------------------------------------------------------------------------------------------------------------------
//customer login logic

void Customer::login(){

	string customer_id;
	string customer_fname;
	string customer_lname;
	string customer_age;
	string customer_contactno;
	string filecustomer_name;
	string filecustomer_password;

	bool login_success = false;

	cout << "\t     *******************| Login |******************"
		<< "\n********************************************************************************";
	cout << "\n\t          Username: ";
	cin >> custInputName;
	cout << "\n\t          Password: ";
	cin >> CustInputPassword;

	ifstream inFile("registration.txt", ios::in);
	if (inFile.fail()) {
		cerr << "File cannot be opened!";
	}


		while (true) {
			inFile >> customer_id;
			
			if (inFile.eof()) {
				break;
			}
			inFile >> customer_fname >> customer_lname >> customer_age >> customer_contactno >> filecustomer_name >> filecustomer_password;
			//setting the values
			this->setId(customer_id);
			this->setFirstName(customer_fname);
			this->setLastName(customer_lname);
			this->setAge(customer_age);
			this->setMobileNumber(customer_contactno);
			this->setUsername(filecustomer_name);
			this->setPassword(filecustomer_password);
			//checks user input with data in FIle
			if (custInputName == getUsername() && CustInputPassword == getPassword()) {
				login_success = true;
				system("CLS");
				RegCustMenu();
				break;
			}
			
		}//end of while	

		if (!login_success)
		{
			system("CLS");
			cout << "\n                                -***-                                   \n";
			cout << "    Invalid login details. Please enter the correct details and try again.\n";
			cout << "                                -***-                                   \n";
			cout << "\n\n";
			login();
			
		}

		inFile.close();
		system("pause>null");
}//end of login method
//------------------------------------------------------------------------------------------------------------------
//customer registration logic

void Customer::regCustomer(){
	
	cout << "\n";
	cout << "\t*****************| New user registration window |****************"
		<< "\n********************************************************************************";

		try {

			ofstream outFile;
			outFile.open("registration.txt", ios::app);
			

			if (!outFile) {
				cout << "\n                                -***-                                   \n";
				cerr << "\t  Error : There was an error in opening the file.\n";
				cout << "                                -***-                                   \n";
				exit(1);// terminate due to an error
			}
			else {
				string IdNum;
				IdNum = to_string(this->generateCustomerID());// converting the int ID to string
				
				cout << "\n\t          Your customer ID: " << IdNum <<endl;
				cout << "\n\t          Enter your first name: ";
				cin >> custfname;
				cout << "\n\t          Enter your last name: ";
				cin >> custlname;
				cout << "\n\t          Enter your Age: ";
				while (!(cin >> custage)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');//restricting non numeric values
					cout << "\n\t          Invalid input!";
					cout << "\n\t          Try entering age again: ";
				}
				cout << "\n\t          Enter your contact number: ";
				cin >> custcontactno;
				cout << "\n\t          Enter a Username for your future proceedings: ";
				cin >>filecustname;
				cout << "\n\t          Enter a password for your future proceedings: ";
				cin >> filecustpassword;

				validateCustomer();

				outFile << IdNum <<'\t'<< custfname << '\t'<< custlname << '\t' << custage << '\t' << custcontactno << '\t' << filecustname << '\t' << filecustpassword << endl;
				cout << "\n";
				outFile.close();
			}

			cout << "\n    Congratulation!! " << custfname << " you have successfully registered to the system!\n";

			cout << "\n\t          Press ENTER to login" << endl;
			system("pause>null");
			system("cls");
			return login();
			
		}
		catch (exception ex) {
			cout << "\n                                -***-                                   \n";
			cout << "\t  Error : Your registration was unsucessful please try again.\n";
			cout << "                                -***-                                   \n";
		}
		
}
//------------------------------------------------------------------------------------------------------------------
//checking if the customer already exists
void Customer::validateCustomer() {
	string customerV_id;
	string customerV_fname;
	string customerV_lname;
	string customerV_age;
	string customerV_contactno;
	string filecustomerV_name;
	string filecustomerV_password;

	bool validation_success = false;

	ifstream inValFile("registration.txt", ios::in);
	if (inValFile.fail()) {
		cerr << "File cannot be opened!";
	}


	while (true) {
		inValFile >> customerV_id;

		if (inValFile.eof()) {
			break;
		}
		inValFile >> customerV_fname >> customerV_lname >> customerV_age >> customerV_contactno >> filecustomerV_name >> filecustomerV_password;

		//setting the values
		this->setId(customerV_id);
		this->setFirstName(customerV_fname);
		this->setLastName(customerV_lname);
		this->setAge(customerV_age);
		this->setMobileNumber(customerV_contactno);
		this->setUsername(filecustomerV_name);
		this->setPassword(filecustomerV_password);

		if (custfname == getFirstName() && custcontactno == getMobileNumber()) {
			validation_success = true;
			cout << "";
			system("CLS");
			cout << "\n\n";
			cout << "*** "<<custfname<<", You are already a customer in our system. Try logging in directly ***";
			cout << "\n\n";
			login();
			break;
		}
	}//end of while

	inValFile.close();
}

//------------------------------------------------------------------------------------------------------------------
//menu for a registered customer
void Customer::RegCustMenu(){

		cout << "\n";
		cout << "\t*******************| Registered customer menu |******************"
			<< "\n********************************************************************************";
		cout << "\n\t          Select an option...";
		cout << "\n";
		cout << "\n\t               1. Hall reservation                                                 ";
		cout << "\n\t               2. View  hall plan                                                  ";
		cout << "\n\t               3. Ticket purchases                                                  ";
		cout << "\n\t               4. Cancel a hall reservation                                        ";
		cout << "\n\t               5. Generate purchased ticket                                       ";
		cout << "\n\t               6. Back                                                 ";
		cout << "\n";
		cin >> option;
	
	//while ((option = cin.get()) != EOF)
	//{
		switch (option)
		{
		case 1:
			system("CLS");
			event ->hallReservation();
			break;
		case 2:
			system("CLS");
			cout << "\n";
			cout << "\t      *******************| Hall Plan |******************"
				<< "\n********************************************************************************";
			hal->hallPlan();
		
			cout << "\n\t      Press ENTER to go back to the menu";
			system("pause>null");
			system("cls");
			return 	RegCustMenu();
			break;
		case 3:
			system("CLS");
			cout << "\n";
			cout << "          *******************| Ticket Purchases |******************"
				<< "\n********************************************************************************";
			cout << "";
			event->ticketPurchase();
			break;
		case 4:
			system("CLS");
			cout << "\n";
			cout << "       *******************| Cancel Hall Reservations |******************"
				<< "\n********************************************************************************";
			event->cancelHallReservations();
			break;
		case 5:
			system("CLS");
			tickets->generateTicket();
			break;
		case 6:
			system("CLS");
			userDisplay();
			cout << "";
			break;
			
		default:
			system("CLS");
			cout << "\n                                -***-                                   \n";
			cout << "\t  Error : Incorrect option entered. Enter a valid choice!.\n";
			cout << "                                -***-                                   \n";
			cout << "";
			return RegCustMenu();
			break;
		}
	/*}*/

}
//------------------------------------------------------------------------------------------------------------------
//creating an object to read view events from Event class
void Customer::viewAllEvents(){
	cout << "\n";
	cout << "\t    *******************| Events Window |******************"
		<< "\n********************************************************************************";
	cout << "\n";
	event->viewEvent();

}
//------------------------------------------------------------------------------------------------------------------
//creating an object to read view upcoming from Event
void Customer::upcomingEvents()
{
	cout << "\n";
	cout << "\t    *******************| Upcoming Events |******************"
		<< "\n********************************************************************************";
	cout << "\n";
	event->viewupcomingEvents();
}

//------------------------------------------------------------------------------------------------------------------
//generating a customer ID
int Customer::generateCustomerID() {
	/*srand(time(NULL));
	int ID = rand() % 100;*/

	srand((unsigned)time(0));//using srand to avoid the same number repeating
	int random_integer;
	int lowest = 10, highest = 1000;
	int range = (highest - lowest) + 1;
	for (int index = 0; index < 20; index++) {
		random_integer = lowest + int(range*rand() / (RAND_MAX + 1.0));
		
	}
	
	return random_integer;
}
//------------------------------------------------------------------------------------------------------------------

void Customer::customer_Event() {

	ofstream outFile;
	outFile.open("Customer_EventDetails.txt", ios::app);

	if (!outFile) {
		cout << "\n                                -***-                                   \n";
		cerr << "\t  Error : There was an error in opening the file.\n";
		cout << "                                -***-                                   \n";
		exit(1);// terminate due to an error
	}

}