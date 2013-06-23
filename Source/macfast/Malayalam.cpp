// Malayalam.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>
#include "Malayalam.h"
#include "KeyMaps.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma data_seg(".HOOKDATA")//Shared data among all instances.
HHOOK hook = NULL;
DWORD msgTime = NULL;
HINSTANCE hinstance = NULL;
LPMSG msg = NULL;
BOOL preback=FALSE,paint = FALSE;
static DWORD prev = 32,prev_key;
static DWORD prev_PK = -1,prev_K;// For kootaksharam
static DWORD key;
static INT keyDown = 0;
static UINT index = 0,left_index;
#pragma data_seg()

#define BACK_SPACE 0x01000008

static AFX_EXTENSION_MODULE MalayalamDLL = { NULL, NULL };

extern "C" int APIENTRY

DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("MALAYALAM.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(MalayalamDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(MalayalamDLL);
		Initialize();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		
//		Remove();
		TRACE0("MALAYALAM.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(MalayalamDLL);
	}

	hinstance = hInstance;
	hook = NULL;
	Initialize();
	prev = 32;
	return 1;   // ok
}

AFX_CLASS_EXPORT void installhook()
{
	hook = NULL;
	hook = SetWindowsHookEx(WH_GETMESSAGE,GetMsgProc,hinstance,NULL);
	if(hook==NULL)
		MessageBox(NULL,"Unable to install hook","Error!",MB_OK);
}

AFX_CLASS_EXPORT void removehook()
{
	UnhookWindowsHookEx(hook);
}
AFX_CLASS_EXPORT LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	return FALSE;
}
void PutBackSpace(int n)
{
	for(int i =0;i<n;i++)
	{
 		if(preback==TRUE)
		{
			if(key != 0x18 && key != 0x22 && key != 0x24 && key != 0x25 && key != 0x2e)
			{
				PostMessage(msg->hwnd,WM_KEYDOWN,BACK_SPACE,0);
				PostMessage(msg->hwnd,WM_KEYUP,BACK_SPACE,0);
			}
			PostMessage(msg->hwnd,WM_CHAR,BACK_SPACE,0);
			
		}
		else if(paint == TRUE)
		{
			
			if(key != 0x18 && key != 0x22 && key != 0x24 && key != 0x25&& key!= 0x2e )
				PostMessage(msg->hwnd,WM_CHAR,BACK_SPACE,0);
		}
		else
			PostMessage(msg->hwnd,WM_CHAR,BACK_SPACE,0);
	}
}
AFX_CLASS_EXPORT LRESULT CALLBACK GetMsgProc(int nCode,WPARAM wParam,LPARAM lParam)
{

	preback = FALSE;
	paint = FALSE;
	try{
	if (nCode < 0)
		return CallNextHookEx(hook, nCode, wParam, lParam);
	msg = (LPMSG) lParam;

	LPTSTR faceName = NULL;
	if(nCode == HC_ACTION && wParam == PM_REMOVE && msgTime != msg->time&&isMalayalam())
	{
		switch (msg->message){
			case WM_CHAR:
					
					msgTime = msg->time;
					_font_Macfast();
					if(msg->wParam > 32)
					{
						PutBackSpace(1);
						PostMessageW(msg->hwnd,WM_CHAR,msg->wParam ,0); 
						
					}
					break;

			case WM_KEYDOWN:
					key = (msg->lParam&0xFF0000)>>16;
					keyDown = 1;
					if(	(key>=0x02&&key<=0x0a)||
						(key>=0x10&&key<=0x19)||
						(key>=0x1e&&key<=0x26)||
						(key>=0x2c&&key<=0x32))
					{
							index = 1;
							left_index = 1;
					}
					break;
			case WM_KEYUP:if((key>=0x02&&key<=0x0a)||
							 (key>=0x10&&key<=0x19)||
							 (key>=0x1e&&key<=0x26)||
							 (key>=0x2c&&key<=0x32)||
							 (key==0x36||key==0x2a)&&
							 prev!=0)
						  {
							  
							if(key == 0x36 && keyDown==1)
							{//Right Shift Scancode - 0x36
								keyDown = 0;
								msgTime = msg->time;
								
								_font_Macfast_rshift();
								PutBackSpace(1);
								PostMessageW(msg->hwnd,WM_CHAR,prev,0);
											
							}
							else if(key == 0x2A &&keyDown==1)
							{//Left Shift Scancode - 0x2A
								 
								keyDown = false;
								msgTime = msg->time;
								_font_Macfast_lshift();
								PutBackSpace(1);
								PostMessageW(msg->hwnd,WM_CHAR,prev,0);
							}
						  }
							else 
								prev = 0;
					break;
				}
		
	}
	}catch(...){}
	if(nCode>=0) 
		return (CallNextHookEx(hook,nCode,prev,lParam) );
	else  return TRUE;
}
BOOL isMalayalam()
{
	if(GetKeyState(VK_SCROLL)&1)
	{
		CWnd * window = CWnd::FromHandle(msg->hwnd);
		
		window = window->GetTopLevelParent();
		CString s;
		window->GetWindowText(s);
		
		if(s.Find("Microsoft Word")>-1)
		{
			preback = FALSE;
			return true;
		}
		else if(s.Find("Paint")>-1)
		{
			paint = TRUE;
			return true;
		}
		else 
		{ 
			
			preback = TRUE;
			return true;
		}
		return true;
	}
	return false;
}

void _font_Macfast_lshift(){

	if(Left_Shift[prev_key-10] != NULL  )
	{
		left_index ++;
		while(Left_Shift[prev_key-10][index] == NULL)
			index++;
		
		if(left_index > Left_Shift[prev_key-10][index][0])
			left_index = 1;
		prev = Left_Shift[prev_key-10][index][left_index];
	}
}
void _font_Macfast_rshift(){

	if(Primary_Right_Shift[prev_key]!=NULL)
	{
		index++;
		if(index > Primary_Right_Shift[prev_key][0])
			index = 1;

		prev = Primary_Right_Shift[prev_key][index];
	
	}	
}


void _font_Macfast()
{
		if(prev_K == 0x01000d4d){
		
		for(int i = 0;Kootaksharam[i][0]!=0x0000;i++)
		{
			if(Kootaksharam[i][0] != prev_PK || Kootaksharam[i][1] != prev)
				continue;
			PutBackSpace(4);
			PostMessageW(msg->hwnd,WM_CHAR,Kootaksharam[i][2],0);
			PostMessage(msg->hwnd,WM_CHAR,32,0);
			prev = Kootaksharam[i][2];
		}
	}

//	If the key pressed is uppercase letters
	if(msg->wParam >=65 && msg->wParam <=90)
		prev_key = msg->wParam-55;
//	If the key pressed is lowercase letters
	else if(msg->wParam >=97 && msg->wParam <=122)
		prev_key = msg->wParam-87;
	else if(msg->wParam >=48 && msg->wParam <=57)
	{
		prev_key = msg->wParam - 48;
		return;
	}
	else
		return;

	msg->wParam = Primary_Letters[prev_key-10];

	prev_PK = prev_K;
	prev_K = prev;
	prev = msg->wParam;


}

