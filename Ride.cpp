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