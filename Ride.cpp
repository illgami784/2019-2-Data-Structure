#pragma once
#include "Ride.h"
#include "User.h"

bool Ride::rideUser() {//requireTime���� ����
	// if numPerRide is more than waitingUser
	if (numWaitingUser < numPerRide) {
		for (int i = 0; i < numWaitingUser; i++) {
			User* user = ridingUser.Pop();//���࿡ rideUser�� null�̸�?? ó���ʿ�!
			moveToUser(user);
			waitingUser.dequeue(user);
			ridingUser.Push(user);
			totalUser++;//�̿밴 �� +1 
		}
		numWaitingUser = 0;
	}
	// if numPerRide is less than waitingUser
	else {
		for (int i = 0; i < numPerRide; i++) {
			User* user = ridingUser.Pop();//���࿡ rideUser�� null�̸�?? ó���ʿ�!
			moveToUser(user);
			waitingUser.dequeue(user);
			ridingUser.Push(user);
			totalUser++;//�̿밴 �� +1 
		}
		numWaitingUser -= numPerRide;
	}
	calcWaitingTime();
	Sleep(requireTime);
	return true;
}

bool Ride::moveToUser(User* user) {
	int min = 100000;
	int cur;
	user->wantToRide.ResetList();

	for (int i = 0; i < user->wantToRide.GetLength(); i++) {
		user->wantToRide.GetNextItem(cur);
		Ride test;
		test.setId(cur);
		rideListPointer->Get(test);
		if (min > test.getWaitingTime()) {
			min = test.getWaitingTime();
			user->setNowLocation(cur);
		}
	}
	calcWaitingTime();
	return true;
}

Ride::Ride() {
	id = -1;
	requireTime = 0; //���̱ⱸ�� �ѹ��� �۵��ϴµ� �ɸ��� �ð�(�� ����)
	numPerRide = 0; //�� ���� ���̱ⱸ��  Ż �� �ִ� User ��
	watingTime = 0; //���� ��� �ð�(�� ����)
	minAge = 0; //�� Ride�� Ÿ�� ���� �ּ� ���� (0~100)
	totalUser = 0; //�����ϰ� ž���� �� User ��
	numWaitingUser = 0; //���� ��ٸ��� �ִ� ����� ��
	isOpen = 0; //false
	ridingUser.setMax(numPerRide);
	rideListPointer = NULL;

}

bool Ride::calcWaitingTime() {
	watingTime = (numWaitingUser / numPerRide) * requireTime;

	if (watingTime > maxWatingTime) {
		maxWatingTime = watingTime;
	}
	if (numWaitingUser > maxNumWaitingUser) {
		maxNumWaitingUser = numWaitingUser;
	}
	return true;
}

void Ride::setId(int _id)
{
	this->id = _id;
}

void Ride::setMinAge(int minAge) {
	Ride::minAge = minAge;
}

bool Ride::addWaitingUser(User& user) {
	numWaitingUser++;
	waitingUser.enqueue(&user); //add User in the waitinglist

	return true;
}

void Ride::printInfo() const {
	cout << "\n\tid : " << id;
	cout << "\n\trequire time : " << requireTime;
	cout << "\n\tnum of seats : " << numPerRide;
	cout << "\n\tmin age : " << minAge << endl;
}

bool Ride::run() {
	totalUser = 0;
	isOpen = true;
	maxNumWaitingUser = 0;
	maxWatingTime = 0;
	while (true)
	{
		rideUser();
	}
}

bool Ride::stop() {
	numWaitingUser = 0;
	isOpen = false;
	watingTime = 0;
	ridingUser.Empty();
	waitingUser.MakeEmpty();
	return true;
}

Ride::Ride(const Ride& ride) {
	this->id = ride.id;
	this->requireTime = ride.requireTime;
	this->minAge = ride.minAge;
	this->numPerRide = ride.numPerRide;
	this->totalUser = ride.totalUser;
	this->isOpen = ride.isOpen;
	this->rideListPointer = ride.rideListPointer;
	this->maxNumWaitingUser = ride.maxNumWaitingUser;
	this->maxWatingTime = ride.maxWatingTime;
}

void Ride::setAllFromKB() {
	// requireTime, minAge�� Ű����κ��� �Է� �޾� ����.
	while (1) {
		cout << "\n\tSet the requireTime(second) of Ride : ";
		cin >> requireTime;
		cout << "\n\tSet the minAge(0-100) of Ride : ";
		cin >> minAge;
		cout << "\n\tSet the num of People per of Ride :";
		cin >> numPerRide;
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

void Ride::setRideListPointer(DoublySortedLinkedList<Ride>* _rideListPointer)
{
	rideListPointer = _rideListPointer;
}

int Ride::getWaitingTime() {
	return watingTime;
}

int Ride::getId() {
	return id;
}

liveInfo Ride::getLiveInfo() {
	liveInfo print;
	print.info = id;
	print.numWatingUser = numWaitingUser;
	print.watingtime = watingTime;

	return print;
}

liveInfo Ride::printStat() {
	liveInfo print;
	print.info = id;
	print.totalUser = totalUser;
	print.watingtime = maxWatingTime;
	print.numWatingUser = maxNumWaitingUser;

	return print;
}


bool Ride::operator<(const Ride& rhs) const {
	return id < rhs.id;
}

bool Ride::operator==(const Ride& rhs) const {
	return id == rhs.id;
}

bool Ride::operator!=(const Ride& rhs) const {
	return !(rhs == *this);
}

bool Ride::operator>(const Ride& rhs) const {
	return rhs < *this;
}

bool Ride::operator<=(const Ride& rhs) const {
	return !(rhs < *this);
}

bool Ride::operator>=(const Ride& rhs) const {
	return !(*this < rhs);
}


Ride& Ride::operator=(const Ride& rhs) {
	this->id = rhs.id;
	this->requireTime = rhs.requireTime;
	this->minAge = rhs.minAge;
	this->numPerRide = rhs.numPerRide;
	this->totalUser = rhs.totalUser;
	return *this;
}

