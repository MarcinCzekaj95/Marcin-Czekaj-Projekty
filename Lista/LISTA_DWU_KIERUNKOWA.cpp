#include "LISTA_DWU_KIERUNKOWA.h"

int node::licznik=0;

node::node()
{
    head=0;
    tail=0;
    next=0;
    prev=0;
    data=0;
}

node::~node()
{

}

void node::PUSH_TO_FRONT(int number)
{
    node * n = new node();
    n->data=number;
    if(head==0 && tail==0)
    {
        head = n;
        tail = n;
        licznik++;
    }
    else
    {
        node * tmp = head;
        head->prev = n;
        head = head->prev;
        head->next = tmp;
        head->prev = 0;
        licznik++;
    }
}

void node::PUSH_TO_BACK(int number)
{
    node * n = new node();
    n->data = number;
    if(tail==0 && head==0)
    {
        head = n;
        tail = n;
        licznik++;
    }
    else
    {
        node * tmp = tail;
        tail->next=n;
        tail = tail->next;
        tail->prev = tmp;
        tail->next = 0;
        licznik++;
    }

}

void node::POP_FROM_FRONT()
{
    if(licznik>1)
    {
        cout<<"USUWAM ELEMENT Z POCZATKU LISTY: "<<head->data<<endl;
        node * tmp = head;
        head = head->next;
        delete tmp;
        head->prev = 0;
        licznik--;
        Sleep(2000);
    }
    else if(licznik==1)
    {
        cout<<"USUWAM ELEMENT Z POCZATKU LISTY: "<<head->data<<endl;
        delete head;
        delete tail;
        head = 0;
        tail = 0;
        licznik--;
        Sleep(2000);
    }
    else
    {
        cout<<"LISTA JEST PUSTA"<<endl;
        Sleep(2000);
    }

}

void node::POP_FROM_BACK()
{
    if(licznik>1)
    {
        cout<<"USUWAM ELEMENT Z KONCA LISTY: "<<tail->data<<endl;
        node * tmp = tail;
        tail = tail->prev;
        delete tmp;
        tail->next = 0;
        licznik--;
        Sleep(2000);
    }
    else if(licznik==1)
    {
        cout<<"USUWAM ELEMENT Z KONCA LISTY: "<<tail->data<<endl;
        delete head;
        delete tail;
        head = 0;
        tail = 0;
        licznik--;
        Sleep(2000);
    }
    else
    {
        cout<<"LISTA JEST PUSTA"<<endl;
        Sleep(2000);
    }
}



void node::Write()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    node * tmp = head;
    cout<<"------------------------------------------------------------"<<endl;
    while(tmp)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl<<"------------------------------------------------------------"<<endl<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void node::SIZES()
{
    cout<<"ROZMIAR TABLICY TO: "<<licznik<<endl;
    Sleep(2000);
}

void node::IS_EMPTY()
{
    if(licznik==0)
    {
        cout<<"CZY LISTA JEST PUSTA: "<<"TAK"<<endl;
        Sleep(2000);
    }
    else
    {
        cout<<"CZY LISTA JEST PELNA: "<<"NIE"<<endl;
        Sleep(2000);
    }
}

void node::Clear_LISTS()
{
    node * tmp = head;
    while(tmp)
    {
        tmp = tmp->next;
        cout<<"USUWAM: "<<head->data<<endl;
        delete head;
        head = tmp;
    }
    delete next;
    delete prev;
    delete tail;
    delete head;
    delete tmp;

}
void Lista_Dwu_Kierunkowa()
{
    node * Lista_Dwukierunkowa = new node();
    int liczba = 0;
    char wybor = '0';
    while(wybor!='7')
    {
        Lista_Dwukierunkowa->Write();
        cout<<"MENU"<<endl;
        cout<<"1 - Push_Front\n2 - Push_Back\n3 - Pop_Front\n4 - Pop_Back\n5 - Size\n6 - IS_EMPTY?\n7 - FINISH\n\n\n";
        wybor = getch();
        switch(wybor)
        {
            case '1':
                cout<<"JAKA LICZBE CHCESZ DODAC NA POCZATEK LISTY: ";
                cin>>liczba;
                Lista_Dwukierunkowa->PUSH_TO_FRONT(liczba);
                cout<<endl;
                break;
            case '2':
                cout<<"JAKA LICZBE CHCESZ DODAC NA KONIEC LISTY: ";
                cin>>liczba;
                Lista_Dwukierunkowa->PUSH_TO_BACK(liczba);
                cout<<endl;
                break;
            case '3':
                Lista_Dwukierunkowa->POP_FROM_FRONT();
                break;
            case '4':
                Lista_Dwukierunkowa->POP_FROM_BACK();
                break;
            case '5':
                Lista_Dwukierunkowa->SIZES();
                break;
            case '6':
                Lista_Dwukierunkowa->IS_EMPTY();
                break;
            case '7':
                cout<<"KONCZE..."<<endl;
                break;
            default:
                cout<<"ZLY NUMER PODAJ INNY"<<endl;
                break;
        }

    }
    Lista_Dwukierunkowa->Clear_LISTS();
    delete Lista_Dwukierunkowa;
}


