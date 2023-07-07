#include <ncurses.h> 
#include <locale.h>
#include "defining.h"

void ftitle_logo(int max_yw,int max_xw){
    W__logo = newwin(22,140,max_yw  ,max_xw + 6);
    wattron(W__logo,A_BOLD);
    wprintw(W__logo,"--The------------------------------------------------------------------------------------------------------------------------------\n\n");
    wprintw(W__logo,"                                                 iiii     kkkkkkkk                                lllllll                     \n");
    wprintw(W__logo,"                                                i::::i    k::::::k                                l:::::l                     \n");
    wprintw(W__logo,"                                                 iiii     k::::::k                                l:::::l                     \n");
    wprintw(W__logo,"                                                          k::::::k                                l:::::l                     \n");
    wprintw(W__logo,"    wwwwwww           wwwww           wwwwwww  iiiiiii     k:::::k    kkkkkkk   aaaaaaaaaaaaa      l::::l     aaaaaaaaaaaaa   \n");
    wprintw(W__logo,"     w:::::w         w:::::w         w:::::w   i:::::i     k:::::k   k:::::k    a::::::::::::a     l::::l     a::::::::::::a  \n");
    wprintw(W__logo,"      w:::::w       w:::::::w       w:::::w     i::::i     k:::::k  k:::::k     aaaaaaaaa:::::a    l::::l     aaaaaaaaa:::::a \n");
    wprintw(W__logo,"       w:::::w     w:::::::::w     w:::::w      i::::i     k:::::k k:::::k               a::::a    l::::l              a::::a \n");
    wprintw(W__logo,"        w:::::w   w:::::w:::::w   w:::::w       i::::i     k::::::k:::::k         aaaaaaa:::::a    l::::l       aaaaaaa:::::a \n");
    wprintw(W__logo,"         w:::::w w:::::w w:::::w w:::::w        i::::i     k:::::::::::k        aa::::::::::::a    l::::l     aa::::::::::::a \n");
    wprintw(W__logo,"          w:::::w:::::w   w:::::w:::::w         i::::i     k:::::::::::k       a::::aaaa::::::a    l::::l    a::::aaaa::::::a \n");
    wprintw(W__logo,"           w:::::::::w     w:::::::::w          i::::i     k::::::k:::::k     a::::a    a:::::a    l::::l   a::::a    a:::::a \n");
    wprintw(W__logo,"            w:::::::w       w:::::::w          i::::::i   k::::::k k:::::k    a::::a    a:::::a   l::::::l  a::::a    a:::::a \n");
    wprintw(W__logo,"             w:::::w         w:::::w           i::::::i   k::::::k  k:::::k   a:::::aaaa::::::a   l::::::l  a:::::aaaa::::::a \n");
    wprintw(W__logo,"              w:::w           w:::w            i::::::i   k::::::k   k:::::k   a::::::::::aa:::  al::::::l   a::::::::::aa:::a\n");
    wprintw(W__logo,"               www             www             iiiiiiii   kkkkkkkk    kkkkkkk   aaaaaaaaaa  aaa  allllllll    aaaaaaaaaa  aaaa\n\n                                                                                                                      .APPLICATION\n");
    wprintw(W__logo,"-----------------------------------------------------------------------------------------------------------------------------------\n");
    wrefresh(W__logo);

    





}


