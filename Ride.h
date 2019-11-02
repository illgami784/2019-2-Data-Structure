#pragma once

class Ride{
public:

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	Ride();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	int calWatingTime();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	void printInfo();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool addWaitingPeople();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool ridePeople();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool run();

private:
	int id;
	int requireTime;
	int watingTime;
	int numPerRide;
	int minAge;
	int totalPeople;
	bool isOpen;

	Stack ridingPeple;
	Queue watingPeople;

};