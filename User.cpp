#include "User.h"

User::User()
{
	id = -1;
	ticketRank = -1;
	age = -1;
	nowLocation = -1;
	
	wantToRide.Add(6);
	wantToRide.Add(3);
}

User::User(int numOfEnterPeople)
{
	id = numOfEnterPeople;
	ticketRank = rand() % 5;
	age = rand() % 40 +10;
	nowLocation = 0;
};

//bool User::WantToRide()
//{
//	return false;
//}

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

bool User::operator==(const User &rhs) const {
	return id == rhs.id;
}

bool User::operator<(const User &rhs) const {
	return id < rhs.id;
}

bool User::operator>(const User &rhs) const {
	return rhs < *this;
}

bool User::operator<=(const User &rhs) const {
	return !(rhs < *this);
}

bool User::operator>=(const User &rhs) const {
	return !(*this < rhs);
}

bool User::operator!=(const User &rhs) const {
	return !(rhs == *this);
}

/*bool User::moveToUser() {
	int min = 100000000000;
	int cur;
	wantToRide.ResetList();
	for (int i = 0; i < wantToRide.GetLength(); i++) {
		wantToRide.GetNextItem(cur);
		Ride test;
		test.setId(cur);
		Admin::rideList.Get(test);
		if (min > test.getWaitingTime()) {
			min = test.getWaitingTime();
			setNowLocation(cur);
		}
	}
}*/
