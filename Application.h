#pragma once
#include "Admin.h"
#include "User.h"
#include "Ride.h"
#include "Intro.cpp"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <conio.h>
#include "DoublyIterator.h"
#include <fstream>
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

	void printLive(int tick);

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
	void printAllRideInfo();

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

	string clock(int tick);

	void writeRideListToFile()
	{
		if ((admin.rideListPointer()->GetLength()==0))
		{
			cout << "\t�� �����Ͱ� �������� �ʽ��ϴ�. " << endl;
			return;
		}
		
		ofstream fin;
		fin.open("ride.txt");
		DoublyIterator<Ride> itor(*admin.rideListPointer());
		Ride temp;
		temp=itor.Next();
		while (itor.NextNotNull())
		{
			
			fin << itor.GetCurrentNodePointer()->data.getId() << " " << itor.GetCurrentNodePointer()->data.getRequireTime() << " " << itor.GetCurrentNodePointer()->data.getMinAge() << " " << itor.GetCurrentNodePointer()->data.getNumPerRide();
			temp=itor.Next();
			if (itor.NextNotNull())
			{
				fin << endl;
			}
		}
		fin.close();
		cout << "\tWrite Complete" << endl;

	}
	void ReadRideListFromFile()
	{
		if (admin.rideListPointer()->GetLength()!=0)
		{
				admin.rideListPointer()->MakeEmpty();
		}
			ifstream fout;
			fout.open("ride.txt");

			if (fout.is_open())
			{
				int temp;
				while (1)
				{
					
					Ride* ridetemp = new Ride;
					fout >> temp;
					if (!fout) break;
					ridetemp->setId(temp);
					fout >> temp;
					ridetemp->setRequiredTime(temp);
					fout >> temp;
					ridetemp->setMinAge(temp);
					fout >> temp;
					ridetemp->setNumPerRide(temp);
					ridetemp->setridingUsersetMax(temp);
					admin.insertRideFromFile(*ridetemp);
					if (!fout) break;
				}
				cout << "\tRead Complete" << endl;
				fout.close();
			}
			else
				cout << "\t �о�� �����Ͱ� �������� �ʽ��ϴ�. " << endl;
	}

private:
	int m_Command; //��ɾ� �Է¿� ���
	int OpenTime; //������ �ð� ��迡 ���?
	int CloseTime; //������ �ð� ��迡 ���?
	int Day; //opening days
	bool isOpen; //���� ����
	Admin admin; //���̵��� Admin
	Intro intro;
};