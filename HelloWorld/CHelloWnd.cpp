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
