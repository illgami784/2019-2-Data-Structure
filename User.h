#pragma once
#include "Stack.h"
#include "UnsortedList.h"
#include "DoublySortedLinkedList.h"
#include <iostream>
using namespace std;
class Ride;
class Admin;

class User {
public:

	/**
	*	�⺻ ������ �Դϴ�.
	*/
	User();

	/**
	*	@brief	�������Դϴ�.
	*	@post	ticketRank(0~9), age(0~99)�� �� ���� ����,
	id�� Admin�� numOfEnterPeople�� ����, wantToRide�� ���ǿ� ���� ������.
	������ ���� �ʱ�ȭ�� ����
	*/
	User(int numOfEnterPeople, DoublySortedLinkedList<Ride>* ride);

	/*
	���������
	*/
	User(const User& user);

	/**
	*	@brief	���� �Լ����� �𸣰ھ��~ wantToRide��
	��������� ���� ���θ� �˷��ִ°ǰ�?
	*	@pre
	*	@post
	*	@return
	*/
	bool WantToRide();

	/**
	*	@brief	�� User�� ������ ����մϴ�.
	*/
	void printInfo();

	/**
	*	@brief	age ����
	*	@post	age�� �Է��� ������ ���մϴ�.
	*	@return �����ϸ� true, �����ϸ� false
	*/
	bool setAge(int _age);

	/**
	*	@brief	id ���� - �̰� �ٲٸ� �ȵ��� �ʳ���?
	*	@post	id�� �Է��� ������ ���մϴ�.
	*	@return	�����ϸ� true, �����ϸ� false
	*/
	bool setID();

	/**
	*	@brief	�Է� ���� _location���� User�� ��ġ�� �ű�ϴ�.
	*	@pre	wantToRide�� _location�� ���� �����ؾ� �մϴ�.
	*	@post	wantToRide���� �ش� ���� ã�� ���� �� hadRide�� �ű�ϴ�.
	nowLocation�� �Է��� ������ ����˴ϴ�.
	*	@return	�����ϸ� true, �����ϸ� false
	*/
	bool setNowLocation(int _location);

	/**
	*	@brief	age�� ��ȯ�մϴ�.
	*	@pre	age�� �����ؾ���.
	*	@return	age�� ������.
	*/
	int getAge() const;

	/**
	*	@brief	id�� ��ȯ�մϴ�.
	*	@pre	id�� �����ؾ���.
	*	@return	id�� ������.
	*/
	int getId() const;

	/**
	*	@brief	nowLocation�� ��ȯ�մϴ�.
	*	@pre	nowLocation�� �����ؾ���.
	*	@return	nowLocation�� ������.
	*/
	int getNowLocation() const;

	void setAllFromKB() {

	}

	/*wanted to ride list�� �����͸� ��ȯ*/
	UnsortedList* WantToRidePointer()
	{
		return &wantToRide;
	}
	void setRideListPointer(DoublySortedLinkedList<Ride>* _ridelistpointer)
	{
		rideListPointer = _ridelistpointer;
	}

	friend class Ride;

	bool operator==(const User& rhs) const;

	bool operator!=(const User& rhs) const;

	bool operator<(const User& rhs) const;

	bool operator>(const User& rhs) const;

	bool operator<=(const User& rhs) const;

	bool operator>=(const User& rhs) const;

	User& operator= (const User& rhs);

private:
	int id; //���� ��ȣ, numOfEnterPeople�� ����
	int age; //ticketRank�� �Բ� Ż �� �ִ� Ride ����
	int nowLocation; //���� ��ġ�� ���̱ⱸ id, �ʱ� ���� -1, ���̰��� �ٱ��� -2

	DoublySortedLinkedList<Ride>* rideListPointer;

	UnsortedList wantToRide; //Ÿ�� ���� ���̱ⱸ id�� ��� �迭
	Stack<int> hadRide; //�̹� ž���� ���̱ⱸ�� ��� ����
};
