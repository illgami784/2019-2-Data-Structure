#include "User.h"

User::User()
{
	id = -1;
	ticketRank = -1;
	age = -1;
	nowLocation = -1;
}

User::User(int numOfEnterPeople, UnsortedList<Ride> *RideList)
{
	id = numOfEnterPeople;
	ticketRank = rand() % 10;
	age = rand() % 100;
	nowLocation = -1;
};

bool User::WantToRide()
{
	return false;
}

void User::printInfo() const
{
	cout << "\nID : " << id << "\tTicketRank : " << ticketRank 
		<< "\tAge : " << age << "\tNowLocation : " << nowLocation;
}

bool User::setAge(int _age)
{
	age = _age;
	return true;
}

bool User::setID()
{
	return false;
}

bool User::setNowLocation(int _location)
{
	wantToRide.Delete(_location);
	hadRide.Push(_location);
}


int User::getAge() const
{
	return age;
}

int User::getId() const
{
	return id;
}


int User::getNowLocation() const
{
	return nowLocation;
}