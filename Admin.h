#pragma once
#include "User.h"

class Admin {
public:

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	Admin();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	~Admin();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	int newUser();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	int moveUser();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	int nextRide();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	int addRide();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	int deleteRide();

private:
	int numOfEnterPeople;
	int maxPeople;
	int lenRideList;
	LinkedQueue waitingEnterPeople;
	LinkedList rideList;
	SortedList userList;
};