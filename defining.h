#include <ncurses.h>



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