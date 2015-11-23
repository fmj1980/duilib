#include "StdAfx.h"
#include "CHelloWnd.h"



CHelloDuilibWnd::CHelloDuilibWnd(void)
{

}

CHelloDuilibWnd::~CHelloDuilibWnd(void)
{

}

DuiLib::CDuiString CHelloDuilibWnd::GetSkinFolder()
{
	return _T("skin");
}

DuiLib::CDuiString CHelloDuilibWnd::GetSkinFile()
{
	return _T("HelloDuilib.xml");
}

LPCTSTR CHelloDuilibWnd::GetWindowClassName(void) const
{
	return _T("HelloDuilib_Wnd");
}


void CHelloDuilibWnd::Notify(TNotifyUI& msg)
{
	if (_tcsicmp(msg.sType, _T("click")) == 0)
	{
		if (_tcsicmp(msg.pSender->GetName(), _T("closebtn")) == 0)
		{
			/*PostMessage(WM_CLOSE, 0L, 0L);
			::PostQuitMessage(0);*/
		}
	}
}



void CHelloDuilibWnd::InitWindow()
{
	CLabelUI* helloTxUI = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("apptitle")));
	helloTxUI->SetText(_T("hehe"));
	CButtonUI* btnClose = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("closebtn")));
	CVerticalLayoutUI* layoutBody = static_cast<CVerticalLayoutUI*>(m_PaintManager.FindControl(_T("body")));

	CLabelUI* txtUI = new CLabelUI();
	layoutBody->Add(txtUI);
	txtUI->SetFloat(true);
	txtUI->SetPos({ 10, 10, 0, 0 });
	txtUI->SetFixedWidth(200);
	txtUI->SetFixedHeight(20);
	txtUI->SetText(_T("Hello Dynamic Text"));
	layoutBody->NeedUpdate();

	btnClose->OnEvent += MakeDelegate(this, &CHelloDuilibWnd::OnCloseClicked);
}

bool CHelloDuilibWnd::OnCloseClicked(void* param)
{
	TEventUI* pMsg = (TEventUI*)param;
	if (pMsg->Type == UIEVENT_BUTTONUP)
	{
		return true;
	}
	else if (pMsg->Type == UIEVENT_DBLCLICK)
	{
		return true;
	}
	return true;
}
