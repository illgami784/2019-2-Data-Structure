#pragma once

#include "User.h"
#include "Ride.h"
#include "DoublySortedLinkedList.h"
#include "SortedList.h"
#include <vector>
#include <iostream>
#include "Queue.h"
#include <chrono>
using namespace std;

class Ride;
class User;


class Admin {
public:

	/**
	*	@brief	�⺻ �������Դϴ�
	*	@post	maxUser�� �Է°����� ����, UserList�� ���̸� maxUser��
	ũ��� ����, numOfEnterUser = 0
	*/
	Admin();

	/**
	*	@brief	�⺻ �Ҹ����Դϴ�.
	*	@post
	*/
	~Admin() = default;

	/**
	*	@brief	Ư�� �ð����� ����Ǹ� ���ο� User�� ����� �Լ�.
	*	@pre	userList�� full�� �ƴϿ����� full�Ͻ� watingEnterUser�� User�� ����
	*	@post	userList�� full�� �ƴϸ� numOfEnterUser++
	���ο� User �߰� numOfEntterUser�� id�� �������ش�. ���� nextRide�� ȣ��.
	*	@return	������ true, ���н� false
	*/
	bool newUser();


	/**
	*	@brief	user�� wantToRide�� �� Ride���� watingTime�� Ȯ���ؼ�
	user�� ���� �������� �������ش�.
	*	@pre	user�� wantToRide�� ������� �ʾƾ���
	*	@post	user�� setNowLocation ȣ���� �� ����
	*	@return	������ true, ���н� false
	*/
	bool nextRide(User*& user);


	/**
	*	@brief	rideList�� ride�� �߰��Ѵ�.
	*	@pre	ride�� ���� ä�����־����
	*	@post	rideList�� ���� ride �߰�.
	*	@return	������ true ���н� false
	*/
	bool insertRide(Ride& ride);

	/**
	*	@brief	rideList�� ride�� �����Ѵ�.
	*	@pre	rideList�� �ش� id�� ���̱ⱸ�� �����ؾ��Ѵ�.
	*	@post	rideList���� �ش� id�� ���̱ⱸ ����
	*	@return	������ true ���н� false
	*/
	bool removeRide(int _id);

	/**
	*	@brief	id�� �޾� RideList���� ���� ������ ride�� ��ȯ
	*	@return	������ RideList�� ��ü�� value�� ��ȯ
	*/
	Ride searchRide(int idx);


	/**
	*	@brief	RideList�� ���� ���
	*/
	void PrintRideAll();


	/**
	*	@brief	id�� �޾� userList���� ���� ������ user�� ��ȯ
	*	@return	������ user�� ��ü�� value�� ��ȯ
	*/
	User searchUser(int idx);
	/**
	*	@brief	rideList�� length ��ȯ
	*	@return	rideList�� length ��ȯ
	*/
	int getRideLength();

	/**
	*   @brief   rideList pointer ��ȯ
	*   @return rideList pointer
   */
	DoublySortedLinkedList<Ride>* rideListPointer();

	void setRun();
	void run(int tick);
	void runDelete();
	
	void setMaxUser(int _num);

	int getNumOfEnterUser();

private:
	DoublySortedLinkedList<Ride> rideList;
	int numOfEnterUser; //���� �� ������ User�� ��
	int maxUser; //�ִ� ���� ���� User ��
	int lenRideList; //rideList�� ���� = ride ����
	Queue<User*> waitingEnterUser; //userList�� �� �� ������ ���� User
	//Ride�� ��� list
	SortedList<User*> userList; //User�� ��� list
};
