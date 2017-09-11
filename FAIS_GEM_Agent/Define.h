//////////////////////////////////////////////////////
// DEFINE.H

#define		RESULT_OK		0x00

#define		WM_TERMMSG_ACK		WM_USER+10000

#define		TIMER_CONTROL_MODE_ERS	WM_USER+1000


///////////// Control State /////////////////
typedef enum
{
	CONTROL_UNKOWN = 0,
	CONTROL_EQUIPMENT_OFFLINE = 1,
	CONTROL_GOING_TO_ONLINE = 2,
	CONTROL_HOST_OFFLINE = 3,
	CONTROL_ONLINE_LOCAL = 4,
	CONTROL_ONLINE_REMOTE = 5,
} CONTROL_STATE;

#define SVID_EQUIPMENT_STATUS	810
#define SVID_CURRENT_RECIPE		1102 
#define SVID_DUMMY_STATUS		830 
#define SVID_MAGAZINE_ID		1101

#define CEID_OFFLINE			801
#define CEID_ONLINE_LOCAL		802
#define CEID_ONLINE_REMOTE		803

//typedef enum
//{
//	DFFAULT_EQUIPMENT_OFFLINE = 0,
//	DEFAULT_HOST_OFFLINE = 1,
//	DEFAULT_ONLINE_LOCAL = 2,
//	DEFAULT_ONLINE_REMOTE = 3
//} DEFAULT_CONTROL_STATE;
//
//typedef enum
//{
//	SPOOL_INACTIVE = 0,
//	SPOOL_ACTIVE = 1,
//	SPOOL_FULL = 2,
//	SPOOL_PURGE = 3,
//	SPOOL_TRANSMIT = 4,
//	SPOOL_NOSPOOL = 5,
//	SPOOL_POWEROFF = 6,
//	SPOOL_POWERON = 7,
//} SPOOL_STATE;


























#define HSMS			_T("HSMS")
#define HSMS_PORT		_T("PORT")
#define HSMS_DEVICEID	_T("DEVICEID")
#define HSMS_LINKTEST	_T("LINKTEST")
#define HSMS_RETRY		_T("RETRY")
#define HSMS_T3			_T("T3")
#define HSMS_T5			_T("T5")
#define HSMS_T6			_T("T6")
#define HSMS_T7			_T("T7")
#define HSMS_T8			_T("T8")

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMMON(MAIN) SVID
///////////////////////////////// 14.07.28 giheon SVID Insert 

#define SVID_EQ_ID				1001
#define SVID_EQ_MODEL			1002
#define SVID_PRODUCT_NAME		1003
//2014-07-19 (update) 14.07.25 giheon
#define SVID_STEP				1010
#define SVID_LANGUAGE			1020
#define SVID_USER_NAME			1030
#define SVID_FACTORY			1040
#define	SVID_TRANS_CODE			1050
#define SVID_LOT_ID				1060
#define	SVID_OPER				1070
#define	SVID_DEVICE				1080
#define	SVID_RUN_ID				1090
#define	SVID_FAB_LOT			1100

#define SVID_VAR1				1110
#define SVID_VAR2				1120
#define SVID_VAR3				1130
#define SVID_VAR4				1140
#define SVID_VAR5				1150
#define SVID_VAR6				1160
#define SVID_VAR7				1170
#define SVID_VAR8				1180
#define SVID_VAR9				1190
#define SVID_VAR10				1200
#define SVID_VAR11				1210
#define SVID_VAR12				1220
#define SVID_VAR13				1230
#define SVID_VAR14				1240
#define SVID_VAR15				1250
#define SVID_VAR16				1260
#define SVID_VAR17				1270
#define SVID_VAR18				1280
#define SVID_VAR19				1290
#define SVID_VAR20				1300
#define SVID_VAR21				1310
#define SVID_VAR22				1320
#define SVID_VAR23				1330
#define SVID_VAR24				1340
#define SVID_VAR25				1350
#define SVID_VAR26				1360
#define SVID_VAR27				1370
#define SVID_VAR28				1380
#define SVID_VAR29				1390
#define SVID_VAR30				1400
#define SVID_VAR31				1410
#define SVID_VAR32				1420
#define SVID_VAR33				1430
#define SVID_VAR34				1440

#define SVID_L1					1450
#define SVID_L2					1460
#define SVID_L3					1470
#define SVID_L4					1480
#define SVID_L5					1490
#define SVID_L6					1500	
#define SVID_L7					1510
#define SVID_L8					1520
#define SVID_L9					1530
#define SVID_L10				1540
#define SVID_L11				1550
#define SVID_L12				1560
#define SVID_L13				1570
#define SVID_L14				1580
#define SVID_L15				1590
#define SVID_L16				1600
#define SVID_L17				1610
#define SVID_L18				1620
#define SVID_L19				1630
#define SVID_L20				1640
#define SVID_L21				1650
#define SVID_L22				1660
#define SVID_L23				1670
#define SVID_L24				1680
#define SVID_L25				1690
#define SVID_L26				1700
#define SVID_L27				1710
#define SVID_L28				1720
#define SVID_L29				1730
#define SVID_L30				1740
//
#define SVID_TBL1_COUNT			2100
#define SVID_TBL1				2110
#define SVID_TBL1_LIST			2111
#define SVID_TBL2_COUNT			2200
#define SVID_TBL2				2210
#define SVID_TBL2_LIST 			2211
#define SVID_TBL3_COUNT			2300
#define SVID_TBL3				2310
#define SVID_TBL3_LIST			2311
#define SVID_TBL4_COUNT			2400
#define SVID_TBL4				2410
#define SVID_TBL4_LIST			2411
#define SVID_TBL5_COUNT			2500
#define SVID_TBL5				2510
#define SVID_TBL5_LIST			2511
#define SVID_TBL6_COUNT			2600
#define SVID_TBL6				2610
#define SVID_TBL6_LIST			2611
#define SVID_TBL7_COUNT			2700
#define SVID_TBL7				2710
#define SVID_TBL7_LIST			2711
#define SVID_TBL8_COUNT			2800
#define SVID_TBL8				2810
#define SVID_TBL8_LIST			2811
#define SVID_TBL9_COUNT			2900
#define SVID_TBL9				2910
#define SVID_TBL9_LIST			2911

#define SVID_EVENT1				7010
#define SVID_EVENT2				7020
#define SVID_EVENT3				7030
#define SVID_EVENT4				7040
#define SVID_EVENT5				7050
#define SVID_EVENT6				7060
#define SVID_EVENT7				7070
#define SVID_EVENT8				7080
#define SVID_EVENT9				7090
#define SVID_EVENT10			7100
#define SVID_EVENT11			7110
#define SVID_EVENT12			7120
#define SVID_EVENT13			7130
#define SVID_EQUIP_DATE			9000
///////////////////////////////////////////////////////////////

#define SVID_COMMSTATE			2001
#define SVID_CONTROLSTATE		2002
#define SVID_PREV_CONTROLSTATE	2003
#define SVID_ALID				2005
#define SVID_ALCD				2007
#define SVID_ALTX				2008

#define SVID_CLOCK				2012
#define SVID_MDLN				2013
#define SVID_SOFTREV			2014

#define SVID_OPERATOR_ID		2026

#define SVID_SPOOLCOUNT_TOTAL	2030
#define SVID_SPOOLCOUNT_ACTUAL	2031
#define SVID_SPOOL_FULLTIME		2032
#define SVID_SPOOL_STARTTIME	2033
#define SVID_SPOOL_STATE		2034
#define SVID_SPOOL_MAX_COUNT	2035

#define SVID_ECID				2041
#define SVID_ECVAL				2042

#define SVID_PROC_STATE			2050
#define SVID_PREV_PROCSTATE		2051

#define SVID_PPCHANGE_NAME		2061
#define SVID_PPCHANGE_STATUS	2062

////////////////////////////////////////////////////////////
#define SVID_PPID				2200
#define SVID_PORTID				2300


////////////////////////////////////////////////////////////////////////////////////
#define CEID_EIS_SSD_CMN_IN_TAG		1000 //2014.07 SK Hynix Module Inline 
#define CEID_EQ_EFF_INFO			7000

//////////////////////////////////////////////////////////

//#define ECID_PORT					3001

#define	ECID_ESTABLISH_TIMEOUT		3001


//#define ECID_DEVICEID				3002
#define ECID_T3						3002
#define ECID_T5						3003
#define ECID_T6						3004
#define ECID_T7						3005
#define ECID_T8						3006
#define ECID_CONVERSATION_TIMEOUT	3007
#define ECID_LINKTEST				3008
#define ECID_RETRY					3009

#define ECID_DEFAULT_COMM_STATE		3010
#define ECID_DEFAULT_CONTROL_STATE	3011

//#define ECID_MDLN					3103
//#define ECID_SOFTREV				3104

#define ECID_MAX_SPOOL_SIZE			3012
#define ECID_MAXSPOOL_TRANSMIT		3013
#define ECID_SPOOL_OVERWRITE		3014
#define ECID_SPOOLING_MODE			3015

#define ECID_TIME_FORMAT			3016
#define ECID_JOBINFO_OPCONFIRM		3017
#define ECID_IDLE_TIME				3018
//#define ECID_BCR_USE				3600


#define TIMERID_TRAY				1001
#define TIMERID_START				1002

#define TIMERID_SETTIME				1003
#define INTERVAL_SETTIME			1000

///////////////////////////////////////////////////////////////////////
#define PROCESS_UNDEFINE		0
#define PROCESS_INIT			1
#define PROCESS_IDLE			2
#define PROCESS_SETUP			3
#define PROCESS_READY			4
#define PROCESS_EXECUTING		5
#define PROCESS_PAUSED			6

///////////////////////////////////////////////////////////////////////
//for the readability
//DMS:10.18.84.201 ,test:10.18.84.247 , AL:10.18.84.206, AS:10.18.84.224, FS: 10.18.84.225 
//ip
#define DMS_IP			L"10.18.84.201"
#define	ETH1_IP			L"10.18.84.202"
#define	ETH2_IP			L"10.18.84.204"
#define ATL_IP			L"10.18.84.206"
#define ATH1_IP			L"10.18.84.207"
#define ATH2_IP			L"10.18.84.216"
#define ATS_IP			L"10.18.84.224"
#define FS_IP			L"10.18.84.225"
//(전산등록) device id 
#define ETH1_DEV_ID		L"MODULE01-EH1"
#define ET1_DEV_ID		L"MODULE01-ES1"
#define ETH2_DEV_ID		L"MODULE01-EH2"
#define ET2_DEV_ID		L"MODULE01-ES2"
#define ATL_DEV_ID		L"MODULE01-AL1"
#define ATH1_DEV_ID		L"MODULE01-AH1"
#define ATH2_DEV_ID		L"MODULE01-AH2"
#define ATS_DEV_ID		L"MODULE01-AS1"
#define FS_DEV_ID		L"MODULE01-FS1"
//Common Func
#define MOVE_OUT_LOT_INFO	 L"MOVE_OUT_LOT_INFO"
#define MOVE_OUT			 L"MOVE_OUT"
#define MOVE_IN_LOT_INFO	 L"MOVE_IN_LOT_INFO"
#define MOVE_IN				 L"MOVE_IN"
#define LABEL				 L"LABEL"
#define SPLIT_LABEL			 L"SPLIT_LABEL"
#define LOW_YIELD_INFO		 L"LOW_YIELD_INFO"	
#define LOW_YIELD_OCCUR_INFO L"LOW_YIELD_OCCUR_INFO"
#define LOW_YIELD_OCCUR		 L"LOW_YIELD_OCCUR"
//공정
#define ERN					 L"5600"
#define AT_INPUT			 L"5560"
#define AHN					 L"5710"
#define ARN					 L"5700"
#define VM					 L"5800"
//ZEBRA Label Printer ZPL - LH(Label Home),BA(Code 93 Bar Code) command 좌표 수정
//(Zebra Label Printer Model) ATL,ATS - GC420t/ FS - 105SLPLUS
#define GC420_LH			 L"^LH120"
#define SL105_LH             L"^LH300"
#define GC420_BA			 L"^BAN,55"
#define SL105_BA			 L"^BAN,55"