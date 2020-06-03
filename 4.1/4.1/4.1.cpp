// 4.1.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "4.1.h"
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <wchar.h>
#define DIV 1024
#define WIDTH 7
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY41, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY41));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY41));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY41);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)
//    {
//    case WM_COMMAND:
//        {
//            int wmId = LOWORD(wParam);
//            // Разобрать выбор в меню:
//            switch (wmId)
//            {
//            case IDM_ABOUT:
//                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//                break;
//            case IDM_EXIT:
//                DestroyWindow(hWnd);
//                break;
//            default:
//                return DefWindowProc(hWnd, message, wParam, lParam);
//            }
//        }
//        break;
//    case WM_PAINT:
//        {
//            PAINTSTRUCT ps;
//            HDC hdc = BeginPaint(hWnd, &ps);
//            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
//            EndPaint(hWnd, &ps);
//        }
//        break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
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
		Ellipse(hdc, clr, 20, 350, 350);
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
