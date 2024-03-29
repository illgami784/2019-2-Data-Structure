#pragma once
#include "DoublySortedLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <Windows.h>
#include <iostream>
using namespace std;

class User;
class Admin;

struct liveInfo {
	int info;
	int totalUser;
	int numWatingUser;
	int watingtime;
};

class Ride {
public:

	/**
	*	@brief	기본 생성자 입니다.
	*	@post	id, requireTime, minAge, minTicketRank를 입력받아 설정
	id는 Admin의 RideList의 길이에 따라 정해짐, watingTime 0으로 초기화
	*/
	Ride();

	/*
	copy constructure
	int id; //고유 번호 RideList의 길이에 따라 정해짐
	int requireTime; //놀이기구를 한번에 작동하는데 걸리는 시간(초 단위)
	int numPerRide; //한 번에 놀이기구를  탈 수 있는 User 수
	int watingTime; //예상 대기 시간(초 단위)
	int minAge; //이 Ride를 타기 위한 최소 나이 (0~100)
	int totalUser; //개장하고 탑승한 총 User 수
	int numWaitingUser; //지금 기다리고 있는 사람의 수
	bool isOpen;
	*/
	Ride(const Ride& ride);

	/**
	*	@brief	watingTime을 산출함. rideUser 루프가 돌때마다 호출
	*	@pre	requireTime과 numPerRide의 값이 존재해야함.
	*	@post	requireTime과 numPerRide,
	watingUser의 길이를 통해 watingTime 값 설정
	*	@return	성공시 true, 실패시 false
	*/
	bool calcWaitingTime();

	/**
	*	@brief	id에 값을 할당
	*	@param	설정할 id 값
	*/
	void setId(int _id);

	/**
	*	@brief	id, requireTime, minAge, minticketRank을
	키보드로부터 입력 받아 설정.
	*	@post	id, requireTime, minAge, minticketRank의 값이
	키보드로 입력한 값으로 설정됨.
	*/
	void setAllFromKB();

	/**
	*	@brief	이 Ride의 정보를 출력합니다.
	*/
	void printInfo() const;

	/**
	*	@brief	입력받은 User를 watingUser에 추가함
	*	@post	watingUser에 user가 추가됨.
	*	@return	성공하면 true, 실패하면 false
	*/
	bool addWaitingUser(User*& user);

	/**
	*	@brief	놀이공원이 개장되면 Ride를 작동시키는 함수
	*	@pre	isOpen이 false여야함.
	*	@post	isOpen을 true로 바꾸고 ridePeople을 동작시킴(계속 동작~)
	*	@return	이미 작동 중인데(isOpen이 true) 호출시 false 아니면 true
	*/
	bool run();

	/**
	*	@brief	놀이공원이 폐장되면 Ride를 멈추는 함수
	*	@pre	isOepn이 true여야함.
	*	@post	isOpen을 false로 바꾸고 watingPeople과 ridingPeople을 비움.
	*	@return	이미 멈췄는데(isOpen이 false) 호출시 false 아니면 true
	*/
	bool stop();

	/**
	*	@brief	Ride가 동작하는 함수. isOpen이 true면
	requireTime마다 계속 반복됨.
	*	@pre	isOpen이 true이며 watingUser가 존재해야함.
	*	@post	기존 존재하는 ridingUser의 User들을 outUser를 호출해 나가게함.
	watingUser에서 numPerRide만큼 User를 빼 ridingUser에 추가함.
	*	@return	리턴?
	*/
	bool rideUser();



	int getMinAge() const;

	bool moveToUser(User*& user);

	void setMinAge(int minAge);

	void setRideListPointer(DoublySortedLinkedList<Ride>* _rideListPointer);
	
	int getId();

	int getWaitingTime();

	int getRequireTime();

	int getNumPerRide();



	int getTotalUser();

	liveInfo getLiveInfo();

	liveInfo printStat();

	void increwatinguser();

	bool operator<(const Ride& rhs) const;

	bool operator>(const Ride& rhs) const;

	bool operator<=(const Ride& rhs) const;

	bool operator>=(const Ride& rhs) const;

	bool operator==(const Ride& rhs) const;

	bool operator!=(const Ride& rhs) const;

	Ride& operator=(const Ride& rhs);

	friend class User;

	void setRequiredTime(int _requiredTime);

	void setNumPerRide(int _numPerRide);

	void setridingUsersetMax(int _numPerRide);

	void setTotalUser(int _totaluser);

private:
	int id; //고유 번호 RideList의 길이에 따라 정해짐
	int requireTime; //놀이기구를 한번에 작동하는데 걸리는 시간(초 단위)
	int numPerRide; //한 번에 놀이기구를  탈 수 있는 User 수
	int watingTime; //예상 대기 시간(초 단위)
	int minAge; //이 Ride를 타기 위한 최소 나이 (0~100)
	int totalUser; //개장하고 탑승한 총 User 수
	int numWaitingUser; //지금 기다리고 있는 사람의 수
	bool isOpen; //개장 여부를 나타냄, rideUser 무한 루프를 깨기 위해 사용
	int maxWatingTime;//하루 최대 watingTime
	int maxNumWaitingUser;//하루 최대 기다린사람

	DoublySortedLinkedList<Ride>* rideListPointer; //자신이 담긴 rideList의 시작 주소를 가진다.
	Stack<User*> ridingUser; //현재 탑승 중인 User을 담는 Stack
	Queue<User*> waitingUser; //기다리는 User들을 담는 Queue - 추후 heap으로

};
