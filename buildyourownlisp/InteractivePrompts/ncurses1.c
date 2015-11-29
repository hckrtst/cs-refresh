#include <ncurses.h>

int main(int argc, char **argv) {
    initscr();
    printw("Hello kitty\n");
    refresh();
    getch();
    endwin();

    return 0;
}
