/************************************LICENCE**************************************\
                                    
                                    MIT License

                        Copyright (c) 2023 AbdeRaouf-Laib
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
            furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
                copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
                                    SOFTWARE.
/*********************************************************************************/

/****************************General code reading tips****************************\
*                                                                                 *  
*                                                                                 *
* !! The program is a terminal application so a library is included ncurses lib   *
* !! W__ : is a window;                                                           *
* !! F__ : is a fonction;                                                         *
* !! Almost all variants have work or place names;                                *
* !! The code depends a lot on functionality                                      *
* !! The condition is usually without {} which means it only executes one command *
*                                                                                 *
*                                                                                 *
/*********************************************************************************/                                                                              

#include <stdio.h>
#include <ncurses.h>
#include "logo_face.h"

//defind window
WINDOW * W__logo;
WINDOW * W__welcome;
WINDOW * W__about;
WINDOW * W__vertion_sponsor;
WINDOW * W__ABOUT;
WINDOW * W__list_of_using;
WINDOW * W__F1;
WINDOW * W__main;
WINDOW * W__list2_of_using;
WINDOW * W__how_use;
WINDOW * W__return;
WINDOW * W__exit;

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
#define main__width 18
#define main__height 3
#define list__width 22
#define list__height 19 
#define yx__main 0 
#define width__list2 22
#define heigth__list2 15
#define y__list2 3
#define x__list2 1
#define returnandexit__width 19
#define returnanfexit__heigth 3

//define values
int Fonction__Key__values;
int Key__values1;
int Key__values2;
int effect__leftandright = 0;
int effect__upanddown1 = 0;
int effect__upanddown2 = 0;
int effect__upanddown3 = 0;
int y__W__list2;
int x__W__lisr2;
int rtu_print_face;
int rtu_print_face2;

//declration of fonction
void F__Color(); 
int F__print_face();
void F__vertion_sponsor();
int F__face_about();
int F__about(int k);
int F__welcome(int *y1,int *x1);
void F__title(int y1,int x1,int *z1,int *r1);
void F__list(int z1,int r1);
int F__face_F1();;
int F__print_face2();
int F__print_list_using();
void F__print_list2_of_using();
void F__list2_of_using();
void F__how_use();
void F__returnandexit();

int main(){
    dubT:
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    F__Color();
    keypad(stdscr,TRUE);
    refresh();
    rtu_print_face = F__print_face();
    if(rtu_print_face == esc){
        endwin();
        return 0;
    }
    int rtu_print_face2 = F__print_face2();
    if(rtu_print_face2 == space)
        goto dubT;
    
    clear();
    endwin();
    return 0;
}

/*define colors*/
void F__Color(){
    init_pair(BW, COLOR_BLACK, COLOR_WHITE);
    init_pair(BLW, COLOR_BLUE, COLOR_WHITE);
    init_pair(BLB, COLOR_BLUE, COLOR_BLACK);
    init_pair(RB, COLOR_RED, COLOR_BLACK);
}


//face app fonction
int F__print_face(){
    dub:
    Key__values1 = curs_down;
    int k = 0;
    int b;
    do{
        int x1;
        int y1;
        int z1,r1;
        
        F__about(k); 
        F__welcome(&y1,&x1);
        F__title(y1,x1,&z1,&r1);
        F__list(z1,r1);
        F__vertion_sponsor();
        
        delwin(W__logo);
        delwin(W__about);
        delwin(W__welcome);
        delwin(W__list_of_using);
        delwin(W__vertion_sponsor);
            Key__values1 = getch();
            if(Key__values1 == curs_down || Key__values1 == curs_up)
                k++;
            if(k == 1)
                if(Key__values1 == enter){
                    clear();
                    refresh();
                    Key__values1 = F__face_about();
                    break;
                }
            if(k > 1)
                k = 0;

    }while( Key__values1 != enter &&  Key__values1 != esc && Key__values1 != f1);
    if(Key__values1 == f1){
        clear();
        refresh();
        Key__values1 = F__face_F1();;
    }
    if(Key__values1 == 0)
        goto dub;  
    if(Key__values1 == esc)
        return Key__values1;
    
}
//print the vertion and sponsor
void F__vertion_sponsor(){  
    W__vertion_sponsor = newwin(4,40,35,120);
    mvwprintw(W__vertion_sponsor,1,1,"version: 1.00.000.102.H_kakashi R&H");
    mvwprintw(W__vertion_sponsor,2, 1,"Sponsor: 3moke Uchiha_MADARA");
    wrefresh(W__vertion_sponsor);
}

//print the about content 
int F__face_about(){
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
            F__face_about();
        }
}

//print the about window 
int F__about(int k){
    W__about = newwin(3,11,1,155);
    if( k == 1)
        wbkgd(W__about, COLOR_PAIR(BW));
    
    box(W__about,0,0);
    wattron(W__about,A_BOLD);
    mvwprintw(W__about,1,1,"ABOUT (!)");
    wattroff(W__about,A_BOLD);
    wrefresh(W__about);
    return 0;
}

//print welcome
int F__welcome(int *y1,int *x1){
    int y,x; 
    W__welcome = newwin(4,12,3,8);
    wattron(W__welcome,A_BOLD);
    wprintw(W__welcome,"WELCOME; to,");
    wattroff(W__welcome,A_BOLD);
    wrefresh(W__welcome);
    getmaxyx(W__welcome,y,x);
    *y1 = y;
    *x1 = x;
    return 0;
}

//Calling the logo function from a logo_face lib
void F__title(int y1,int x1,int *z1,int *r1){
    ftitle_logo(8,14);
    int z,r;
    getyx(W__logo, z, r);
    *z1 = z;
    *r1 = r;
}

//useing list 
void F__list(int z1,int r1){
    W__list_of_using = newwin(4, 45,z1 + 14, r1 );
    wprintw(W__list_of_using,("!!!....press ('F1') how to use ;\n"));
    wprintw(W__list_of_using,("!!!....press ('ENTER') to continue ;\n"));
    wprintw(W__list_of_using,("!!!....press ('ESC') to exit ;\n"));
    wrefresh(W__list_of_using);
}

//print f1 content 
int F__face_F1(){
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
            F__face_F1();;
        }
}
int F__print_face2(){
    do{
        if(Key__values2 == curs_right)
            effect__leftandright++;
        else if(Key__values2 == curs_left)
            effect__leftandright--;
        if(effect__leftandright < 0)
            effect__leftandright = 2;
        else if(effect__leftandright > 2)
            effect__leftandright = 0;
        if(effect__leftandright == 0)
            if(Key__values2 == 258 || Key__values2 == 259)
                effect__upanddown1++;
        if(effect__upanddown1 > 1)
            effect__upanddown1 = 0;
        clear();
        refresh();
        F__print_list2_of_using();
        Key__values2 = getch();
        if(effect__leftandright == 0)
            if(effect__upanddown1 == 0)
                if(Key__values2 == enter){
                    Key__values2 = space;
                    break;
                }

    }while(Key__values2 != 10 && Key__values2 != 32 && Key__values2 != 27);
    clear();
    refresh();
    return Key__values2;
}

void F__print_list2_of_using(){
    W__main = newwin(main__height,main__width,yx__main,yx__main);
    wborder(W__main,'|','|','-','-','+','+','+','+');
    if(effect__leftandright != 0){
        F__list2_of_using();
        wattron(W__main,A_BOLD);
            mvwprintw(W__main,1,7,"main");
        wattroff(W__main,A_BOLD);
   }
   else if(effect__leftandright == 0){
        F__list2_of_using();
        wbkgd(W__main,COLOR_PAIR(BW));
        wattron(W__main,A_BOLD);
            mvwprintw(W__main,1,7,"main");
        wattroff(W__main,A_BOLD);
   }
    wrefresh(W__main);
}
void F__list2_of_using(){
        W__list2_of_using = newwin(heigth__list2,width__list2,y__list2,x__list2);
        if(effect__leftandright == 0){
            box(W__list2_of_using,0,0);
        }
        F__how_use();
        F__returnandexit();
        wrefresh(W__list2_of_using);
}
void F__how_use(){
    W__how_use = subwin(W__list2_of_using ,4 ,19 ,2 ,2 );
    if(effect__leftandright != 0){
        wclear(W__how_use);
    }
    else{
        mvwprintw(W__list2_of_using,2,1.5,"('ENTER'):to selcte");
        mvwprintw(W__list2_of_using,4,1.5,"('SPACE'):to returne");
        mvwprintw(W__list2_of_using,6,1.5,"('ESC'):to exit");
        wrefresh(W__how_use);
    }
}
void F__returnandexit(){
    W__return = subwin(W__list2_of_using,3,19,11,2);
    W__exit = subwin(W__list2_of_using,3,19,14,2);
    if(effect__leftandright != 0){
        wclear(W__exit);
        wclear(W__return);
    }
    else if(effect__leftandright == 0){
        if(effect__upanddown1 == 0){
                wattron(W__return,COLOR_PAIR(BLB));
                box(W__return,0,0);
                mvwprintw(W__return,1,1.5,"*.....return   ");
                wattroff(W__return,COLOR_PAIR(BLB)); 
                box(W__exit,0,0);
                mvwprintw(W__exit,1,1.5,"*.....exit   ");
                wrefresh(W__exit);    
            }  
        else if(effect__upanddown1 == 1){   
            box(W__return,0,0);
            mvwprintw(W__return,1,1.5,"*.....return");
            wattron(W__exit,COLOR_PAIR(BLB));
               box(W__exit,0,0);
               mvwprintw(W__exit,1,1.5,"*.....exit       ");
            wattroff(W__exit,COLOR_PAIR(BLB));
        }
    }    
}