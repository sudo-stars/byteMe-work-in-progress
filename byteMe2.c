#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>


char *ascii_title[] = {
 ███████████  █████ █████ ███████████ ██████████    ██████   ██████ ██████████
▒▒███▒▒▒▒▒███▒▒███ ▒▒███ ▒█▒▒▒███▒▒▒█▒▒███▒▒▒▒▒█   ▒▒██████ ██████ ▒▒███▒▒▒▒▒█
 ▒███    ▒███ ▒▒███ ███  ▒   ▒███  ▒  ▒███  █ ▒     ▒███▒█████▒███  ▒███  █ ▒ 
 ▒██████████   ▒▒█████       ▒███     ▒██████       ▒███▒▒███ ▒███  ▒██████   
 ▒███▒▒▒▒▒███   ▒▒███        ▒███     ▒███▒▒█       ▒███ ▒▒▒  ▒███  ▒███▒▒█   
 ▒███    ▒███    ▒███        ▒███     ▒███ ▒   █    ▒███      ▒███  ▒███ ▒   █
 ███████████     █████       █████    ██████████    █████     █████ ██████████
▒▒▒▒▒▒▒▒▒▒▒     ▒▒▒▒▒       ▒▒▒▒▒    ▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒▒     ▒▒▒▒▒ ▒▒▒▒▒▒▒▒▒▒ 
                                                                                                                                                           
};
int title_lines = 8;

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);

    start_color();
    init_pair(1, COLOR_MAGENTA, -1); // pink-ish text

    int row, col;
    getmaxyx(stdscr, row, col);
    int start_col = (col - strlen(ascii_title[0])) / 2;

    for(int i = 0; i < title_lines; i++) {
        attron(COLOR_PAIR(1));
        mvprintw(i+1, start_col, "%s", ascii_title[i]);
        attroff(COLOR_PAIR(1));
    }

    char top[3][256];

    while(1) {
        clear();


        mvprintw("<3");

        refresh();
        sleep(1);
    }

    endwin();
    return 0;
}
