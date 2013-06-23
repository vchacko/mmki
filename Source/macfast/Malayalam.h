
#define AFX_CLASS_EXPORT __declspec(dllexport)


AFX_CLASS_EXPORT void installhook();//This function installs the Keyboard hook.
AFX_CLASS_EXPORT void removehook();//This function removes the previously installed hook.
AFX_CLASS_EXPORT LRESULT CALLBACK GetMsgProc(int,WPARAM,LPARAM);
AFX_CLASS_EXPORT LRESULT CALLBACK KeyboardProc(int,WPARAM,LPARAM);
void _font_Macfast();
void _font_Macfast_lshift();
void _font_Macfast_rshift();

BOOL isMalayalam();