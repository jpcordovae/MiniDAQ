#include "frontend.hpp"

WINDOW *MAIN_WINDOW;

WINDOW* new_win(int _height, int _width, int _starty, int _startx)
{
  WINDOW * new_win = newwin(_height, _width, _starty, _startx);
  box(new_win,0,0);
  wrefresh(new_win);
  return new_win;
}

void delete_win(WINDOW *_local_win)
{
  wborder(_local_win,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(_local_win);
  delwin(_local_win);
}

void resize_main_window(int dummy)
{
  signal(SIGWINCH,SIG_IGN);
  endwin();
  //initscr();
  clear();
  int lines = atoi(getenv("LINES"));
  int columns = atoi(getenv("COLUMNS"));
  wresize(MAIN_WINDOW,lines,columns);
  refresh();
  signal(SIGWINCH,resize_main_window);
}

void create_main_window()
{
  WINDOW *my_win;
  int startx, starty, width, height;
  int ch;

  initscr();			/* Start curses mode 		*/
  cbreak();			/* Line buffering disabled, Pass on
				 * everty thing to me 		*/
  keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

  height = 3;
  width = 10;
  starty = (LINES - height) / 2;	/* Calculating for a center placement */
  startx = (COLS - width) / 2;	/* of the window		*/
  printw("Press F1 to exit");
  refresh();
  my_win = new_win(height, width, starty, startx);

  while((ch = getch()) != KEY_F(1))
    {	switch(ch)
	{	case KEY_LEFT:
	    delete_win(my_win);
	    my_win = new_win(height, width, starty,--startx);
	    break;
	case KEY_RIGHT:
	  delete_win(my_win);
	  my_win = new_win(height, width, starty,++startx);
	  break;
	case KEY_UP:
	  delete_win(my_win);
	  my_win = new_win(height, width, --starty,startx);
	  break;
	case KEY_DOWN:
	  delete_win(my_win);
	  my_win = new_win(height, width, ++starty,startx);
	  break;	
	}
    }
		
  endwin();			/* End curses mode		  */
}
