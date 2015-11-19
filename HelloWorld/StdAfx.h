#define  _AFXDLL

#include <afx.h>
#include <objbase.h>
#include <zmouse.h>
#include <exdisp.h>
#include <comdef.h>
#include <vector>
#include <sstream>

#include <exception>
#include <stack>
#include <mutex>
#include <memory>

#include <chrono>
#include <iostream>
#include <time.h>
//#include <windows.h>

#include "..\DuiLib\UIlib.h"

#include "resource.h"

using namespace DuiLib;

//#ifdef _DEBUG
//#   ifdef _UNICODE
//#       pragma comment(lib, "..\\Lib\\DuiLib_ud.lib")
//#   else
//#       pragma comment(lib, "..\\Lib\\DuiLib_d.lib")
//#   endif
//#else
//#   ifdef _UNICODE
//#       pragma comment(lib, "..\\Lib\\DuiLib_u.lib")
//#   else
//#       pragma comment(lib, "..\\Lib\\DuiLib.lib")
//#   endif
//#endif
