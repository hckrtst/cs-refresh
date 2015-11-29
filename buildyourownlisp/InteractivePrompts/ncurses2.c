#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define MATH_PI 3.1418


static struct timespec ts = {.tv_sec = 0, .tv_nsec = 100000000};

void draw_shape() {
    int delta = 0.1;
    for (float rad = 0.0f; rad < 25;  rad=rad+0.1) {
        delta+=1;
        mvaddch(25 + 11*sin(2*rad), 75 + 48*cos(rad), 'o');
        refresh();
        mvprintw(50,50,"Radians : %2.3f", rad); 
        refresh();
        nanosleep(&ts, NULL);
    }
}

int main(int argc, char **argv) {
    // basic setup
    initscr();
    raw();

    // seed random
    srand(time(NULL));
    int max = 20;
    
    int row, col;
    getmaxyx(stdscr, row, col);
    

    while(1) {
        max--;
        float x = rand() % row;
        float y = rand() % col;
        mvprintw(x, y, "meow! at (%2.2f ,%2.2f)", x, y);
        refresh();
            
        if (nanosleep(&ts, NULL) < 0) {
            printw("Adios muchachos!");
            break;
        }
        if (max < 0) break;
    }

    draw_shape();

    sleep(3);
    endwin();
    return 0;
}
