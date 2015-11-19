#include "StdAfx.h"
#include "Hello.h"

using std::shared_ptr;

CHelloWorld::CHelloWorld()
{
	shared_ptr<int> sharedPtr = make_shared<int>(1);
	_weakPtr = weak_ptr<int>(sharedPtr);
	if ( !_weakPtr.expired())
	{
		shared_ptr<int> sharedPtr = _weakPtr.lock();
	}
}

CHelloWorld::~CHelloWorld()
{

}

void CHelloWorld::SayHello()
{
	shared_ptr<int> sharedPtr = _weakPtr.lock();
	bool expired = _weakPtr.expired();
	int* intPtr = sharedPtr.get();
	if ( intPtr != NULL)
	{
		int result = *intPtr;
	}
	this->TestTime();
	TestString();
	TestResource();
}


void CHelloWorld::TestTime()
{
	using namespace std::chrono;
	using namespace std;
	typedef duration<int, std::ratio<1>> days_type;
	time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
	time_t tcount = today.time_since_epoch().count();
	std:cout << today.time_since_epoch().count() << " days since epoch" << std::endl;

	clock_t time_clock = clock() / CLOCKS_PER_SEC;
	DWORD tikeCount = GetTickCount();

	tm* tm1 = localtime(&tcount);
	tm* t1 = gmtime(&tcount);
	time_t mkTime = mktime(tm1);
	time_t mkTime1 = _mkgmtime(tm1);
	time_t difTime = difftime(mkTime1, mkTime);

	char* charTime = asctime(tm1);
	char* cTime = ctime(&mkTime);

	char strTime[128];
	strftime(strTime, 128, "It is now %I %p", tm1);
	char strTime1[128];
	strftime(strTime1, 128, "Today is %A, day %d of %B in the year %Y.\n", tm1);

	struct tm *t;
	time_t tt;
	time(&tt);
	t = localtime(&tt);

	char buffer[50];
	sprintf(buffer, "%4d年%02d月%02d日 %02d:%02d:%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	wchar_t wbuffer[50];
	wsprintfW(wbuffer, _T("%4d adb"), t->tm_year);
	OutputDebugStringA(buffer);

	time_t start, end;
	start = time(NULL);
	Sleep(1000);
	//system("pause");
	end = time(NULL);
	char pauseTime[128];
	sprintf(pauseTime, "The pause used %f seconds.\n", difftime(end, start));//<- 
}

LPCTSTR format(LPCTSTR pstrFormat, ...)
{
	LPTSTR szSprintf = NULL;
	va_list argList;
	int nLen;
	va_start(argList, pstrFormat);
	nLen = ::_vsntprintf(NULL, 0, pstrFormat, argList);
	szSprintf = (TCHAR*)malloc((nLen + 1) * sizeof(TCHAR));
	ZeroMemory(szSprintf, (nLen + 1) * sizeof(TCHAR));
	int iRet = ::_vsntprintf(szSprintf, nLen + 1, pstrFormat, argList);
	va_end(argList);
	return szSprintf;
}

void CHelloWorld::TestString()
{
	char buffer[50];
	int index = 100;
	//int 转字符串
	sprintf(buffer, "%d", index); 
	OutputDebugStringA(buffer);

	//单字节字符串转int
	index = atoi(buffer);

	size_t len = strlen(buffer) + 1;
	wchar_t *wStr = (wchar_t*)malloc(len*sizeof(wchar_t));
	//单字节转宽直接
	mbstowcs_s(0, wStr, len, buffer, _TRUNCATE); 
	OutputDebugStringW(wStr);

	wchar_t wbuffer[50];
	wsprintfW(wbuffer, L"%d", index);
	//宽字节字符串转int
	index = _wtoi(wbuffer);
	OutputDebugStringW(wbuffer);
	len = wcslen(wbuffer) + 1;
	char *cStr = (char*)malloc(len*sizeof(char));
	//宽字节转单字节
	wcstombs_s(0, cStr, len, wbuffer, _TRUNCATE);
	OutputDebugStringA(cStr);

	wchar_t str[] = _T("Hello World");
	wchar_t* upperStr = _tcsupr(str);
	wchar_t* lowerStr = _tcslwr(str);
	ASSERT(_tcsicmp(lowerStr, _T("hello world")) == 0);

	//Left 3
	wchar_t leftChar[50];
	_tcsncpy(leftChar, str, 5);
	leftChar[5] = *(_T("\0"));

	//Mid 3 - 2
	wchar_t midChar[50];
	ZeroMemory(midChar, (50) * sizeof(TCHAR));
	_tcsncpy(midChar, str + 3 -1, 2);
	//midChar[2] = *(_T("\0"));

	//find ll
	LPCTSTR finPtr = _tcsstr(str, _T("ll"));
	if (finPtr != NULL){
		DWORD findIndex = finPtr - str;
	}

	//format
	LPCTSTR formatResut = format(_T("hello %d"), 123);

	//HASH KEY?
	UINT hash = 0;
	SIZE_T length = _tcslen(str);
	wchar_t cr = str[length - 1];
	while (length-- > 0) hash = (hash << 5) + hash + str[length];
}

void CHelloWorld::TestResource()
{
	HINSTANCE instace = CPaintManagerUI::GetInstance();
	char strHello[40];
	LoadStringA(instace, IDS_STRING_HELLO, strHello, 40);

	HICON icon = LoadIcon(instace, MAKEINTRESOURCE(IDI_ICON));

	HMODULE module = GetModuleHandle(NULL);
	ASSERT(instace == module);

	HRSRC   hResource = FindResource(instace,MAKEINTRESOURCE(IDR_HELLO_WND), TEXT("XML"));
 	if ( !hResource )
	{
		return;
	}
	HGLOBAL hGlobal = ::LoadResource(instace, hResource);
	if ( hGlobal)
	{
		LPVOID   pData = LockResource(hGlobal);
		if ( pData)
		{
			DWORD dwSize = SizeofResource(instace, hResource);

			TCHAR tszModule[MAX_PATH + 1] = { 0 };
			::GetModuleFileName(instace, tszModule, MAX_PATH);
			CDuiString sInstancePath = tszModule;
			int pos = sInstancePath.ReverseFind(_T('\\'));
			if (pos >= 0) sInstancePath = sInstancePath.Left(pos + 1);
			sInstancePath += _T("Hello.xml");

			CFile   calcFile;
			if (calcFile.Open(sInstancePath, CFile::modeCreate | CFile::modeReadWrite))
			{
				calcFile.Write(pData, dwSize);
				calcFile.Close();
			}
		}
	}
}

