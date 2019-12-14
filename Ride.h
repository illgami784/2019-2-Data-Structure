#pragma once
#include "DoublySortedLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <Windows.h>
#include <iostream>
using namespace std;

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
	Ride(const Ride& ride);

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

	bool moveToUser(User*& user);

	void setMinAge(int minAge);

	void setRideListPointer(DoublySortedLinkedList<Ride>* _rideListPointer);

	int getWaitingTime();

	int getId();

	int getRequireTime();

	liveInfo getLiveInfo();

	liveInfo printStat();

	void increwatinguser();

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
