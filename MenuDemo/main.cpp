//
// main.cpp
// ~~~~~~~~
//
// Copyright (c) 2011 achellies (achellies at 163 dot com)
//
// This code may be used in compiled form in any way you desire. This
// source file may be redistributed by any means PROVIDING it is 
// not sold for profit without the authors written consent, and 
// providing that this notice and the authors name is included. 
//
// This file is provided "as is" with no expressed or implied warranty.
// The author accepts no liability if it causes any damage to you or your
// computer whatsoever. It's free, so don't hassle me about it.
//
// Beware of bugs.
//

#include "stdafx.h"
#include "..\DuiLib\Utils\WinImplBase.h"
#include "main_frame.hpp"
#include <chrono>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <atlbase.h>
#include <atlconv.h>

#if defined(WIN32) && !defined(UNDER_CE)
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
#else
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nCmdShow)
#endif
{
//	using namespace std::chrono;
//	using namespace std;
//	typedef duration<int, std::ratio<1>> days_type;
//	time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
//	time_t tcount = today.time_since_epoch().count();
//std:cout << today.time_since_epoch().count() << " days since epoch" << std::endl;
//
//	clock_t time_clock = clock() / CLOCKS_PER_SEC;
//	DWORD tikeCount = GetTickCount();
//
//	tm* tm1 = localtime(&tcount);
//	tm* t1 = gmtime(&tcount);
//	time_t mkTime = mktime(tm1);
//	time_t mkTime1 = _mkgmtime(tm1);
//	time_t difTime = difftime(mkTime1, mkTime);
//
//	char* charTime = asctime(tm1);
//	char* cTime = ctime(&mkTime);
//
//	char strTime[128];
//	strftime(strTime, 128, "It is now %I %p", tm1);
//	char strTime1[128];
//	strftime(strTime1, 128, "Today is %A, day %d of %B in the year %Y.\n", tm1);
//
//	struct tm *t;
//	time_t tt;
//	time(&tt);
//	t = localtime(&tt);
//
//	char buffer[50];
//	sprintf(buffer, "%4dÄê%02dÔÂ%02dÈÕ %02d:%02d:%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
//	OutputDebugStringA(buffer);
//
//	time_t start, end;
//	start = time(NULL);
//	Sleep(1000);
//	//system("pause");
//	end = time(NULL);
//	char pauseTime[128];
//	sprintf(pauseTime,"The pause used %f seconds.\n", difftime(end, start));//<- 
//
	CPaintManagerUI::SetInstance(hInstance);



#if defined(WIN32) && !defined(UNDER_CE)
	HRESULT Hr = ::CoInitialize(NULL);
#else
	HRESULT Hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
#endif
	if (FAILED(Hr)) return 0;

	MainFrame* pFrame = new MainFrame();
	if (pFrame == NULL) return 0;
#if defined(WIN32) && !defined(UNDER_CE)
	pFrame->Create(NULL, _T("MenuTest"), UI_WNDSTYLE_FRAME, WS_EX_STATICEDGE | WS_EX_APPWINDOW, 0, 0, 600, 800);
#else
	pFrame->Create(NULL, _T("MenuTest"), UI_WNDSTYLE_FRAME, WS_EX_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
#endif
	pFrame->CenterWindow();
	::ShowWindow(*pFrame, SW_SHOW);

	CPaintManagerUI::MessageLoop();

	return 0;
}