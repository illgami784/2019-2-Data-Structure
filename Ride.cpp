#include "User.h"
#include "Ride.h"
#include <iostream>

using namespace std;

int id; //고유 번호 RideList의 길이에 따라 정해짐
int requireTime; //놀이기구를 한번에 작동하는데 걸리는 시간(초 단위)
int numPerRide; //한 번에 놀이기구를  탈 수 있는 User 수
int watingTime; //예상 대기 시간(초 단위)
int minAge; //이 Ride를 타기 위한 최소 나이 (0~100)
int minTicketRank; //이 Ride를 타기 위한 최소 티켓 등급 (0~10)
int totalUser; //개장하고 탑승한 총 User 수
bool isOpen;

Ride::Ride() {

}

void Ride::setAllFromKB() {
	//id, requireTime, minAge, minticketRank을 키보드로부터 입력 받아 설정.
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