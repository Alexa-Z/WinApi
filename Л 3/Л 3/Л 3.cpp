// Л 3.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Л 3.h"

#define MAX_LOADSTRING 100
#include <iostream>
#include <Windows.h>
#include <Windowsx.h>
#include <tchar.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
int Timer1 = 1;
int Timer2 = 2;
int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWnd;		// Дескриптор главного окна программы 
	MSG msg; 		// Структура для хранения сообщения 
	WNDCLASS wc; 	// Класс окна
	// Определение класса окна 
	wc.hInstance = This;
	wc.lpszClassName = WinName; 				// Имя класса окна 
	wc.lpfnWndProc = WndProc; 					// Функция окна 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wc.lpszMenuName = NULL; 					// Нет меню 
	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 


	// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		_T("Это таймер!"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

	ShowWindow(hWnd, mode); 				// Показать окно

	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int x = 10, y = 10;
	static wchar_t*symbol = new wchar_t[100];
	static int size = 0;
	static int time = 0;
	static int time2 = 0;
	wchar_t text[255];
	HDC hDC;
	PAINTSTRUCT paintStruct;
	RECT clientRect;
	RECT rect = { x,y,x + 70,y + 70 };
	HFONT hFont = CreateFont(90, 0, 0, 0, 0, 0, 0, 0,
		DEFAULT_CHARSET,
		0, 0, 0, 0,
		L"Arial Bold");
	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &paintStruct);
		GetClientRect(hwnd, &clientRect);
		if (size > 0)
			DrawText(hDC, (LPCWSTR)symbol, size, &clientRect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &paintStruct);
		break;
	case WM_TIMER:
		
		if (wParam == Timer1)
			time++;
		else if (wParam == Timer2)
			time2++;
		hDC = GetDC(hwnd);
		for (int i = 0; i < 21; i++)
			text[i] = NULL;
		wsprintf(text, TEXT("Timer1=%d, timer2=%d"), time2, time);
		TextOut(hDC, 300, 100, text, 21);
		break;
	case WM_LBUTTONDOWN:
		KillTimer(hwnd, Timer1);    
		KillTimer(hwnd, Timer2);
		break;
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		break;
	case WM_CHAR:
		if (wParam == VK_RETURN)
		{
			size = 0;
			SetTimer(hwnd, Timer1, 100, (TIMERPROC)WndProc);
			SetTimer(hwnd, Timer2, 1000, NULL);
		}
		if (wParam == VK_BACK)
		{
			size--;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		else
		{
			symbol[size] = (wchar_t)wParam;
			size++;
		}
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}


/*UINT_PTR SetTimer(
	HWND hWnd,
	UINT_PTR nIDEvent,
	UINT uElapse,
	TIMERPROC lpTimerFunc);


	SetTimer(hwnd, ID_TIMERn, iMsecInterval, TimerProc);
#define ID_TIMER1   1
#define ID_TIMER2   2
	void CALLBACK TimerProc(HWND hwnd, UINT Msg, UINT iTimerID,
		DWORD dwTimer)
	{
		// Запись информации на диск
	}
	int CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam,
		LPARAM lParam) {
		
			switch (Msg) {
			case WM_CREATE:
				SetTimer(hwnd, ID_TIMER1, 60000, (TIMERPROC)TimerProc);
				SetTimer(hwnd, ID_TIMER2, 1000, NULL);   			break;
			case WM_TIMER:
				if (wParam == ID_TIMER2) InvalidateRect(hwnd, NULL, FALSE);
				break;
			case WM_PAINT:      					break;
			case WM_DESTROY:
				KillTimer(hwnd, ID_TIMER1);    KillTimer(hwnd, ID_TIMER2);
				break;
				
			}
	
		LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
		{

	return 0;
}*/

