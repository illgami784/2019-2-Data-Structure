#pragma once
#include "User.h"
#include "Ride.h"

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
	~Admin();

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
	bool addRide(Ride ride);

	/**
	*	@brief	rideList�� ride�� �����Ѵ�.
	*	@pre	rideList�� �ش� id�� ���̱ⱸ�� �����ؾ��Ѵ�.
	*	@post	rideList���� �ش� id�� ���̱ⱸ ����
	*	@return	������ true ���н� false
	*/
	bool deleteRide(int _id);

private:
	int numOfEnterUser; //���� �� ������ User�� ��
	int maxUser; //�ִ� ���� ���� User ��
	int lenRideList; //rideList�� ���� = ride ����
	LinkedQueue waitingEnterUser; //userList�� �� �� ������ ���� User
	LinkedList rideList; //Ride�� ��� list
	SortedList userList; //User�� ��� list
};