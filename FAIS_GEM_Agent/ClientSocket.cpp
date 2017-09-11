// ClientSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FAIS_GEM_Agent.h"
#include "ClientSocket.h"
#include "ListenSocket.h"

#include "FAIS_GEM_AgentDlg.h"


// CClientSocket

CClientSocket::CClientSocket()
{
	m_pListenSocket = NULL;
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 멤버 함수
void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}

void CClientSocket::OnClose(int nErrorCode)
{
	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);

	//MJH TODO - 2017-09-11 TO-CHECK
	/*((CFAIS_GEM_AgentDlg*)AfxGetMainWnd())->m_bEqConnect = FALSE;
	((CFAIS_GEM_AgentDlg*)AfxGetMainWnd())->SelfShutDown();*/
}

void CClientSocket::OnReceive(int nErrorCode)
{
	CString strIP = L"";
	UINT nPort = 0;
	
	CHAR	szBuffer[1024*10];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	TCHAR	szTBuffer[1024*10];
	::ZeroMemory(szTBuffer, sizeof(szTBuffer));
	
	GetPeerName(strIP, nPort);
//MJH TO-DO 2017-08-26 IP로 VISION/MMI 분기
	CString strRcv,strLog;

	if(Receive((BYTE*)szBuffer, sizeof(szBuffer)) > 0)
	{
		CFAIS_GEM_AgentDlg* pMain = (CFAIS_GEM_AgentDlg*)AfxGetMainWnd();

		pMain->MBCS2Unicode(szBuffer,szTBuffer);
		
		strRcv.Format(L"%s",szTBuffer);	
		pMain->ProcGEM_FromEQ(strIP,strRcv);

		strLog.Format(L"[RCV][%s]%s",strIP,strRcv);
		GetLog()->Debug(strLog.GetBuffer()); 
		pMain->AddLogTCP(strLog);
	}
	
	CSocket::OnReceive(nErrorCode);
}