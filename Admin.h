#pragma once

#include "User.h"
#include "Ride.h"
#include "DoublySortedLinkedList.h"
#include "CircularQueue.h"
#include "SortedList.h"
#include <thread>
#include <vector>
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
	*	@brief	user�� ���� ��ġ�� ���� �ش��ϴ� Ride�� �̵���Ŵ
	*	@pre	user�� nowLocation�� ����Ǿ���
	*	@post	�ش� Ride�� watingUser�� user �߰�
	*	@return	������ true ���н� false
	*/
	bool moveUser(User &user);

	/**
	*	@brief	user�� wantToRide�� �� Ride���� watingTime�� Ȯ���ؼ�
	user�� ���� �������� �������ش�.
	*	@pre	user�� wantToRide�� ������� �ʾƾ���
	*	@post	moveUser�� ȣ��Ǹ� user�� setNowLocation ȣ���� �� ����
	*	@return	������ true, ���н� false
	*/
	bool nextRide(User &user);

	/**
	*	@brief	rideList�� ride�� �߰��Ѵ�.
	*	@pre	ride�� ���� ä�����־����
	*	@post	rideList�� ���� ride �߰�.
	*	@return	������ true ���н� false
	*/
	bool addRide(Ride& ride);

	/**
	*	@brief	rideList�� ride�� �����Ѵ�.
	*	@pre	rideList�� �ش� id�� ���̱ⱸ�� �����ؾ��Ѵ�.
	*	@post	rideList���� �ش� id�� ���̱ⱸ ����
	*	@return	������ true ���н� false
	*/
	bool deleteRide(int _id);
	/**
    *   @brief   rideList pointer ��ȯ
    *   @return rideList pointer
   */
	static DoublySortedLinkedList<Ride>* rideListPointer()
	{
		return &rideList;
	}
	void run(){
		DoublyIterator<Ride> itor(rideList);
		vector<thread> run;
		thread temp;
		while(itor.NotNull()){
			run.push_back(thread(itor.GetCurrentNode().data.rideUser()));
			itor.Next();
		}


	}

private:
	static DoublySortedLinkedList<Ride> rideList;
	int numOfEnterUser; //���� �� ������ User�� ��
	int maxUser; //�ִ� ���� ���� User ��
	int lenRideList; //rideList�� ���� = ride ����
	CircularQueue<User> waitingEnterUser; //userList�� �� �� ������ ���� User
	//Ride�� ��� list
	SortedList<User> userList; //User�� ��� list
	User* p_U;
};

Admin::Admin()
{
	numOfEnterUser = 0;
	maxUser = 100; //maxUser ����
	lenRideList = 0;
}

bool Admin::addRide(Ride& ride)
{
	if (rideList.Add(ride))
		return 1;
	return 0;
}

bool Admin::deleteRide(int _id)
{
	Ride temp;
	temp.setId(_id);
	if (rideList.Get(temp))
	{
		rideList.Delete(temp);
		return 1;
	}
	return 0;
}

