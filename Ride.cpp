#include "User.h"
#include "Ride.h"
#include <iostream>

using namespace std;



void Ride::setAllFromKB() {
	//id, requireTime, minAge, minticketRank�� Ű����κ��� �Է� �޾� ����.
	cout << "\tSet the id of Ride : ";
	cin >> id;
	cout << "\tSet the requireTime(second) of Ride : ";
	cin >> requireTime;
	cout << "\tSet the minAge(0-100) of Ride : ";
	cin >> minAge;
	cout << "\tSet the minTicketRank(0-10) of Ride : ";
	cin >> minTicketRank;

	cout << "\n\tThe Setup completed.\n";
}

int Ride::getMinAge() const {
	return minAge;
}

