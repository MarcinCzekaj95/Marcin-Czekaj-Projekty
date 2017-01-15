object Form1: TForm1
  Left = 305
  Top = 165
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pole1: TImage
    Left = 120
    Top = 48
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole1Click
  end
  object pole2: TImage
    Left = 224
    Top = 48
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole2Click
  end
  object pole3: TImage
    Left = 328
    Top = 48
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole3Click
  end
  object pole4: TImage
    Left = 120
    Top = 152
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole4Click
  end
  object pole5: TImage
    Left = 224
    Top = 152
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole5Click
  end
  object pole6: TImage
    Left = 328
    Top = 152
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole6Click
  end
  object pole7: TImage
    Left = 120
    Top = 256
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole7Click
  end
  object pole8: TImage
    Left = 224
    Top = 256
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole8Click
  end
  object pole9: TImage
    Left = 328
    Top = 256
    Width = 100
    Height = 100
    Cursor = crHandPoint
    Visible = False
    OnClick = pole9Click
  end
  object Tura: TImage
    Left = 688
    Top = 40
    Width = 30
    Height = 30
    Visible = False
  end
  object Label1: TLabel
    Left = 528
    Top = 40
    Width = 146
    Height = 29
    Caption = 'Tura gracza:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object WygranaX: TLabel
    Left = 528
    Top = 112
    Width = 134
    Height = 29
    Caption = 'Wygrana X:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object WygranaO: TLabel
    Left = 528
    Top = 152
    Width = 136
    Height = 29
    Caption = 'Wygrana O:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Remis: TLabel
    Left = 552
    Top = 200
    Width = 82
    Height = 29
    Caption = 'Remis:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object punktX: TLabel
    Left = 688
    Top = 112
    Width = 11
    Height = 20
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object punktO: TLabel
    Left = 688
    Top = 152
    Width = 11
    Height = 20
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object R: TLabel
    Left = 688
    Top = 208
    Width = 11
    Height = 20
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Pion1: TImage
    Left = 218
    Top = 48
    Width = 8
    Height = 308
    Visible = False
  end
  object Pion2: TImage
    Left = 322
    Top = 48
    Width = 8
    Height = 308
    Visible = False
  end
  object Poz1: TImage
    Left = 120
    Top = 146
    Width = 308
    Height = 6
    Visible = False
  end
  object Poz2: TImage
    Left = 120
    Top = 250
    Width = 308
    Height = 6
    Visible = False
  end
  object Start: TButton
    Left = 664
    Top = 280
    Width = 163
    Height = 57
    Caption = 'Od nowa'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    Visible = False
    OnClick = StartClick
  end
  object Starcik: TButton
    Left = 320
    Top = 136
    Width = 217
    Height = 89
    Caption = 'Start'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = StarcikClick
  end
end
