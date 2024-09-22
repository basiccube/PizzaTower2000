//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SoundPack.h"
#include "IniFiles.hpp"
#include "Math.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSoundPackForm *SoundPackForm;
TIniFile *SaveIni;
//---------------------------------------------------------------------------
__fastcall TSoundPackForm::TSoundPackForm(TComponent* Owner) : TForm(Owner)
{
	SaveIni = new TIniFile(GetCurrentDir() + "\\saveData.ini");

        TSearchRec sr;
        if (FindFirst(GetCurrentDir() + "\\sfx\\*", faDirectory, sr) != 0)
        	return;

	do
        {
        	if (sr.Name != "." && sr.Name != "..")
                {
                        SFXListBox->Items->Add(sr.Name);
                }
        }
        while (FindNext(sr) == 0);

	FindClose(sr);
}
//---------------------------------------------------------------------------
void __fastcall TSoundPackForm::CancelButtonClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TSoundPackForm::OKButtonClick(TObject *Sender)
{
	if (SFXListBox->ItemIndex != -1)
        {
        	SaveIni->WriteString("Option", "SoundDir", SFXListBox->Items->Strings[SFXListBox->ItemIndex]);
        }
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TSoundPackForm::FormDestroy(TObject *Sender)
{
	delete SaveIni;	
}
//---------------------------------------------------------------------------
