object SoundPackForm: TSoundPackForm
  Left = 423
  Top = 176
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Select Sound Pack...'
  ClientHeight = 185
  ClientWidth = 265
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnDestroy = FormDestroy
  DesignSize = (
    265
    185)
  PixelsPerInch = 96
  TextHeight = 13
  object SoundPackLabel: TLabel
    Left = 8
    Top = 8
    Width = 133
    Height = 13
    Caption = 'Select a sound pack to use:'
  end
  object OKButton: TButton
    Left = 88
    Top = 152
    Width = 81
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'OK'
    TabOrder = 0
    OnClick = OKButtonClick
  end
  object CancelButton: TButton
    Left = 176
    Top = 152
    Width = 81
    Height = 25
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = CancelButtonClick
  end
  object SFXListBox: TListBox
    Left = 8
    Top = 24
    Width = 249
    Height = 121
    Style = lbOwnerDrawFixed
    ItemHeight = 16
    TabOrder = 2
  end
end
