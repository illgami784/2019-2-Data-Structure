#pragma once
#include "Application.h"
Application::Application()
{
	m_Command = 0;
	OpenTime = 0;
	CloseTime = 0;
	isOpen = false;
}

void Application::run()
{
	while (true) {
		if (isOpen)
		{
			open();
		}
		else
		{
			close();
		}
	}
}

void Application::open()
{
	m_Command = 0;
	int tick = 0, num = 1;
	
	cout << "\n\t한 번에 추가할 유저 수를 입력해주세요 : ";
	while (true)
	{
		cin >> num;
		if (num >= 1) break;
	}
	admin.setMaxUser(num * 10);

	admin.setRun();

	while (true) {
		if (m_Command == -1) break;
		
		tick++;

		switch (m_Command)
		{
		case 0:
			printLive(tick);
			break;
		case 1:
			searchRide();
			break;
		case 2:
			searchAllUser();
			break;
		}
		
		for(int i = 0; i < num; i++) admin.newUser();

		admin.run(tick);

		Sleep(900);

		m_Command = getKey();
	}
	isOpen = false;
	admin.runDelete();
	if(m_Command==-1)
		system("CLS");
	return;
}

int Application::getKey()
{
	if (_kbhit()) {
		int nKey = _getch();
		switch (nKey)
		{
		case 'p':
			return -1;
		case 's':
			return 1;
		case 'u':
			return 2;
		}
	}
	return 0;
}

void Application::printLive(int tick)
{
	// ID, 대기인원, 대기시간? 이거만 있음될듯
	// 이 함수랑
	system("CLS");
	DoublyIterator<Ride> itor( *(admin.rideListPointer()) );
	cout << "\t현재 시간 - " << clock(tick) << "\n\t놀이기구 갯수 - " << admin.getRideLength()
		<<"\n\t입장인원 수 - " << admin.getNumOfEnterUser();
	itor.Next();
	cout << "\n\n" << setw(25) << "놀이기구 목록" << setw(10) << "대기인원";
	while (itor.NextNotNull())
	{
		liveInfo live = itor.GetCurrentNodePointer()->data.getLiveInfo();
		cout << "\n" << setw(25) << live.info;
		cout << setw(10) << live.numWatingUser;
		cout << '\t';
		for (int j = 0; j < live.watingtime; j++) {
			cout << "■";
		}
		itor.Next();
	}
	cout << '\n';
	
	cout << "\n\n\t" << "- 중단하기(p)" << "\n\t" << "- 놀이기구 상세 정보 검색(s)" << "\n\t" << "- 유저 상세 정보 검색(u)" "\n\t-->";
}

string Application::clock(int tick)
{
	string temp = "";
	int hour = tick / 60;
	int min = tick % 60;
	
	if (hour == 0) temp += "00:";
	else if (hour < 10) temp += "0" + to_string(hour) + ":";
	else temp += to_string(hour) + ":";

	if (min < 10) temp += "0" + to_string(min);
	else temp += to_string(min);

	return temp;
}


void Application::close()
{
	while (true) {
		getCloseCommand();
		switch (m_Command)
		{
		case 1:
			printTodayInfo();
			break;
		case 2:
			printAllRideInfo();
			break;
		case 3:
			searchRide();
			break;
		case 4:
			addRide();
			break;
		case 5:
			updateRide();
			break;
		case 6:
			deleteRide();
			break;
		case 7:
			isOpen = true;
			return;
		case 0:
			exit(100);
		default:
			cout << "\n\t입력 오류입니다. 다시 입력해주세요.";
			break;
		}
	}
}

bool Application::getCloseCommand()
{
	cout << "\n\t폐장 상태";
	cout << "\n\t1. 놀이공원 통계 보기";
	cout << "\n\t2. 전체 놀이기구 정보 보기";
	cout << "\n\t3. 상세 놀이기구 정보 보기";
	cout << "\n\t4. 놀이기구 추가 하기";
	cout << "\n\t5. 놀이기구 수정 하기";
	cout << "\n\t6. 놀이기구 삭제 하기";
	cout << "\n\t7. 개장하기";
	cout << "\n\t0. 프로그램 종료";
	cout << "\n\t->";
	cin.clear();
	cin >> m_Command;
	return true;
}

bool Application::getOpenCommand()
{
	cout << "\n\t안녕";
	return true;
}


bool Application::isItOpen() const
{
	return isOpen;
}

bool Application::searchAllUser()
{
	int num = admin.getNumOfEnterUser();
	int id;

	if (num == 0)
	{
		cout << "\n\t유저가 존재하지 않습니다. 자동으로 돌아갑니다.";
		Sleep(500);
		return false;
	}

	while (true) {
		cout << "\n\t현재 유저는 0~" << num- 1<< "까지 입니다.";
		cout << "\n\t검색하고 싶은 유저 번호를 입력하세요(input -7 to exit)-->";
		cin >> id;
		if ( (id >= 0 && id < num) || id == -7) { break; }
		cout << "\n\t잘못된 입력입니다.";
	}

	if ((id >= 0 && id < num))
	{
		User searchedUser = admin.searchUser(id);
		searchedUser.printInfo();
		cout << "\n\t나가시려면 p를 눌러주세요";
		while (true)
		{
			if (getKey() == -1) break;
			Sleep(500);
		}
	}
	m_Command = 0;
	return true;
}

void Application::printAllRideInfo()
{
	admin.PrintRideAll();
}



bool Application::searchRide()
{
	int num = admin.getRideLength();
	int id;

	if (num == 0)
	{
		cout << "\n\t놀이기구가 존재하지 않습니다. 자동으로 돌아갑니다.";
		Sleep(500);
		return false;
	}
	while (true) {
		cout << "\n\t현재 놀이기구는 0~" << num-1 << "까지 입니다.";
		cout << "\n\t검색하고 싶은 놀이기구 번호를 입력하세요(input -7 to exit)-->";
		cin >> id;
		if ((id >= 0 && id < num) || id == -7) { break; }
		cout << "\n\t잘못된 입력입니다.";
	}
	if ((id >= 0 && id < num))
	{
		Ride searchedRide = admin.searchRide(id);
		searchedRide.printInfo();
		cout << "\n\t나가시려면 p를 눌러주세요";
		while (true)
		{
			if (getKey() == -1) break;
			Sleep(500);
		}
	}
	
	m_Command = 0;
	return true;
}


bool Application::addRide()
{
	Ride* addingRide=new Ride;
	addingRide->setAllFromKB();
	admin.insertRide(*addingRide);
	return true;
}


bool Application::deleteRide()
{
	int id;
	int num = admin.getRideLength();
	if (num == 0)
	{
		cout << "\n\t놀이기구가 존재하지 않습니다. 자동으로 돌아갑니다.";
		Sleep(500);
		return false;
	}

	while (true) {
		cout << "\n\t현재 놀이기구는 0~" << num -1<< "까지 입니다.";
		cout << "\n\t삭제하고 싶은 놀이기구 번호를 입력하세요-->";
		cin >> id;
		if (id >= 0 && id < num) { break; }
		cout << "\n\t잘못된 입력입니다.";
	}
	if (id >= 0 && id < num)
	{
		if (admin.removeRide(id))
		{
			cout << "\n\t삭제에 성공했습니다.";
			return true;
		}
		cout << "\n\t삭제에 실패했습니다.";
	}
	
	return false;
}

bool Application::updateRide()
{

	return true;
}

void Application::printTodayInfo() {
	DoublySortedLinkedList<Ride>* rideList = admin.rideListPointer();
	Ride cur;
	liveInfo print;
	for (int i = 0; i < rideList->GetLength(); i++) {
		cur.setId(i);
		rideList->Get(cur);
		print = cur.printStat();
		cout << "\n\tid : " << print.info;
		cout << "\n\ttotlaUser : " << print.totalUser;
		cout << "\n\tMax waitingtime : " << print.watingtime;
		cout << "\n\tMax waitingUser number : " << print.numWatingUser << '\n';
	}
}
