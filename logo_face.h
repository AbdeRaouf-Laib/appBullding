#include <ncurses.h> //? New Curses aka :"ncurses" C/C++ Library (used to make TUI programs).
#include<locale.h>
/**/
void flogo(WINDOW * wlogo,int *wmax_yw,int *wmax_xw){
    setlocale(LC_ALL, "fr_FR.utf8");
    wlogo = newwin(7,70,*wmax_yw,*wmax_xw + 4);
    wprintw(wlogo,"--------------------------------------------------\n");
    wprintw(wlogo,"#  \033[1;37m██     ██ ██ ██   ██  █████  ██       █████\n");
    wprintw(wlogo,"#  \033[1;37m██     ██ ██ ██  ██  ██   ██ ██      ██   ██ \n");
    wprintw(wlogo,"#  \033[1;37m██  █  ██ ██ █████   ███████ ██      ███████ \n");
    wprintw(wlogo,"#  \033[1;37m██ ███ ██ ██ ██  ██  ██   ██ ██      ██   ██ \n");
    wprintw(wlogo,"#   \033[1;37m███ ███  ██ ██   ██ ██   ██ ███████ ██   ██ \n");
    wprintw(wlogo,"--------------------------------------------------\n");
    wrefresh(wlogo);
}


