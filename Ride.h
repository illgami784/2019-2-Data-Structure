#pragma once

#include "queue1.h"
//#include "User.h"
#include "DoublySortedLinkedList.h"
#include "Stack.h"
#include "Admin.h"
#include "Queue.h"

class Admin;

class Ride{
public:

	/**
	*	@brief	�⺻ ������ �Դϴ�.
	*	@post	id, requireTime, minAge, minTicketRank�� �Է¹޾� ����
	id�� Admin�� RideList�� ���̿� ���� ������, watingTime 0���� �ʱ�ȭ
	*/
	Ride();

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
	bool addWaitingUser(User user);

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

	int getWaitingTime(){
		return watingTime;
	}

private:
	int id; //���� ��ȣ RideList�� ���̿� ���� ������
	int requireTime; //���̱ⱸ�� �ѹ��� �۵��ϴµ� �ɸ��� �ð�(�� ����)
	int numPerRide; //�� ���� ���̱ⱸ��  Ż �� �ִ� User ��
	int watingTime; //���� ��� �ð�(�� ����)
	int minAge; //�� Ride�� Ÿ�� ���� �ּ� ���� (0~100)
	int minTicketRank; //�� Ride�� Ÿ�� ���� �ּ� Ƽ�� ��� (0~10)
	int totalUser; //�����ϰ� ž���� �� User ��
	bool isOpen; //���� ���θ� ��Ÿ��, rideUser ���� ������ ���� ���� ���


	DoublySortedLinkedList<Ride>* rideListPointer; //�ڽ��� ��� rideList�� ���� �ּҸ� ������.
	Stack<User*> ridingUser; //���� ž�� ���� User�� ��� Stack
	Queue<User*> waitingUser; //��ٸ��� User���� ��� Queue - ���� heap����

};
bool Ride::rideUser() {//requireTime���� ����
	User* user;
	for (int i = 0; i < numPerRide; i++) {
		user = ridingUser.Pop();
		user->moveToUser();
		waitingUser.dequeue(user);
		ridingUser.Push(user);
	}//�ϴ� �̷��� �ϰ� ���߿� waitingUser�� numperRide ���� ������ (waitingUser�� Null�ϋ� ����ó��)
	calcWaitingTime();
	Sleep(requireTime);
	callback();


}

//bool Ride::moveToUser(User* user) {
//	int min = 100000000000;
//	int cur;
//	user->wantToRide.ResetList();
//	for(int i = 0; i < user->wantToRide.GetLength(); i++){
//		user->wantToRide.GetNextItem(cur);
//		Ride test;
//		test.setId(cur);
//		Admin::rideList.Get(test);
//		if(min>test.getWaitingTime()){
//			min = test.getWaitingTime();
//			user->setNowLocation(cur);
//		}
//	}
//	calcWaitingTime();
//}

bool Ride::calcWaitingTime() {
	watingTime = (waitingUser.getLength() / numPerRide) * requireTime;
}


Ride::Ride()
{
	ridingUser.setMax(numPerRide);
}

void Ride::setId(int _id)
{
	this->id = _id;
}

void Ride::setMinAge(int minAge) {
	Ride::minAge = minAge;
}
