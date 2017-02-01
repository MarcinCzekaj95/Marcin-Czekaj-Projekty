#include "SzyfrCezara.h"

SzyfrCezara::SzyfrCezara(string n)
    :napis(n),CzyMoznaDeszyfrowac(false)
{

}

SzyfrCezara::~SzyfrCezara()
{

}

void SzyfrCezara::Cezar()
{
    int i=0;
    cin>>ile;
    while(i<napis.length())
    {
        if(napis[i]>='A'&&napis[i]<='Z')
        {
            napis[i]+=(ile%25);
            if(napis[i]>'Z')
            {
                napis[i]=(napis[i]-90) + 64;
            }
            else if(napis[i]<'A')
            {
                napis[i]=91-(65-napis[i]);
            }
        }
        else if(napis[i]>='a'&&napis[i]<='z')
        {
            napis[i]-=32;
            napis[i]+=(ile%25);
            if(napis[i]>'Z')
            {
                napis[i]=(napis[i]-90) + 64;
            }
            else if(napis[i]<'A')
            {
                napis[i]=91-(65-napis[i]);
            }
            napis[i]+=32;
        }
        else if(napis[i]>='0'&&napis[i]<='9')
        {
            napis[i]+=(ile%10);
            if(napis[i]>'9')
            {
                napis[i]=(napis[i]-57) + 47;
            }
            else if(napis[i]<'0')
            {
                napis[i]=58-(48-napis[i]);
            }
        }
        i++;
    }
    i=0;
    cout<<endl;
    CzyMoznaDeszyfrowac=true;
}


void SzyfrCezara::DeszyfracjaCezara()
{
    if(CzyMoznaDeszyfrowac==true)
    {
        int i=0;
        ile = -ile;
        while(i<napis.length())
        {
            if(napis[i]>='A'&&napis[i]<='Z')
            {
                napis[i]+=(ile%25);
                if(napis[i]>'Z')
                {
                    napis[i]=(napis[i]-90) + 64;
                }
                else if(napis[i]<'A')
                {
                    napis[i]=91-(65-napis[i]);
                }
            }
            else if(napis[i]>='a'&&napis[i]<='z')
            {
                napis[i]-=32;
                napis[i]+=(ile%25);
                if(napis[i]>'Z')
                {
                    napis[i]=(napis[i]-90) + 64;
                }
                else if(napis[i]<'A')
                {
                    napis[i]=91-(65-napis[i]);
                }
                napis[i]+=32;
            }
            else if(napis[i]>='0'&&napis[i]<='9')
            {
                napis[i]+=(ile%10);
                if(napis[i]>'9')
                {
                    napis[i]=(napis[i]-57) + 47;
                }
                else if(napis[i]<'0')
                {
                    napis[i]=58-(48-napis[i]);
                }
            }
            i++;
        }
        i=0;
        cout<<endl;
        CzyMoznaDeszyfrowac=false;
    }
    else
    {
        cout<<"Nie mozna deszyfrowac"<<endl;
    }
}


void SzyfrCezara::napisz()
{
    napis="";
    cin>>napis;
    system("cls");
}

void SzyfrCezara::SwitchCezara()
{
    //napis="";
    char wybor='0';
    while(wybor!='4')
    {
        if(napis=="")
        {
            cout<<"Brak Napisu"<<endl<<endl<<endl;
        }
        else
        {
            cout<<"Twoj napis to: "<<napis<<endl<<endl<<endl;

        }
        cout<<"MENU"<<endl;
        cout<<"SZYFR CEZARA"<<endl;
        cout<<"1 - stworz napis"<<endl;
        cout<<"2 - Szyfrowanie"<<endl;
        cout<<"3 - Deszyfracja"<<endl;
        cout<<"4 - Wyjscie Z Szyfru"<<endl;
        cin>>wybor;
        system("cls");
        switch(wybor)
        {
            case '1':
                cout<<"Podaj napis: ";
                napisz();
                break;
            case '2':
                cout<<"Stary napis to: "<<napis<<endl;
                cout<<"o ile mam przesunac napis: ";
                Cezar();
                break;
            case '3':
                cout<<"Zaszyfrowany napis to: "<<napis<<endl;
                cout<<"Deszyfracja: ";
                DeszyfracjaCezara();
                break;
            case '4':
                cout<<"Koniec Szyfru"<<endl;
                break;
            default:
                cout<<"bledny numer podaj inny"<<endl;
                break;
        }
        cout<<endl;
    }
}
