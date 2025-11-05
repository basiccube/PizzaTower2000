class CLauncherWindow : public CFrameWnd
{
public:
	CLauncherWindow();

	static void CALLBACK SetFont(HWND child, LPARAM font);

	afx_msg void OnStartClick();
	afx_msg void OnExitClick();
	afx_msg void OnSndPackClick();

	afx_msg void OnWScreenCheck();
	afx_msg void OnHUDCheck();

	bool b_Widescreen;
	bool b_NewHUD;

private:
	CStatic infoText;
	CStatic charInfoText;

	CButton startBtn;
	CButton exitBtn;
	CButton sndPackBtn;

	CButton wscreenChk;
	CButton hudChk;

	CListBox charList;
	CListBox charDirList;

	enum
	{
		ID_STARTBTN = 100,
		ID_EXITBTN,
		ID_SNDPACKBTN,
		ID_WSCREENCHK,
		ID_HUDCHK,
		ID_CHARLIST,
		ID_CHARDIRLIST
	};

	DECLARE_MESSAGE_MAP()
};