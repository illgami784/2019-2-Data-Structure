#pragma once

class User {
public:

	/**
	*	@brief	�⺻ �������Դϴ�.
	*	@post	ticketRank(0~10), age(0~100)�� �� ���� ����,
	id�� Admin�� numOfEnterPeople�� ����, wantToRide�� ���ǿ� ���� ������.
	������ ���� �ʱ�ȭ�� ����
	*/
	User();

	/**
	*	@brief	���� �Լ����� �𸣰ھ��~ wantToRide��
	��������� ���� ���θ� �˷��ִ°ǰ�?
	*	@pre
	*	@post
	*	@return
	*/
	bool WantToRide();

	/**
	*	@brief	�� User�� ������ ����մϴ�.
	*/
	void printInfo() const;

	/**
	*	@brief	age ����
	*	@post	age�� �Է��� ������ ���մϴ�.
	*	@return �����ϸ� true, �����ϸ� false
	*/
	bool setAge(int _age);

	/**
	*	@brief	id ���� - �̰� �ٲٸ� �ȵ��� �ʳ���?
	*	@post	id�� �Է��� ������ ���մϴ�.
	*	@return	�����ϸ� true, �����ϸ� false
	*/
	bool setID();

	/**
	*	@brief	�Է� ���� _location���� User�� ��ġ�� �ű�ϴ�.
	*	@pre	wantToRide�� _location�� ���� �����ؾ� �մϴ�.
	*	@post	wantToRide���� �ش� ���� ã�� ���� �� hadRide�� �ű�ϴ�.
	nowLocation�� �Է��� ������ ����˴ϴ�.
	*	@return	�����ϸ� true, �����ϸ� false
	*/
	bool setNowLocation(int _location);

	/**
	*	@brief	age�� ��ȯ�մϴ�.
	*	@pre	age�� �����ؾ���.
	*	@return	age�� ������.
	*/
	int getAge() const;

	/**
	*	@brief	id�� ��ȯ�մϴ�.
	*	@pre	id�� �����ؾ���.
	*	@return	id�� ������.
	*/
	int getId() const;

	/**
	*	@brief	nowLocation�� ��ȯ�մϴ�.
	*	@pre	nowLocation�� �����ؾ���.
	*	@return	nowLocation�� ������.
	*/
	int getNowLocation() const;

private:
	int ticketRank; //age�� �Բ� Ż �� �ִ� Ride ���� ( ���̿��� ���� )
	int age; //ticketRank�� �Բ� Ż �� �ִ� Ride ����
	int id; //���� ��ȣ, numOfEnterPeople�� ����
	int nowLocation; //���� ��ġ�� ���̱ⱸ id, �ʱ� ���� -1
	UnsortedList wantToRide; //Ÿ�� ���� ���̱ⱸ id�� ��� �迭
	Stack hadRide; //�̹� ž���� ���̱ⱸ�� ��� ����

};