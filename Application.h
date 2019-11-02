#pragma once
#include "Admin.h"
class Application {
public:

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	Application();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	void run();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool GetCommand();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool Open();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	void PrintRideInfo();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	void PrintAllInfo();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool SearchClients();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool SearchRide();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool AddRide();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool DeleteRide();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	bool UpdateRide();

	/**
	*	@brief
	*	@pre
	*	@post
	*	@return
	*/
	void PrintTodayInfo();

private:
	int m_Command;
	int OpenTime;
	int CloseTime;
	bool open;
	Admin admin;
};