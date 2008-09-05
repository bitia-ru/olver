#include "addon.h"
#include <string.h>

int main()
{
char *str="aaa\bccc";
char buff[128];
char *ti;
    initscr();
    printw("before dump\n");
    refresh();
    Dump_Contents(0, 0, 0, 0);
    endwin();

    return 0;
}

