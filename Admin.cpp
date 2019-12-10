#include "Admin.h"


Admin::Admin()
{
	numOfEnterUser = 0;
	maxUser = 100; //maxUser 미정
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
	int idx;
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
	srand((unsigned int)time(0));
	int time = rand() % 500 + 100;
	Sleep(time);
	return 1;
}
DoublySortedLinkedList<Ride>* Admin::rideListPointer()
{
	return &rideList;
}

void Admin::run() {
	DoublyIterator<Ride> itor(rideList);
	runVector = new vector<thread*>;
	thread* temp = new thread;
	while (itor.NotNull()) {
		runVector->push_back(new thread([&]() { itor.GetCurrentNode().data.rideUser();  }));
		itor.Next();
	}

	//run 전체 실행
	for (auto run : *runVector)
	{
		run->detach();
	}

}
void Admin::runDelete() {
	for (auto elem : *runVector) {
		delete elem;
	}
}

int Admin::getNumOfEnterUser()
{
	return numOfEnterUser;
}