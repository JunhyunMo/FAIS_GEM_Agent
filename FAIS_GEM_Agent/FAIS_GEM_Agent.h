
// FAIS_GEM_Agent.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CFAIS_GEM_AgentApp:
// �� Ŭ������ ������ ���ؼ��� FAIS_GEM_Agent.cpp�� �����Ͻʽÿ�.
//

class CFAIS_GEM_AgentApp : public CWinApp
{
public:
	CFAIS_GEM_AgentApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CFAIS_GEM_AgentApp theApp;