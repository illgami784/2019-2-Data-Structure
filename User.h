#pragma once
#include "Stack.h"
#include "UnsortedList.h"
#include <iostream>
#include "Ride.h"
//#include "Admin.h"
using namespace std;

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
	User(int numOfEnterPeople)

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
	void printInfo() const;

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

//	friend void Admin::calcRide(User user);
	UnsortedList<int> wantToRide; //Ÿ�� ���� ���̱ⱸ id�� ��� �迭


private:
	int id; //���� ��ȣ, numOfEnterPeople�� ����
	int ticketRank; //age�� �Բ� Ż �� �ִ� Ride ���� ( ���̿��� ���� )
	int age; //ticketRank�� �Բ� Ż �� �ִ� Ride ����
	int nowLocation; //���� ��ġ�� ���̱ⱸ id, �ʱ� ���� -1, ���̰��� �ٱ��� -2

	UnsortedList<int> wantToRide; //Ÿ�� ���� ���̱ⱸ id�� ��� �迭
	Stack<int> hadRide; //�̹� ž���� ���̱ⱸ�� ��� ����
};