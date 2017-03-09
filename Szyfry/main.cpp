#include "SzyfrCezara.h"
#include "SzyfrKlucz.h"

int main()
{
    SzyfrCezara * a = new SzyfrCezara("");
    SzyfVinegre * b = new SzyfVinegre("napis bo tak jest ok i tyle","napid");
    char wybor='0';
    while(wybor!='4')
    {
        cout<<"MENU"<<endl;
        cout<<"1 - Szyfr Cezara"<<endl;
        cout<<"2 - Szyfr Vigenere'a"<<endl;
        cout<<"3 - Szyfr 3"<<endl;
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

    return 0;
}
