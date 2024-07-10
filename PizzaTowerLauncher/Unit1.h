//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TLauncherForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ExitButton;
	TButton *StartButton;
	TCheckBox *WidescreenCheckbox;
	TLabel *InfoLabel;
	TListBox *CharListBox;
	TLabel *CharLabel;
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall StartButtonClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall WidescreenCheckboxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TLauncherForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLauncherForm *LauncherForm;
//---------------------------------------------------------------------------
#endif
