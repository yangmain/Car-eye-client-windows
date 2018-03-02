// CarEyePlayerWebActiveXCtrl.cpp : CCarEyePlayerWebActiveXCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "CarEyePlayerWebActiveX.h"
#include "CarEyePlayerWebActiveXCtrl.h"
#include "CarEyePlayerWebActiveXPropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CCarEyePlayerWebActiveXCtrl, COleControl)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CCarEyePlayerWebActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// ����ӳ��

BEGIN_DISPATCH_MAP(CCarEyePlayerWebActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CCarEyePlayerWebActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CCarEyePlayerWebActiveXCtrl, "Start", dispidStart, Start, VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CCarEyePlayerWebActiveXCtrl, "Config", dispidConfig, Config, VT_EMPTY, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CCarEyePlayerWebActiveXCtrl, "Close", dispidClose, Close, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CCarEyePlayerWebActiveXCtrl, "SetOSD", dispidSetOSD, SetOSD, VT_EMPTY, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)

END_DISPATCH_MAP()



// �¼�ӳ��

BEGIN_EVENT_MAP(CCarEyePlayerWebActiveXCtrl, COleControl)
	EVENT_CUSTOM_ID("OnPlayEvent", eventidOnPlayEvent, OnPlayEvent, VTS_BSTR)
END_EVENT_MAP()



// ����ҳ

// TODO: ����Ҫ���Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CCarEyePlayerWebActiveXCtrl, 1)
	PROPPAGEID(CCarEyePlayerWebActiveXPropPage::guid)
END_PROPPAGEIDS(CCarEyePlayerWebActiveXCtrl)



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CCarEyePlayerWebActiveXCtrl, "CarEyePLAYERWEBACT.CarEyePlayerWebActCtrl.1",
	0x1ee1c648, 0xf4a9, 0x42f9, 0x9a, 0xa7, 0x2c, 0x8e, 0x3a, 0xf7, 0xb7, 0xfd)



// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CCarEyePlayerWebActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)



// �ӿ� ID

const IID IID_DCarEyePlayerWebActiveX = { 0xFB5E35A6, 0x2538, 0x47C4, { 0x9B, 0x40, 0xB0, 0xFB, 0x6A, 0x0, 0xDE, 0xA0 } };
const IID IID_DCarEyePlayerWebActiveXEvents = { 0x66887A6D, 0xC75B, 0x48B8, { 0xB5, 0xE1, 0xBD, 0x72, 0x2D, 0x87, 0x59, 0x23 } };


// �ؼ�������Ϣ

static const DWORD _dwCarEyePlayerWebActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCarEyePlayerWebActiveXCtrl, IDS_CarEyePLAYERWEBACTIVEX, _dwCarEyePlayerWebActiveXOleMisc)



// CCarEyePlayerWebActiveXCtrl::CCarEyePlayerWebActiveXCtrlFactory::UpdateRegistry -
// ���ӻ��Ƴ� CCarEyePlayerWebActiveXCtrl ��ϵͳע�����

BOOL CCarEyePlayerWebActiveXCtrl::CCarEyePlayerWebActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳�������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegInsertable | afxRegApartmentThreading ��Ϊ afxRegInsertable��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CarEyePLAYERWEBACTIVEX,
			IDB_CarEyePLAYERWEBACTIVEX,
			afxRegInsertable | afxRegApartmentThreading,
			_dwCarEyePlayerWebActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// ��Ȩ�ַ���

static const TCHAR _szLicFileName[] = _T("CarEyePlayerWebPlugin.lic");

static const WCHAR _szLicString[] = L"Copyright (c) 2016 ";



// CCarEyePlayerWebActiveXCtrl::CCarEyePlayerWebActiveXCtrlFactory::VerifyUserLicense -
// ����Ƿ�����û�����֤

BOOL CCarEyePlayerWebActiveXCtrl::CCarEyePlayerWebActiveXCtrlFactory::VerifyUserLicense()
{
	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);
}



// CCarEyePlayerWebActiveXCtrl::CCarEyePlayerWebActiveXCtrlFactory::GetLicenseKey -
// ��������ʱ��Ȩ��Կ

BOOL CCarEyePlayerWebActiveXCtrl::CCarEyePlayerWebActiveXCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR *pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}



// CCarEyePlayerWebActiveXCtrl::CCarEyePlayerWebActiveXCtrl - ���캯��

CCarEyePlayerWebActiveXCtrl::CCarEyePlayerWebActiveXCtrl()
{
	InitializeIIDs(&IID_DCarEyePlayerWebActiveX, &IID_DCarEyePlayerWebActiveXEvents);
	// TODO: �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
	m_bInit = false;

	memset(szURL, 0x00, 512);
	memset(szUserName, 0x00, 128);
	memset(szPassword, 0x00, 128);
	nHardDecode = 0;
	eRenderFormat = DISPLAY_FORMAT_YV12;

	nFrameCache = 3;
	bPlaySound = TRUE;
	bShowToScale = FALSE;
	bShowStatisticInfo = TRUE;
}



// CCarEyePlayerWebActiveXCtrl::~CCarEyePlayerWebActiveXCtrl - ��������

CCarEyePlayerWebActiveXCtrl::~CCarEyePlayerWebActiveXCtrl()
{
	// TODO: �ڴ������ؼ���ʵ�����ݡ�

}



// CE	AfxMessageBox(_T("ҳ���Ѿ��رգ����¼���OCX"));


void CCarEyePlayerWebActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: �����Լ��Ļ�ͼ�����滻����Ĵ��롣
// 	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
// 	pdc->Ellipse(rcBounds);

	DoSuperclassPaint(pdc, rcBounds);

	//if (!m_pActiveDlg.IsFullScreen())
	{
		m_pActiveDlg.MoveWindow(rcBounds, TRUE);
	}

	CBrush brBackGnd(TranslateColor(AmbientBackColor()));
	pdc->FillRect(rcBounds, &brBackGnd);

}



// CCarEyePlayerWebActiveXCtrl::DoPropExchange - �־���֧��

void CCarEyePlayerWebActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}



// CCarEyePlayerWebActiveXCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CCarEyePlayerWebActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}



// CCarEyePlayerWebActiveXCtrl::AboutBox - ���û���ʾ�����ڡ���

void CCarEyePlayerWebActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CarEyePLAYERWEBACTIVEX);
	dlgAbout.DoModal();
}



// CCarEyePlayerWebActiveXCtrl ��Ϣ��������


int CCarEyePlayerWebActiveXCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ�������ר�õĴ�������
	// OCX���ô��ڱ�����OCX�ؼ�Ϊ���ര�ڵ��Ӵ��ڣ����������ʾ�������� [4/14/2014-10:12:38 Dingshuai]
	m_pActiveDlg.Create(CMainVideoWnd::IDD, this);

	return 0;
}


void CCarEyePlayerWebActiveXCtrl::OnDestroy()
{
	COleControl::OnDestroy();
	// TODO: �ڴ˴�������Ϣ�����������
	m_pActiveDlg.DestroyWindow();

}

int CCarEyePlayerWebActiveXCtrl::CarEyePlayerCallBack( int _channelId, int *_channelPtr, int _frameType, char *pBuf, CAREYE_RTSP_FRAME_INFO* _frameInfo)
{
	if (_frameType == CAREYE_SDK_EVENT_FRAME_FLAG)
	{
		//TRACE( "%s", pBuf  );
		CCarEyePlayerWebActiveXCtrl* pMaster = (CCarEyePlayerWebActiveXCtrl*)_channelPtr;
		if (pMaster && _frameInfo)
		{
			if (_frameInfo->codec == CAREYE_SDK_EVENT_CODEC_EXIT)
			{
					if (NULL !=pMaster->m_pActiveDlg)			
						pMaster->m_pActiveDlg.Invalidate();
			}
			else if (_frameInfo->codec == CAREYE_SDK_EVENT_CODEC_ERROR)
			{
				CString sErrorMsg = (CString)pBuf;
				pMaster->OnPlayEvent(sErrorMsg);
				// ��������������ʱ��  [11/22/2017 SwordTwelve]
				// 


			}
// 			CString sErrorMsg = (CString)pBuf;
// 			pMaster->OnPlayEvent(sErrorMsg);

		}
	}
	return 0;
}

LONG CCarEyePlayerWebActiveXCtrl::Start(LPCTSTR sURL, LPCTSTR sRenderFormat, LPCTSTR sUserName, LPCTSTR sPassword, LPCTSTR sHardDecord)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO: �ڴ����ӵ��ȴ����������
	// 
	int nRet = 0;
	if (m_bInit)
	{
		char szRenderFormat[128] ;
		char szHardDecord[128] ;
		if (wcslen(sURL) < 1)		
			return -1;
		__WCharToMByte(sURL, szURL, sizeof(szURL)/sizeof(szURL[0]));
		if (wcslen(sRenderFormat) > 0)
		{
			__WCharToMByte(sRenderFormat, szRenderFormat, sizeof(szRenderFormat)/sizeof(szRenderFormat[0]));
		}
		if (wcslen(sUserName) > 0)
		{
			__WCharToMByte(sUserName, szUserName, sizeof(szUserName)/sizeof(szUserName[0]));
		}
		if (wcslen(sPassword) > 0)
		{
			__WCharToMByte(sPassword, szPassword, sizeof(szPassword)/sizeof(szPassword[0]));
		}
		if (wcslen(sHardDecord) > 0)
		{
			__WCharToMByte(sHardDecord, szHardDecord, sizeof(szHardDecord)/sizeof(szHardDecord[0]));
		}

		nHardDecode = atoi(szHardDecord);
		int nRenderType = atoi(szRenderFormat);
		eRenderFormat = DISPLAY_FORMAT_YV12;
		switch (nRenderType)
		{
		case 0:
			eRenderFormat = DISPLAY_FORMAT_YV12;
			break;
		case 1:
			eRenderFormat = DISPLAY_FORMAT_YUY2;
			break;
		case 2:
			eRenderFormat = DISPLAY_FORMAT_UYVY;
			break;
		case 3:
			eRenderFormat = DISPLAY_FORMAT_A8R8G8B8;
			break;
		case 4:
			eRenderFormat = DISPLAY_FORMAT_X8R8G8B8;
			break;
		case 5:
			eRenderFormat = DISPLAY_FORMAT_RGB565;
			break;
		case 6:
			eRenderFormat = DISPLAY_FORMAT_RGB555;
			break;
		case 7:
			eRenderFormat = DISPLAY_FORMAT_RGB24_GDI;
			break;
		}

		nRet = m_player.Start(szURL, m_pActiveDlg.GetSafeHwnd(), eRenderFormat , 1, szUserName , szPassword, nHardDecode, &CCarEyePlayerWebActiveXCtrl::CarEyePlayerCallBack, this);

	}
	else
	{
		SetTimer( WM_TIMER_START_ID, 500, NULL );
	}

	return nRet;
}


void CCarEyePlayerWebActiveXCtrl::Config(LPCTSTR sFrameCache, LPCTSTR sPlaySound, LPCTSTR sShowToScale, LPCTSTR sShowStatisticInfo )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO: �ڴ����ӵ��ȴ����������
	// 
	if (m_bInit)
	{
		char szFrameCache[128] = {0,};
		char szPlaySound[128] = {0,};
		char szShowToScale[128] = {0,};
		char szShowStatisticInfo[128] = {0,};


		if (wcslen(sFrameCache) > 0)
		{
			__WCharToMByte(sFrameCache, szFrameCache, sizeof(szFrameCache)/sizeof(szFrameCache[0]));
			nFrameCache = atoi(szFrameCache);
		}
		if (wcslen(sPlaySound) > 0)
		{
			__WCharToMByte(sPlaySound, szPlaySound, sizeof(szPlaySound)/sizeof(szPlaySound[0]));
			bPlaySound = atoi(szPlaySound);
		}
		if (wcslen(sShowToScale) > 0)
		{
			__WCharToMByte(sShowToScale, szShowToScale, sizeof(szShowToScale)/sizeof(szShowToScale[0]));
			bShowToScale = atoi(szShowToScale);
		}
		if (wcslen(sShowStatisticInfo) > 0)
		{
			__WCharToMByte(sShowStatisticInfo, szShowStatisticInfo, sizeof(szShowStatisticInfo)/sizeof(szShowStatisticInfo[0]));
			bShowStatisticInfo = atoi(szShowStatisticInfo);
		}
		m_player.Config(nFrameCache, bPlaySound, bShowToScale, bShowStatisticInfo );
	}
	else
	{
		SetTimer( WM_TIMER_CONFIG_ID, 500, NULL );
	}
}


void CCarEyePlayerWebActiveXCtrl::SetOSD(LPCTSTR show, LPCTSTR alpha, LPCTSTR red, LPCTSTR green, LPCTSTR blue, 
	LPCTSTR left, LPCTSTR top, LPCTSTR right, LPCTSTR bottom, LPCTSTR strOSD)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_bInit)
	{
		char szshow[128] = {0,};
		char szalpha[128] = {0,};
		char szred[128] = {0,};
		char szgreen[128] = {0,};
		char szblue[128] = {0,};

		char szleft[128] = {0,};
		char sztop[128] = {0,};
		char szright[128] = {0,};
		char szbottom[128] = {0,};

		CAREYE_PALYER_OSD osd;
		memset(&osd, 0x00, sizeof(osd));
		int R,G,B = 0;
		int bShow = 0;
		if (wcslen(show) > 0)
		{
			__WCharToMByte(show, szshow, sizeof(szshow)/sizeof(szshow[0]));
			bShow = atoi(szshow);
		}
		if (wcslen(alpha) > 0)
		{
			__WCharToMByte(alpha, szalpha, sizeof(szalpha)/sizeof(szalpha[0]));
			osd.alpha = atoi(szalpha);
		}
		if (wcslen(red) > 0)
		{
			__WCharToMByte(red, szred, sizeof(szred)/sizeof(szred[0]));
			R = atoi(szred);
		}
		if (wcslen(green) > 0)
		{
			__WCharToMByte(green, szgreen, sizeof(szgreen)/sizeof(szgreen[0]));
			G = atoi(szgreen);
		}
		if (wcslen(blue) > 0)
		{
			__WCharToMByte(blue, szblue, sizeof(szblue)/sizeof(szblue[0]));
			B = atoi(szblue);
		}
		if (wcslen(left) > 0)
		{
			__WCharToMByte(left, szleft, sizeof(szleft)/sizeof(szleft[0]));
			osd.rect.left = atoi(szleft);
		}
		if (wcslen(top) > 0)
		{
			__WCharToMByte(top, sztop, sizeof(sztop)/sizeof(sztop[0]));
			osd.rect.top = atoi(sztop);
		}
		if (wcslen(right) > 0)
		{
			__WCharToMByte(right, szright, sizeof(szright)/sizeof(szright[0]));
			osd.rect.right = atoi(szright);
		}
		if (wcslen(bottom) > 0)
		{
			__WCharToMByte(bottom, szbottom, sizeof(szbottom)/sizeof(szbottom[0]));
			osd.rect.bottom = atoi(szbottom);
		}
		osd.color = RGB(R,G,B);

		if (wcslen(strOSD) > 0)
		{
			__WCharToMByte(strOSD, osd.stOSD, sizeof(osd.stOSD)/sizeof(osd.stOSD[0]));
		}
		m_player.SetOSD(bShow, osd);

	}
}

void CCarEyePlayerWebActiveXCtrl::Close(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ����ӵ��ȴ����������
	m_player.Close();
}

void CCarEyePlayerWebActiveXCtrl::OnSetClientSite()
{
	// TODO: 
	if (m_pClientSite) 
	{
		int ret = CarEyePlayerManager::Init();
#if 0
		CString str = _T("");
		str.Format(_T("Init = %d"), ret);
		AfxMessageBox(str);
#endif
		//�����ڼ����С������Ҫ����Ϊ�ؼ��ڱ��ؼ���ʱ���Զ��ػ������¶�λ��
		VERIFY (CreateControlWindow (::GetDesktopWindow(), CRect(0,0,0,0), CRect(0,0,0,0)));
		m_bInit = true;
	}
	else
	{
		Close();
		// ����ˢ�»ᱨ�� [10/12/2017 dingshuai]
		//CarEyePlayerManager::UnInit();
		//AfxMessageBox(_T("ҳ���Ѿ��رգ����¼���OCX"));
		DestroyWindow();
		m_bInit = false;

	}
	COleControl::OnSetClientSite();
}

void CCarEyePlayerWebActiveXCtrl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 
	switch (nIDEvent)
	{
	case WM_TIMER_START_ID:
		{
			if (m_bInit)
			{
				int ret = m_player.Start(szURL, m_pActiveDlg.GetSafeHwnd(), eRenderFormat , 1, szUserName , szPassword, nHardDecode);
				KillTimer(WM_TIMER_START_ID);
			}
		}
		break;
	case WM_TIMER_CONFIG_ID:
		{
			if (m_bInit)
			{
				m_player.Config(nFrameCache, bPlaySound, bShowToScale, bShowStatisticInfo );
				KillTimer(WM_TIMER_CONFIG_ID);
			}
		}
		break;
	}

	COleControl::OnTimer(nIDEvent);
}
