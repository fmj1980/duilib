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

	CHelloDuilibWnd* wnd = new CHelloDuilibWnd; // ���ɶ���
	wnd->Create(NULL, NULL, UI_WNDSTYLE_DIALOG, 0); // ����DLG����
	wnd->CenterWindow(); // ���ھ���
	wnd->ShowWindow(); // ��ʾ

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	return 0;
}