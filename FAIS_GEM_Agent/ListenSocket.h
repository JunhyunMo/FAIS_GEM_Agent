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

	BOOL			SendData(CString strIP, CString str);
    //2017-09-28
	void			SendDataAll(CString sendData);
};


