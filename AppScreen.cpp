#include <Windows.h>
#include <conio.h>
#include <string>
#include "Screen.cpp"
using namespace std;

class AppScreen {

public:
	AppScreen() {}
	void run() { 
		char* c = &main[0];
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
			screen.ScreenPrint(0, 0, c);
			screen.ScreenShow();
			Sleep(1000);
			main = "\n\t\t어서오세요~";
			screen.ScreenPrint(0, 0, c);
			screen.ScreenShow();
			Sleep(1000);
		}
	}



private:
	Screen screen;
	string main = "\n\t\t놀이동산 시뮬레이터";
};
