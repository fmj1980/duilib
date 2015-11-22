#pragma once
#include "StdAfx.h"

class CHelloDuilibWnd :
	public WindowImplBase
{
public:
	CHelloDuilibWnd(void);
	~CHelloDuilibWnd(void);

protected:
	virtual CDuiString GetSkinFolder();;
	virtual CDuiString GetSkinFile();;
	virtual LPCTSTR GetWindowClassName(void) const;;
	virtual void Notify(TNotifyUI& msg);
	virtual void InitWindow();
	bool OnCloseClicked(void* param);
};