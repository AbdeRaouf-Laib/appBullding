#include <ncurses.h>
#include <stdio.h>

int main(){
    int ch;
    initscr();
    cbreak();
    keypad(stdscr,TRUE);
    ch = getch();
    printw("%d",ch);
    getch();
    endwin();
}