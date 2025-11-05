#include <AFXWIN.H>
#include "main.h"

#include "launchwnd.h"

CLauncher launcher;

CLauncher::CLauncher()
{
}

BOOL CLauncher::InitInstance()
{
	m_pMainWnd = new CLauncherWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}