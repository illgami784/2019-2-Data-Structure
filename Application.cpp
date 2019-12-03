#include "Application.h"
#include "AppScreen.cpp"

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
	//#include <conio.h>, <time.h>, <windows.h> needed
	//visualizing random graph -> have to change into REAL Amuse graph
	int input = 1;

	cout << "\n\t Amusement Park Statistic";

	cout << "\n\t Press 's' to close the park";

	int randomgraph;//length of graph
	int ridenum = 5;//5 rides 

	while (true) { //repeat until press 's'

		for (int i = 0; i <= ridenum; i++) {
			cout << "\n\t" << i << "th Ride : ";
			randomgraph = rand() % 60 + 1; // random graph
			for(int i = 0; i <= randomgraph;i++)
				cout << "+";
			cout << endl;
		}

		if (_kbhit())
		{
			input = _getch(); //get input
		}
		Sleep(70);

		if (input == 's') { //if input == 's'
			isOpen = 0;//close
			break;
		}
	}

	return;
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
	cin >> m_Command;
	return true;
}

bool Application::getOpenCommand()
{
	cout << "\n\t�ȳ�";
	
}


bool Application::isItOpen() const
{

}

bool Application::searchAllUser()
{

}

void Application::printRideInfo(int _id) const
{

}

void Application::printAllRideInfo() const
{

}



bool Application::searchRide()
{

}


bool Application::addRide()
{

}


bool Application::deleteRide()
{

}

bool Application::updateRide()
{

}


void Application::printTodayInfo()
{

}