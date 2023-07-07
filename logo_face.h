#include <ncurses.h> 
#include <locale.h>
#include "defining.h"

void ftitle_logo(int max_yw,int max_xw){
    wlogo = newwin(22,140,max_yw  ,max_xw + 6);
    wattron(wlogo,A_BOLD);
    wprintw(wlogo,"--The------------------------------------------------------------------------------------------------------------------------------\n\n");
    wprintw(wlogo,"                                                 iiii     kkkkkkkk                                lllllll                     \n");
    wprintw(wlogo,"                                                i::::i    k::::::k                                l:::::l                     \n");
    wprintw(wlogo,"                                                 iiii     k::::::k                                l:::::l                     \n");
    wprintw(wlogo,"                                                          k::::::k                                l:::::l                     \n");
    wprintw(wlogo,"    wwwwwww           wwwww           wwwwwww  iiiiiii     k:::::k    kkkkkkk   aaaaaaaaaaaaa      l::::l     aaaaaaaaaaaaa   \n");
    wprintw(wlogo,"     w:::::w         w:::::w         w:::::w   i:::::i     k:::::k   k:::::k    a::::::::::::a     l::::l     a::::::::::::a  \n");
    wprintw(wlogo,"      w:::::w       w:::::::w       w:::::w     i::::i     k:::::k  k:::::k     aaaaaaaaa:::::a    l::::l     aaaaaaaaa:::::a \n");
    wprintw(wlogo,"       w:::::w     w:::::::::w     w:::::w      i::::i     k:::::k k:::::k               a::::a    l::::l              a::::a \n");
    wprintw(wlogo,"        w:::::w   w:::::w:::::w   w:::::w       i::::i     k::::::k:::::k         aaaaaaa:::::a    l::::l       aaaaaaa:::::a \n");
    wprintw(wlogo,"         w:::::w w:::::w w:::::w w:::::w        i::::i     k:::::::::::k        aa::::::::::::a    l::::l     aa::::::::::::a \n");
    wprintw(wlogo,"          w:::::w:::::w   w:::::w:::::w         i::::i     k:::::::::::k       a::::aaaa::::::a    l::::l    a::::aaaa::::::a \n");
    wprintw(wlogo,"           w:::::::::w     w:::::::::w          i::::i     k::::::k:::::k     a::::a    a:::::a    l::::l   a::::a    a:::::a \n");
    wprintw(wlogo,"            w:::::::w       w:::::::w          i::::::i   k::::::k k:::::k    a::::a    a:::::a   l::::::l  a::::a    a:::::a \n");
    wprintw(wlogo,"             w:::::w         w:::::w           i::::::i   k::::::k  k:::::k   a:::::aaaa::::::a   l::::::l  a:::::aaaa::::::a \n");
    wprintw(wlogo,"              w:::w           w:::w            i::::::i   k::::::k   k:::::k   a::::::::::aa:::  al::::::l   a::::::::::aa:::a\n");
    wprintw(wlogo,"               www             www             iiiiiiii   kkkkkkkk    kkkkkkk   aaaaaaaaaa  aaa  allllllll    aaaaaaaaaa  aaaa\n\n                                                                                                                      .APPLICATION\n");
    wprintw(wlogo,"-----------------------------------------------------------------------------------------------------------------------------------\n");
    wrefresh(wlogo);

    





}


