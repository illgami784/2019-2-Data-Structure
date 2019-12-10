#pragma once
//#include "User.h"
#include "DoublySortedLinkedList.h"
#include "Stack.h"
//#include "Admin.h"
#include "Queue.h"
#include <Windows.h>
class User;
class Admin;

struct liveInfo {
	int info;
	int totalUser;
	int numWatingUser;
	int watingtime;
};

class Ride {
public:

	/**
	*	@brief	�⺻ ������ �Դϴ�.
	*	@post	id, requireTime, minAge, minTicketRank�� �Է¹޾� ����
	id�� Admin�� RideList�� ���̿� ���� ������, watingTime 0���� �ʱ�ȭ
	*/
	Ride();

	/*
	copy constructure
	int id; //���� ��ȣ RideList�� ���̿� ���� ������
	int requireTime; //���̱ⱸ�� �ѹ��� �۵��ϴµ� �ɸ��� �ð�(�� ����)
	int numPerRide; //�� ���� ���̱ⱸ��  Ż �� �ִ� User ��
	int watingTime; //���� ��� �ð�(�� ����)
	int minAge; //�� Ride�� Ÿ�� ���� �ּ� ���� (0~100)
	int totalUser; //�����ϰ� ž���� �� User ��
	int numWaitingUser; //���� ��ٸ��� �ִ� ����� ��
	bool isOpen;
	*/
	Ride(const Ride& ride) {
		this->id = ride.id;
		this->requireTime = ride.requireTime;
		this->minAge = ride.minAge;
		this->numPerRide = ride.numPerRide;
		this->totalUser = ride.totalUser;
	}

	/**
	*	@brief	watingTime�� ������. rideUser ������ �������� ȣ��
	*	@pre	requireTime�� numPerRide�� ���� �����ؾ���.
	*	@post	requireTime�� numPerRide,
	watingUser�� ���̸� ���� watingTime �� ����
	*	@return	������ true, ���н� false
	*/
	bool calcWaitingTime();

	/**
	*	@brief	id�� ���� �Ҵ�
	*	@param	������ id ��
	*/
	void setId(int _id);

	/**
	*	@brief	id, requireTime, minAge, minticketRank��
	Ű����κ��� �Է� �޾� ����.
	*	@post	id, requireTime, minAge, minticketRank�� ����
	Ű����� �Է��� ������ ������.
	*/
	void setAllFromKB();

	/**
	*	@brief	�� Ride�� ������ ����մϴ�.
	*/
	void printInfo() const;

	/**
	*	@brief	�Է¹��� User�� watingUser�� �߰���
	*	@post	watingUser�� user�� �߰���.
	*	@return	�����ϸ� true, �����ϸ� false
	*/
	bool addWaitingUser(User& user);

	/**
	*	@brief	���̰����� ����Ǹ� Ride�� �۵���Ű�� �Լ�
	*	@pre	isOpen�� false������.
	*	@post	isOpen�� true�� �ٲٰ� ridePeople�� ���۽�Ŵ(��� ����~)
	*	@return	�̹� �۵� ���ε�(isOpen�� true) ȣ��� false �ƴϸ� true
	*/
	bool run();

	/**
	*	@brief	���̰����� ����Ǹ� Ride�� ���ߴ� �Լ�
	*	@pre	isOepn�� true������.
	*	@post	isOpen�� false�� �ٲٰ� watingPeople�� ridingPeople�� ���.
	*	@return	�̹� ����µ�(isOpen�� false) ȣ��� false �ƴϸ� true
	*/
	bool stop();

	/**
	*	@brief	Ride�� �����ϴ� �Լ�. isOpen�� true��
	requireTime���� ��� �ݺ���.
	*	@pre	isOpen�� true�̸� watingUser�� �����ؾ���.
	*	@post	���� �����ϴ� ridingUser�� User���� outUser�� ȣ���� ��������.
	watingUser���� numPerRide��ŭ User�� �� ridingUser�� �߰���.
	*	@return	����?
	*/
	bool rideUser();

	/**
	*	@brief	Ride�� ž�� �Ϸ��� User�� �ٸ� ������ ������ �Լ�.
	*	@pre	ridingUser�� User�� �����ؾ���
	*	@post	ridingUser�� User�� ���� rideListPointer��
	�̿��� ��ġ �̵������ش�.
	*	@return �� �۵��� true �ƴϸ� false
	*/
	bool outUser();

	int getMinAge() const;

	bool moveToUser(User* user);

	void setMinAge(int minAge);

	void setRideListPointer(DoublySortedLinkedList<Ride>* _rideListPointer)
	{
		rideListPointer = _rideListPointer;
	}

	int getWaitingTime() {
		return watingTime;
	}

	int getId() {
		return id;
	}

	liveInfo getLiveInfo() {
		liveInfo print;
		print.info = id;
		print.numWatingUser = numWaitingUser;
		print.watingtime = watingTime;

		return print;
	}

	liveInfo printStat() {
		liveInfo print;
		print.info = id;
		print.totalUser = totalUser;
		print.watingtime = maxWatingTime;
		print.numWatingUser = maxNumWaitingUser;

		return print;
	}

	bool operator<(const Ride& rhs) const;

	bool operator>(const Ride& rhs) const;

	bool operator<=(const Ride& rhs) const;

	bool operator>=(const Ride& rhs) const;

	bool operator==(const Ride& rhs) const;

	bool operator!=(const Ride& rhs) const;

	Ride& operator=(const Ride& rhs);

	friend class User;


private:
	int id; //���� ��ȣ RideList�� ���̿� ���� ������
	int requireTime; //���̱ⱸ�� �ѹ��� �۵��ϴµ� �ɸ��� �ð�(�� ����)
	int numPerRide; //�� ���� ���̱ⱸ��  Ż �� �ִ� User ��
	int watingTime; //���� ��� �ð�(�� ����)
	int minAge; //�� Ride�� Ÿ�� ���� �ּ� ���� (0~100)
	int totalUser; //�����ϰ� ž���� �� User ��
	int numWaitingUser; //���� ��ٸ��� �ִ� ����� ��
	bool isOpen; //���� ���θ� ��Ÿ��, rideUser ���� ������ ���� ���� ���
	int maxWatingTime;//�Ϸ� �ִ� watingTime
	int maxNumWaitingUser;//�Ϸ� �ִ� ��ٸ����


	DoublySortedLinkedList<Ride>* rideListPointer; //�ڽ��� ��� rideList�� ���� �ּҸ� ������.
	Stack<User*> ridingUser; //���� ž�� ���� User�� ��� Stack
	Queue<User*> waitingUser; //��ٸ��� User���� ��� Queue - ���� heap����

};
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

}

bool Ride::moveToUser(User* user) {
	int min = 100000000000;
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
}

bool Ride::calcWaitingTime() {
	watingTime = (numWaitingUser / numPerRide) * requireTime;

	if (watingTime > maxWatingTime) {
		maxWatingTime = watingTime;
	}
	if (numWaitingUser > maxNumWaitingUser) {
		maxNumWaitingUser = numWaitingUser;
	}
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
	cout << "\n\tid : " << id << endl;
	cout << "\n\trequire time : " << requireTime << endl;
	cout << "\n\tnum of seats : " << numPerRide << endl;
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
}