#include <Windows.h>
#include <conio.h>
#include <string>
#include "Screen.cpp"
using namespace std;

class AppScreen {

public:
	AppScreen() {}
	void run() { 
		char* mainC = &main[0];
		char* closeMainC = &closeMain[0];
		while (true) {
			screen.ScreenShow();
			if (_kbhit())
			{
				int nKey = _getch();
				if (nKey == 'q')
					break;
				switch (nKey)
				{
				case 'j':
					break;
				case 'l':
					break;
				}
			}
			screen.ScreenClear();
			screen.ScreenPrint(0, 0, mainC);
			screen.ScreenShow();
			Sleep(1000);
			screen.ScreenPrint(0, 0, closeMainC);
			screen.ScreenShow();
			Sleep(1000);
		}
	}



private:
	Screen screen;
	string main = "\n\t\t���̵��� �ùķ�����";
	string closeMain = "\n���� ����\n������ ���ؼ��� ��ư�� �����ּ���.\n1. ���̰��� ��� ����\n2. ��ü ���̱ⱸ ���� ����\n3. �� ���̱ⱸ ���� ����\n4. ���̱ⱸ �߰��ϱ�\n5. ���̱ⱸ ���� �ϱ�\n6. ���̱ⱸ ���� �ϱ�\n7. �����ϱ�\n0. ���α׷� ����";

};



