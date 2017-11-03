#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Event
{

public:
	Event();
	~Event();
	void setCustName(string custName);
	string getCustName();
	void setHallType(string hallType);
	string getHallType();
	void setEventID(string eventID);
	string getEventID();
	void setEventName(string eventName);
	string getEventName();
	void setEventMonth(int eventmonth);
	int getEventMonth();
	void setEventDate(int eventDate);
	int getEventDate();
	void setEventYear(int eventYear);
	int getEventYear();
	void setEventStartTime(string eventStartTime);
	string getEventStartTime();
	void setEventEndTime(string eventEndTime);
	string getEventEndTime();
	void setEventTicketPrice(int eventTicketprice);
	int getEventTicketPrice();
	void setNoOFTickets(int noOfTickets);
	int getNoOFTickets();
	void viewupcomingEvents();
	void addEvent();	
	void viewEvent();
	void hallReservation();
	int generateID();
	void cancelHallReservations();
	void reservationRelatedtoCust();
	void ticketPurchase();
	void secondaryMenu();
	void dateValidation(int, int, int);
	void timeValidation(string , string);
	//vector<string> split(const string & str);
	vector<string> split(const string & s, char delim);
	bool validateEventid(string eventId);

	//creating variables to hold data of AddEvent 
	string Eventid, title, hall, Eventstarttime, Eventendtime;
	int month, date, year, price, Eventticketnos;

	//creating variables to hold data of Registration 
	string firstname, lastname, customerid, customerage, customercontactno, filecustomerame;
	string filecustomerpassword;

	//creating variables to hold data of ticketPurchase 
	string reference, tname, peventid, cardtype, cardnumber;
	int noticket,emonth, edate, eyear;

	int option1=0;
	string	HREvent_custName;
	int HReventMonth;
	int HReventDate;
	int HReventYear;

private:
	string custName,hallType,eventCustName, eventID, eventName,eventStarTime,eventEndTime;
	int eventTicketPrice, noOfTickets;
	int eventMonth;
	int eventYear;
	int eventDate;
	


};

