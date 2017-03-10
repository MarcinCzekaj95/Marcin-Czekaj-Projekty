#include "SzyfrCezara.h"
#include "SzyfrKlucz.h"

class SzyfrPlayFair
{
    string napis,napisPoprawny,tekst;
    bool czyMoznaSzyfrowac,czyMoznaDeszyfrowac;
    char tablica[5][5];
    int licznik,licznik2,liczbaElementow;
    char litera;
public:
    SzyfrPlayFair(string);

    ~SzyfrPlayFair();

    void Szyfruj();

    void Deszyfruj();

    void SwitchPlayFaira();

    void PodajNapis();

};

SzyfrPlayFair::SzyfrPlayFair(string n)
    :czyMoznaSzyfrowac(true),czyMoznaDeszyfrowac(false)
{
    napis = n;
    licznik = 0;
    licznik2 = 0;
    litera = 'a';
    liczbaElementow = 0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            tablica[i][j]='0';
        }
    }
}

SzyfrPlayFair::~SzyfrPlayFair()
{

}

void SzyfrPlayFair::Szyfruj()
{
    int licz=0,k1=0,m1=0,k2=0,m2=0;
    char pomoc[2];
    if(czyMoznaSzyfrowac==true)
    {
    while(licz < tekst.length())
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(tekst.length()%2!=0)
                {
                    tekst+="q";
                }
                if(tekst[licz]==tekst[licz+1])
                {
                    tekst[licz+1]='x';
                }
                if(tablica[i][j]==tekst[licz])
                {
                    k1=i;
                    m1=j;
                    cout<<licz<<": ("<<k1<<","<<m1<<")"<<" "<<tekst[licz]<<endl;
                }
                if(tablica[i][j]==tekst[licz+1])
                {
                    k2=i;
                    m2=j;
                    cout<<licz<<": ("<<k2<<","<<m2<<")"<<" "<<tekst[licz+1]<<endl;
                }
            }
        }
        if(m1==m2)
        {
            if(k1==0)
            {
                tekst[licz] = tablica[k1+1][m1];
            }
            else if(k1==4)
            {
                tekst[licz] = tablica[k1-1][m1];
            }
            else
            {
                tekst[licz] = tablica[k1+1][m1];
            }
            if(k2==0)
            {
                tekst[licz+1] = tablica[k2+1][m1];
            }
            else if(k1==4)
            {
                tekst[licz+1] = tablica[k2-1][m1];
            }
            else
            {
                tekst[licz+1] = tablica[k2+1][m1];
            }

        }
        else if(k1==k2)
        {
            if(m1==0)
            {
                tekst[licz] = tablica[k1][m1+1];
            }
            else if(k1==4)
            {
                tekst[licz] = tablica[k1][m1-1];
            }
            else
            {
                tekst[licz] = tablica[k1][m1+1];
            }
            if(k2==0)
            {
                tekst[licz+1] = tablica[k2][m2+1];
            }
            else if(k1==4)
            {
                tekst[licz+1] = tablica[k2][m2-1];
            }
            else
            {
                tekst[licz+1] = tablica[k2][m2+1];
            }
        }
        else
        {
            tekst[licz] = tablica[k1][m2];
            tekst[licz+1] = tablica[k2][m1];
        }
        licz+=2;
    }
    czyMoznaSzyfrowac=false;
    czyMoznaDeszyfrowac=true;
    }
    else
    {
        cout<<"Nie mozna szyfrowac zaszyfrowanego"<<endl;
    }
    cout<<tekst<<endl;
}

void SzyfrPlayFair::Deszyfruj()
{
        int licz=0,k1=0,m1=0,k2=0,m2=0;
    char pomoc[2];
    if(czyMoznaDeszyfrowac==true)
    {
    while(licz < tekst.length())
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(tekst.length()%2!=0)
                {
                    tekst+="q";
                }
                if(tekst[licz]==tekst[licz+1])
                {
                    tekst[licz+1]='x';
                }
                if(tablica[i][j]==tekst[licz])
                {
                    k1=i;
                    m1=j;
                    cout<<licz<<": ("<<k1<<","<<m1<<")"<<" "<<tekst[licz]<<endl;
                }
                if(tablica[i][j]==tekst[licz+1])
                {
                    k2=i;
                    m2=j;
                    cout<<licz<<": ("<<k2<<","<<m2<<")"<<" "<<tekst[licz+1]<<endl;
                }
            }
        }
        if(m1==m2)
        {
            if(k1==0)
            {
                tekst[licz] = tablica[k1+1][m1];
            }
            else if(k1==4)
            {
                tekst[licz] = tablica[k1-1][m1];
            }
            else
            {
                tekst[licz] = tablica[k1-1][m1];
            }
            if(k2==0)
            {
                tekst[licz+1] = tablica[k2+1][m1];
            }
            else if(k1==4)
            {
                tekst[licz+1] = tablica[k2-1][m1];
            }
            else
            {
                tekst[licz+1] = tablica[k2-1][m1];
            }

        }
        else if(k1==k2)
        {
            if(m1==0)
            {
                tekst[licz] = tablica[k1][m1+1];
            }
            else if(k1==4)
            {
                tekst[licz] = tablica[k1][m1-1];
            }
            else
            {
                tekst[licz] = tablica[k1][m1-1];
            }
            if(k2==0)
            {
                tekst[licz+1] = tablica[k2][m2+1];
            }
            else if(k1==4)
            {
                tekst[licz+1] = tablica[k2][m2-1];
            }
            else
            {
                tekst[licz+1] = tablica[k2][m2-1];
            }
        }
        else
        {
            tekst[licz] = tablica[k1][m2];
            tekst[licz+1] = tablica[k2][m1];
        }
        licz+=2;
    }
    czyMoznaDeszyfrowac=false;
    czyMoznaSzyfrowac = true;
    }
    else
    {
        cout<<"Nie mozna deszyfrowac odszyfrowanego"<<endl;
    }
    cout<<tekst<<endl;
}

void SzyfrPlayFair::PodajNapis()
{
    czyMoznaDeszyfrowac = false;
    czyMoznaSzyfrowac = true;
    licznik = 0;
    licznik2 = 0;
    litera = 'a';
    liczbaElementow=0;
    cin>>napis;
    cout<<"Podaj tekst to zaszyfrowania: ";
    cin>>tekst;
    napisPoprawny = napis;
    while(licznik < napis.length())
    {
        licznik2 = licznik+1;
        while(licznik2<napis.length())
        {
            if(napis[licznik]==napisPoprawny[licznik2])
            {
                napisPoprawny[licznik2]='0';
                liczbaElementow++;
            }
            licznik2++;
        }
        licznik++;
    }
    licznik = 0;
    licznik2 = 0;
    while(licznik<napisPoprawny.length())
    {
        if(napisPoprawny[licznik]!= '0')
        {
            napis[licznik2] = napisPoprawny[licznik];
            licznik2++;
        }
        licznik++;
    }
    for(int k=0;k<(napisPoprawny.length()-liczbaElementow);k++)
    {
        cout<<napis[k];
    }
    cout<<endl;

    licznik = 0;
    licznik2 = 0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(licznik<napisPoprawny.length()-liczbaElementow)
            {
                tablica[i][j] = napis[licznik];
                licznik++;
            }
            else
            {
                licznik2 = 0;
                while(licznik2<napis.length())
                {
                        if(napis[licznik2]>=65&&napis[licznik2]<=90)
                        {
                            napis[licznik2]+=32;
                            if(litera == napis[licznik2])
                            {
                                litera++;
                                licznik2=0;
                                continue;
                            }
                            napis[licznik2]-=32;
                        }
                        else if(napis[licznik2]>=97&&napis[licznik2]<=122)
                        {
                            if(litera == napis[licznik2])
                            {
                                litera++;
                                licznik2=0;
                                continue;
                            }
                        }
                    licznik2++;
                }
                if((litera>=65 && litera<=90) || (litera>=97&&litera<=122))
                {
                    if(litera == 'J'|| litera == 'j')
                    {
                        litera++;
                    }
                    tablica[i][j] = litera;
                    litera++;
                }
            }
        }
    }
}

void SzyfrPlayFair::SwitchPlayFaira()
{
        char wybor='0';
    while(wybor!='4')
    {
        if(napis=="")
        {
            cout<<"Brak Napisu"<<endl<<endl<<endl;
        }
        else
        {
            cout<<"Twoj napis to: "<<tekst<<endl;
        }
        cout<<"MENU"<<endl;
        cout<<"SZYFR PlayFaira"<<endl;
        cout<<"1 - stworz napis"<<endl;
        cout<<"2 - Szyfrowanie"<<endl;
        cout<<"3 - Deszyfrowanie"<<endl;
        cout<<"4 - Koniec"<<endl;
        cin>>wybor;
        system("cls");
        switch(wybor)
        {
            case '1':
                cout<<"Podaj klucz: ";
                PodajNapis();
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        cout<<tablica[i][j]<<" | ";
                    }
                    cout<<endl;
                }
                break;
            case '2':
                cout<<"Stary napis to: "<<tekst<<endl;
                cout<<"Tablica to: "<<endl;
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        cout<<tablica[i][j]<<" | ";
                    }
                    cout<<endl;
                }
                cout<<"Szyfrowanie:"<<endl;
                Szyfruj();
                break;
            case '3':
                cout<<"napis to: "<<tekst<<endl;
                cout<<"Tablica to: "<<endl;
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        cout<<tablica[i][j]<<" | ";
                    }
                    cout<<endl;
                }
                cout<<"Deszyfracja:"<<endl;
                Deszyfruj();
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

int main()
{
    SzyfrCezara * a = new SzyfrCezara("");
    SzyfVinegre * b = new SzyfVinegre("napis bo tak jest ok i tyle","napid");
    SzyfrPlayFair * c = new SzyfrPlayFair("jakis napis");
    char wybor='0';
    while(wybor!='4')
    {
        cout<<"MENU"<<endl;
        cout<<"1 - Szyfr Cezara"<<endl;
        cout<<"2 - Szyfr Vigenere'a"<<endl;
        cout<<"3 - Szyfr PlayFair"<<endl;
        cout<<"4 - exit"<<endl;
        cin>>wybor;
        system("cls");
        switch(wybor)
        {
        case '1':
            a->SwitchCezara();
            system("cls");
            break;
        case '2':
            b->SwitchVinegre();
            system("cls");
            break;
        case '3':
            c->SwitchPlayFaira();
            break;
        case '4':
            cout<<"Koncze..."<<endl;
            break;
        default:
            cout<<"Zly numer"<<endl;
            break;
        }
    }

    delete a;
    delete b;
    delete c;

    return 0;
}
