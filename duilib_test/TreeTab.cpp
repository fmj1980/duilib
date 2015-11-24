
#include "stdafx.h"
#include "TreeTab.h"
#include "DialogBuilderCallbackEx.h"
#include "MyList.h"
#include "TreeView.h"

CTreeTab::CTreeTab(CPaintManagerUI* ppm)
{
	CDialogBuilder builder;
	CDialogBuilderCallbackEx cb (ppm);
	CContainerUI* pbtnTab = static_cast<CContainerUI*>(builder.Create(_T("tree.xml"), 0, &cb, ppm));
	if( pbtnTab ) {
		this->Add(pbtnTab);
	}
	else {
		this->RemoveAll();
		return;
	}

	CDuiTreeView* pTree1 = static_cast<CDuiTreeView*>(pbtnTab->FindSubControl(_T("Tree1")));
	pTree1->OnNotify += MakeDelegate(this,&CTreeTab::OnFolderChanged);
	if (pTree1) {
		pTree1->SetDepth(4);
		pTree1->SetExpandImage(_T("tree_expand.png"));
		CDuiTreeView::Node* pCategoryNode = NULL;
		CDuiTreeView::Node* pGameNode = NULL;
		CDuiTreeView::Node* pServerNode = NULL;
		CDuiTreeView::Node* pRoomNode = NULL;
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}�Ƽ���Ϸ"));
		for (int i = 0; i < 4; ++i)
		{
			pGameNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}���˶�����"), pCategoryNode);
			for (int i = 0; i < 3; ++i)
			{
				pServerNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}���Է�����"), pGameNode);
				for (int i = 0; i < 3; ++i)
				{
					pRoomNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}���Է���"), pServerNode);
				}
			}
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}����������Ϸ"));
		for (int i = 0; i < 2; ++i)
		{
			pTree1->AddNode(_T("��ȱһ"), pCategoryNode);
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}������Ϸ"));
		for (int i = 0; i < 8; ++i)
		{
			pTree1->AddNode(_T("˫��"), pCategoryNode);
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}������Ϸ"));
		for (int i = 0; i < 8; ++i)
		{
			pTree1->AddNode(_T("������"), pCategoryNode);
		}
	}
}

CTreeTab::~CTreeTab(void)
{
}

bool CTreeTab::OnFolderChanged(void* param)
{
	TNotifyUI* pMsg = (TNotifyUI*)param;
	if (pMsg->sType == _T("selectchanged"))
	{
	
		return true;
	}
	return true;
}
