#include "User.h"
#include "Ride.h"
#include <iostream>

using namespace std;

int id; //���� ��ȣ RideList�� ���̿� ���� ������
int requireTime; //���̱ⱸ�� �ѹ��� �۵��ϴµ� �ɸ��� �ð�(�� ����)
int numPerRide; //�� ���� ���̱ⱸ��  Ż �� �ִ� User ��
int watingTime; //���� ��� �ð�(�� ����)
int minAge; //�� Ride�� Ÿ�� ���� �ּ� ���� (0~100)
int minTicketRank; //�� Ride�� Ÿ�� ���� �ּ� Ƽ�� ��� (0~10)
int totalUser; //�����ϰ� ž���� �� User ��
bool isOpen;

Ride::Ride() {

}

void Ride::setAllFromKB() {
	//id, requireTime, minAge, minticketRank�� Ű����κ��� �Է� �޾� ����.
	cout << "\tSet the id of Ride : ";
	cin >> id;
	cout << "\tSet the requireTime(second) of Ride : ";
	cin >> requireTime;
	cout << "\tSet the minAge(0-100) of Ride : ";
	cin >> minAge;
	cout << "\tSet the minTicketRank(0-10) of Ride : ";
	cin >> minTicketRank;

	cout << "\n\tThe Setup completed.\n";
}