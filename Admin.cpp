#include "Admin.h"
#include <chrono>


Admin::Admin()
{
	numOfEnterUser = 0;
	maxUser = 100; //maxUser ¹ÌÁ¤
	lenRideList = 0;
	//userList.setMax(100);
}

bool Admin::insertRide(Ride& ride)
{
	ride.setId(lenRideList);
	lenRideList++;
	ride.setRideListPointer(&rideList);
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
int Admin:: getRideLength()
{
	return rideListPointer()->GetLength();
}

User Admin:: searchUser(int idx)
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

void Admin::PrintRideAll()
{
	DoublyIterator<Ride> itor(*rideListPointer());
	itor.Next();
	while (itor.NextNotNull())
	{
		itor.GetCurrentNode().data.printInfo();
		itor.Next();
	}
}
Ride Admin:: searchRide(int idx)
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
bool Admin::nextRide(User& user)
{
	int temp;
	DoublyIterator<Ride> itor(*rideListPointer());
	int idx = 0;
	int min = 100000;
	itor.Next();
	while (itor.NextNotNull())
	{
		user.WantToRidePointer()->ResetList();
		user.WantToRidePointer()->GetNextItem(temp);
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
	srand((unsigned int) time(NULL));
	int time = rand() % 500 + 100;
	return 1;
}
DoublySortedLinkedList<Ride>* Admin::rideListPointer()
{
	return &rideList;
}

void Admin::run(int  tick) {
	DoublyIterator<Ride> itor(rideList);
	itor.Next();
	while (itor.NextNotNull()) {
		if ((tick / itor.GetCurrentNodePointer()->data.getRequireTime()) == 0)
		{
			itor.GetCurrentNodePointer()->data.rideUser();
		}
		itor.Next();
	}
}

void Admin::setRun() {
	DoublyIterator<Ride> itor(rideList);
	itor.Next();
	while (itor.NextNotNull()) {
		itor.GetCurrentNodePointer()->data.run();
		
		itor.Next();
	}
}

void Admin::runDelete() {

	DoublyIterator<Ride> itor(rideList);
	itor.Next();
	while (itor.NextNotNull())
	{
		itor.GetCurrentNode().data.stop();
		itor.Next();
	}
}

int Admin::getNumOfEnterUser()
{
	return numOfEnterUser;
}