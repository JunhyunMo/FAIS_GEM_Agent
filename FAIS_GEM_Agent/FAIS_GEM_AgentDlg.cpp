﻿
// FAIS_GEM_AgentDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "FAIS_GEM_Agent.h"
#include "FAIS_GEM_AgentDlg.h"
#include "afxdialogex.h"
#include "Global.h" //MJH 2017-08-26

#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFAIS_GEM_AgentDlg 대화 상자



CFAIS_GEM_AgentDlg::CFAIS_GEM_AgentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFAIS_GEM_AgentDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFAIS_GEM_AgentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXGEMCTRL1, m_XGem);
	DDX_Control(pDX, IDC_LIST_GEM, m_ctlListGEM);
	DDX_Control(pDX, IDC_LIST_TCP, m_ctlListTCP);
}

BEGIN_MESSAGE_MAP(CFAIS_GEM_AgentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_START, &CFAIS_GEM_AgentDlg::OnBnClickedBtStart)
	ON_BN_CLICKED(IDC_BT_STOP, &CFAIS_GEM_AgentDlg::OnBnClickedBtStop)
	ON_BN_CLICKED(IDC_BT_SVR_STOP, &CFAIS_GEM_AgentDlg::OnBnClickedBtSvrStop)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BT_SVR_START, &CFAIS_GEM_AgentDlg::OnBnClickedBtSvrStart)
END_MESSAGE_MAP()


// CFAIS_GEM_AgentDlg 메시지 처리기

BOOL CFAIS_GEM_AgentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	//중복실행방지
	HANDLE hEvent;
    hEvent = CreateEvent(NULL, FALSE, TRUE, AfxGetAppName());
    if ( GetLastError() == ERROR_ALREADY_EXISTS)
    {
        PostQuitMessage(WM_QUIT);
    }
	//

	SetDlgItemText(IDC_EDIT_SVR_PORT,L"10101");
	ShowWindow(SW_MINIMIZE);

	SvrStart();

	XGemStart();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFAIS_GEM_AgentDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFAIS_GEM_AgentDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFAIS_GEM_AgentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFAIS_GEM_AgentDlg::MBCS2Unicode(LPCSTR lpData,LPWSTR ReturnData)
{
	memset(ReturnData,0,(strlen(lpData)/2)+5);
	MultiByteToWideChar(949,0,lpData,-1,ReturnData,strlen(lpData));
	return;
}

void CFAIS_GEM_AgentDlg::Unicode2MBCS(LPWSTR lpData,LPSTR lpRtd)
{
	memset(lpRtd,0x00,wcslen(lpData)*2+1);
	WideCharToMultiByte(949,0,lpData,-1,lpRtd,wcslen(lpData)*2,NULL,NULL);
	return;
}

void CFAIS_GEM_AgentDlg::ProcGEM_FromEQ(CString strIP, CString strRcv)
{
	CString strMsg;// = L"[RCV]" + strRcv;
	strMsg.Format(L"[RCV](%s) %s",strIP,strRcv);
	AddLogTCP(strMsg);
	GetLog()->Debug(strMsg.GetBuffer());

	CString strCommand,strPacketBody;
	CString strSend;

	long  nRet = -1;

	strCommand = strRcv.Left(3);
	strPacketBody = strRcv.Mid(8);

	if(strCommand == L"STA")
	{
		nRet = XGemStart(); //OnLine Remote 

		if(	nRet == 0)
		{
			strSend = L"STA0011|OK|";
		}
	}
	else if(strCommand == L"STP")
	{
		nRet = XGemStop(); 
		strSend = L"STP0011|OK|";
	}
	else if(strCommand == L"ERS") //2017-09-20 
	{
		nRet = SendERS(strPacketBody);
		if(nRet >= 0)
		{
			strSend = L"ERS0011|OK|";
		}
		else
		{
			strSend = L"ERS0011|NG|";
		}
	}
	else if(strCommand == L"ARS")
	{
		nRet = SendARS(strPacketBody);
		if(nRet == 0)
		{
			strSend = L"ARS0011|OK|";
		}
		else
		{
			strSend = L"ARS0011|NG|";
		}
	}
	//else if(strCommand == L"TDS")
	//{
	//	return;
	//}
	//else
	//{
	//	strSend.Format(L"%s - Unknown Command",strCommand);
	//}

	//
	if(m_ListenSocket.SendData(strIP, strSend)==TRUE)
	{
		strMsg.Format(L"[SND](%s) %s",strIP,strSend);
		AddLogTCP(strMsg);
		GetLog()->Debug(strMsg.GetBuffer());
	}
	
}

void CFAIS_GEM_AgentDlg::ProcGEM_ToEQ(CString strSendPacket)
{
	m_ListenSocket.SendDataAll(strSendPacket.GetBuffer());
	
	CString strMsg;
	strMsg.Format(L"[SND-ALL] %s",strSendPacket);
	AddLogTCP(strMsg);
	GetLog()->Debug(strMsg.GetBuffer());
	
}

void CFAIS_GEM_AgentDlg::AddLogGEM(CString str)
{
	m_ctlListGEM.AddString(str);

	int nCnt = m_ctlListGEM.GetCount();

	while(nCnt > 2000)
	{  
		m_ctlListGEM.DeleteString(0);
		break;
	}	  

	m_ctlListGEM.SetCurSel(nCnt - 1);
}

void CFAIS_GEM_AgentDlg::AddLogTCP(CString str)
{
	m_ctlListTCP.AddString(str);

	int nCnt = m_ctlListTCP.GetCount();

	while(nCnt > 2000)
	{  
		m_ctlListTCP.DeleteString(0);
		break;
	}	  

	m_ctlListTCP.SetCurSel(nCnt - 1);
}

long CFAIS_GEM_AgentDlg::XGemStart()
{
	CString strCfg = L"FAIS_Gem_Agent.cfg";

	long nRet = m_XGem.Initialize(strCfg);
	CString strLog;
	if(nRet == 0)
	{
		strLog = L"XGem 초기화 성공";
		AddLogGEM(strLog);
		GetLog()->Debug(strLog.GetBuffer());
		
		nRet = m_XGem.Start();

		if(nRet == 0)
		{
			strLog = L"XGem 시작 성공";
			AddLogGEM(strLog);
			GetLog()->Debug(strLog.GetBuffer());
			GetDlgItem(IDC_BT_START)->EnableWindow(FALSE);
		}
		else
		{
			strLog.Format(L"XGem 시작 실패 (%d).", nRet);
			AddLogGEM(strLog);
			GetLog()->Debug(strLog.GetBuffer());
		}

	}
	else {
		strLog.Format(L"XGem 초기화 실패 (%d).", nRet);
		AddLogGEM(strLog);
		GetLog()->Debug(strLog.GetBuffer());
    }
	
	return nRet;
}

void CFAIS_GEM_AgentDlg::OnBnClickedBtStart()
{
	XGemStart();
}

long CFAIS_GEM_AgentDlg::XGemStop()
{
	long nRet = m_XGem.Stop();
	CString strLog;
	if(nRet == 0)
	{
		strLog = L"XGem Stop 성공";
		AddLogGEM(strLog);
		GetLog()->Debug(strLog.GetBuffer());

		
		nRet = m_XGem.Close();
		if(nRet == 0)
		{
			strLog = L"XGem Close 성공";
			AddLogGEM(strLog);
			GetLog()->Debug(strLog.GetBuffer());
			GetDlgItem(IDC_BT_START)->EnableWindow(TRUE);
		}
		else
		{
			strLog.Format(L"XGem Close 실패 (%d)", nRet);
			AddLogGEM(strLog);
			GetLog()->Debug(strLog.GetBuffer());
		}
	}
	else {
		strLog.Format(L"XGem Stop 실패 (%d)", nRet);
		AddLogGEM(strLog);
		GetLog()->Debug(strLog.GetBuffer());
    }
	return nRet;
}

void CFAIS_GEM_AgentDlg::OnBnClickedBtStop()
{
	XGemStop();
}

BEGIN_EVENTSINK_MAP(CFAIS_GEM_AgentDlg, CDialogEx)
	ON_EVENT(CFAIS_GEM_AgentDlg, IDC_EXGEMCTRL1, 27, CFAIS_GEM_AgentDlg::eXGEMStateEventExgemctrl1, VTS_I4)
	ON_EVENT(CFAIS_GEM_AgentDlg, IDC_EXGEMCTRL1, 2, CFAIS_GEM_AgentDlg::eGEMCommStateChangedExgemctrl1, VTS_I4)
	ON_EVENT(CFAIS_GEM_AgentDlg, IDC_EXGEMCTRL1, 1, CFAIS_GEM_AgentDlg::eSECSMessageReceivedExgemctrl1, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
END_EVENTSINK_MAP()

//MJH 2017-08-26
void CFAIS_GEM_AgentDlg::eXGEMStateEventExgemctrl1(long nState)
{
	if (nState == XGemState_Execute) {
		//bEnable : 0(Disabled), 1(Enabled)
		m_XGem.GEMSetEstablish(1);
		m_XGem.GEMEQInitialized(1); 
	}

}

BOOL CFAIS_GEM_AgentDlg::SvrStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strMsg;
	if(m_ListenSocket.Create(GetDlgItemInt(IDC_EDIT_SVR_PORT), SOCK_STREAM))
	{
		DWORD optval = true;
		int temp = sizeof(DWORD);
		optval = true;
		temp = sizeof(DWORD);
		
		BOOL bRet = m_ListenSocket.SetSockOpt(SO_KEEPALIVE, (void*)&optval, temp);

		if (bRet == TRUE) {
			strMsg = L"SetSockOpt SO_KEEPALIVE";
			AddLogTCP(strMsg);
			GetLog()->Debug(strMsg.GetBuffer());
		}
		else
		{
			strMsg = L"Fail - SetSockOpt SO_KEEPALIVE";
			AddLogTCP(strMsg);
			GetLog()->Debug(strMsg.GetBuffer());
		}

		if(!m_ListenSocket.Listen())
		{
			strMsg = L"ERROR: Listen() return FALSE";
			AddLogTCP(strMsg);
			GetLog()->Debug(strMsg.GetBuffer());
			return FALSE;
		}
		else
		{
			strMsg = L"Socket Server Started.";
			AddLogTCP(strMsg);
			GetLog()->Debug(strMsg.GetBuffer());
			GetDlgItem(IDC_BT_SVR_START)->EnableWindow(FALSE);
			return TRUE;
		}
	}
	else
	{
		DWORD dErr = GetLastError();
		strMsg.Format(L"ERROR: Failed to create server socket - %d",dErr);
		AddLogTCP(strMsg);
		GetLog()->Debug(strMsg.GetBuffer());
		return FALSE;
	}
}

BOOL CFAIS_GEM_AgentDlg::SvrStop()
{
	POSITION pos;
	pos = m_ListenSocket.m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;

	while(pos != NULL)
	{
		pClient = (CClientSocket*)
			m_ListenSocket.m_ptrClientSocketList.GetNext(pos);
		if(pClient != NULL)
		{
			pClient->ShutDown(2);//receives = 0 • sends = 1  • both = 2 
			pClient->Close();

			delete pClient;
		}
	}

	m_ListenSocket.ShutDown(2); //receives = 0 • sends = 1  • both = 2 

	m_ListenSocket.Close();

	CString strMsg = L"Socket Server Stopped.";
	AddLogTCP(strMsg);
	GetLog()->Debug(strMsg.GetBuffer());

	GetDlgItem(IDC_BT_SVR_START)->EnableWindow(TRUE);

	return TRUE;
}
//2017-09-01
void CFAIS_GEM_AgentDlg::eGEMCommStateChangedExgemctrl1(long nState)
{
	long	nReturn = 0;
	CString strMsg = L"";

	if(nState == 5) //Communication State -1 : None 1 : Comm Disabled 2 : WaitCRFromHost 3 : WaitDelay 4 : WaitCRA 5 : Communicating
	 {
		nReturn = m_XGem.GEMReqRemote(); //
		if( nReturn == 0 ) {
			AddLogGEM(L"Send GEMReqRemote successfully");
			//SetTimer(IDD,1000,NULL);
			//ControlModeChangeERS(805);
			m_nControlMode = CONTROL_ONLINE_REMOTE;
			SetTimer(TIMER_CONTROL_MODE_ERS,1000,NULL);
		}
		else {
			strMsg.Format(L"Fail to GEMReqRemote (%d)", nReturn );
			AddLogGEM(strMsg);
		}
	 }
}


void CFAIS_GEM_AgentDlg::OnBnClickedBtSvrStop()
{
	SvrStop();

	//for test - Setting data variable for complex type.
	//SubMapReq_S14F1(L"");
	//for test
	CString strMsg;
	int nReturn = m_XGem.GEMReqRemote(); //
		if( nReturn == 0 ) {
			AddLogGEM(L"Send GEMReqRemote successfully");
			//SetTimer(IDD,1000,NULL);
			//ControlModeChangeERS(805);
			m_nControlMode = CONTROL_ONLINE_REMOTE;
			SetTimer(TIMER_CONTROL_MODE_ERS,1000,NULL);
		}
		else {
			strMsg.Format(L"Fail to GEMReqRemote (%d)", nReturn );
			AddLogGEM(strMsg);
		}
}


void CFAIS_GEM_AgentDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent)
	{
		KillTimer(TIMER_CONTROL_MODE_ERS);
		long nCEID;
		switch(m_nControlMode)
		{
			case CONTROL_HOST_OFFLINE:
				nCEID = CEID_OFFLINE;
				ControlModeERS(nCEID);
				break;
			case CONTROL_ONLINE_LOCAL:
				nCEID = CEID_ONLINE_LOCAL;
				ControlModeERS(nCEID);
				break;
			case CONTROL_ONLINE_REMOTE:
				nCEID = CEID_ONLINE_REMOTE;
				ControlModeERS(nCEID);
				break;
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CFAIS_GEM_AgentDlg::ControlModeERS(long nCEID)
{
	long	nReturn = 0;
	CString strMsg = L"";
	CString strValue;
	BSTR bstr;

	long nVID = SVID_EQUIPMENT_STATUS; //810 Equipment Status (IDE/RUN…)
	strValue = L"IDE"; //Equipment Status IDLE/RUN)
	bstr = strValue.AllocSysString();
	nReturn = m_XGem.GEMSetVariable(1, &nVID, &bstr);
	SysFreeString(bstr);

	nVID = SVID_CURRENT_RECIPE; //1102 Current Recipe Name
	strValue = L"";
	bstr = strValue.AllocSysString();
	nReturn = m_XGem.GEMSetVariable(1, &nVID, &bstr);
	SysFreeString(bstr);
	
	nVID = SVID_DUMMY_STATUS; //830 Dummy Status (1: ON, 0: OFF)
	strValue = L"0";
	bstr = strValue.AllocSysString();
	nReturn = m_XGem.GEMSetVariable(1, &nVID, &bstr);
	SysFreeString(bstr);
	
	nVID = SVID_MAGAZINE_ID; //1101
	strValue = L"";
	bstr = strValue.AllocSysString();
	nReturn = m_XGem.GEMSetVariable(1, &nVID, &bstr);
	SysFreeString(bstr);

	nReturn = m_XGem.GEMSetEvent(nCEID);
	if( nReturn == 0 ) 
	{
		strMsg.Format(L"Send GEMSetEvent %d successfully",nCEID);
		AddLogGEM(strMsg);
	}
	else {
		strMsg.Format(L"Fail to GEMSetEvent %d (%d)", nCEID, nReturn);
		AddLogGEM(strMsg);
	}
}

void CFAIS_GEM_AgentDlg::OnBnClickedBtSvrStart()
{
	SvrStart();
}

int CFAIS_GEM_AgentDlg::SendERS(CString strPacketBody)
{
	CString strCEID;
	strCEID.Format(L"%s", strPacketBody.Left(4));
	CString strSV;
	strSV.Format(L"%s",strPacketBody.Mid(5));
	
	CString strValue;

	int nIdx = -1;
	int nIdxPrev = -1;

	long nCEID,nVID;
	BSTR bstr;
	long nRet;
	CString strEventName,strMsg;

	if(strCEID == L"1000" ) // LOSS CODE REQ (1000) - rcv ex)  ERS0017|1000|D/A|
	{
		nCEID = (long)_wtoi(strCEID);
		strEventName = L"LOSS CODE REQ";
		nIdx = strSV.Find(L"|");
		strValue = strSV.Left(nIdx);
		nIdxPrev = nIdx;

		nVID = 1100; //TYPE(ASCII) - W/B,D/A
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);
	}
	else if(strCEID == L"1100" ) // MGZ Read (1100) - ERS0041|1100|IMS73225|HPBD-D1572_X_5_3_X|
	{
		nCEID = (long)_wtoi(strCEID);
		strEventName = L"MGZ Read";
		
		nIdx = strSV.Find(L"|");
		strValue = strSV.Left(nIdx);
		nIdxPrev = nIdx;

		nVID = 1101; //MAGAZINE_ID(ASCII) -  IMS73225
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1102; //CURRENT_RECIPE(ASCII) -  HPBD-D1572_X_5_3_X
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);
	}
	else if(strCEID == L"1200" ) // SUB Load (1200) - ERS0040|1200|R303571724IK1011707240FEDI|
	{
		nCEID = (long)_wtoi(strCEID);
		strEventName = L"SUB Load";
		
		nIdx = strSV.Find(L"|");
		strValue = strSV.Left(nIdx);
		nIdxPrev = nIdx;

		nVID = 1103; //SUB_ID(ASCII) -  R303571724IK1011707240FEDI
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);
	}
	else if(strCEID == L"1300" ) // SUBMAP Upload (1300) - ERS0298|1300|R303571724IK1011707240FEDI|7|20|5|00220000000002020000000000022000000000000000000000000000020000000000000000000200|TCRHE86A|c0c00202c0c0c0c0c0c0c0c0c002c002c0c0c0c0c0c0c0c0c0c0c00202c0c0c0c0c0c0c0c0c0c0c0c0c0c0c004c0c0c0c0c0c0c0c0c0c0c0c002c0c004c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c002c0c0|
	{
		nCEID = (long)_wtoi(strCEID);
		strEventName = L"SUBMAP Upload";
		
		nIdx = strSV.Find(L"|");
		strValue = strSV.Left(nIdx);
		nIdxPrev = nIdx;

		nVID = 1103; //SUB_ID(ASCII) -  R303571724IK1011707240FEDI
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1104; //ORIGIN_LOC(U1) -  7
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1105; //ROWS(U4) -  20
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1106; //COLUMNS(U4) -  5
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1107; //CELL_STATUS(ASCII) -  00220000000002020000000000022000000000000000000000000000020000000000000000000200
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1108; //LOT_ID(ASCII) -  TCRHE86A
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1109; //CELL_GRADE(ASCII) -  c0c00202c0c0c0c0c0c0c0c0c002c002c0c0c0c0c0c0c0c0c0c0c00202c0c0c0c0c0c0c0c0c0c0c0c0c0c0c004c0c0c0c0c0c0c0c0c0c0c0c002c0c004c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c002c0c0
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);
	}
	else if(strCEID == L"1400" ) //2017-09-26 Inspection Result (1) - Monitoring Sheet (?)
	{
		nCEID = (long)_wtoi(strCEID);
		strEventName = L"Inspection Result (1)";
		
		nIdx = strSV.Find(L"|");
		strValue = strSV.Left(nIdx);
		nIdxPrev = nIdx;

		nVID = 1103; //SUB_ID(ASCII) 
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1110; //OPER(ASCII) 
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1111; //SAMPLE_QTY(U4) 
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1112; //DEFECT_QTY(U4) 
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;

		nVID = 1113; //COMMENT(ASCII) 
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);
	}
	else if(strCEID == L"1500" ) //2017-09-26 Inspection Result (2) - Measurement (?)
	{
		nCEID = (long)_wtoi(strCEID);
		strEventName = L"Inspection Result (2)";
		
		nIdx = strSV.Find(L"|");
		strValue = strSV.Left(nIdx);
		nIdxPrev = nIdx;
		nVID = 1103; //SUB_ID(ASCII) 
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;
		nVID = 1110; //OPER(ASCII) 
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;
		nVID = 1111; //SAMPLE_QTY(U4) 
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);

		////MEASURE_VALUE LIST - data type U4 나중에 현업 확인 - 3D 측정값? float x.xx - 2017.09.25 미팅시 청주 현업 engr' ment -  
		long nObjId;
		m_XGem.MakeObject(&nObjId);
		
		nIdx = strSV.Find(L"|",nIdxPrev+1);
		strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
		nIdxPrev = nIdx;
		nVID = 1114; 
		int nListDataCount = _wtoi(strValue); //리스트포함 데이터 수량
		m_XGem.SetList(nObjId, nListDataCount);

		int i; double d;
		for( i = 0; i < nListDataCount; i++ )
		{
			nIdx = strSV.Find(L"|",nIdxPrev+1);
			strValue = strSV.Mid(nIdxPrev+1, nIdx-nIdxPrev -1);
			nIdxPrev = nIdx;
			d = _wtoi(strValue);
			m_XGem.SetU4(nObjId,&d,1);
		}
	
		m_XGem.GEMSetVariables(nObjId, nVID);
	}
	else if(strCEID == L"1600" ) // SUB Unoad (1600) - ERS0040|1800|R303571724IK1011707240FEDI|
	{
		nCEID = (long)_wtoi(strCEID);
		strEventName = L"SUB Unload";
		
		nIdx = strSV.Find(L"|");
		strValue = strSV.Left(nIdx);
		nIdxPrev = nIdx;

		nVID = 1103; //SUB_ID(ASCII) -  R303571724IK1011707240FEDI
		bstr = strValue.AllocSysString();
		m_XGem.GEMSetVariable(1, &nVID, &bstr);
		SysFreeString(bstr);
	}

	nRet = m_XGem.GEMSetEvent(nCEID);

	if( nRet == 0 ) {
		strMsg.Format(L"[S6F11] %s (%d)",strEventName,nCEID);
        AddLogGEM(strMsg);
		GetLog()->Debug(strMsg.GetBuffer());
    }

	return nRet;
}

int CFAIS_GEM_AgentDlg::SendARS(CString strPacketBody)
{
	CString strALID = strPacketBody.Left(4);
	CString strState = strPacketBody.Mid(5,1); //1: Alarm Set, 0: Alarm Clear
	
	long  nALID = _wtoi(strALID);

	int nRet;
	CString strMsg;

	if(strState == L"1")
	{
		nRet = m_XGem.GEMSetAlarm(nALID, 1); //state (0 : clear, 1: detect)
	}
	else if (strState == L"0")
	{
		nRet = m_XGem.GEMSetAlarm(nALID, 0);
	}

	if(nRet == 0)
	{
		strMsg.Format(L"[S5F1] %d (%s)", nALID, strState);
		AddLogGEM(strMsg);
	}
        
	return nRet;
}
//2017-09-26
CString CFAIS_GEM_AgentDlg::BSTR2CString(BSTR bstr)
{
    char* pbstr;
    USES_CONVERSION;    // <atlconv.h>, convert를 위한 macro
    pbstr = OLE2A(bstr);      // BSTR -> char
    return CString(bstr);
}

void CFAIS_GEM_AgentDlg::eSECSMessageReceivedExgemctrl1(long nObjectID, long nStream, long nFunction, long nSysbyte)
{
	long nReturn = -1;
	long nItems = 0;
	BSTR bstr;
	long nItemCount = 0;

	CString strValue,strValue1,strValue2;
	SHORT   shortValue = 0;
	double  doubleValue = 0;
	long	nSize = 1;

	CString strLog;

	//2017-09-28
	CString strPacketBody = L""; //VISION,VRS,MMI 전송용 Packet Body;
	int nTotalPacketSize = 0;
	CString	strSendPacket = L"";
	//

//S2F41 - Host Command
	if(nStream == 2 && nFunction == 41) 
	{
		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue = BSTR2CString(bstr);
		SysFreeString(bstr);
		strPacketBody.Format(L"%s|",strValue);
		strLog.Format(L"[SECS-II:IN] S%dF%d HOST COMMAND (%s) ",nStream, nFunction, strValue);
		AddLogGEM(strLog.GetBuffer());

		if(strValue == L"LOSS_CODE")
		{
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPNAME = [LOSS_CODE_COUNT] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetU4(nObjectID,&doubleValue,&nItemCount,nSize); //LOSS_CODE_COUNT = [2]
			strValue2.Format(L"%.0f",doubleValue);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());
			
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPNAME = [LOSS_CODE] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //LOSS_CODE = [ADFM]
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPNAME = [GRADE_CODE] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // = [01]
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPNAME = [DESC] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // = [Adhesive(에폭시,WBL)에 의한 이물질 오염의 경우]   
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());
			
		}
		else if(strValue == L"MGZ_READ_CONFIRM")
		{
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPNAME = [MGZ-ID] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //MAGAZINE_ID = [IMS73225] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPNAME = [CONFIRM-FLAG]  
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [T] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPNAME = [LOT-ID]  
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //= [TCS1524QA] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [RECIPE-NAME] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [HPBW-D0001_1_1]
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //   CPNAME = [SAMPLE_QTY]  
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [100] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [USL] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [200] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [LSL] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [300]
			strValue2 = BSTR2CString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			SysFreeString(bstr);
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [UCL] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [400] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [LCL] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [500] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [MCP-NO] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [A-093TD] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [MODE]
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [DDR4]  
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [DENSITY]
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPVAL1 = [8G] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [TECH] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPVAL1 = [PL] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [PKG1] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPVAL1 = [FBGA] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [PKG2] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPVAL1 = [DDP] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [LEAD] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); // CPVAL1 = [78] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [SUB_COUNT] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 = [n] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			int nSubCount = _wtoi(strValue2); //SUB 갯수
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
		
			for(int i = 0; i < nSubCount; i++)
			{
				nReturn = m_XGem.GetList(nObjectID, &nItems);

				nReturn = m_XGem.GetList(nObjectID, &nItems);
				nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [SUB_ID]
				strValue1 = BSTR2CString(bstr);
				SysFreeString(bstr);
				strPacketBody += strValue1;
				strPacketBody += L"|";
				nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL1 
				strValue2 = BSTR2CString(bstr);
				SysFreeString(bstr);
				strPacketBody += strValue2;
				strPacketBody += L"|";
				strLog.Format(L"[%s] %s",strValue1,strValue2);
				AddLogGEM(strLog.GetBuffer());

				nReturn = m_XGem.GetList(nObjectID, &nItems);
				nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [OPER] 
				strValue1 = BSTR2CString(bstr);
				SysFreeString(bstr);
				strPacketBody += strValue1;
				strPacketBody += L"|";
				nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL2 
				strValue2 = BSTR2CString(bstr);
				SysFreeString(bstr);
				strPacketBody += strValue2;
				strPacketBody += L"|";
				strLog.Format(L"[%s] %s",strValue1,strValue2);
				AddLogGEM(strLog.GetBuffer());

				nReturn = m_XGem.GetList(nObjectID, &nItems);
				nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //  CPNAME = [EQP_ID] 
				strValue1 = BSTR2CString(bstr);
				SysFreeString(bstr);
				strPacketBody += strValue1;
				strPacketBody += L"|";
				nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL3 
				strValue2 = BSTR2CString(bstr);
				SysFreeString(bstr);
				strPacketBody += strValue2;
				strPacketBody += L"|";
				strLog.Format(L"[%s] %s",strValue1,strValue2);
				AddLogGEM(strLog.GetBuffer());
			}

		}
		else if(strValue == L"SUB_CONFIRM")
		{
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPNAME = [SUB-ID] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //SUBSTRATE_ID = [R303571724IK1011707240FED]
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPNAME = [CONFIRM-FLAG] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL = [T] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());
		}
		else if(strValue == L"INSPECTION_CONFIRM")
		{
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPNAME = [SUB-ID] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //SUBSTRATE_ID = [R303571724IK1011707240FED]
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());

			nReturn = m_XGem.GetList(nObjectID, &nItems);
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPNAME = [CONFIRM-FLAG] 
			strValue1 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue1;
			strPacketBody += L"|";
			nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount); //CPVAL = [T] 
			strValue2 = BSTR2CString(bstr);
			SysFreeString(bstr);
			strPacketBody += strValue2;
			strPacketBody += L"|";
			strLog.Format(L"[%s] %s",strValue1,strValue2);
			AddLogGEM(strLog.GetBuffer());
		}
		else if(strValue == L"STOP")
		{
			;
		}
		else //Host Command 오류
		{
			return;
		}
//VISION,VRS,MMI 전송
		nTotalPacketSize = strPacketBody.GetLength() + 8;
		strSendPacket.Format(L"HCS%04d|%s",nTotalPacketSize,strPacketBody);
		ProcGEM_ToEQ(strSendPacket);
//
//Host Command 응답 S2F42
		m_XGem.MakeObject(&nObjectID);
		m_XGem.SetList(nObjectID,2);
		short nBinary = 0;    //ACK
		m_XGem.SetBinary( nObjectID, &nBinary, 1 );
		m_XGem.SetList(nObjectID,0);
		
		nReturn =  m_XGem.SendSECSMessage(nObjectID, nStream, nFunction + 1, nSysbyte);
//
		if(nReturn == 0)
		{
			strLog.Format(L"[SECS-II:OUT]  S%dF%d", nStream, nFunction + 1);
			AddLogGEM(strLog.GetBuffer());
		}
		else
		{
			strLog.Format(L"Fail to reply S%dF%d (%d)", nStream, nFunction, nReturn);
			AddLogGEM(strLog.GetBuffer());
		}
	}
	//TO-DO
	else if(nStream == 14 && nFunction == 2) //S14F2 - SUBMAP Down
	{
		strLog.Format(L"[SECS-II:IN] S%dF%d SUBMAP Down",nStream, nFunction);
		AddLogGEM(strLog.GetBuffer());

		nReturn = m_XGem.GetList(nObjectID, &nItems); //nReturn 0: success, <0 failure
		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue = BSTR2CString(bstr);
		SysFreeString(bstr);
		strLog.Format(L"SUB-ID %s" ,strValue);
		AddLogGEM(strLog.GetBuffer());
		
		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue1 = BSTR2CString(bstr);
		SysFreeString(bstr);

		m_XGem.GetU1(nObjectID,&shortValue,&nItemCount,nSize);
		strValue2.Format(L"%d",shortValue);
		strLog.Format(L"[%s] %s",strValue1,strValue2);
		AddLogGEM(strLog.GetBuffer());

		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue1 = BSTR2CString(bstr);
		SysFreeString(bstr);
		
		m_XGem.GetU4(nObjectID,&doubleValue,&nItemCount,nSize);
		strValue2.Format(L"%.0f",doubleValue);
		strLog.Format(L"[%s] %s",strValue1,strValue2);
		AddLogGEM(strLog.GetBuffer());

		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue1 = BSTR2CString(bstr);
		SysFreeString(bstr);
		
		m_XGem.GetU4(nObjectID,&doubleValue,&nItemCount,nSize);
		strValue2.Format(L"%.0f",doubleValue);
		strLog.Format(L"[%s] %s",strValue1,strValue2);
		AddLogGEM(strLog.GetBuffer());

		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue1 = BSTR2CString(bstr);
		SysFreeString(bstr);
		
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue2 = BSTR2CString(bstr);
		SysFreeString(bstr);
		strLog.Format(L"[%s] %s",strValue1,strValue2);
		AddLogGEM(strLog.GetBuffer());

		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue1 = BSTR2CString(bstr);
		SysFreeString(bstr);

		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue2 = BSTR2CString(bstr);
		SysFreeString(bstr);
		strLog.Format(L"[%s] %s",strValue1,strValue2);
		AddLogGEM(strLog.GetBuffer());
		
		nReturn = m_XGem.GetList(nObjectID, &nItems);
		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue1 = BSTR2CString(bstr);
		SysFreeString(bstr);
		

		nReturn = m_XGem.GetAscii(nObjectID,&bstr,&nItemCount);
		strValue2 = BSTR2CString(bstr);
		SysFreeString(bstr);
		strLog.Format(L"[%s] %s",strValue1,strValue2);
		AddLogGEM(strLog.GetBuffer());

		nReturn = m_XGem.CloseObject(nObjectID);
	}
}

int	CFAIS_GEM_AgentDlg::SubMapReq_S14F1(CString strPacketBody)
{
	long nRet = -1;
	long nObjectID = 0;
	long nItemCount = 0;
	CString strValue = L"";

	m_XGem.MakeObject(&nObjectID);
	
	nItemCount = 5;
	m_XGem.SetList(nObjectID,nItemCount);
	
	strValue = L"MODEL"; //OBJTYPE = [MODEL] 
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());

	strValue = L"StripMap"; //OBJSPEC = [StripMap] 
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());

	nItemCount = 1;
	m_XGem.SetList(nObjectID,nItemCount);
	strValue = L"R303571724IK1011707240FED"; //SUB_ID = [R303571724IK1011707240FED] 
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());
	
	nItemCount = 0; // (?) 업체용 문서상.. 테스트시 확인필요
	m_XGem.SetList(nObjectID,nItemCount);
	
	nItemCount = 6;
	m_XGem.SetList(nObjectID,nItemCount);

	strValue = L"OriginLocation";
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());

	strValue = L"Rows";
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());

	strValue = L"Columns";
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());

	strValue = L"CellStatus";
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());
	
	strValue = L"Bincode";
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());

	strValue = L"LotID";
	m_XGem.SetAscii(nObjectID,(LPCTSTR)strValue,strValue.GetLength());
	
	nRet = m_XGem.SendSECSMessage(nObjectID,14,1,0);
	return nRet;
}

