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
	string main = "\n\t\t놀이동산 시뮬레이터";
	string closeMain = "\n폐장 상태\n동작을 위해서는 버튼을 눌러주세요.\n1. 놀이공원 통계 보기\n2. 전체 놀이기구 정보 보기\n3. 상세 놀이기구 정보 보기\n4. 놀이기구 추가하기\n5. 놀이기구 수정 하기\n6. 놀이기구 삭제 하기\n7. 개장하기\n0. 프로그램 종료";

};



