
//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：定义应用程序的入口点。
//			在这儿将之后会用到的数据发送到MyDirector单例中
//			在这儿设定游戏速度 （次刷新/秒）


// win32_Mygame.cpp : 定义应用程序的入口点。
//
#include "stdafx.h"
#include "win32_Mygame.h"
#include "MyDirector.h"
#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明:
void CALLBACK clock_proc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);
void setKeyStatu(string key,string statu);
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	
	float size1=0.6;

	size winSize(712*size1,1024*size1);
	MyDirector::getDirector()->setWinSize(winSize);
	
	MSG msg;
	HACCEL hAccelTable;
	
	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32_MYGAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	
	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}
	
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32_MYGAME));

	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
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
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32_MYGAME));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32_MYGAME);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,
	   CW_USEDEFAULT, 0, MyDirector::getDirector()->getWinSize().x, MyDirector::getDirector()->getWinSize().y, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	MyDirector::getDirector()->setHWND(hWnd);
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	
	static bool isopen=false;
	switch (message)
	{
	case WM_CREATE:
		{
			SetTimer(hWnd, 10, 1000/80,clock_proc);  
		  return 0 ; 
		}
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
		
	case WM_KEYDOWN:
		{
			string temp="DOWN";
			switch(wParam) 
			{
			case VK_UP:
				{	
					setKeyStatu("UP", temp);
					break;
				}
			case VK_DOWN:
				{
					setKeyStatu("DOWN", temp);
					break;
				}
			case VK_LEFT:
				{	
					setKeyStatu("LEFT", temp);
					break;
				}
			case VK_RIGHT:
				{
					setKeyStatu("RIGHT", temp);
					break;
				}
			case VK_SHIFT:
				{
					setKeyStatu("SHIFT", temp);
					break;
				}
			default:
				{
					char asc=wParam;
					string key;
					key=asc;
					setKeyStatu(key, temp);
					
			

				}
			}
			break;
		}
	
	case WM_KEYUP:
		{
			string temp="UP";
			switch(wParam) 
			{
			case VK_UP:
				{	
					setKeyStatu("UP", temp);
					break;
				}
			case VK_DOWN:
				{
					setKeyStatu("DOWN", temp);
					break;
				}
			case VK_LEFT:
				{	
					setKeyStatu("LEFT", temp);
					break;
				}
			case VK_RIGHT:
				{
					setKeyStatu("RIGHT", temp);
					break;
				}
			case VK_SHIFT:
				{
					setKeyStatu("SHIFT", temp);
				
					break;
				}
			default:
				{
					
					char asc=wParam;
					string key;
					key=asc;
					setKeyStatu(key, temp);
				

				}
			}
		}
	case WM_LBUTTONDOWN:
		{
			MyDirector::getDirector()->setKeyStatu("LBUTTON","DOWN");
			MyDirector::getDirector()->Mousex=LOWORD(lParam);
			MyDirector::getDirector()->Mousey=HIWORD(lParam);		
		}
		break;
	case WM_LBUTTONUP:
		{
			MyDirector::getDirector()->setKeyStatu("LBUTTON","UP");
			MyDirector::getDirector()->Mousex=LOWORD(lParam);
			MyDirector::getDirector()->Mousey=HIWORD(lParam);
		}
		break;
	case WM_MOUSEMOVE:
		{
			MyDirector::getDirector()->Mousex=LOWORD(lParam);
			MyDirector::getDirector()->Mousey=HIWORD(lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//MyDirector::getDirector()->update();
		// TODO: 在此添加任意绘图代码...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		
		KillTimer(hWnd,10);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
void setKeyStatu(string key,string statu)
{
	MyDirector::getDirector()->setKeyStatu(key,statu);
}
// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
void CALLBACK clock_proc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
	MyDirector::getDirector()->update();
}
