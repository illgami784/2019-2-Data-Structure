// application �׽�Ʈ�� Ŭ�����Դϴ�!.

#pragma once
#include <string>
using namespace std;

struct fakeRide {
	int id; //���� ��ȣ RideList�� ���̿� ���� ������
	string name;
	string info;
	int requireTime; //���̱ⱸ�� �ѹ��� �۵��ϴµ� �ɸ��� �ð�(�� ����)
	int numPerRide; //�� ���� ���̱ⱸ��  Ż �� �ִ� User ��
	int watingTime; //���� ��� �ð�(�� ����)
	int minAge; //�� Ride�� Ÿ�� ���� �ּ� ���� (0~100)
	int minTicketRank; //�� Ride�� Ÿ�� ���� �ּ� Ƽ�� ��� (0~10)
	int totalUser; //�����ϰ� ž���� �� User ��
	int numWatingUser;
};

class fakeAdmin {
public:
	fakeAdmin() {
		for (int i = 0; i < 10; i++) {
			string temp = "�ѷ��ڽ��� - " + to_string(i);
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