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
	*	@brief	기본 생성자입니다
	*	@post	maxUser를 입력값으로 설정, UserList의 길이를 maxUser의
	크기로 설정, numOfEnterUser = 0
	*/
	Admin();

	/**
	*	@brief	기본 소멸자입니다.
	*	@post
	*/
	~Admin() = default;

	/**
	*	@brief	특정 시간마다 실행되며 새로운 User를 만드는 함수.
	*	@pre	userList가 full이 아니여야함 full일시 watingEnterUser에 User를 넣음
	*	@post	userList가 full이 아니면 numOfEnterUser++
	새로운 User 추가 numOfEntterUser을 id로 설정해준다. 이후 nextRide를 호출.
	*	@return	성공시 true, 실패시 false
	*/
	bool newUser();

	/**
	*	@brief	user의 현재 위치에 따라 해당하는 Ride로 이동시킴
	*	@pre	user의 nowLocation이 변경되야함
	*	@post	해당 Ride의 watingUser에 user 추가
	*	@return	성공시 true 실패시 false
	*/
	bool moveUser(User &user);

	/**
	*	@brief	user의 wantToRide와 각 Ride들의 watingTime을 확인해서
	user의 다음 목적지를 결정해준다.
	*	@pre	user의 wantToRide가 비어있지 않아야함
	*	@post	moveUser도 호출되며 user의 setNowLocation 호출해 값 변경
	*	@return	성공시 true, 실패시 false
	*/
	bool nextRide(User &user);

	/**
	*	@brief	rideList에 ride를 추가한다.
	*	@pre	ride의 값이 채워져있어야함
	*	@post	rideList의 끝에 ride 추가.
	*	@return	성공시 true 실패시 false
	*/
	bool addRide(Ride& ride);

	/**
	*	@brief	rideList에 ride를 제거한다.
	*	@pre	rideList에 해당 id의 놀이기구가 존재해야한다.
	*	@post	rideList에서 해당 id의 놀이기구 제거
	*	@return	성공시 true 실패시 false
	*/
	bool deleteRide(int _id);
	/**
    *   @brief   rideList pointer 반환
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
	int numOfEnterUser; //개장 후 입장한 User의 수
	int maxUser; //최대 수용 가능 User 수
	int lenRideList; //rideList의 길이 = ride 갯수
	CircularQueue<User> waitingEnterUser; //userList가 다 차 들어오지 못한 User
	//Ride가 담긴 list
	SortedList<User> userList; //User가 담긴 list
	User* p_U;
};

Admin::Admin()
{
	numOfEnterUser = 0;
	maxUser = 100; //maxUser 미정
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

