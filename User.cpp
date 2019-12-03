#include "User.h"



User::User()
{
	id = count;
	ticketRank = rand() % 5;
	age = rand() % 40 +10;
	nowLocation = 0;
	count++;
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
	nowLocation = _location;
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

bool User::moveToUser() {
	int min = 100000000000;
	int cur;
	if(wantToRide.GetLength()==0){
		setNowLocation(-1);
		return false;
	}
	wantToRide.ResetList();
	for(int i = 0; i < wantToRide.GetLength(); i++){
		wantToRide.GetNextItem(cur);
		Ride test;
		test.setId(cur);
		auto ride = Admin::rideListPointer();
		ride->Get(test);
		if (min > test.getWaitingTime()) {
			min = test.getWaitingTime();
			setNowLocation(cur);
		}
	}
	return true;
}