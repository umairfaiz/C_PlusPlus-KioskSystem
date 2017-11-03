#pragma once
#include <iostream>
#include<string>
using namespace std;

class Ticket {
private:

public:
	Ticket();
	~Ticket();
	void generateTicket();

	//creating variables to hold data of AddEvent 
	string EventcustName, Eventid, title, hall, Eventstarttime, Eventendtime;
	int month, date, year, price, Eventticketnos;

	//creating variables to hold data of ticketPurchase 
	string tname, peventid, cardtype, cardnumber;
	int noticket, emonth, edate, eyear, reference;
};
