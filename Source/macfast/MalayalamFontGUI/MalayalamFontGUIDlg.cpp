// MalayalamFontGUIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MalayalamFontGUI.h"
#include "MalayalamFontGUIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CTrayDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CTrayDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CTrayDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CTrayDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMalayalamFontGUIDlg dialog

CMalayalamFontGUIDlg::CMalayalamFontGUIDlg(CWnd* pParent /*=NULL*/)
	: CTrayDialog(CMalayalamFontGUIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMalayalamFontGUIDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMalayalamFontGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CTrayDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMalayalamFontGUIDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMalayalamFontGUIDlg, CTrayDialog)
	//{{AFX_MSG_MAP(CMalayalamFontGUIDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_START, OnStart)
	ON_BN_CLICKED(IDEXIT, OnExit)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_COMMAND(ID_STOP, OnStop)
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_START, OnStart)
	ON_COMMAND(ID_MACFAST_SPLASH, OnMacfastSplash)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMalayalamFontGUIDlg message handlers

BOOL CMalayalamFontGUIDlg::OnInitDialog()
{
	CTrayDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	TraySetIcon(IDR_MAINFRAME);
    TraySetToolTip("MACFAST Malayalam Keyboard");
    TraySetMenu(IDR_MENU);
	CSplashWnd::ShowSplashScreen(NULL);
	start = false;

	WINDOWPLACEMENT m_placement;
	m_placement.showCmd = SW_SHOWMINIMIZED;
	this->SetWindowPlacement(&m_placement);
	SetTimer(1, 750, NULL);
	this->OnStart(); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMalayalamFontGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CTrayDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMalayalamFontGUIDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CTrayDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMalayalamFontGUIDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMalayalamFontGUIDlg::OnStart() 
{
	// TODO: Add your control notification handler code here

	if(start == false){
		start = true;
		installhook();
	}
}

void CMalayalamFontGUIDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	removehook();
	CTrayDialog::OnCancel();
}



void CMalayalamFontGUIDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	removehook();
	CTrayDialog::OnClose();
}



void CMalayalamFontGUIDlg::OnOk() 
{
	// TODO: Add your control notification handler code here
//	OnCommand(SC_MINIMIZE,0);
	if(TrayShow())
		this->ShowWindow(SW_HIDE);
}

void CMalayalamFontGUIDlg::OnStop() 
{
	// TODO: Add your command handler code here
		if(start == true){
		start = false;
		removehook();
//		m_Start.SetWindowText("Start");
		
	}
}

void CMalayalamFontGUIDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg about;
	about.DoModal(); 
}



int CMalayalamFontGUIDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTrayDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	return 0;
}



void CMalayalamFontGUIDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTrayDialog::OnTimer(nIDEvent);
	if(TrayShow())
		this->ShowWindow(SW_HIDE);
}

void CMalayalamFontGUIDlg::OnMacfastSplash() 
{
	// TODO: Add your command handler code here
	CSplashWnd::ShowSplashScreen(NULL,10000);  
}
