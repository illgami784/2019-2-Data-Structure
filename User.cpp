
#pragma once
#include "User.h"
#include "Ride.h"

User::User()
{
	id = -1;
	age = -1;
	nowLocation = -1;
	wantToRide.setMax(5);
}

User::User(int numOfEnterPeople, DoublySortedLinkedList<Ride>* ride)
{
	id = numOfEnterPeople;
	age = rand() % 40 +10;
	nowLocation = 0;

	rideListPointer = ride;
	wantToRide.setMax(5);
};

User::User(const User& user) {
	this->id = user.id;
	this->age = user.age;
	this->nowLocation = user.nowLocation;
	this->wantToRide = user.wantToRide;
	this->hadRide = user.hadRide;
	this->rideListPointer = user.rideListPointer;
}

//wantToRide 초기화
bool User::WantToRide()
{
	DoublyIterator<Ride> itor(*rideListPointer);
	itor.Next();
	int half;
	while (itor.NextNotNull())
	{
		int Id = itor.GetCurrentNode().data.getId();//놀이기구의 minAge
		int getAge = itor.GetCurrentNode().data.getMinAge();
		if (getAge <= age) {
			half = rand() % 2;
			if (half == 1||half==0)
				wantToRide.Add(Id);
		}
		itor.Next();
	}
	return true;
}

void User::printInfo()
{
	cout << "\n\tID : " << id;
	cout << "\n\tAge : " << age;
	cout << "\n\tNowLocation : " << nowLocation;
	cout << "\n\tWantToRide :";
	wantToRide.Print();
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
	if (_location != -2) {
		wantToRide.Delete(_location);
		hadRide.Push(_location);
	}
	if (wantToRide.GetLength() == 0)
	{
		nowLocation = -2;
	}
	else
		nowLocation = _location;
	return true;
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

User& User::operator=(const User& rhs)  {
	this->id = rhs.id;
	this->age =rhs.age;
	this->nowLocation = rhs.nowLocation;
	this->wantToRide = rhs.wantToRide;

	return *this;
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
