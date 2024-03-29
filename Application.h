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
	*	@brief	기본 생성자입니다.
	*	@post	open = false
	*/
	Application();

	/**
	*	@brief	관리 프로그램 시작
	*	@pre	open의 값이 설정되있어야 합니다.
	*	@post	open값에 따라 다른 메뉴 실행
	*/
	void run();

	void open();

	int getKey();

	void printLive(int tick);

	void close();

	/**
	*	@brief	명령어를 입력받는 함수
	*	@post	m_Command가 입력한 값이 된다.
	*	@return	성공시 true 실패시 false
	*/
	bool getOpenCommand();

	/**
	*	@brief	명령어를 입력받는 함수
	*	@post	m_Command가 입력한 값이 된다.
	*	@return	성공시 true 실패시 false
	*/
	bool getCloseCommand();

	/**
	*	@brief	open 여부를 리턴한다.
	*	@return	open 리턴
	*/
	bool isItOpen() const;

	/**
	*	@brief	모른 Ride의 대략적인 정보를 출력한다.
	*	@pre	rideList에 Ride가 하나라도 존재해야함
	*/
	void printAllRideInfo();

	/**
	*	@brief	사용자의 정보 조회?
	*	@pre
	*	@post
	*	@return	성공시 true 실패시 false
	*/
	bool searchAllUser();

	/**
	*	@brief	rideList에서 검색한다.
	*	@pre
	*	@post
	*	@return	성공시 true 실패시 false
	*/
	bool searchRide();

	/**
	*	@brief	rideList에 Ride를 추가한다.
	*	@pre
	*	@post
	*	@return	성공시 true 실패시 false
	*/
	bool addRide();

	/**
	*	@brief	rideList의 Ride를 삭제한다.
	*	@pre
	*	@post
	*	@return	성공시 true 실패시 false
	*/
	bool deleteRide();

	/**
	*	@brief	rideList의 Ride의 정보를 변경한다.
	*	@pre
	*	@post
	*	@return	성공시 true 실패시 false
	*/
	bool updateRide();

	/**
	*	@brief	열렸을 때의 정보를 출력한다.
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
			cout << "\t쓸 데이터가 존재하지 않습니다. " << endl;
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
				cout << "\t 읽어올 데이터가 존재하지 않습니다. " << endl;
	}

private:
	int m_Command; //명령어 입력에 사용
	int OpenTime; //개장한 시간 통계에 사용?
	int CloseTime; //폐장한 시간 통계에 사용?
	int Day; //opening days
	bool isOpen; //개장 여부
	Admin admin; //놀이동산 Admin
	Intro intro;
};