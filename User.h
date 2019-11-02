#pragma once

class User {
public:

	/**
	*	@brief	기본 생성자입니다.
	*	@post	ticketRank(0~10), age(0~100)의 값 랜덤 생성,
	id에 Admin의 numOfEnterPeople을 넣음, wantToRide를 조건에 따라 생성함.
	나머지 변수 초기화도 진행
	*/
	User();

	/**
	*	@brief	무슨 함수인지 모르겠어요~ wantToRide가
	비었는지에 대한 여부를 알려주는건가?
	*	@pre
	*	@post
	*	@return
	*/
	bool WantToRide();

	/**
	*	@brief	이 User의 정보를 출력합니다.
	*/
	void printInfo() const;

	/**
	*	@brief	age 설정
	*	@post	age가 입력한 값으로 변합니다.
	*	@return 성공하면 true, 실패하면 false
	*/
	bool setAge(int _age);

	/**
	*	@brief	id 설정 - 이거 바꾸면 안되지 않나요?
	*	@post	id가 입력한 값으로 변합니다.
	*	@return	성공하면 true, 실패하면 false
	*/
	bool setID();

	/**
	*	@brief	입력 받은 _location으로 User의 위치를 옮깁니다.
	*	@pre	wantToRide에 _location의 값이 존재해야 합니다.
	*	@post	wantToRide에서 해당 값을 찾아 제거 후 hadRide로 옮깁니다.
	nowLocation이 입력한 값으로 변경됩니다.
	*	@return	성공하면 true, 실패하면 false
	*/
	bool setNowLocation(int _location);

	/**
	*	@brief	age를 반환합니다.
	*	@pre	age가 존재해야함.
	*	@return	age를 리턴함.
	*/
	int getAge() const;

	/**
	*	@brief	id를 반환합니다.
	*	@pre	id가 존재해야함.
	*	@return	id를 리턴함.
	*/
	int getId() const;

	/**
	*	@brief	nowLocation을 반환합니다.
	*	@pre	nowLocation이 존재해야함.
	*	@return	nowLocation을 리턴함.
	*/
	int getNowLocation() const;

private:
	int ticketRank; //age와 함께 탈 수 있는 Ride 결정 ( 길이에서 변경 )
	int age; //ticketRank와 함께 탈 수 있는 Ride 결정
	int id; //고유 번호, numOfEnterPeople로 정함
	int nowLocation; //현재 위치한 놀이기구 id, 초기 값은 -1
	UnsortedList wantToRide; //타고 싶은 놀이기구 id가 담긴 배열
	Stack hadRide; //이미 탑승한 놀이기구가 담긴 스택

};