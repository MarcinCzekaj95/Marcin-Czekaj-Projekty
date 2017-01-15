//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Start;
        TImage *pole1;
        TImage *pole2;
        TImage *pole3;
        TImage *pole4;
        TImage *pole5;
        TImage *pole6;
        TImage *pole7;
        TImage *pole8;
        TImage *pole9;
        TImage *Tura;
        TLabel *Label1;
        TLabel *WygranaX;
        TLabel *WygranaO;
        TLabel *Remis;
        TLabel *punktX;
        TLabel *punktO;
        TLabel *R;
        TButton *Starcik;
        TImage *Pion1;
        TImage *Pion2;
        TImage *Poz1;
        TImage *Poz2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall StartClick(TObject *Sender);
        void __fastcall pole1Click(TObject *Sender);
        void __fastcall pole2Click(TObject *Sender);
        void __fastcall pole3Click(TObject *Sender);
        void __fastcall pole4Click(TObject *Sender);
        void __fastcall pole5Click(TObject *Sender);
        void __fastcall pole6Click(TObject *Sender);
        void __fastcall pole7Click(TObject *Sender);
        void __fastcall pole8Click(TObject *Sender);
        void __fastcall pole9Click(TObject *Sender);
        void __fastcall StarcikClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
