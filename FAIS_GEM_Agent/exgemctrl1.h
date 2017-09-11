#pragma once

// 컴퓨터에서 Microsoft Visual C++를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// 참고: 이 파일의 내용을 수정하지 마십시오. Microsoft Visual C++에서
//  이 클래스를 다시 생성할 때 수정한 내용을 덮어씁니다.

/////////////////////////////////////////////////////////////////////////////
// CExgemctrl1 래퍼 클래스입니다.

class CExgemctrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CExgemctrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x2220F20C, 0x2FA3, 0x461C, { 0x84, 0xD4, 0x94, 0x8B, 0x6D, 0x7, 0xE7, 0x9B } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 특성입니다.
public:


// 작업입니다.
public:

// _DeXGem

// Functions
//

	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long Initialize(LPCTSTR sCfg)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sCfg);
		return result;
	}
	long Start()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Stop()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Close()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MakeObject(long * pnObjectID)
	{
		long result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pnObjectID);
		return result;
	}
	long SetList(long nObjectID, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, nItemCount);
		return result;
	}
	long GetList(long nObjectID, long * pnItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnItemCount);
		return result;
	}
	long GEMSetVariables(long nObjectID, long nVid)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, nVid);
		return result;
	}
	long SendSECSMessage(long nObjectID, long nStream, long nFunction, long nSysbyte)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, nStream, nFunction, nSysbyte);
		return result;
	}
	long GEMReqOffline()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GEMReqLocal()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GEMReqRemote()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GEMSetEstablish(long bState)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bState);
		return result;
	}
	long GEMSetParam(LPCTSTR sParamName, LPCTSTR sParamValue)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sParamName, sParamValue);
		return result;
	}
	long GEMGetParam(LPCTSTR sParamName, BSTR * psParamValue)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sParamName, psParamValue);
		return result;
	}
	long GEMEQInitialized(long nInitType)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nInitType);
		return result;
	}
	long GEMReqGetDateTime()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GEMRspGetDateTime(long nMsgId, LPCTSTR sSystemTime)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sSystemTime);
		return result;
	}
	long GEMRspDateTime(long nMsgId, long nResult)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, nResult);
		return result;
	}
	long GEMSetAlarm(long nID, long nState)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nID, nState);
		return result;
	}
	long GEMRspRemoteCommand(long nMsgId, LPCTSTR sCmd, long nHCAck, long nCount, long * pnResult)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sCmd, nHCAck, nCount, pnResult);
		return result;
	}
	long GEMRspChangeECV(long nMsgId, long nResult)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, nResult);
		return result;
	}
	long GEMSetECVChanged(long nCount, long * pnEcIds, BSTR * psEcVals)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnEcIds, psEcVals);
		return result;
	}
	long GEMSetPPChanged(long nMode, LPCTSTR sPpid, long nSize, LPCTSTR sBody)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMode, sPpid, nSize, sBody);
		return result;
	}
	long GEMSetPPFmtChanged(long nMode, LPCTSTR sPpid, LPCTSTR sMdln, LPCTSTR sSoftRev, long nCount, BSTR * psCCode, long * pnParamCount, BSTR * psParamNames)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PBSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMode, sPpid, sMdln, sSoftRev, nCount, psCCode, pnParamCount, psParamNames);
		return result;
	}
	long GEMReqPPLoadInquire(LPCTSTR sPpid, long nLength)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid, nLength);
		return result;
	}
	long GEMRspPPLoadInquire(long nMsgId, LPCTSTR sPpid, long nResult)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sPpid, nResult);
		return result;
	}
	long GEMReqPPSend(LPCTSTR sPpid, LPCTSTR sBody)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid, sBody);
		return result;
	}
	long GEMRspPPSend(long nMsgId, LPCTSTR sPpid, long nResult)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sPpid, nResult);
		return result;
	}
	long GEMReqPP(LPCTSTR sPpid)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid);
		return result;
	}
	long GEMRspPP(long nMsgId, LPCTSTR sPpid, LPCTSTR sBody)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sPpid, sBody);
		return result;
	}
	long GEMRspPPDelete(long nMsgId, long nCount, BSTR * psPpids, long nResult)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, nCount, psPpids, nResult);
		return result;
	}
	long GEMRspPPList(long nMsgId, long nCount, BSTR * psPpids)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, nCount, psPpids);
		return result;
	}
	long GEMReqPPFmtSend(LPCTSTR sPpid, LPCTSTR sMdln, LPCTSTR sSoftRev, long nCount, BSTR * psCCode, long * pnParamCount, BSTR * psParamNames)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PBSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid, sMdln, sSoftRev, nCount, psCCode, pnParamCount, psParamNames);
		return result;
	}
	long GEMRspPPFmtSend(long nMsgId, LPCTSTR sPpid, long nResult)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sPpid, nResult);
		return result;
	}
	long GEMReqPPFmt(LPCTSTR sPpid)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid);
		return result;
	}
	long GEMRspPPFmt(long nMsgId, LPCTSTR sPpid, LPCTSTR sMdln, LPCTSTR sSoftRev, long nCount, BSTR * psCCode, long * pnParamCount, BSTR * psParamNames)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PBSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sPpid, sMdln, sSoftRev, nCount, psCCode, pnParamCount, psParamNames);
		return result;
	}
	long GEMReqPPFmtVerification(LPCTSTR sPpid, long nCount, long * pnAck, BSTR * psSeqNumber, BSTR * psError)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid, nCount, pnAck, psSeqNumber, psError);
		return result;
	}
	long GEMSetTerminalMessage(long nTid, LPCTSTR sMsg)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nTid, sMsg);
		return result;
	}
	long GEMSetVariable(long nCount, long * pnVid, BSTR * psValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnVid, psValue);
		return result;
	}
	long GEMEnableLog(long bEnabled)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bEnabled);
		return result;
	}
	long GEMSetLogOption(LPCTSTR sDriectory, LPCTSTR sPrefix, LPCTSTR sExtension, long nKeepDay, long bMakeDailyLog, long bMakeSubDirectory)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sDriectory, sPrefix, sExtension, nKeepDay, bMakeDailyLog, bMakeSubDirectory);
		return result;
	}
	long GEMSetEvent(long nEventID)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nEventID);
		return result;
	}
	long GEMGetVariable(long nCount, long * pnVid, BSTR * psValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnVid, psValue);
		return result;
	}
	long GEMSetSpecificMessage(long nObjectID, LPCTSTR sMsgName)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, sMsgName);
		return result;
	}
	long GEMGetSpecificMessage(long nObjectID, long * pnRObjectID, LPCTSTR sMsgName)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_BSTR ;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnRObjectID, sMsgName);
		return result;
	}
	long GetAllStringItem(long nObjectID, BSTR * psValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, psValue);
		return result;
	}
	long SetAllStringItem(long nObjectID, LPCTSTR sValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, sValue);
		return result;
	}
	long GEMSetVarName(long nCount, BSTR * psVidName, BSTR * psValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, psVidName, psValue);
		return result;
	}
	long GEMGetVarName(long nCount, BSTR * psVidName, BSTR * psValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, psVidName, psValue);
		return result;
	}
	long CloseObject(long nObjectID)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID);
		return result;
	}
	long GEMReqAllECInfo()
	{
		long result;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SetBinary(long nObjectID, short * pnValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, nItemCount);
		return result;
	}
	long SetBool(long nObjectID, short * pnValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, nItemCount);
		return result;
	}
	long SetU1(long nObjectID, short * pnValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, nItemCount);
		return result;
	}
	long SetU2(long nObjectID, long * pnValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, nItemCount);
		return result;
	}
	long SetU4(long nObjectID, double * prValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_I4 ;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, prValue, nItemCount);
		return result;
	}
	long SetU8(long nObjectID, double * prValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_I4 ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, prValue, nItemCount);
		return result;
	}
	long SetI1(long nObjectID, short * pnValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, nItemCount);
		return result;
	}
	long SetI2(long nObjectID, short * pnValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, nItemCount);
		return result;
	}
	long SetI4(long nObjectID, long * plValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, plValue, nItemCount);
		return result;
	}
	long SetI8(long nObjectID, long * plValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, plValue, nItemCount);
		return result;
	}
	long SetF4(long nObjectID, float * prValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR4 VTS_I4 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, prValue, nItemCount);
		return result;
	}
	long SetF8(long nObjectID, double * prValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_I4 ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, prValue, nItemCount);
		return result;
	}
	long SetAscii(long nObjectID, LPCTSTR pszValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pszValue, nItemCount);
		return result;
	}
	long GetBinary(long nObjectID, short * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GetBool(long nObjectID, short * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GetU1(long nObjectID, short * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GetU2(long nObjectID, long * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GetU4(long nObjectID, double * prValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, prValue, pnItemCount, nSize);
		return result;
	}
	long GetU8(long nObjectID, double * prValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, prValue, pnItemCount, nSize);
		return result;
	}
	long GetI1(long nObjectID, short * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GetI2(long nObjectID, short * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x4c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GetI4(long nObjectID, long * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x4d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GetI8(long nObjectID, long * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x4e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GetF4(long nObjectID, float * prValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x4f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, prValue, pnItemCount, nSize);
		return result;
	}
	long GetF8(long nObjectID, double * prValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, prValue, pnItemCount, nSize);
		return result;
	}
	long GetAscii(long nObjectID, BSTR * psValue, long * pnItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, psValue, pnItemCount);
		return result;
	}
	long GEMReqPPSendEx(LPCTSTR sPpid, LPCTSTR sRecipePath)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid, sRecipePath);
		return result;
	}
	long GEMRspPPEx(long nMsgId, LPCTSTR sPpid, LPCTSTR sRecipePath)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sPpid, sRecipePath);
		return result;
	}
	long GEMRspPPSendEx(long nMsgId, LPCTSTR sPpid, LPCTSTR sRecipePath, long nResult)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sPpid, sRecipePath, nResult);
		return result;
	}
	long GEMReqPPEx(LPCTSTR sPpid, LPCTSTR sRecipePath)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid, sRecipePath);
		return result;
	}
	long SetAsciiEx(long nObjectID, short * pnValue, long nItemCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, nItemCount);
		return result;
	}
	long GetAsciiEx(long nObjectID, short * pnValue, long * pnItemCount, long nSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, pnValue, pnItemCount, nSize);
		return result;
	}
	long GEMSetVariableEx(long nObjectID, long nVid)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nObjectID, nVid);
		return result;
	}
	long GEMReqLoopback(long nCount, long * pnAbs)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnAbs);
		return result;
	}
	long GEMSetEventEnable(long nCount, long * pnCEIDs, long nEnable)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x5a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnCEIDs, nEnable);
		return result;
	}
	long GEMSetAlarmEnable(long nCount, long * pnALIDs, long nEnable)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x5b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnALIDs, nEnable);
		return result;
	}
	long GEMGetEventEnable(long nCount, long * pnCEIDs, long * pnEnable)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x5c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnCEIDs, pnEnable);
		return result;
	}
	long GEMGetAlarmEnable(long nCount, long * pnALIDs, long * pnEnable)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x5d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnALIDs, pnEnable);
		return result;
	}
	long GEMGetAlarmInfo(long nCount, long * pnALIDs, long * pnALCDs, BSTR * psALTXs)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x5e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnALIDs, pnALCDs, psALTXs);
		return result;
	}
	long GEMGetSVInfo(long nCount, long * pnSVIDs, BSTR * psMins, BSTR * psMaxs)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x5f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnSVIDs, psMins, psMaxs);
		return result;
	}
	long GEMGetECVInfo(long nCount, long * pnEcIds, BSTR * psNames, BSTR * psDefs, BSTR * psMins, BSTR * psMaxs, BSTR * psUnits)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR VTS_PBSTR VTS_PBSTR VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nCount, pnEcIds, psNames, psDefs, psMins, psMaxs, psUnits);
		return result;
	}
	long GEMRspOffline(long nMsgId, long nAck)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x61, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, nAck);
		return result;
	}
	long GEMRspOnline(long nMsgId, long nAck)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, nAck);
		return result;
	}
	long GEMReqHostOffline()
	{
		long result;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GEMReqStartPolling(LPCTSTR sName, long nScanTime)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sName, nScanTime);
		return result;
	}
	long GEMReqStopPolling(LPCTSTR sName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sName);
		return result;
	}
	long GEMRspRemoteCommand2(long nMsgId, LPCTSTR sCmd, long nHCAck, long nCount, BSTR * psCpName, long * pnCpAck)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sCmd, nHCAck, nCount, psCpName, pnCpAck);
		return result;
	}
	long GEMReqPPFmtSend2(LPCTSTR sPpid, LPCTSTR sMdln, LPCTSTR sSoftRev, long nCount, BSTR * psCCode, long * pnParamCount, BSTR * psParamNames, BSTR * psParamValues)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PBSTR VTS_PI4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_I4, (void*)&result, parms, sPpid, sMdln, sSoftRev, nCount, psCCode, pnParamCount, psParamNames, psParamValues);
		return result;
	}
	long GEMRspPPFmt2(long nMsgId, LPCTSTR sPpid, LPCTSTR sMdln, LPCTSTR sSoftRev, long nCount, BSTR * psCCode, long * pnParamCount, BSTR * psParamNames, BSTR * psParamValues)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PBSTR VTS_PI4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMsgId, sPpid, sMdln, sSoftRev, nCount, psCCode, pnParamCount, psParamNames, psParamValues);
		return result;
	}

// Properties
//

CString GetIP()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}
void SetIP(CString propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}
long GetPort()
{
	long result;
	GetProperty(0x2, VT_I4, (void*)&result);
	return result;
}
void SetPort(long propVal)
{
	SetProperty(0x2, VT_I4, propVal);
}
BOOL GetActive()
{
	BOOL result;
	GetProperty(0x3, VT_BOOL, (void*)&result);
	return result;
}
void SetActive(BOOL propVal)
{
	SetProperty(0x3, VT_BOOL, propVal);
}


};
