//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

char p1,p2,p3,p4,p5,p6,p7,p8,p9;
char kto;
int pktX=0;
int pktO=0;
int remis=0;
int a;

void sprawdz()
{
    if((p1==p2&&p2==p3&&p1!='n')||
    (p4==p5&&p5==p6&&p4!='n')||
    (p7==p8&&p8==p9&&p7!='n')||
    (p1==p5&&p5==p9&&p1!='n')||
    (p2==p5&&p5==p8&&p2!='n')||
    (p1==p4&&p4==p7&&p1!='n')||
    (p3==p5&&p5==p7&&p3!='n')||
    (p3==p6&&p6==p9&&p3!='n'))
    {
    char * w;
        if(kto=='x')
        {
           w="Wygrana O";
           pktO++;
           Form1->punktO->Caption=pktO;

        }
        else
        {
           w="Wygrywa X";
           pktX++;
           Form1->punktX->Caption=pktX;

        }
        Application->MessageBoxA(w,"Koniec Gry!",MB_OK) ;


        Form1->pole1->Enabled=false;
        Form1->pole2->Enabled=false;
        Form1->pole3->Enabled=false;
        Form1->pole4->Enabled=false;
        Form1->pole5->Enabled=false;
        Form1->pole6->Enabled=false;
        Form1->pole7->Enabled=false;
        Form1->pole8->Enabled=false;
        Form1->pole9->Enabled=false;



        }
        else if(p1!='n'&&
        p2!='n'&&
        p3!='n'&&
        p4!='n'&&
        p5!='n'&&
        p6!='n'&&
        p7!='n'&&
        p8!='n'&&
        p9!='n')
        {
        char * w;

           w="Remis";
           remis++;
           Form1->R->Caption=remis;
        Application->MessageBoxA(w,"Koniec Gry!",MB_OK) ;
        Form1->pole1->Enabled=false;
        Form1->pole2->Enabled=false;
        Form1->pole3->Enabled=false;
        Form1->pole4->Enabled=false;
        Form1->pole5->Enabled=false;
        Form1->pole6->Enabled=false;
        Form1->pole7->Enabled=false;
        Form1->pole8->Enabled=false;
        Form1->pole9->Enabled=false;



        }



}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        pole1->Picture->LoadFromFile("img1/nic.bmp");
        pole2->Picture->LoadFromFile("img1/nic.bmp");
        pole3->Picture->LoadFromFile("img1/nic.bmp");
        pole4->Picture->LoadFromFile("img1/nic.bmp");
        pole5->Picture->LoadFromFile("img1/nic.bmp");
        pole6->Picture->LoadFromFile("img1/nic.bmp");
        pole7->Picture->LoadFromFile("img1/nic.bmp");
        pole8->Picture->LoadFromFile("img1/nic.bmp");
        pole9->Picture->LoadFromFile("img1/nic.bmp");



        srand(time(NULL));

        a=rand()%2;

        if(a==1)
        {
        Tura->Picture->LoadFromFile("img1/osmall.bmp");
        p1='n';
        p2='n';
        p3='n';
        p4='n';
        p5='n';
        p6='n';
        p7='n';
        p8='n';
        p9='n';
        kto='o';
        pole1->Enabled=true;
        pole2->Enabled=true;
        pole3->Enabled=true;
        pole4->Enabled=true;
        pole5->Enabled=true;
        pole6->Enabled=true;
        pole7->Enabled=true;
        pole8->Enabled=true;
        pole9->Enabled=true;
        }
        if(a==0)
        {
        Tura->Picture->LoadFromFile("img1/xsmall.bmp");
        p1='n';
        p2='n';
        p3='n';
        p4='n';
        p5='n';
        p6='n';
        p7='n';
        p8='n';
        p9='n';
        kto='x';

        pole1->Enabled=true;
        pole2->Enabled=true;
        pole3->Enabled=true;
        pole4->Enabled=true;
        pole5->Enabled=true;
        pole6->Enabled=true;
        pole7->Enabled=true;
        pole8->Enabled=true;
        pole9->Enabled=true;


        }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartClick(TObject *Sender)
{
        pole1->Picture->LoadFromFile("img1/nic.bmp");
        pole2->Picture->LoadFromFile("img1/nic.bmp");
        pole3->Picture->LoadFromFile("img1/nic.bmp");
        pole4->Picture->LoadFromFile("img1/nic.bmp");
        pole5->Picture->LoadFromFile("img1/nic.bmp");
        pole6->Picture->LoadFromFile("img1/nic.bmp");
        pole7->Picture->LoadFromFile("img1/nic.bmp");
        pole8->Picture->LoadFromFile("img1/nic.bmp");
        pole9->Picture->LoadFromFile("img1/nic.bmp");
srand(time(NULL));
a=rand()%10+1;
        if(a<=5)
        {
        p1='n';   p2='n';       p3='n';         p4='n';         p5='n';
        p6='n';         p7='n';         p8='n';         p9='n';

        Tura->Picture->LoadFromFile("img1/osmall.bmp");

        kto='o';
        pole1->Enabled=true;
        pole2->Enabled=true;
        pole3->Enabled=true;
        pole4->Enabled=true;
        pole5->Enabled=true;
        pole6->Enabled=true;
        pole7->Enabled=true;
        pole8->Enabled=true;
        pole9->Enabled=true;
        }
                if(a>5)
        {
        p1='n';   p2='n';       p3='n';         p4='n';         p5='n';
        p6='n';         p7='n';         p8='n';         p9='n';

        Tura->Picture->LoadFromFile("img1/xsmall.bmp");

        kto='x';
        pole1->Enabled=true;
        pole2->Enabled=true;
        pole3->Enabled=true;
        pole4->Enabled=true;
        pole5->Enabled=true;
        pole6->Enabled=true;
        pole7->Enabled=true;
        pole8->Enabled=true;
        pole9->Enabled=true;
        }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::pole1Click(TObject *Sender)
{

if(p1=='n')
{
        if(kto=='x')
        {
         pole1->Picture->LoadFromFile("img1/x.bmp");
         p1='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole1->Picture->LoadFromFile("img1/o.bmp");
         p1='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole1->Enabled=false;
        sprawdz();
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::pole2Click(TObject *Sender)
{
if(p2=='n')
{
        if(kto=='x')
        {
         pole2->Picture->LoadFromFile("img1/x.bmp");
         p2='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole2->Picture->LoadFromFile("img1/o.bmp");
         p2='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole2->Enabled=false;
        sprawdz();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole3Click(TObject *Sender)
{
if(p3=='n')
{
        if(kto=='x')
        {
         pole3->Picture->LoadFromFile("img1/x.bmp");
         p3='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole3->Picture->LoadFromFile("img1/o.bmp");
         p3='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole3->Enabled=false;
        sprawdz();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole4Click(TObject *Sender)
{
if(p4=='n')
{
        if(kto=='x')
        {
         pole4->Picture->LoadFromFile("img1/x.bmp");
         p4='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole4->Picture->LoadFromFile("img1/o.bmp");
         p4='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole4->Enabled=false;
        sprawdz();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole5Click(TObject *Sender)
{
if(p5=='n')
{
        if(kto=='x')
        {
         pole5->Picture->LoadFromFile("img1/x.bmp");
         p5='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole5->Picture->LoadFromFile("img1/o.bmp");
         p5='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole5->Enabled=false;
        sprawdz();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole6Click(TObject *Sender)
{
if(p6=='n')
{
        if(kto=='x')
        {
         pole6->Picture->LoadFromFile("img1/x.bmp");
         p6='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole6->Picture->LoadFromFile("img1/o.bmp");
         p6='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole6->Enabled=false;
        sprawdz();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole7Click(TObject *Sender)
{
if(p7=='n')
{
        if(kto=='x')
        {
         pole7->Picture->LoadFromFile("img1/x.bmp");
         p7='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole7->Picture->LoadFromFile("img1/o.bmp");
         p7='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole7->Enabled=false;
        sprawdz();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole8Click(TObject *Sender)
{
if(p8=='n')
{
        if(kto=='x')
        {
         pole8->Picture->LoadFromFile("img1/x.bmp");
         p8='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole8->Picture->LoadFromFile("img1/o.bmp");
         p8='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole8->Enabled=false;
        sprawdz();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole9Click(TObject *Sender)
{
if(p9=='n')
{
        if(kto=='x')
        {
         pole9->Picture->LoadFromFile("img1/x.bmp");
         p9='x';
         kto='o';
         Tura->Picture->LoadFromFile("img1/osmall.bmp");

        }
        else
        {
        pole9->Picture->LoadFromFile("img1/o.bmp");
         p9='o';
         kto='x';
         Tura->Picture->LoadFromFile("img1/xsmall.bmp") ;


        }

        pole9->Enabled=false;
        sprawdz();
        }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::StarcikClick(TObject *Sender)
{
        pole1->Visible=true;
        pole2->Visible=true;
        pole3->Visible=true;
        pole4->Visible=true;
        pole5->Visible=true;
        pole6->Visible=true;
        pole7->Visible=true;
        pole8->Visible=true;
        pole9->Visible=true;
        Tura->Visible=true;
        Label1->Visible=true;
        punktO->Visible=true;
        punktX->Visible=true;
        R->Visible=true;
        Remis->Visible=true;
        WygranaO->Visible=true;
        WygranaX->Visible=true;
        Start->Visible=true;
        Starcik->Visible=false;
        Poz1->Visible=true;
        Poz2->Visible=true;
        Pion1->Visible=true;
        Pion2->Visible=true;
        Poz1->Picture->LoadFromFile("img1/kreskaS.bmp");
        Poz2->Picture->LoadFromFile("img1/kreskaS.bmp");
        Pion1->Picture->LoadFromFile("img1/kreskaP.bmp");
        Pion2->Picture->LoadFromFile("img1/kreskaP.bmp");


}
//---------------------------------------------------------------------------

