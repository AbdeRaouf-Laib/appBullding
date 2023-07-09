#include <stdio.h>
#include <ncurses.h>
#include "defining.h"
#include "logo_face.h"

//defind window
WINDOW * W__logo;
WINDOW * W__welcome;
WINDOW * W__about;
WINDOW * W__vertion_sponsor;
WINDOW * W__ABOUT;
WINDOW * W__list;
WINDOW * W__F1;
/*Variables are used to define colors*/
#define BW 1
#define BLW 2
#define BLB 3
#define RB 4


//const Value
#define welcome "WELCOME; to,"
#define enter 10
#define curs_down 258
#define curs_up 259
#define curs_right 261
#define curs_left 260
#define esc 27
#define f1 265
#define space 32

//define values
int Fonction__Key__values;
int Key__values;

    
int print_face();
void Color();

int main(){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    Color();
    keypad(stdscr,TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    refresh();
    print_face();
    endwin();
}

/*define colors*/
void Color(){
    init_pair(BW, COLOR_BLACK, COLOR_WHITE);
    init_pair(BLW, COLOR_BLUE, COLOR_WHITE);
    init_pair(BLB, COLOR_BLUE, COLOR_BLACK);
    init_pair(RB, COLOR_RED, COLOR_BLACK);
}

//print the vertion and sponsor
void F__vertion_sponsor(){  
    W__vertion_sponsor = newwin(4,40,35,120);
    mvwprintw(W__vertion_sponsor,1,1,"version: 1.00.000.102.H_kakashi R&H");
    mvwprintw(W__vertion_sponsor,2, 1,"Sponsor: 3moke Uchiha_MADARA");
    wrefresh(W__vertion_sponsor);
}

//print the about content 
int Face_About() {
        W__ABOUT = newwin(3,40,17,60);
        wrefresh(W__ABOUT);
        wprintw(W__ABOUT,"NOT FOUND!!!press 'enter' for return...");
        wrefresh(W__ABOUT);
        Fonction__Key__values = getch();
        if(Fonction__Key__values == enter){
            clear();
            refresh();
            return Fonction__Key__values = 0;
        }
        else{
            clear();
            refresh();
            Face_About();
        }
}

//print the about window 
void face_about(int k){
    W__about = newwin(3,11,1,155);
    if( k == 1){
        wbkgd(W__about, COLOR_PAIR(BW));
    }
    box(W__about,0,0);
    wattron(W__about,A_BOLD);
    mvwprintw(W__about,1,1,"ABOUT (!)");
    wattroff(W__about,A_BOLD);
    wrefresh(W__about);
}

//print welcome
void face_hello(int *y1,int *x1){
    int y,x; 
    W__welcome = newwin(4,12,3,8);
    wattron(W__welcome,A_BOLD);
    wprintw(W__welcome,"WELCOME; to,");
    wattroff(W__welcome,A_BOLD);
    wrefresh(W__welcome);
    getmaxyx(W__welcome,y,x);
    *y1 = y;
    *x1 = x;
}

//Calling the logo function from a logo_face lib
void face_title(int y1,int x1,int *z1,int *r1){
    ftitle_logo(8,14);
    int z,r;
    getyx(W__logo, z, r);
    *z1 = z;
    *r1 = r;
}

//useing list 
void face_list(int z1,int r1){
    W__list = newwin(4, 45,z1 + 14, r1 );
    wprintw(W__list,("!!!....press ('F1') how to use ;\n"));
    wprintw(W__list,("!!!....press ('ENTER') to continue ;\n"));
    wprintw(W__list,("!!!....press ('ESC') to exit ;\n"));
    wrefresh(W__list);
}

//print f1 content 
int face_F1(){
    W__F1 = newwin(3,40,17,60);
        wrefresh(W__F1);
        wprintw(W__F1,"NOT FOUND!!!press 'ENTER' for return...");
        wrefresh(W__F1);
        Fonction__Key__values = getch();
        if(Fonction__Key__values == enter){
            clear();
            refresh();
            return Fonction__Key__values = 0;
        }
        else{
            clear();
            refresh();
            face_F1();
        }
}

//main fonction for faceApp lib
int print_face(){
    dub:
    Key__values = curs_down;
    int k = 0;
    int b;
    do{
        int x1;
        int y1;
        int z1,r1;
        
        face_about(k); 
        face_hello(&y1,&x1);
        face_title(y1,x1,&z1,&r1);
        face_list(z1,r1);
        F__vertion_sponsor();
        
        delwin(W__logo);
        delwin(W__about);
        delwin(W__welcome);
        delwin(W__list);
        delwin(W__vertion_sponsor);
            Key__values = getch();
            if(Key__values == curs_down || Key__values == curs_up)
                k++;

            if(k == 1){
                if(Key__values == enter){
                    clear();
                    refresh();
                    Key__values = Face_About();
                    break;
                }
            }
            if(k > 1)
                k = 0;

    }while( Key__values != enter &&  Key__values != esc && Key__values != f1);
    if(Key__values == f1){
        clear();
        refresh();
        Key__values = face_F1();
    }
    if(Key__values == 0)
        goto dub;  
    if(Key__values == enter){
        
    }
    if(Key__values == esc)
        return Key__values;
    
}