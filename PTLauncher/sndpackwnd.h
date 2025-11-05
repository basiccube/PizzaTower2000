class CSndPackWindow : public CFrameWnd
{
public:
	CSndPackWindow();

	static void CALLBACK SetFont(HWND child, LPARAM font);

	afx_msg void OnOKClick();
	afx_msg void OnCancelClick();

private:
	CStatic infoText;

	CButton okBtn;
	CButton cancelBtn;

	CListBox sndPackList;

	enum
	{
		ID_OKBTN = 100,
		ID_CANCELBTN,
		ID_SNDPACKLIST
	};

	DECLARE_MESSAGE_MAP()
};