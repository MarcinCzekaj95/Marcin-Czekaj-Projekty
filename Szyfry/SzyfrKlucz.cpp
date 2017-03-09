#include "SzyfrKlucz.h"

SzyfVinegre::SzyfVinegre(string n,string k)
    :Jawny(n),Klucz(k),CzyMoznaSzyfrowac(true),CzyMoznaDeszyfrowac(false)
{

}

SzyfVinegre::~SzyfVinegre()
{

}

void SzyfVinegre::PodajNapis()
{
    Jawny = "";
    getline(cin,Jawny,'+');
    CzyMoznaSzyfrowac = true;
}

void SzyfVinegre::PodajKlucz()
{
    cin>>Klucz;
}

void SzyfVinegre::Szyfruj()
{
    int i=0,j=0;
    while(i<Jawny.length())
    {
        if(CzyMoznaSzyfrowac==true)
        {
            if(j<Klucz.length())
            {
                if(Jawny[i]>='A' && Jawny[i]<='Z')
                {
                    if(Klucz[j]>='A'&&Klucz[j]<='Z')
                    {
                        Jawny[i]+=((Klucz[j]-65)%26);
                        if(Jawny[i]>'Z')
                        {
                            Jawny[i]=(Jawny[i]-90) + 64;
                        }
                    }
                    else if(Klucz[j]>='a'&&Klucz[j]<='z')
                    {
                        Klucz[j]-=32;
                        Jawny[i]+=((Klucz[j]-65)%26);
                        if(Jawny[i]>'Z')
                        {
                            Jawny[i]=(Jawny[i]-90) + 64;
                        }
                        Klucz[j]+=32;
                    }
                    j++;
                }
                else if(Jawny[i]>='a' && Jawny[i]<='z')
                {
                    Jawny[i]-=32;
                    if(Klucz[j]>='A'&&Klucz[j]<='Z')
                    {
                        Jawny[i]+=((Klucz[j]-65)%26);
                        if(Jawny[i]>'Z')
                        {
                            Jawny[i]=(Jawny[i]-90) + 64;
                        }
                    }
                    else if(Klucz[j]>='a'&&Klucz[j]<='z')
                    {
                        Klucz[j]-=32;
                        Jawny[i]+=((Klucz[j]-65)%26);
                        if(Jawny[i]>'Z')
                        {
                            Jawny[i]=(Jawny[i]-90) + 64;
                        }
                        Klucz[j]+=32;
                    }
                    Jawny[i]+=32;
                    j++;
                }
                else if(Jawny[i]>='0'&&Jawny[i]<='9')
                {
                    Jawny[i]+=((Klucz[i]-48)%10);
                    if(Jawny[i]>'9')
                    {
                        Jawny[i]=(Jawny[i]-57) + 47;
                    }
                    j++;
                }
                i++;
            }
            else
            {
                j=0;
            }
        }
        else
        {
            cout<<"Nie mozna szyfrowac zaszyfrowanej informacji"<<endl;
            break;
        }
    }
            cout<<endl;
    plik.open("Viniger/ZaszyfrowanyViniger.txt",ios::out);
    if(plik.is_open())
    {
        plik<<Jawny;
        plik.close();
    }
    CzyMoznaSzyfrowac = false;
    CzyMoznaDeszyfrowac = true;
}

void SzyfVinegre::Deszyfruj()
{
    int i=0,j=0,ile;
    while(i<Jawny.length())
    {
        if(CzyMoznaDeszyfrowac == true)
        {
            if(j<Klucz.length())
            {
                if(Jawny[i]>='A' && Jawny[i]<='Z')
                {
                    if(Klucz[j]>='A'&&Klucz[j]<='Z')
                    {
                        Jawny[i]-=((Klucz[j]-65)%26);
                        if(Jawny[i]<'A')
                        {
                            Jawny[i]=90-(64-Jawny[i]);
                        }
                    }
                    else if(Klucz[j]>='a'&&Klucz[j]<='z')
                    {
                        Klucz[j]-=32;
                        Jawny[i]-=((Klucz[j]-65)%26);
                        if(Jawny[i]<'A')
                        {
                            Jawny[i]=90-(64-Jawny[i]);
                        }
                        Klucz[j]+=32;
                    }
                    j++;
                }
                else if(Jawny[i]>='a' && Jawny[i]<='z')
                {
                    Jawny[i]-=32;
                    if(Klucz[j]>='A'&&Klucz[j]<='Z')
                    {
                        Jawny[i]-=((Klucz[j]-65)%26);
                        if(Jawny[i]<'A')
                        {
                            Jawny[i]=90-(64-Jawny[i]);
                        }
                    }
                    else if(Klucz[j]>='a'&&Klucz[j]<='z')
                    {
                        Klucz[j]-=32;
                        Jawny[i]-=((Klucz[j]-65)%26);
                        if(Jawny[i]<'A')
                        {
                            Jawny[i]=90-(64-Jawny[i]);
                        }

                        Klucz[j]+=32;
                    }
                    Jawny[i]+=32;
                    j++;
                }
                else if(Jawny[i]>='0'&&Jawny[i]<='9')
                {
                    Jawny[i]-=((Klucz[i]-48)%10);
                    if(Jawny[i]<'0')
                    {
                        Jawny[i]=58-(48-Jawny[i]);
                    }
                    j++;
                }
                i++;
            }
            else
            {
                j=0;
            }
        }
        else
        {
            cout<<"Wiadomosc zostala odszyfrowana"<<endl;
            break;
        }
    }
    plik.open("Viniger/Deszyfracja.txt",ios::out);
    if(plik.is_open())
    {
        plik<<Jawny;
        plik.close();
    }
    CzyMoznaDeszyfrowac = false;
    CzyMoznaSzyfrowac = true;

}

void SzyfVinegre::SwitchVinegre()
{
    char wybor='0';
    while(wybor!='5')
    {
        if(Jawny=="")
        {
            cout<<"Brak Napisu"<<endl<<endl<<endl;
        }
        else
        {
            cout<<"Twoj napis to: "<<Jawny<<endl;
            cout<<"Twoj klucz to: "<<Klucz<<endl<<endl<<endl<<endl;

        }
        cout<<"MENU"<<endl;
        cout<<"SZYFR VINEGRE'A"<<endl;
        cout<<"1 - stworz napis"<<endl;
        cout<<"2 - podaj klucz"<<endl;
        cout<<"3 - Szyfrowanie"<<endl;
        cout<<"4 - Deszyfracja"<<endl;
        cout<<"5 - Koniec Szyfru"<<endl;
        cin>>wybor;
        system("cls");
        switch(wybor)
        {
            case '1':
                cout<<"(Wpisz '+' a natsepnie nacisnij enter aby zakonczyc pisanie) Podaj napis: ";
                PodajNapis();
                break;
            case '2':
                cout<<"Stary napis to: "<<Jawny<<endl;
                cout<<"Podaj klucz: ";
                PodajKlucz();
                break;
            case '3':
                cout<<"napis to: "<<Jawny<<endl;
                cout<<"Szyfrowanie: ";
                Szyfruj();
                break;
            case '4':
                Deszyfruj();
                break;
            case '5':
                cout<<"Koniec Szyfru"<<endl;
                break;
            default:
                cout<<"bledny numer podaj inny"<<endl;
                break;
        }
        cout<<endl;
    }
}

