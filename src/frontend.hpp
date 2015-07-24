#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>

extern WINDOW *MAIN_WINDOW;

WINDOW * new_win(int _height, int _width, int _starty, int _startx);
void delete_win(WINDOW *_local_win);
void create_main_window();
