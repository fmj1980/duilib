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
	sprintf(buffer, "%4dÄê%02dÔÂ%02dÈÕ %02d:%02d:%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
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

