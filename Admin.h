#pragma once

#include "User.h"
#include "Ride.h"
#include "DoublySortedLinkedList.h"
#include "SortedList.h"
#include <thread>
#include <vector>
#include "Queue.h"

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
	bool nextRide(User& user)
	{
		int temp;
		DoublyIterator<Ride> itor(*rideListPointer());
		int idx;
		int min = 100000;
		itor.Next();
		user.WantToRidePointer()->ResetList();
		user.WantToRidePointer()->GetNextItem(temp);
		while (itor.NextNotNull())
		{
			for (int i = 0; i < user.WantToRidePointer()->GetLength(); i++)
			{
				if (itor.GetCurrentNode().data.getId() == temp)
				{
					if (itor.GetCurrentNode().data.getWaitingTime() < min)
					{
						idx = itor.GetCurrentNode().data.getId();
					}
				}

				user.WantToRidePointer()->GetNextItem(temp);
			}
			itor.Next();
		}
		user.setNowLocation(idx);
		return 1;
	}

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
	Ride searchRide(int idx)
	{
		DoublyIterator<Ride> itor(*rideListPointer());
		itor.Next();
		while (itor.NextNotNull())
		{
			if (itor.GetCurrentNode().data.getId() == idx)
			{
				Ride temp(itor.GetCurrentNodePointer()->data);
				return temp;
			}
			itor.Next();
		}
	}

	/**
	*	@brief	RideList�� ���� ���
	*/
	void PrintRideAll()
	{
		DoublyIterator<Ride> itor(*rideListPointer());
		itor.Next();
		while (itor.NextNotNull())
		{
			itor.GetCurrentNode().data.printInfo();
			itor.Next();
		}
	}

	/**
	*	@brief	id�� �޾� userList���� ���� ������ user�� ��ȯ
	*	@return	������ user�� ��ü�� value�� ��ȯ
	*/
	User searchUser(int idx)
	{
		User temp;
		userList.ResetList();
		for (int i = 0; i < userList.GetLength(); i++)
		{
			userList.GetNextItem(temp);
			if (temp.getId() == idx)
			{
				return temp;
			}
		}
	}
	/**
	*	@brief	rideList�� length ��ȯ
	*	@return	rideList�� length ��ȯ
	*/
	int getRideLength()
	{
		return rideListPointer()->GetLength();
	}

	/**
	*   @brief   rideList pointer ��ȯ
	*   @return rideList pointer
   */
	DoublySortedLinkedList<Ride>* rideListPointer()
	{
		return &rideList;
	}

	void run() {
		DoublyIterator<Ride> itor(rideList);
		runVector = new vector<thread*>;
		thread* temp = new thread;
		while (itor.NotNull()) {
			runVector->push_back(new thread([&]() { itor.GetCurrentNode().data.rideUser();  }));
			itor.Next();
		}

		//run ��ü ����
		for (auto run : *runVector)
		{
			run->detach();
		}

	}
	void runDelete() {
		for (auto elem : *runVector) {
			delete elem;
		}
	}

	int getNumOfEnterUser()
	{
		return numOfEnterUser;
	}

private:
	DoublySortedLinkedList<Ride> rideList;
	int numOfEnterUser; //���� �� ������ User�� ��
	int maxUser; //�ִ� ���� ���� User ��
	int lenRideList; //rideList�� ���� = ride ����
	Queue<User> waitingEnterUser; //userList�� �� �� ������ ���� User
	//Ride�� ��� list
	SortedList<User> userList; //User�� ��� list
	vector<thread*>* runVector;
};

Admin::Admin()
{
	numOfEnterUser = 0;
	maxUser = 100; //maxUser ����
	lenRideList = 0;
	runVector = NULL;
}

bool Admin::insertRide(Ride& ride)
{
	if (rideList.Add(ride))
		return 1;
	return 0;
}

bool Admin::removeRide(int _id)
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

bool Admin::newUser() {
	User user(numOfEnterUser, &rideList);
	if (waitingEnterUser.getLength())
	{
		waitingEnterUser.dequeue(user);
		user.WantToRide();
		nextRide(user);
		userList.Add(user);
	}
	else if (!userList.IsFull()) {
		user.WantToRide();
		nextRide(user);
		userList.Add(user);
	}
	else {
		waitingEnterUser.enqueue(user);
	}
	numOfEnterUser++;
	srand((unsigned int)time(0));
	int time = rand() % 500 + 100;
	Sleep(time);
	return 1;
}
