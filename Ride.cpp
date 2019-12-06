#include "User.h"
#include "Ride.h"
#include <iostream>

using namespace std;


void Ride::setAllFromKB() {
	// requireTime, minAge을 키보드로부터 입력 받아 설정.
	while (1) {
		cout << "\n\tSet the requireTime(second) of Ride : ";
		cin >> requireTime;
		cout << "\n\tSet the minAge(0-100) of Ride : ";
		cin >> minAge;
		if (minAge >= 0 && minAge <= 100)
			break;
		else
			cout << "\n\t Interval Wrong! Please try again";
	}

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
