#include <ncurses.h>
#include "logo_face.h"
#include<locale.h>

/**/
void face_welcome(WINDOW * wwelcome, int *max_yw,int *max_xw){
    const char * we = "Welcome ;to, ";
    const int hiw = 4 , wiw = 12;
    wwelcome = newwin( hiw, wiw, 3, 8);
    wattron(wwelcome,A_BOLD);
    wprintw(wwelcome,"%s",we);
    wattroff(wwelcome,A_BOLD);
    wrefresh(wwelcome);
    getmaxyx(wwelcome,*max_yw,*max_xw);
}







void print_face(){
    int max_yw,max_xw;
    do{
        WINDOW * wwelcome;
        face_welcome(&*wwelcome,&max_yw,&max_xw);
        WINDOW * wlogo;
        setlocale(LC_ALL, "fr_FR.utf8");
        flogo(&*wlogo,&max_yw,&max_xw);

    }while(true);
}