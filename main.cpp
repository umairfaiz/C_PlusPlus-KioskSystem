#include <iostream>
#include <cstring>
#include "Customer.h"
#include "Admin.h"
#include "Event.h"
#include "User.h"


void displayMainMenu();
using namespace std;


int main(){

	displayMainMenu();

	system("pause");
	getchar();
	return 0;
	
			
}
void displayMainMenu() {
	int option;

	/*Customer menu;
	menu.displayMenu();*/

	cout << "\n********************************************************************************"
		<< "\t ***************** Welcome to BMCH kiosk system ******************" 
		<< "\n********************************************************************************";
	cout << "\n              Please select an option to proceed...                        \n";
	cout << "\n\t               1. Login\n\n                                                ";
	cout << "\n\t               2. Registrations\n\n                                        ";
	cout << "\n\t               3. View new and upcoming events\n\n                         ";
	cout << "\n\t               4. View Exhibition event times\n\n                          ";
	cout << "\n\t               9. Exit\n\n                                            ";
	cout << "\n________________________________________________________________________________";
	cout << "\n";
	// creating an objects access relevant classes
	User *user = new User;
	Customer *cust= new Customer;
	

	while ((option = cin.get()) != EOF) {
		
		switch (option) {
		case '1':
			system("CLS");
			user->loginUser();
			break;
		case '2':
			system("CLS");
			user->RegisterUser();
			break;
		case '3':
			system("CLS");
			cust->upcomingEvents();
			cout << "\n\t    Press ENTER to go Back to Main Menu";
			system("pause>null");
			system("CLS");
			main();

			break;
		case '4':
			system("CLS");
			cust->viewAllEvents();
			cout << "\n\t    Press ENTER to go Back to Main Menu";
			system("pause>null");
			system("CLS");
			main();
			
			break;
		case '9':
			system("CLS");
			cout << "\n\n\n\n\n\n\n\n\n\n";
			cout << "******************************************************************************";
			cout << "                ****|Thank you for using our kiosk system|****                ";
			system("pause>null");
			exit(0);

			break;
		case '\n': // ignore newlines,
		case '\t': // tabs,
		case ' ': // and spaces in input
			break; // exit switch
		default: // catch all other characters
			cout << "\n                                -***-                                   \n";
			cout << "\t  Error : Incorrect option entered. Enter a valid choice!.\n";
			cout << "                                -***-                                   \n";
			main();
			break;
		}
		
	}

}