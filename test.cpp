// application 테스트용 클래스입니다!.

#pragma once
#include <string>
using namespace std;

struct fakeRide {
	int id; //고유 번호 RideList의 길이에 따라 정해짐
	string name;
	string info;
	int requireTime; //놀이기구를 한번에 작동하는데 걸리는 시간(초 단위)
	int numPerRide; //한 번에 놀이기구를  탈 수 있는 User 수
	int watingTime; //예상 대기 시간(초 단위)
	int minAge; //이 Ride를 타기 위한 최소 나이 (0~100)
	int minTicketRank; //이 Ride를 타기 위한 최소 티켓 등급 (0~10)
	int totalUser; //개장하고 탑승한 총 User 수
	int numWatingUser;
};

class fakeAdmin {
public:
	fakeAdmin() {
		for (int i = 0; i < 10; i++) {
			string temp = "롤러코스터 - " + to_string(i);
			string info = to_string(i) + '.' + temp;
			ride[i] = { i,temp,info,i, i, i, i, i, i, i };
		}
	}

	fakeRide* getRide() {
		return ride;
	}

	int getSize() {
		return 10;
	}
private:
	fakeRide ride[10];
};