#pragma once

class CTreeTab :
	public CContainerUI
{
public:
	CTreeTab(CPaintManagerUI* ppm);
	~CTreeTab(void);

	bool OnFolderChanged(void* param);
};
