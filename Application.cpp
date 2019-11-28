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
	while (true) {
		cout << "\n\t ���Ḧ ���ؼ��� ~�� �Է��ϼ���";

	}
	isOpen = false;
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