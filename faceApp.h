#include <ncurses.h>
#include "defining.h"
#include "logo_face.h"


void ver_sup(){  
        ver_sp = newwin(4,40,35,120);
        mvwprintw(ver_sp,1,1,"version: 1.00.000.102.H_kakashi R&H");
        mvwprintw(ver_sp,2, 1,"Sponsor: 3moke Uchiha_MADARA");
        wrefresh(ver_sp);
}
int Face_About(){
    int ba;
    ABOUT = newwin(3,40,17,60);
        wrefresh(ABOUT);
        wprintw(ABOUT,"NOT FOUND!!!press 'enter' for return...");
        wrefresh(ABOUT);
        ba = getch();
        if(ba == 10){
            clear();
            refresh();
            return ba = 0;
        }
        else{
            clear();
            refresh();
            Face_About();
        }
}
void face_about(int k){
    wabout = newwin(3,11,1,155);
    if( k == 1){
        wbkgd(wabout, COLOR_PAIR(1));
    }
    box(wabout,0,0);
    wattron(wabout,A_BOLD);
    mvwprintw(wabout,1,1,"ABOUT (!)");
    wattroff(wabout,A_BOLD);
    wrefresh(wabout);
}
void face_hello(int *y1,int *x1){
    int y,x; 
    wwelcome = newwin(4,12,3,8);
    wattron(wwelcome,A_BOLD);
    wprintw(wwelcome,"WELCOME; to,");
    wattroff(wwelcome,A_BOLD);
    wrefresh(wwelcome);
    getmaxyx(wwelcome,y,x);
    *y1 = y;
    *x1 = x;
}

void face_title(int y1,int x1,int *z1,int *r1){
    ftitle_logo(8,14);
    int z,r;
    getyx(wlogo, z, r);
    *z1 = z;
    *r1 = r;
}
void face_list(int z1,int r1){
    list = newwin(4, 45,z1 + 15, r1 );
    wprintw(list,("!!!....press ('F1') how to use ;\n"));
    wprintw(list,("!!!....press ('ENTER') to continue ;\n"));
    wprintw(list,("!!!....press ('ESC') to exit ;\n"));
    wrefresh(list);
}
int face_F1(){
    int ba;
    F1 = newwin(3,40,17,60);
        wrefresh(F1);
        wprintw(F1,"NOT FOUND!!!press 'ENTER' for return...");
        wrefresh(F1);
        ba = getch();
        if(ba == 10){
            clear();
            refresh();
            return ba = 0;
        }
        else{
            clear();
            refresh();
            face_F1();
        }
}
int print_face(){
    dub:
    int bo ;
    int k = 0;
    int b ;
    bo = 258;
    k = 0;
    do{
        int x1;
        int y1;
        int z1,r1;
        
        face_about(k); 
        face_hello(&y1,&x1);
        face_title(y1,x1,&z1,&r1);
        face_list(z1,r1);
        ver_sup();

        delwin(wlogo);
        delwin(wabout);
        delwin(wwelcome);
        delwin(list);
        delwin(ver_sp);
            bo = getch();
            if(bo == 258 || bo == 259)
                k++;
            if(k == 1){
                if(bo == 10){
                    clear();
                    refresh();
                    bo = Face_About();
                    break;
                }
            }  
            if(k > 1)
                k = 0;
    }while( bo  != 10 &&  bo != 27 && bo !=265);
    if(bo == 265){
    clear();
    refresh();
    bo = face_F1();
    }
    if(bo == 0){
        goto dub;
    }

    if(bo == 27){
        return bo;
    }
}