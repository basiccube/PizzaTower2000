//---------------------------------------------------------------------------

#ifndef SoundPackH
#define SoundPackH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TSoundPackForm : public TForm
{
__published:	// IDE-managed Components
	TButton *OKButton;
	TButton *CancelButton;
	TListBox *SFXListBox;
	TLabel *SoundPackLabel;
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall OKButtonClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSoundPackForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSoundPackForm *SoundPackForm;
//---------------------------------------------------------------------------
#endif
