
// FAIS_GEM_AgentDlg.h : ��� ����
//

#pragma once
#include "exgemctrl1.h"
#include "ListenSocket.h"
#include "afxwin.h"


// CFAIS_GEM_AgentDlg ��ȭ ����
class CFAIS_GEM_AgentDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CFAIS_GEM_AgentDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FAIS_GEM_AGENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedBtStart();
	afx_msg void OnBnClickedBtStop();
	
	DECLARE_EVENTSINK_MAP()
	void eXGEMStateEventExgemctrl1(long nState);
public:
	void	MBCS2Unicode(LPCSTR lpData,LPWSTR ReturnData);
	void	Unicode2MBCS(LPWSTR lpData,LPSTR lpRtd);
	void	AddLogTCP(CString str);

	void	ProcGEM_FromEQ(CString strIP, CString strRcv);
	void	ProcGEM_ToEQ(CString strIP, CString strRcv);
	CExgemctrl1 m_XGem;
	
	CListBox m_ctlListGEM;
	void    AddLogGEM(CString str);
	

	CListenSocket	m_ListenSocket;
	BOOL	SvrStart();
	BOOL	SvrStop();
	CListBox m_ctlListTCP;
	void eGEMCommStateChangedExgemctrl1(long nState);
	afx_msg void OnBnClickedBtSvrStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	//2017-09-02 
	int	  m_nControlMode; //1: Off-Line 2: On-Line Local 3: On-Line Remote
	void  ControlModeERS(long nCEID); //ERS - Event Report Send

	//2017-09-15
	long    XGemStart();
	long	XGemStop();

	//2017-09-05
	int		SendARS(CString strPacketBody);
	afx_msg void OnBnClickedBtSvrStart();
	//2017-09-20
	int 	SendERS(CString strPacketBody);
};
