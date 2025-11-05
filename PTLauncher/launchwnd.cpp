#include <AFXWIN.H>
#include "launchwnd.h"
#include "sndpackwnd.h"

#include "resource.h"

#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)
bool FileExists(LPCTSTR path)
{
	DWORD attrib = GetFileAttributes(path);
	return (attrib != INVALID_FILE_ATTRIBUTES && !(attrib & FILE_ATTRIBUTE_DIRECTORY));
}

#define EXE_PATH "PizzaTower2000.exe"
#define INI_PATH ".\\saveData.ini"

#define PLAYER_PATH ".\\gfx\\player\\"

#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240
#define PADDING 8

#define BUTTON_WIDTH 80
#define BUTTON_HEIGHT 25
#define BUTTON_PADDING PADDING * 2


HICON launcherIcon;
CLauncherWindow::CLauncherWindow()
{
	if (!FileExists(EXE_PATH))
	{
		MessageBox("Cannot find the executable for Pizza Tower 2000.");
		PostQuitMessage(0);
	}
	

	launcherIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_LAUNCHER));
	
	// create launcher window
	LPCTSTR wndClass = AfxRegisterWndClass(NULL, 0, GetSysColorBrush(COLOR_3DFACE), launcherIcon);
	Create(wndClass,
		"Pizza Tower 2000 Launcher",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT),
		NULL, 0);
	ModifyStyleEx(WS_EX_CLIENTEDGE, 0, 0);
	
	infoText.Create("Configure game options and then press the Start! button to launch the game.",
					WS_CHILD | WS_VISIBLE | SS_LEFT,
					CRect(PADDING, PADDING, WINDOW_WIDTH - PADDING, 150),
					this);
	
	// create buttons
	const int startX = PADDING;
	const int startY = WINDOW_HEIGHT - BUTTON_PADDING - (BUTTON_HEIGHT * 2);
	const int startW = startX + BUTTON_WIDTH;
	const int startH = startY + BUTTON_HEIGHT;
	startBtn.Create("Start!",
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					CRect(startX, startY, startW, startH),
					this, ID_STARTBTN);
	
	const int exitX = WINDOW_WIDTH - PADDING - BUTTON_WIDTH - 6;
	const int exitY = startY;
	const int exitW = exitX + BUTTON_WIDTH;
	const int exitH = startH;
	exitBtn.Create("Exit",
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					CRect(exitX, exitY, exitW, exitH),
					this, ID_EXITBTN);

	const int sndPackX = (WINDOW_WIDTH / 2) - (BUTTON_WIDTH / 2);
	const int sndPackY = startY;
	const int sndPackW = sndPackX + BUTTON_WIDTH;
	const int sndPackH = startH;
	sndPackBtn.Create("Sound Packs",
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					CRect(sndPackX, sndPackY, sndPackW, sndPackH),
					this, ID_SNDPACKBTN);

	// create check boxes
	const int wscreenX = PADDING;
	const int wscreenY = PADDING + 32;
	const int wscreenW = wscreenX + 128;
	const int wscreenH = wscreenY + 32;
	wscreenChk.Create("Enable Widescreen",
						WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
						CRect(wscreenX, wscreenY, wscreenW, wscreenH),
						this, ID_WSCREENCHK);
	
	const int hudX = wscreenX + 160;
	const int hudY = wscreenY;
	const int hudW = hudX + 128;
	const int hudH = hudY + 32;
	hudChk.Create("Enable New HUD",
					WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
					CRect(hudX, hudY, hudW, hudH),
					this, ID_HUDCHK);

	// create character list
	const int charListX = PADDING * 4;
	const int charListY = WINDOW_HEIGHT - PADDING - 140;
	const int charListW = WINDOW_WIDTH - (PADDING * 4) - PADDING;
	const int charListH = charListY + 76;
	charList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | LBS_NOINTEGRALHEIGHT,
					CRect(charListX, charListY, charListW, charListH),
					this, ID_CHARLIST);
	charList.SetItemHeight(0, 24);

	charDirList.Create(WS_CHILD,
					CRect(0, 0, 1, 1),
					this, ID_CHARDIRLIST);

	charInfoText.Create("Select the character that will be used in-game:",
					WS_CHILD | WS_VISIBLE | SS_LEFT,
					CRect(charListX, charListY - 16, charListW, charListY),
					this);

	// set fonts on all controls
	HFONT mainFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SetFont(infoText.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(startBtn.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(exitBtn.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(sndPackBtn.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(wscreenChk.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(hudChk.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(charInfoText.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(charList.GetSafeHwnd(), (LPARAM)mainFont);

	CenterWindow();

	// read from the options ini
	int wscreenValue = GetPrivateProfileInt("Option", "Widescreen", 0, INI_PATH);
	int hudValue = GetPrivateProfileInt("Option", "HUD", 0, INI_PATH);
	
	b_Widescreen = (bool)wscreenValue;
	if (b_Widescreen)
		wscreenChk.SetCheck(BST_CHECKED);
	else
		wscreenChk.SetCheck(BST_UNCHECKED);

	b_NewHUD = (bool)hudValue;
	if (b_NewHUD)
		hudChk.SetCheck(BST_CHECKED);
	else
		hudChk.SetCheck(BST_UNCHECKED);

	// find characters
	WIN32_FIND_DATA findData;
	
	char playerFindPath[MAX_PATH];
	strcpy(playerFindPath, "");
	strcat(playerFindPath, PLAYER_PATH);
	strcat(playerFindPath, "*");
	
	HANDLE hFile = FindFirstFile(playerFindPath, &findData);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(hFile, &findData) != 0)
		{
			if (strcmp(findData.cFileName, "..") != 0)
			{
				char charIniPath[MAX_PATH];
				strcpy(charIniPath, "");
				strcat(charIniPath, PLAYER_PATH);
				strcat(charIniPath, findData.cFileName);
				strcat(charIniPath, "\\character.ini");

				TCHAR charName[64];
				GetPrivateProfileString("Character", "Name", "", charName, 64, charIniPath);
				
				charList.AddString(charName);
				charDirList.AddString(findData.cFileName);
			}
		}
		FindClose(hFile);
	}

}

void CLauncherWindow::SetFont(HWND child, LPARAM font)
{
	::SendMessage(child, WM_SETFONT, font, true);
}

void CLauncherWindow::OnStartClick()
{
	// save options
	LPCTSTR wscreenStr = "0";
	if (b_Widescreen)
		wscreenStr = "1";
	WritePrivateProfileString("Option", "Widescreen", wscreenStr, INI_PATH);

	LPCTSTR hudStr = "0";
	if (b_NewHUD)
		hudStr = "1";
	WritePrivateProfileString("Option", "HUD", hudStr, INI_PATH);

	// write character
	CString charStr;
	int charLen;

	int charSel = charList.GetCurSel();
	if (charSel != LB_ERR)
	{
		charLen = charDirList.GetTextLen(charSel);
		charDirList.GetText(charSel, charStr.GetBuffer(charLen));
		charStr.ReleaseBuffer();

		WritePrivateProfileString("Option", "PlayerDir", (LPCTSTR)charStr, INI_PATH);
	}

	// launch the game
	ShellExecute(m_hWnd, "open", "PizzaTower2000.exe", "", "", SW_SHOW);
	PostQuitMessage(0);
}

void CLauncherWindow::OnExitClick()
{
	PostQuitMessage(0);
}

void CLauncherWindow::OnSndPackClick()
{
	CSndPackWindow *sndWnd = new CSndPackWindow();
	sndWnd->ShowWindow(SW_SHOWNORMAL);
	BeginModalState();
}

void CLauncherWindow::OnWScreenCheck()
{
	int chk = wscreenChk.GetCheck();
	if (chk == BST_UNCHECKED)
		b_Widescreen = false;
	else if (chk == BST_CHECKED)
		b_Widescreen = true;
}

void CLauncherWindow::OnHUDCheck()
{
	int chk = hudChk.GetCheck();
	if (chk == BST_UNCHECKED)
		b_NewHUD = false;
	else if (chk == BST_CHECKED)
		b_NewHUD = true;
}

BEGIN_MESSAGE_MAP(CLauncherWindow, CWnd)
	ON_BN_CLICKED(ID_STARTBTN, OnStartClick)
	ON_BN_CLICKED(ID_EXITBTN, OnExitClick)
	ON_BN_CLICKED(ID_SNDPACKBTN, OnSndPackClick)
	ON_BN_CLICKED(ID_WSCREENCHK, OnWScreenCheck)
	ON_BN_CLICKED(ID_HUDCHK, OnHUDCheck)
END_MESSAGE_MAP()