
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
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}推荐游戏"));
		for (int i = 0; i < 4; ++i)
		{
			pGameNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}四人斗地主"), pCategoryNode);
			for (int i = 0; i < 3; ++i)
			{
				pServerNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}测试服务器"), pGameNode);
				for (int i = 0; i < 3; ++i)
				{
					pRoomNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}测试房间"), pServerNode);
				}
			}
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}最近玩过的游戏"));
		for (int i = 0; i < 2; ++i)
		{
			pTree1->AddNode(_T("三缺一"), pCategoryNode);
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}棋牌游戏"));
		for (int i = 0; i < 8; ++i)
		{
			pTree1->AddNode(_T("双扣"), pCategoryNode);
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}休闲游戏"));
		for (int i = 0; i < 8; ++i)
		{
			pTree1->AddNode(_T("飞行棋"), pCategoryNode);
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
