#pragma once
#include "Admin.h"
#include "test.cpp"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;
class Application {
public:

	/**
	*	@brief	�⺻ �������Դϴ�.
	*	@post	open = false
	*/
	Application();

	/**
	*	@brief	���� ���α׷� ����
	*	@pre	open�� ���� �������־�� �մϴ�.
	*	@post	open���� ���� �ٸ� �޴� ����
	*/
	void run();

	void open();

	int getKey();

	void printLive();

	void close();

	/**
	*	@brief	��ɾ �Է¹޴� �Լ�
	*	@post	m_Command�� �Է��� ���� �ȴ�.
	*	@return	������ true ���н� false
	*/
	bool getOpenCommand();

	/**
	*	@brief	��ɾ �Է¹޴� �Լ�
	*	@post	m_Command�� �Է��� ���� �ȴ�.
	*	@return	������ true ���н� false
	*/
	bool getCloseCommand();

	/**
	*	@brief	open ���θ� �����Ѵ�.
	*	@return	open ����
	*/
	bool isItOpen() const;

	/**
	*	@brief	�� Ride�� �뷫���� ������ ����Ѵ�.
	*	@pre	rideList�� Ride�� �ϳ��� �����ؾ���
	*/
	void printAllRideInfo() const;

	/**
	*	@brief	������� ���� ��ȸ?
	*	@pre
	*	@post
	*	@return	������ true ���н� false
	*/
	bool searchAllUser();

	/**
	*	@brief	rideList���� �˻��Ѵ�.
	*	@pre
	*	@post
	*	@return	������ true ���н� false
	*/
	bool searchRide();

	/**
	*	@brief	rideList�� Ride�� �߰��Ѵ�.
	*	@pre
	*	@post
	*	@return	������ true ���н� false
	*/
	bool addRide();

	/**
	*	@brief	rideList�� Ride�� �����Ѵ�.
	*	@pre
	*	@post
	*	@return	������ true ���н� false
	*/
	bool deleteRide();

	/**
	*	@brief	rideList�� Ride�� ������ �����Ѵ�.
	*	@pre
	*	@post
	*	@return	������ true ���н� false
	*/
	bool updateRide();

	/**
	*	@brief	������ ���� ������ ����Ѵ�.
	*	@pre
	*	@post
	*	@return
	*/
	void printTodayInfo();





private:
	int m_Command; //��ɾ� �Է¿� ���
	int OpenTime; //������ �ð� ��迡 ���?
	int CloseTime; //������ �ð� ��迡 ���?
	bool isOpen; //���� ����
	Admin admin; //���̵��� Admin
	fakeAdmin fAdmin;
};