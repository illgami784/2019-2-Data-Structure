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
	
	cout << "\n\t�� ���� �߰��� ���� ���� �Է����ּ��� : ";
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
	// ID, ����ο�, ���ð�? �̰Ÿ� �����ɵ�
	// �� �Լ���
	system("CLS");
	DoublyIterator<Ride> itor( *(admin.rideListPointer()) );
	cout << "\t���� �ð� - " << clock(tick) << "\n\t���̱ⱸ ���� - " << admin.getRideLength()
		<<"\n\t�����ο� �� - " << admin.getNumOfEnterUser();
	itor.Next();
	cout << "\n\n" << setw(25) << "���̱ⱸ ���" << setw(10) << "����ο�";
	while (itor.NextNotNull())
	{
		liveInfo live = itor.GetCurrentNodePointer()->data.getLiveInfo();
		cout << "\n" << setw(25) << live.info;
		cout << setw(10) << live.numWatingUser;
		cout << '\t';
		for (int j = 0; j < live.watingtime; j++) {
			cout << "��";
		}
		itor.Next();
	}
	cout << '\n';
	
	cout << "\n\n\t" << "- �ߴ��ϱ�(p)" << "\n\t" << "- ���̱ⱸ �� ���� �˻�(s)" << "\n\t" << "- ���� �� ���� �˻�(u)" "\n\t-->";
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
			cout << "\n\t�Է� �����Դϴ�. �ٽ� �Է����ּ���.";
			break;
		}
	}
}

bool Application::getCloseCommand()
{
	cout << "\n\t���� ����";
	cout << "\n\t1. ���̰��� ��� ����";
	cout << "\n\t2. ��ü ���̱ⱸ ���� ����";
	cout << "\n\t3. �� ���̱ⱸ ���� ����";
	cout << "\n\t4. ���̱ⱸ �߰� �ϱ�";
	cout << "\n\t5. ���̱ⱸ ���� �ϱ�";
	cout << "\n\t6. ���̱ⱸ ���� �ϱ�";
	cout << "\n\t7. �����ϱ�";
	cout << "\n\t0. ���α׷� ����";
	cout << "\n\t->";
	cin.clear();
	cin >> m_Command;
	return true;
}

bool Application::getOpenCommand()
{
	cout << "\n\t�ȳ�";
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
		cout << "\n\t������ �������� �ʽ��ϴ�. �ڵ����� ���ư��ϴ�.";
		Sleep(500);
		return false;
	}

	while (true) {
		cout << "\n\t���� ������ 0~" << num- 1<< "���� �Դϴ�.";
		cout << "\n\t�˻��ϰ� ���� ���� ��ȣ�� �Է��ϼ���(input -7 to exit)-->";
		cin >> id;
		if ( (id >= 0 && id < num) || id == -7) { break; }
		cout << "\n\t�߸��� �Է��Դϴ�.";
	}

	if ((id >= 0 && id < num))
	{
		User searchedUser = admin.searchUser(id);
		searchedUser.printInfo();
		cout << "\n\t�����÷��� p�� �����ּ���";
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
		cout << "\n\t���̱ⱸ�� �������� �ʽ��ϴ�. �ڵ����� ���ư��ϴ�.";
		Sleep(500);
		return false;
	}
	while (true) {
		cout << "\n\t���� ���̱ⱸ�� 0~" << num-1 << "���� �Դϴ�.";
		cout << "\n\t�˻��ϰ� ���� ���̱ⱸ ��ȣ�� �Է��ϼ���(input -7 to exit)-->";
		cin >> id;
		if ((id >= 0 && id < num) || id == -7) { break; }
		cout << "\n\t�߸��� �Է��Դϴ�.";
	}
	if ((id >= 0 && id < num))
	{
		Ride searchedRide = admin.searchRide(id);
		searchedRide.printInfo();
		cout << "\n\t�����÷��� p�� �����ּ���";
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
		cout << "\n\t���̱ⱸ�� �������� �ʽ��ϴ�. �ڵ����� ���ư��ϴ�.";
		Sleep(500);
		return false;
	}

	while (true) {
		cout << "\n\t���� ���̱ⱸ�� 0~" << num -1<< "���� �Դϴ�.";
		cout << "\n\t�����ϰ� ���� ���̱ⱸ ��ȣ�� �Է��ϼ���-->";
		cin >> id;
		if (id >= 0 && id < num) { break; }
		cout << "\n\t�߸��� �Է��Դϴ�.";
	}
	if (id >= 0 && id < num)
	{
		if (admin.removeRide(id))
		{
			cout << "\n\t������ �����߽��ϴ�.";
			return true;
		}
		cout << "\n\t������ �����߽��ϴ�.";
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
