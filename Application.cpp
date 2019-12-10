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
	admin.run();
	while (true) {
		if (m_Command == -1) break;
	
		switch (m_Command)
		{
		case 0:
			printLive();
			break;
		case 1:
			searchRide();
			break;
		case 2:
			searchAllUser();
			break;
		}
		m_Command = getKey();
	}
	isOpen = false;
	admin.runDelete();
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

void Application::printLive()
{
	// ID, ����ο�, ���ð�? �̰Ÿ� �����ɵ�
	// �� �Լ���
	system("CLS");
	fakeRide* ride = fAdmin.getRide();
	int size = fAdmin.getSize();
	cout << "\n" << setw(25) << "���̱ⱸ ���" << setw(10) << "����ο�";
	for (int i = 0; i < size; i++) {
		cout << "\n" << setw(25) << ride[i].info;
		cout << setw(10) << ride[i].numWatingUser;
		cout << '\t';
		for (int j = 0; j < ride[i].watingTime; j++) {
			cout << "��";
		}
	}
	cout << "\n\n\t" << "- �ߴ��ϱ�(p)" << "\n\t" << "- ���̱ⱸ �� ���� �˻�(s)" << "\n\t" << "- ���� �� ���� �˻�(u)" "\n\t-->";
	Sleep(1000);
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
	while (true) {
		cout << "\n\t���� ������ 0~" << num - 1 << "���� �Դϴ�.";
		cout << "\n\t�˻��ϰ� ���� ���� ��ȣ�� �Է��ϼ���-->";
		cin >> id;
		if (id >= 0 && id < num) { break; }
		cout << "\n\t�߸��� �Է��Դϴ�.";
	}
	User searchedUser = admin.searchUser(id);
	searchedUser.printInfo();
	m_Command = 0;
	return true;
}

void Application::printAllRideInfo() const
{

}



bool Application::searchRide()
{
	int num = admin.getRideLength();
	int id;
	while (true) {
		cout << "\n\t���� ���̱ⱸ�� 0~" << num - 1 << "���� �Դϴ�.";
		cout << "\n\t�˻��ϰ� ���� ���̱ⱸ ��ȣ�� �Է��ϼ���-->";
		cin >> id;
		if (id >= 0 && id < num) { break; }
		cout << "\n\t�߸��� �Է��Դϴ�.";
	}
	Ride searchedRide = admin.searchRide(id);
	searchedRide.printInfo();
	m_Command = 0;
	return true;
}


bool Application::addRide()
{
	Ride addingRide;
	addingRide.setAllFromKB();
	admin.insertRide(addingRide);
	return true;
}


bool Application::deleteRide()
{
	int id;
	int num = admin.getRideLength();
	while (true) {
		cout << "\n\t���� ���̱ⱸ�� 0~" << num - 1 << "���� �Դϴ�.";
		cout << "\n\t�����ϰ� ���� ���̱ⱸ ��ȣ�� �Է��ϼ���-->";
		cin >> id;
		if (id >= 0 && id < num) { break; }
		cout << "\n\t�߸��� �Է��Դϴ�.";
	}
	if (admin.removeRide(id))
	{
		cout << "\n\t������ �����߽��ϴ�.";
		return true;
	}
	cout << "\n\t������ �����߽��ϴ�.";
	return false;
}

bool Application::updateRide()
{

	return true;
}


void Application::printTodayInfo()
{

}


