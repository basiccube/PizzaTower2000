#include <AFXWIN.H>
#include "sndpackwnd.h"

#define INI_PATH ".\\saveData.ini"
#define SOUND_PATH ".\\sfx\\"

#define WINDOW_WIDTH 280
#define WINDOW_HEIGHT 220
#define PADDING 8

#define BUTTON_WIDTH 80
#define BUTTON_HEIGHT 25
#define BUTTON_PADDING PADDING * 2

CSndPackWindow::CSndPackWindow()
{
	// create window
	LPCTSTR wndClass = AfxRegisterWndClass(NULL, 0, GetSysColorBrush(COLOR_3DFACE), 0);
	Create(wndClass,
		"Select Sound Pack...",
		WS_OVERLAPPED | WS_CAPTION,
		CRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT),
		NULL, 0);
	ModifyStyleEx(WS_EX_CLIENTEDGE, 0, 0);
	
	infoText.Create("Select a sound pack to use:",
					WS_CHILD | WS_VISIBLE | SS_LEFT,
					CRect(PADDING, PADDING, WINDOW_WIDTH - PADDING, 150),
					this);
	
	// create buttons
	const int cancelX = WINDOW_WIDTH - PADDING - BUTTON_WIDTH - 6;
	const int cancelY = WINDOW_HEIGHT - BUTTON_PADDING - (BUTTON_HEIGHT * 2);
	const int cancelW = cancelX + BUTTON_WIDTH;
	const int cancelH = cancelY + BUTTON_HEIGHT;
	cancelBtn.Create("Cancel",
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					CRect(cancelX, cancelY, cancelW, cancelH),
					this, ID_CANCELBTN);

	const int okX = cancelX - PADDING - BUTTON_WIDTH;
	const int okY = cancelY;
	const int okW = okX + BUTTON_WIDTH;
	const int okH = cancelH;
	okBtn.Create("OK",
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					CRect(okX, okY, okW, okH),
					this, ID_OKBTN);

	// create sound pack list
	const int sndListX = PADDING;
	const int sndListY = PADDING * 3;
	const int sndListW = WINDOW_WIDTH - (PADDING * 2);
	const int sndListH = okY - PADDING;
	sndPackList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | LBS_NOINTEGRALHEIGHT,
					CRect(sndListX, sndListY, sndListW, sndListH),
					this, ID_SNDPACKLIST);
	sndPackList.SetItemHeight(0, 24);

	// set fonts on all controls
	HFONT mainFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SetFont(infoText.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(cancelBtn.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(okBtn.GetSafeHwnd(), (LPARAM)mainFont);
	SetFont(sndPackList.GetSafeHwnd(), (LPARAM)mainFont);

	CenterWindow();

	// find sound packs
	WIN32_FIND_DATA findData;
	
	char sndFindPath[MAX_PATH];
	strcpy(sndFindPath, "");
	strcat(sndFindPath, SOUND_PATH);
	strcat(sndFindPath, "*");
	
	HANDLE hFile = FindFirstFile(sndFindPath, &findData);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(hFile, &findData) != 0)
		{
			if (strcmp(findData.cFileName, "..") != 0)
				sndPackList.AddString(findData.cFileName);
		}
		FindClose(hFile);
	}

}

void CSndPackWindow::SetFont(HWND child, LPARAM font)
{
	::SendMessage(child, WM_SETFONT, font, true);
}

void CSndPackWindow::OnOKClick()
{
	// write sound pack
	CString sndStr;
	int sndLen;

	int sndSel = sndPackList.GetCurSel();
	if (sndSel != LB_ERR)
	{
		sndLen = sndPackList.GetTextLen(sndSel);
		sndPackList.GetText(sndSel, sndStr.GetBuffer(sndLen));
		sndStr.ReleaseBuffer();

		WritePrivateProfileString("Option", "SoundDir", (LPCTSTR)sndStr, INI_PATH);
	}
	
	AfxGetMainWnd()->EndModalState();
	DestroyWindow();
}

void CSndPackWindow::OnCancelClick()
{
	AfxGetMainWnd()->EndModalState();
	DestroyWindow();
}

BEGIN_MESSAGE_MAP(CSndPackWindow, CWnd)
	ON_BN_CLICKED(ID_OKBTN, OnOKClick)
	ON_BN_CLICKED(ID_CANCELBTN, OnCancelClick)
END_MESSAGE_MAP()