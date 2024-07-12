//---------------------------------------------------------------------------

#include <vcl.h>
#include <process.h>
#include <iostream.h>
#pragma hdrstop

#include "Unit1.h"
#include "IniFiles.hpp"
#include "Math.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLauncherForm *LauncherForm;
TIniFile *SaveIni;

bool b_Debug = false;
bool b_Widescreen = false;
string s_GameExe;

//---------------------------------------------------------------------------
__fastcall TLauncherForm::TLauncherForm(TComponent* Owner) : TForm(Owner)
{
        SaveIni = new TIniFile(GetCurrentDir() + "\\saveData.ini");
        double widescreeni = Ceil(SaveIni->ReadFloat("Option", "Widescreen", 0.0f));

        b_Widescreen = (bool)widescreeni;
        WidescreenCheckbox->Checked = b_Widescreen;

        AnsiString exefile = GetCurrentDir() + "\\PizzaTower2000.exe";
        if (FileExists(exefile))
        {
        	s_GameExe = exefile.c_str();
        }
        else
        {
        	ShowMessage("Cannot find the executable for Pizza Tower 2000.");
                if (!b_Debug)
                {
                	Application->Terminate();
                }
        }

        TSearchRec sr;
        if (FindFirst(GetCurrentDir() + "\\gfx\\player\\*", faDirectory, sr) != 0)
        	return;

	do
        {
        	if (sr.Name != "." && sr.Name != "..")
                {
                	CharListBox->Items->Add(sr.Name);
                }
        }
        while (FindNext(sr) == 0);

	FindClose(sr);
}
//---------------------------------------------------------------------------
void __fastcall TLauncherForm::ExitButtonClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TLauncherForm::StartButtonClick(TObject *Sender)
{
	SaveIni->WriteInteger("Option", "Widescreen", (int)b_Widescreen);
        if (CharListBox->ItemIndex != -1)
        {
        	SaveIni->WriteString("Option", "PlayerDir", CharListBox->Items->Strings[CharListBox->ItemIndex]);
        }
        
	spawnlp(P_NOWAITO, s_GameExe.c_str(), s_GameExe.c_str(), NULL);
        Application->Terminate();	
}
//---------------------------------------------------------------------------
void __fastcall TLauncherForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete SaveIni;	
}
//---------------------------------------------------------------------------
void __fastcall TLauncherForm::WidescreenCheckboxClick(TObject *Sender)
{
	b_Widescreen = WidescreenCheckbox->Checked;
}
//---------------------------------------------------------------------------
