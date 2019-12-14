#pragma once
#include "Ride.h"
#include "User.h"

bool Ride::rideUser() {//requireTime마다 실행
	// if numPerRide is more than waitingUser
	int length = ridingUser.GetLength()-1;
	for (length; length > 0; length--)
	{
		User* user = ridingUser.Pop();
		moveToUser(user);
	}

	int num = 0;
	for (num; num < numWaitingUser ; num++) {
		if (num > numPerRide - 1) break;
		User* user = new User;
		waitingUser.dequeue(user);
		ridingUser.Push(user);
		totalUser++;
	}
	numWaitingUser -= num;

	calcWaitingTime();
	Sleep(requireTime);
	return true;
}

bool Ride::moveToUser(User*& user) {
	int temp;
	if (rideListPointer->GetLength() == 0)
	{
		user->setNowLocation(-2);
		return 0;
	}
	DoublyIterator<Ride> itor(*rideListPointer);
	DoublyNodeType<Ride>* tp = NULL;
	int idx = 0;
	int min = 100000;
	itor.Next();
	while (itor.NextNotNull())
	{
		user->WantToRidePointer()->ResetList();
		user->WantToRidePointer()->GetNextItem(temp);
		for (int i = 0; i < user->WantToRidePointer()->GetLength(); i++)
		{
			if (itor.GetCurrentNode().data.getId() == temp)
			{
				itor.GetCurrentNodePointer()->data.calcWaitingTime();
				if (itor.GetCurrentNode().data.getWaitingTime() < min)
				{
					min = itor.GetCurrentNode().data.getWaitingTime();
					idx = itor.GetCurrentNode().data.getId();
					tp = itor.GetCurrentNodePointer();
				}
			}

			user->WantToRidePointer()->GetNextItem(temp);
		}
		itor.Next();
	}
	user->setNowLocation(idx);
	if (tp != NULL)
		tp->data.addWaitingUser(user);
	tp = NULL;
	delete tp;
	return 1;
}

Ride::Ride() {
	id = -1;
	requireTime = 0; //놀이기구를 한번에 작동하는데 걸리는 시간(초 단위)
	numPerRide = 0; //한 번에 놀이기구를  탈 수 있는 User 수
	watingTime = 0; //예상 대기 시간(초 단위)
	minAge = 0; //이 Ride를 타기 위한 최소 나이 (0~100)
	totalUser = 0; //개장하고 탑승한 총 User 수
	numWaitingUser = 0; //지금 기다리고 있는 사람의 수
	isOpen = 0; //false
	ridingUser.setMax(numPerRide);
	rideListPointer = NULL;
	maxNumWaitingUser = numPerRide * 50;
	maxWatingTime = watingTime * 50;
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

bool Ride::addWaitingUser(User*& user) {
	numWaitingUser++;
	waitingUser.enqueue(user); //add User in the waitinglist
	calcWaitingTime();
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
	return true;
	
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
	this->numWaitingUser = ride.numWaitingUser;
	this->ridingUser = ride.ridingUser;
	this->waitingUser = ride.waitingUser;
	this->watingTime = ride.watingTime;
}

void Ride::setAllFromKB() {
	// requireTime, minAge을 키보드로부터 입력 받아 설정.
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
	ridingUser.setMax(numPerRide);
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
	print.totalUser = totalUser;
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

int Ride::getRequireTime() {
	return requireTime;
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
	this->isOpen = rhs.isOpen;
	this->rideListPointer = rhs.rideListPointer;
	this->maxNumWaitingUser = rhs.maxNumWaitingUser;
	this->maxWatingTime = rhs.maxWatingTime;
	this->numWaitingUser = rhs.numWaitingUser;
	this->ridingUser = rhs.ridingUser;
	this->waitingUser = rhs.waitingUser;
	this->watingTime = rhs.watingTime;
	return *this;
}

void Ride::increwatinguser()
{
	numWaitingUser++;
}
