#pragma once

// CListenSocket ��� ����Դϴ�.

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

	CPtrList	m_ptrClientSocketList;
	virtual void	OnAccept(int nErrorCode);
	void			CloseClientSocket(CSocket* pClient);
	void			SendDataAll(TCHAR* pszMessage);

	BOOL			SendData(CString strIP, CString str);
};


