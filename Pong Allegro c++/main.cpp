#include <allegro.h>
#include <iostream>
#include <winalleg.h>
#include <time.h>
#define MAX_FRAME_PER_SEC 60
#define MAX_FRAME_SKIP 10
#define MAX_MENU_STATE 3
/*
speed i increment_speed() slu¿a do tak zwanego spowolnienia gry
dlaczego poniewa¿ na niektorych komputerach gra mog³a by chodziæ zbyt szybko a niektorych zbyt wolno
*/
volatile int speed = 0;

void increment_speed()
{
    speed++;
}
END_OF_FUNCTION(increment_speed);

LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);

const int SKIP_TICK = 1000/MAX_FRAME_PER_SEC;

int sprawdzeniePKT;

int Ile_PKT;


//BITMAP czyli taki swego rodzaju screen pozwalajacy wyswietlac co na niego nalozymy
BITMAP * buffer;

int RANDOMIZE;
int RANDOMIZE2;
int pomocY,pomocX;

int POINTS1,POINTS2;

bool WINNER = false;

//Pozycja paletki w grze
struct Vec2
{
    int x,y;
};

int y1,y2;

float licznik=0.2f;

int sprawdzenie;

float POS_X_CIRCLE,POS_Y_CIRCLE;

//STANY NASZEJ GRY CZYLI CZY JEST ONA W MENU CZY W GRZE CZY KONTYNUJEMY CZY MOZE CHCEMY WYJSC
enum State
{
    state_menu,
    state_new_game,
    state_info,
    state_quit
};
//POZYCJA NASZEGO MENU W ZMIENNYCH PONIEWAZ JEST TO DOBRY NAWYK BO WSZYSTKO MAMY W JEDNYM MIEJSCU
enum MenuPos
{
    Pos_new_game=10,
    Pos_continue=30,
    Pos_quit=50
};

enum MAX_PKT
{
    PKT0,
    PKT12,
    PKT24,
    PKT36
};



inline void init()
{
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);

	install_timer();
	//install_int_ex(increment_speed,BPS_TO_TIMER(40));
	install_keyboard();
	install_mouse();
}

inline void deinit()
{
    destroy_bitmap(buffer);
	clear_keybuf();
	allegro_exit();
}

void display_menu(State stan)
{
    int color = makecol(255,255,255);
    int HighLight = makecol(255,255,0);

    switch(stan)
    {
        case state_new_game:
            textout_centre_ex(buffer,font,"PLAY",SCREEN_W/2,Pos_new_game,HighLight,0);
            textout_centre_ex(buffer,font,"INFO",SCREEN_W/2,Pos_continue,color,0);
            textout_centre_ex(buffer,font,"QUIT",SCREEN_W/2,Pos_quit,color,0);
            break;
        case state_info:
            textout_centre_ex(buffer,font,"PLAY",SCREEN_W/2,Pos_new_game,color,0);
            textout_centre_ex(buffer,font,"INFO",SCREEN_W/2,Pos_continue,HighLight,0);
            textout_centre_ex(buffer,font,"QUIT",SCREEN_W/2,Pos_quit,color,0);
            break;
        case state_quit:
            textout_centre_ex(buffer,font,"PLAY",SCREEN_W/2,Pos_new_game,color,0);
            textout_centre_ex(buffer,font,"INFO",SCREEN_W/2,Pos_continue,color,0);
            textout_centre_ex(buffer,font,"QUIT",SCREEN_W/2,Pos_quit,HighLight,0);
            break;

    }
}

void display_game()
{
    int color = makecol(255,255,255);
    const Vec2 ARENA_POSITION={50,50};
    rect(buffer,ARENA_POSITION.x,ARENA_POSITION.y,SCREEN_W-ARENA_POSITION.x,SCREEN_H-ARENA_POSITION.y,color);
    textout_ex(buffer,font,"Player-1 Controls W/S",50,30,color,0);
    textout_ex(buffer,font,"Player-2 Controls O/L",SCREEN_W-220,30,color,0);
}

void display_info()
{
    int color = makecol(255,0,255);
    textout_centre_ex(buffer,font,"INFORMACJE",SCREEN_W/2,SCREEN_H/2-250,color,0);
    textout_centre_ex(buffer,font,"Gra pong w jezyku c++",SCREEN_W/2,SCREEN_H/2-200,color,0);
    textout_centre_ex(buffer,font,"W bibliotece allegro w wersji 4.0x",SCREEN_W/2,SCREEN_H/2-180,color,0);
    textout_centre_ex(buffer,font,"Sterowanie Gracz nr:1",SCREEN_W/2,SCREEN_H/2-160,color,0);
    textout_centre_ex(buffer,font,"W - gora S - Dol",SCREEN_W/2,SCREEN_H/2-140,color,0);
    textout_centre_ex(buffer,font,"Sterowanie Gracz nr:2",SCREEN_W/2,SCREEN_H/2-120,color,0);
    textout_centre_ex(buffer,font,"O - gora L - Dol",SCREEN_W/2,SCREEN_H/2-100,color,0);
    textout_centre_ex(buffer,font,"PAUSE oraz EXIT - Spacja",SCREEN_W/2,SCREEN_H/2-80,color,0);

}

void MAXI(MAX_PKT PKT)
{
        int color = makecol(255,255,255);
        int HighLight = makecol(255,255,0);
        switch(PKT)
        {
            case PKT12:
                textout_centre_ex(buffer,font,"12 PUNKTOW",SCREEN_W/2,SCREEN_H/2-150,HighLight,0);
                textout_centre_ex(buffer,font,"24 PUNKTY",SCREEN_W/2,SCREEN_H/2-100,color,0);
                textout_centre_ex(buffer,font,"36 PUNKTOW",SCREEN_W/2,SCREEN_H/2-50,color,0);
                break;
            case PKT24:
                textout_centre_ex(buffer,font,"12 PUNKTOW",SCREEN_W/2,SCREEN_H/2-150,color,0);
                textout_centre_ex(buffer,font,"24 PUNKTY",SCREEN_W/2,SCREEN_H/2-100,HighLight,0);
                textout_centre_ex(buffer,font,"36 PUNKTOW",SCREEN_W/2,SCREEN_H/2-50,color,0);
                break;
            case PKT36:
                textout_centre_ex(buffer,font,"12 PUNKTOW",SCREEN_W/2,SCREEN_H/2-150,color,0);
                textout_centre_ex(buffer,font,"24 PUNKTY",SCREEN_W/2,SCREEN_H/2-100,color,0);
                textout_centre_ex(buffer,font,"36 PUNKTOW",SCREEN_W/2,SCREEN_H/2-50,HighLight,0);
                break;
        }
}

void display_gameplay()
{
        int value;
        sprawdzenie=0;
        if(key[KEY_5])
        {
            WINNER=false;
            y1=0;
            y2=0;
            POS_X_CIRCLE=0;
            POS_Y_CIRCLE=0;
            licznik=0.2f;
            POINTS1=0;
            POINTS2=0;
            RANDOMIZE=rand()%2;
            RANDOMIZE2=rand()%50;
            if(RANDOMIZE==1)
            {
                pomocX=1;
                if(RANDOMIZE2>=0 && RANDOMIZE2<24)pomocY=1;
                else if(RANDOMIZE2>=24 && RANDOMIZE2<=50)pomocY=2;
            }
            else
            {
                pomocX=2;
                if(RANDOMIZE2>=0 && RANDOMIZE2<24)pomocY=1;
                else if(RANDOMIZE2>=24 && RANDOMIZE2<=50)pomocY=2;
            }
            sprawdzeniePKT=0;
        }

        if(WINNER==true)
        {
            y1=0;
            y2=0;
            POS_X_CIRCLE=0;
            POS_Y_CIRCLE=0;
            licznik=0.2f;
            sprawdzeniePKT=0;
            POINTS1=0;
            POINTS2=0;
            WINNER=false;
        }
        else
            {
            const int POS_PALLETEONE = 320;
            const int POS_PALLETETWO = 300;
            Vec2 PALLETE_POS = {SCREEN_W/2-POS_PALLETEONE,SCREEN_H/2};
            Vec2 PALLETE2_POS = {SCREEN_W/2+POS_PALLETETWO,SCREEN_H/2};
            int color = makecol(255,255,255);
            int color2 = makecol(255,255,0);
            rectfill(buffer,PALLETE_POS.x,PALLETE_POS.y+y1,PALLETE_POS.x+10,PALLETE_POS.y-70+y1,color);
            rectfill(buffer,PALLETE2_POS.x,PALLETE2_POS.y+y2,PALLETE2_POS.x+10,PALLETE2_POS.y-70+y2,color);
            circlefill(buffer,SCREEN_W/2 + POS_X_CIRCLE,SCREEN_H/2 + POS_Y_CIRCLE,7,color);
            textprintf(buffer,font,SCREEN_W/2+150,SCREEN_H/2-270,color,"%d",POINTS1);
            textprintf(buffer,font,SCREEN_W/2-170,SCREEN_H/2-270,color,"%d",POINTS2);
            textout_centre_ex(buffer,font,"PAUSE - SPACE",SCREEN_W/2,SCREEN_H-20,color2,0);
            textout_centre_ex(buffer,font,"PAUSE - 5",SCREEN_W/2,SCREEN_H/2-280,color2,0);
            if(key[KEY_W] && y1!=-180)
            {
                y1--;
                //std::cout<<PALLETE_POS.y+y1<<std::endl;
            }
            else if(key[KEY_S] && y1!=250)
            {
                y1++;
                //std::cout<<PALLETE_POS.y+y1<<std::endl;
            }
            if(key[KEY_O] && y2!=-180)
            {
                y2--;
                //std::cout<<PALLETE2_POS.y+y2<<std::endl;
            }
            else if(key[KEY_L] && y2!=250)
            {
                y2++;
                //std::cout<<PALLETE2_POS.y+y2<<std::endl;
            }
            if(POS_Y_CIRCLE  >= -251.0 && POS_Y_CIRCLE<=251.0 && POS_X_CIRCLE<=351.0 && POS_X_CIRCLE>=-351.0)
            {
                if(POS_Y_CIRCLE<=-250.0)
                {
                    POS_Y_CIRCLE=-250.0;
                    pomocY=1;
                }
            else if(POS_Y_CIRCLE>=250.0)
            {
                POS_Y_CIRCLE=250.0;
                pomocY=2;
            }
            else if(POS_X_CIRCLE>=350)
            {
                pomocX=1;
            }
            else if(POS_X_CIRCLE<=-350)
            {
                pomocX=2;
            }
            if(pomocY==1)
            {
                POS_Y_CIRCLE+=licznik;
            }
            else if(pomocY==2)
            {
                POS_Y_CIRCLE-=licznik;
                //std::cout<<PALLETE2_POS.x<<" "<<PALLETE2_POS.y<<std::endl;
            }
            if(pomocX==1)
            {
                POS_X_CIRCLE-=licznik;
            }
            else if(pomocX==2)
            {
                POS_X_CIRCLE+=licznik;
            }
            else if(pomocX==3)
            {
                POS_X_CIRCLE+=licznik+0.4f;
            }
            else if(pomocX==4)
            {
                POS_X_CIRCLE-=licznik+0.4f;
            }
            if(POS_X_CIRCLE>=349.0)
            {
                licznik=0.2f;
                POS_X_CIRCLE=0;
                POS_Y_CIRCLE=0;
                RANDOMIZE=rand()%2;
                RANDOMIZE2=rand()%50;
                if(RANDOMIZE==1)
                {
                    pomocX=1;
                    if(RANDOMIZE2>=0 && RANDOMIZE2<24)pomocY=1;
                    else if(RANDOMIZE2>=24 && RANDOMIZE2<=50)pomocY=2;
                }
                else
                {
                    pomocX=2;
                    if(RANDOMIZE2>=0 && RANDOMIZE2<24)pomocY=1;
                    else if(RANDOMIZE2>=24 && RANDOMIZE2<=50)pomocY=2;
                }
                POINTS2++;
            }
            else if(POS_X_CIRCLE<=-349.0)
            {
                licznik=0.2f;
                POS_X_CIRCLE=0;
                POS_Y_CIRCLE=0;
                RANDOMIZE=rand()%2;
                RANDOMIZE2=rand()%50;
                if(RANDOMIZE==1)
                {
                    pomocX=1;
                    if(RANDOMIZE2>=0 && RANDOMIZE2<24)pomocY=1;
                    else if(RANDOMIZE2>=24 && RANDOMIZE2<=50)pomocY=2;
                }
                else
                {
                    pomocX=2;
                    if(RANDOMIZE2>=0 && RANDOMIZE2<24)pomocY=1;
                    else if(RANDOMIZE2>=24 && RANDOMIZE2<=50)pomocY=2;
                }
                POINTS1++;
            }
            if(Ile_PKT==1)
            {
                if(POINTS1==12||POINTS2==12)
                {
                    WINNER=true;
                }
            }
            else if(Ile_PKT==2)
            {
                if(POINTS1==24||POINTS2==24)
                {
                    WINNER=true;
                }
            }
            else if(Ile_PKT==3)
            {
                if(POINTS1==36||POINTS2==36)
                {
                    WINNER=true;
                }
            }
            if(((POS_Y_CIRCLE+399) >=(PALLETE_POS.y+y1) && (POS_Y_CIRCLE+300)<=(PALLETE_POS.y+y1)) && (POS_X_CIRCLE<=-300&&POS_X_CIRCLE>=-320))
            {
                pomocX=2;
                if(((POS_Y_CIRCLE+302)<=(PALLETE_POS.y+y1) && (POS_Y_CIRCLE+348) >=(PALLETE_POS.y+y1)) && (POS_X_CIRCLE<=-300&&POS_X_CIRCLE>=-320))
                {
                    pomocY=1;
                    if(licznik<=1.2f)licznik+=0.1f;
                }
                else if(((POS_Y_CIRCLE+348)<=(PALLETE_POS.y+y1) && (POS_Y_CIRCLE+397) >=(PALLETE_POS.y+y1)) && (POS_X_CIRCLE<=-300&&POS_X_CIRCLE>=-320))
                {
                    pomocY=2;
                }
                if(((POS_Y_CIRCLE+302)<=(PALLETE_POS.y+y1)&&(POS_Y_CIRCLE+324) >=(PALLETE_POS.y+y1)) && (POS_X_CIRCLE<=-300&&POS_X_CIRCLE>=-320))
                {
                    pomocX=2;
                }
                else if(((POS_Y_CIRCLE+324)<=(PALLETE_POS.y+y1)&&(POS_Y_CIRCLE+371) >=(PALLETE_POS.y+y1)) && (POS_X_CIRCLE<=-300&&POS_X_CIRCLE>=-320))
                {
                    pomocX=3;
                }
                else if(((POS_Y_CIRCLE+371)<=(PALLETE_POS.y+y1)&&(POS_Y_CIRCLE+399) >=(PALLETE_POS.y+y1)) && (POS_X_CIRCLE<=-300&&POS_X_CIRCLE>=-320))
                {
                    pomocX=2;
                }
            }
            else if(((POS_Y_CIRCLE+399) >=(PALLETE2_POS.y+y2) && (POS_Y_CIRCLE+300)<=(PALLETE2_POS.y+y2)) && (POS_X_CIRCLE>=290&&POS_X_CIRCLE<=310))
            {
                pomocX=1;
                if(((POS_Y_CIRCLE+302)<=(PALLETE2_POS.y+y2) && (POS_Y_CIRCLE+348) >=(PALLETE2_POS.y+y2)) && (POS_X_CIRCLE>=290&&POS_X_CIRCLE<=310))
                {
                    pomocY=1;
                    if(licznik<=1.2f)licznik+=0.1f;
                }
                else if(((POS_Y_CIRCLE+348)<=(PALLETE2_POS.y+y2) && (POS_Y_CIRCLE+397) >=(PALLETE2_POS.y+y2)) && (POS_X_CIRCLE>=290&&POS_X_CIRCLE<=310))
                {
                    pomocY=2;
                }
                if(((POS_Y_CIRCLE+302)<=(PALLETE2_POS.y+y2)&&(POS_Y_CIRCLE+324) >=(PALLETE2_POS.y+y2)) && (POS_X_CIRCLE>=290&&POS_X_CIRCLE<=310))
                {
                    pomocX=1;
                }
                else if(((POS_Y_CIRCLE+324)<=(PALLETE2_POS.y+y2)&&(POS_Y_CIRCLE+371) >=(PALLETE2_POS.y+y2)) && (POS_X_CIRCLE>=290&&POS_X_CIRCLE<=310))
                {
                    pomocX=4;
                }
                else if(((POS_Y_CIRCLE+371)<=(PALLETE2_POS.y+y2)&&(POS_Y_CIRCLE+399) >=(PALLETE2_POS.y+y2)) && (POS_X_CIRCLE>=290&&POS_X_CIRCLE<=310))
                {
                    pomocX=1;
                }
            }
        }
    }


}

State Pause(int * stan)
{
    if(key[KEY_SPACE])
    {
        return state_menu;
    }
    if(*stan==1)
    {
        sprawdzenie = 1;
        return state_new_game;
    }
    else if(*stan==2)
    {
        return state_info;
    }
}

State MenuStan(int * stan)
{
    int value;
    if(keypressed())
    {
        value = readkey();
        switch(value>>8)
        {
            case KEY_DOWN:
                if(*stan<MAX_MENU_STATE)(*stan)++;
                break;
            case KEY_UP:
                if(*stan>1)(*stan)--;
                break;
            case KEY_ENTER:
                return State(*stan);
        }
    }
    return state_menu;
}


MAX_PKT PktStan(int * stan)
{
    int value;
    if(keypressed())
    {
        value = readkey();
        switch(value>>8)
        {
            case KEY_DOWN:
                if(*stan<MAX_MENU_STATE)(*stan)++;
                break;
            case KEY_UP:
                if(*stan>1)(*stan)--;
                break;
            case KEY_ENTER:
                sprawdzeniePKT=1;
                return MAX_PKT(*stan);
        }
    }
    return PKT0;
}

int main()
{
	init();
	srand(time(NULL));
	int x=1,y=1;
    RANDOMIZE = rand()%2;
	State stan = state_menu;
	int currentState = 1;
	int loops=0;
    int next_freame_skip = GetTickCount();
    MAX_PKT maxPKT=PKT0;
    int StanPKT = 1;
    int color = makecol(255,255,255);
    float interpolation;

    RANDOMIZE=rand()%2;
    RANDOMIZE2=rand()%50;
    if(RANDOMIZE==1)
    {
        pomocX=1;
        if(RANDOMIZE2>=0 && RANDOMIZE2<24)pomocY=1;
        else if(RANDOMIZE2>=24 && RANDOMIZE2<=50)pomocY=2;
    }
    else
    {
        pomocX=2;
        if(RANDOMIZE2>=0 && RANDOMIZE2<24)pomocY=1;
        else if(RANDOMIZE2>=24 && RANDOMIZE2<=50)pomocY=2;
    }
    buffer = create_bitmap(SCREEN_W,SCREEN_H);
    if(!buffer)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie moge zaladowac naszego buffera;");
        allegro_exit();
    }
	while (!key[KEY_ESC])
	{
	    loops=0;

	    //Dodatkowa petla sprawdzajaca czy gra chodzi porpawnie
        while(GetTickCount()>next_freame_skip&&loops<MAX_FRAME_SKIP)
        {
            //
            next_freame_skip+=SKIP_TICK;
            loops++;
            switch(stan)
            {
                case state_menu:
                    stan = MenuStan(&currentState);
                    break;
                case state_new_game:
                    stan = Pause(&currentState);
                    maxPKT = PktStan(&StanPKT);
                    break;
                case state_info:
                    stan = Pause(&currentState);
                    break;
                case state_quit:
                    exit(0);
                    break;
            }
            //speed--;

        }
        clear(buffer);
        switch(stan)
        {
            case state_menu:
                display_menu(State(currentState));
                break;
            case state_new_game:
                if(maxPKT==PKT0 && sprawdzeniePKT==0)
                {
                    MAXI(MAX_PKT(StanPKT));
                    display_game();
                    Ile_PKT=StanPKT;
                }
                else
                {
                    display_game();
                    display_gameplay();
                }
                break;
            case state_info:
                display_info();
                break;
            case state_quit:
                exit(0);
                break;
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

	}
	deinit();
	return 0;
}
END_OF_MAIN()
