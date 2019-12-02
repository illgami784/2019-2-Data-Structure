#include <Windows.h>


class Screen {
public:
	Screen() {
		CONSOLE_CURSOR_INFO cci;

		ScreenBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		ScreenBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		current = &ScreenBuffer[0];
		next = &ScreenBuffer[1];

		cci.dwSize = 1;
		cci.bVisible = FALSE;
		SetConsoleCursorInfo(ScreenBuffer[0], &cci);
		SetConsoleCursorInfo(ScreenBuffer[1], &cci);

	}

	void ScreenClear()
	{
		COORD Coor = { 0,0 };
		DWORD dw;
		FillConsoleOutputCharacter(*(current), ' ', 80 * 25, Coor, &dw);
	}

	void ScreenPrint(int x, int y, char* string)//print a string on the position.
	{
		DWORD dw;
		COORD CursorPosition = { x, y };
		SetConsoleCursorPosition(*(current), CursorPosition);
		WriteFile(*(next), string, strlen(string), &dw, NULL);
		swap();
	}

	void ScreenShow()
	{
		SetConsoleActiveScreenBuffer(*(current));
	}

private:
	void swap() {
		HANDLE* temp = current;
		current = next;
		next = temp;
	}
	HANDLE ScreenBuffer[2];
	HANDLE* current;
	HANDLE* next;
};

