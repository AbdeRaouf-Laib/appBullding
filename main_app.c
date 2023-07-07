#include <stdio.h>
#include <ncurses.h>
#include "faceApp.h"






/*fonction for define colors*/
void Color(){
    init_pair(BW, COLOR_BLACK, COLOR_WHITE);
    init_pair(BLW, COLOR_BLUE, COLOR_WHITE);
    init_pair(BLB, COLOR_BLUE, COLOR_BLACK);
    init_pair(RB, COLOR_RED, COLOR_BLACK);
}

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
