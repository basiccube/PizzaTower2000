object LauncherForm: TLauncherForm
  Left = 194
  Top = 569
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Pizza Tower 2000 Launcher'
  ClientHeight = 200
  ClientWidth = 320
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  DesignSize = (
    320
    200)
  PixelsPerInch = 96
  TextHeight = 13
  object InfoLabel: TLabel
    Left = 8
    Top = 8
    Width = 278
    Height = 26
    Caption = 
      'Configure game options and then press the Start! button to launc' +
      'h the game.'
    WordWrap = True
  end
  object CharLabel: TLabel
    Left = 40
    Top = 72
    Width = 218
    Height = 13
    Caption = 'Select the character that will be used in-game:'
  end
  object ExitButton: TButton
    Left = 232
    Top = 168
    Width = 81
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Exit'
    TabOrder = 0
    OnClick = ExitButtonClick
  end
  object StartButton: TButton
    Left = 7
    Top = 167
    Width = 81
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'Start!'
    TabOrder = 1
    OnClick = StartButtonClick
  end
  object WidescreenCheckbox: TCheckBox
    Left = 8
    Top = 40
    Width = 145
    Height = 25
    Caption = 'Enable Widescreen'
    TabOrder = 2
    OnClick = WidescreenCheckboxClick
  end
  object CharListBox: TListBox
    Left = 40
    Top = 88
    Width = 241
    Height = 73
    Style = lbOwnerDrawFixed
    ItemHeight = 16
    TabOrder = 3
  end
end
