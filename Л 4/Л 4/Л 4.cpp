// Л 4.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Л 4.h"

//const char szClassName[] = "WinLab_01";
//const char szWindowName[] = "Term II. Windows Lab 01.";
//
//#define MAX_LOADSTRING 100
//#include <iostream>
//#include <Windows.h>
//#include <tchar.h>
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
//
////#pragma argsused
//TCHAR WinName[] = _T("MainFrame");
//
////int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine,
////	int nCmdShow)
//
//int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
//	HINSTANCE Prev, 	// В современных системах всегда 0 
//	LPTSTR cmd, 		// Командная строка 
//	int mode) 		// Режим отображения окна
//{
//	HWND hWnd;		// Дескриптор главного окна программы 
//	MSG msg; 		// Структура для хранения сообщения 
//	WNDCLASS wc; 	// Класс окна
//	// Определение класса окна 
//	wc.hInstance = This;
//	wc.lpszClassName = WinName; 				// Имя класса окна 
//	wc.lpfnWndProc = WndProc; 					// Функция окна 
//	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
//	wc.hIcon = LoadIcon(This, IDI_APPLICATION); 		// Стандартная иконка 
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
//	wc.lpszMenuName = NULL; 					// Нет меню 
//	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
//	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 
//
//	// Регистрация класса окна
//	if (!RegisterClass(&wc)) /*return 0;*/  exit(FALSE);
//
//	// Создание окна 
//	hWnd = CreateWindow(WinName,			// Имя класса окна 
//		_T("Каркас Windows-приложения"), 		// Заголовок окна 
//		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
//		CW_USEDEFAULT,				// x 
//		/*CW_USEDEFAULT*/0, 				// y	 Размеры окна 
//		CW_USEDEFAULT, 				// width 
//		/*CW_USEDEFAULT*/0, 				// Height 
//		/*HWND_DESKTOP*/NULL, 				// Дескриптор родительского окна 
//		NULL, 						// Нет меню 
//		This, 						// Дескриптор приложения 
//		NULL); 					// Дополнительной информации нет 
//
//	if (!hWnd)
//		exit(FALSE);
//
//	ShowWindow(hWnd, mode); 				// Показать окно
//	UpdateWindow(hWnd);
//
//	// Цикл обработки сообщений 
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
//		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
//	}
//	return msg.wParam;
//}
//
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, message, wParam, lParam);
//	}
//	return 0;
//}


#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <wchar.h>
#define DIV 1024
#define WIDTH 7
//#pragma warning(disable:4996)

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("4 laba");

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
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK); 		// Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wc.lpszMenuName = NULL; 					// Нет меню 
	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wc.lpszMenuName = MAKEINTRESOURCE(IDC_MY4);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 

	RegisterClass(This);
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

	HMENU MainMenu = CreateMenu();
	HMENU hPopupMenu = CreatePopupMenu();
	HMENU hPopupMenu2 = CreatePopupMenu();
	/*AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu, L"&Месяц ");
	{
		AppendMenu(hPopupMenu, MF_STRING, 1, L"Вкл");
		AppendMenu(hPopupMenu, MF_STRING, 2, L"Выкл");
	}
	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu2, L"&Память ");
	{
		AppendMenu(hPopupMenu2, MF_STRING, 3, L"Вкл");
		AppendMenu(hPopupMenu2, MF_STRING, 4, L"Выкл");
	}*/
	SetMenu(hWnd, MainMenu);

	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	return 0;
}
HANDLE hThread1;
HANDLE hThread2;
DWORD WINAPI Thread1(LPVOID t);
DWORD WINAPI Thread2(LPVOID t);

BOOL z1 = true;
BOOL z2 = true;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)		 // Обработчик сообщений
	{
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		PostQuitMessage(0);
		break; 			// Завершение программы 
	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);
	case WM_COMMAND:
		switch (wParam)
		{
		case IDM_Moon:
		{
			z1 = true;
			hThread1 = CreateThread(NULL, 0, Thread1, hWnd, 0, NULL);
			break;
		}
		case IDM_NOTMoon:
		{
			TerminateThread(hThread1, 0);
			CloseHandle(hThread1);
			z1 = FALSE;
			break;
		}
		case IDM_Memory:
		{
			z2 = TRUE;
			hThread2 = CreateThread(NULL, 0, Thread2, hWnd, 0, NULL);
			break;
		}
		case IDM_NOTMemory:
		{
			TerminateThread(hThread2, 0);
			CloseHandle(hThread2);
			z2 = FALSE;
			break;
		}
		}
	}
	return 0;
}

DWORD WINAPI Thread1(LPVOID t)
{
	bool c;
	int clr = 30;
	//int width = 0;
	//int height = 0;
	RECT rect;
	while (z1)
	{
		GetWindowRect(HWND(t), &rect);
		/*width = (int)(rect.right - rect.left);
		height = (int)(rect.bottom - rect.top);*/
		if (clr > 200) c = true;
		if (clr < 40) c = false;
		if (c) clr = clr - 20;
		if (!c) clr = clr + 20;
			HDC hdc = GetDC(HWND(t));
			HBRUSH hBrush;
			HPEN hPen;
			hBrush = CreateSolidBrush(RGB(0, 200, 250));
			hPen = CreatePen(PS_NULL, 1, RGB(255, 255, 255));
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Ellipse(hdc, 20, 20, /*width /*/ 350, 350);
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			hPen = CreatePen(PS_NULL, 1, RGB(255, 255, 255));
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			/*SelectObject(hdc, hPen);*/
			Ellipse(hdc, clr, 20, 350,350);
			ReleaseDC(HWND(t), hdc);
			Sleep(10);
	}
	return (0);
}

DWORD WINAPI Thread2(LPVOID t)
{
	/*int width = 0;
	int height = 0;*/
	RECT rect;
	MEMORYSTATUSEX stat;
	TCHAR buff[300];
	while (z2)
	{
		stat.dwLength = sizeof(stat);
		GlobalMemoryStatusEx(&stat);
		GetWindowRect(HWND(t), &rect);
		/*width = (int)(rect.right - rect.left);
		height = (int)(rect.bottom - rect.top);*/
		HDC hdc1 = GetDC(HWND(t));
		SetTextColor(hdc1, RGB(0, 230, 200));
		swprintf_s(buff, TEXT("Свободно %*I64d KB физической памяти.\n"), WIDTH, stat.ullAvailPhys / DIV);
		TextOut(hdc1, 550, 120, buff, _tcslen(buff));

		swprintf_s(buff, TEXT("Всего имеется %*I64d KB физической памяти.\n"), WIDTH, stat.ullTotalPhys / DIV);
		TextOut(hdc1, 550, 20, buff, _tcslen(buff));
		Sleep(250);
	}
	return 0;
}