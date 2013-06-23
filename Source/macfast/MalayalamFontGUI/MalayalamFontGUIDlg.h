// MalayalamFontGUIDlg.h : header file
//

#if !defined(AFX_MALAYALAMFONTGUIDLG_H__28880F54_D0F5_11D8_8E5B_000EA633361C__INCLUDED_)
#define AFX_MALAYALAMFONTGUIDLG_H__28880F54_D0F5_11D8_8E5B_000EA633361C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define AFX_CLASS_IMPORT __declspec(dllimport)

#include "TrayDialog.h"
#include "Splash.h"
AFX_CLASS_IMPORT void installhook();//This function installs the Keyboard hook.
AFX_CLASS_IMPORT void removehook();//This function removes the previously installed hook.

/////////////////////////////////////////////////////////////////////////////
// CMalayalamFontGUIDlg dialog

class CMalayalamFontGUIDlg : public CTrayDialog
{
// Construction
public:
	bool start;
	CMalayalamFontGUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMalayalamFontGUIDlg)
	enum { IDD = IDD_MALAYALAMFONTGUI_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMalayalamFontGUIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMalayalamFontGUIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnExit();
	afx_msg void OnClose();
	afx_msg void OnOk();
	afx_msg void OnStop();
	afx_msg void OnAbout();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMacfastSplash();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MALAYALAMFONTGUIDLG_H__28880F54_D0F5_11D8_8E5B_000EA633361C__INCLUDED_)
