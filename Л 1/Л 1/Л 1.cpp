// Л 1.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Л 1.h"

#define MAX_LOADSTRING 100
#include <iostream>
#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
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
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 25); 	// Заполнение окна белым цветом 


	// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		_T("Каркас Windows-приложения"), 		// Заголовок окна 
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
	static int v=0;
	PAINTSTRUCT ps;
	RECT fr;
	HDC hdc;
	int a=50,b=50;
	switch (message)
	{
		case WM_PAINT :
		{
			
			if (v == 1)
			{
				hdc = BeginPaint(hwnd, &ps);
				for (int i = 0; i < 200; i = i + 85)
				{
					for (int j = 0; j < 200; j = j + 25)
					{
						HPEN hpen = CreatePen(0, 3, RGB(rand() % 100, rand() % 100, rand() % 100));
						SelectObject(hdc, hpen);
						MoveToEx(hdc, a, b, NULL);
						LineTo(hdc, i, j);
					}
				}
				EndPaint(hwnd, &ps);
			}
			if(v==2)
			{
				hdc = BeginPaint(hwnd, &ps);
				a = a + rand() % 700;
				b = b + rand() % 400;
				for (int i = a - 50; i < a + 150; i = i + 85)
				{
					for (int j = b - 50; j < b + 150; j = j + 25)
					{
						HPEN hpen = CreatePen(0, 3, RGB(rand() % 100, rand() % 100, rand() % 100));
						SelectObject(hdc, hpen);
						MoveToEx(hdc, a, b, NULL);
						LineTo(hdc, i, j);
					}
				}
				EndPaint(hwnd, &ps);
			}
			/*ValidateRect(hwnd, NULL);*/
			
			break;
		}
	case WM_LBUTTONDOWN:
	{
		v = 1;
		InvalidateRect(hwnd, &fr, TRUE);
		/*HDC hdc = GetDC(hwnd);
		for (int i = 0; i < 200; i = i + 85)
		{
			for (int j = 0; j < 200; j = j + 25)
			{
				HPEN hpen = CreatePen(0, 3, RGB(rand() % 100, rand() % 100, rand() % 100));
				SelectObject(hdc, hpen);
				MoveToEx(hdc, a, b, NULL);
				LineTo(hdc, i, j);
			}
		}
		ValidateRect(hwnd, NULL);
		EndPaint(hwnd, &ps);*/
		break; 
	}
	case WM_RBUTTONDOWN:
	{
		v = 2;
		InvalidateRect(hwnd, &fr,TRUE);
		/*a = a+rand()%700;
		b = b+rand() % 400;
			for (int i = a-50; i < a+150; i = i + 85)
			{
				for (int j = b-50; j < b + 150; j = j + 25)
				{
					HPEN hpen = CreatePen(0, 3, RGB(rand() % 100, rand() % 100, rand() % 100));
					SelectObject(hdc, hpen);
					MoveToEx(hdc, a, b, NULL);
					LineTo(hdc, i, j);
				}
			}*/
		/*ValidateRect(hwnd, NULL);
		EndPaint(hwnd, &ps);*/
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break; 			// Завершение программы 
	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
