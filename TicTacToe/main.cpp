#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

char PLANSZA[3][3];

int licznik;


enum Stan
{
    kolko = 'O',
    krzyzk = 'X'
};

void wyswietl();

void Wybierz(Stan * stan);

void Wybor(char * z);

int sprawdzenie();

void GlownaPetla();

void INFO();


Stan Gracz(int * p);

int main()
{
    char opcja;
    while(true)
    {
        system("CLS");
        cout<<"TIC-TAC-TOE"<<endl<<endl;
        cout<<"1 - Nowa Gra"<<endl;
        cout<<"2 - INFO"<<endl;
        cout<<"3 - QUIT"<<endl;
        opcja=getch();
        switch(opcja)
        {
        case '1':
            GlownaPetla();
            break;
        case '2':
            INFO();
            break;
        case '3':
            exit(0);
            break;
        default:
            cout<<"Nie Ma do wyboru takiej opcji"<<endl;
            break;
        }
    }
    return 0;
}

void INFO()
{
    char wybor;
    while(wybor!='m')
    {
        system("cls");
        cout<<"Jest to gra stworzona w konsoli zapraszam do ogrania"<<endl<<endl;
        cout<<"Wybieramy od 1 - 9 i tworzymy w tym miejscu kolko albo krzyzyk"<<endl<<endl;
        cout<<"Wybierz literke 'm' na klawiaturze aby wyjsc do menu"<<endl;
        wybor = getch();
    }
}

void GlownaPetla()
{
    system("cls");
    licznik=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            PLANSZA[i][j]='0';
        }
    }
    int player;
    int sprawdz;
    int bufor=0;
    Stan ktoryGracz;
    srand(time(NULL));
    ktoryGracz =  Gracz(&player);
    sprawdz = sprawdzenie();
    wyswietl();
    while(licznik!=9 && sprawdz==0)
    {
        Wybierz(&ktoryGracz);
        switch(ktoryGracz)
        {
            case kolko:
                if(licznik>bufor)
                {
                    ktoryGracz = krzyzk;
                    bufor = licznik;
                }
                break;
            case krzyzk:
                if(licznik>bufor)
                {
                    ktoryGracz = kolko;
                    bufor = licznik;
                }
                break;
        }
        sprawdz = sprawdzenie();
        wyswietl();
        if(sprawdz==1 && ktoryGracz==kolko)
        {
            cout<<"Wygrywa: X"<<endl;
        }
        else if(sprawdz==1 && ktoryGracz==krzyzk)
        {
            cout<<"Wygrywa: O"<<endl;
        }
    }
    if(sprawdz==0)
    {
        cout<<"REMIS"<<endl;
    }
    system("pause");
}

void wyswietl()
{
    system("CLS");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"|"<<PLANSZA[i][j]<<"|";
        }
        cout<<endl;
    }
}

void Wybierz(Stan * stan)
{
    char znak;
    if(*stan == kolko)
    {
        znak='O';
        Wybor(&znak);
    }
    else
    {
        znak='X';
        Wybor(&znak);
    }
}

Stan Gracz(int * p)
{
    *p = rand()%2;

    if(*p==0)
    {
        return Stan(kolko);
    }
    else
    {
        return Stan(krzyzk);
    }
}

void Wybor(char * z)
{
        char wybor;
        wybor = getch();
        switch(wybor)
        {
            case '1':
                if(PLANSZA[0][0]=='0')
                {
                    PLANSZA[0][0]=*z;
                    licznik++;
                }
                break;
            case '2':
                if(PLANSZA[0][1]=='0')
                {
                    PLANSZA[0][1]=*z;
                    licznik++;
                }
                break;
            case '3':
                if(PLANSZA[0][2]=='0')
                {
                PLANSZA[0][2]=*z;
                licznik++;
                }
                break;
            case '4':
                if(PLANSZA[1][0]=='0')
                {
                PLANSZA[1][0]=*z;
                licznik++;
                }
                break;
            case '5':
                if(PLANSZA[1][1]=='0')
                {
                PLANSZA[1][1]=*z;
                licznik++;
                }
                break;
            case '6':
                if(PLANSZA[1][2]=='0')
                {
                PLANSZA[1][2]=*z;
                licznik++;
                }
                break;
            case '7':
                if(PLANSZA[2][0]=='0')
                {
                PLANSZA[2][0]=*z;
                licznik++;
                }
                break;
            case '8':
                if(PLANSZA[2][1]=='0')
                {
                PLANSZA[2][1]=*z;
                licznik++;
                }
                break;
            case '9':
                if(PLANSZA[2][2]=='0')
                {
                PLANSZA[2][2]=*z;
                licznik++;
                }
                break;
            default:
                cout<<"Zly numer Podaj Inny"<<endl;
                break;
        }
}

int sprawdzenie()
{
    if((PLANSZA[0][0]==PLANSZA[0][1]&&PLANSZA[0][1]==PLANSZA[0][2]))
    {
        if(PLANSZA[0][0]!='0')
        return 1;
    }
    else if(PLANSZA[1][0]==PLANSZA[1][1]&&PLANSZA[1][1]==PLANSZA[1][2])
    {
        if(PLANSZA[1][0]!='0')
        return 1;
    }
    else if(PLANSZA[2][0]==PLANSZA[2][1]&&PLANSZA[2][1]==PLANSZA[2][2])
    {
        if(PLANSZA[2][0]!='0')
        return 1;
    }
    else if(PLANSZA[0][0]==PLANSZA[1][0]&&PLANSZA[1][0]==PLANSZA[2][0])
    {
        if(PLANSZA[1][0]!='0')
        return 1;
    }
    else if(PLANSZA[0][1]==PLANSZA[1][1]&&PLANSZA[1][1]==PLANSZA[2][1])
    {
        if(PLANSZA[0][1]!='0')
        return 1;
    }
    else if(PLANSZA[0][2]==PLANSZA[1][2]&&PLANSZA[1][2]==PLANSZA[2][2])
    {
        if(PLANSZA[0][2]!='0')
        return 1;
    }
    else if(PLANSZA[0][0]==PLANSZA[1][1]&&PLANSZA[1][1]==PLANSZA[2][2])
    {
        if(PLANSZA[0][2]!='0')
        return 1;
    }
    else if(PLANSZA[0][2]==PLANSZA[1][1]&&PLANSZA[1][1]==PLANSZA[2][0])
    {
        if(PLANSZA[0][2]!='0')
        return 1;
    }

    return 0;

}
