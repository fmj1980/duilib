#include "StdAfx.h"
#include "Hello.h"
#include "CHelloWnd.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{

	CPaintManagerUI::SetInstance(hInstance);
	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	CHelloWorld hello;
	hello.SayHello();

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

	CHelloDuilibWnd* wnd = new CHelloDuilibWnd; // 生成对象
	wnd->Create(NULL, NULL, UI_WNDSTYLE_DIALOG, 0); // 创建DLG窗口
	wnd->CenterWindow(); // 窗口居中
	wnd->ShowWindow(); // 显示

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	return 0;
}