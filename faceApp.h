#include <ncurses.h>
#include "defining.h"
#include "logo_face.h"


void F__vertion_sponsor(){  
    W__vertion_sponsor = newwin(4,40,35,120);
    mvwprintw(W__vertion_sponsor,1,1,"version: 1.00.000.102.H_kakashi R&H");
    mvwprintw(W__vertion_sponsor,2, 1,"Sponsor: 3moke Uchiha_MADARA");
    wrefresh(W__vertion_sponsor);
}
int Face_About(){
    int Fonction__Key__values;
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

void face_title(int y1,int x1,int *z1,int *r1){
    ftitle_logo(8,14);
    int z,r;
    getyx(W__logo, z, r);
    *z1 = z;
    *r1 = r;
}
void face_list(int z1,int r1){
    W__list = newwin(4, 45,z1 + 14, r1 );
    wprintw(W__list,("!!!....press ('F1') how to use ;\n"));
    wprintw(W__list,("!!!....press ('ENTER') to continue ;\n"));
    wprintw(W__list,("!!!....press ('ESC') to exit ;\n"));
    wrefresh(W__list);
}
int face_F1(){
    int Fonction__Key__values;
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
int print_face(){
    dub:
    int Key__values = curs_down;
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

    if(Key__values == esc)
        return Key__values;
    
}