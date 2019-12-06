#include "User.h"
#include "Ride.h"
#include <iostream>

using namespace std;


void Ride::setAllFromKB() {
	//id, requireTime, minAge, minticketRank을 키보드로부터 입력 받아 설정.
	cout << "\tSet the id of Ride : ";
	cin >> id;
	cout << "\tSet the requireTime(second) of Ride : ";
	cin >> requireTime;
	cout << "\tSet the minAge(0-100) of Ride : ";
	cin >> minAge;

	cout << "\n\tThe Setup completed.\n";
}

int Ride::getMinAge() const {
	return minAge;
}

bool Ride::operator<(const Ride &rhs) const {
	return id < rhs.id;
}

bool Ride::operator==(const Ride &rhs) const {
	return id == rhs.id;
}

bool Ride::operator!=(const Ride &rhs) const {
	return !(rhs == *this);
}

bool Ride::operator>(const Ride &rhs) const {
	return rhs < *this;
}

bool Ride::operator<=(const Ride &rhs) const {
	return !(rhs < *this);
}

bool Ride::operator>=(const Ride &rhs) const {
	return !(*this < rhs);
}
