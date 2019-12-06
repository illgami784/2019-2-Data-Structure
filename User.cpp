#include "User.h"


User::User()
{
	id = -1;
	age = -1;
	nowLocation = -1;
}

User::User(int numOfEnterPeople, DoublySortedLinkedList<Ride>* ride)
{
	id = numOfEnterPeople;
	age = rand() % 40 +10;
	nowLocation = 0;

	rideListPointer = ride;
};

//wantToRide 초기화
bool User::WantToRide()
{
	DoublyIterator<Ride> itor(*rideListPointer);
	itor.Next();
	int half;
	while (itor.NextNotNull())
	{
		int i = itor.GetCurrentNode().data.getMinAge();//놀이기구의 minAge
		if (i <= age) {
			half = rand() % 2;
			if (half == 1)
				wantToRide.Add(i);
		}
		itor.Next();
	}
	return true;
}

void User::printInfo() const
{
	cout << "\n\tID : " << id;
	cout << "\n\tAge : " << age;
	cout << "\n\tNowLocation : " << nowLocation;
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
