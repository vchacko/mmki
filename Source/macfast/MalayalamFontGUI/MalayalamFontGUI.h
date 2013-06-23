// MalayalamFontGUI.h : main header file for the MALAYALAMFONTGUI application
//

#if !defined(AFX_MALAYALAMFONTGUI_H__28880F52_D0F5_11D8_8E5B_000EA633361C__INCLUDED_)
#define AFX_MALAYALAMFONTGUI_H__28880F52_D0F5_11D8_8E5B_000EA633361C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMalayalamFontGUIApp:
// See MalayalamFontGUI.cpp for the implementation of this class
//

class CMalayalamFontGUIApp : public CWinApp
{
public:
	CMalayalamFontGUIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMalayalamFontGUIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMalayalamFontGUIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MALAYALAMFONTGUI_H__28880F52_D0F5_11D8_8E5B_000EA633361C__INCLUDED_)
