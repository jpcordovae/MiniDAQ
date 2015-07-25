#include "frontend.hpp"
#include <sys/ioctl.h>
#include <signal.h>

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
  initscr();
  refresh();
  clear();

  int x,y;
  struct winsize ws;
  ioctl(0,TIOCGWINSZ, &ws);
  
  x = ws.ws_col;
  y = ws.ws_row;

  //MAIN_WINDOW = new_win(x,y,0,0);
  wresize(MAIN_WINDOW,y,x);
  wclear(MAIN_WINDOW);
  box(MAIN_WINDOW,0,0);
  wrefresh(MAIN_WINDOW);
  //doupdate();
  
  signal(SIGWINCH,resize_main_window);
}

void create_main_window()
{
  //WINDOW *my_win;
  int ch;

  initscr();			/* Start curses mode 		*/
  cbreak();			/* Line buffering disabled, Pass on
				 * everty thing to me 		*/
  keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

  printw("Press F1 to exit");
  
  refresh();

  int x,y;
  struct winsize ws;
  ioctl(0,TIOCGWINSZ, &ws);
  x = ws.ws_col;
  y = ws.ws_row;
  MAIN_WINDOW = new_win(y,x,0,0);
  
  signal(SIGWINCH,resize_main_window);
  
  while((ch = getch()) != KEY_F(1))
    {	
      switch(ch)
	{	
	case KEY_LEFT:
	  //delete_win(my_win);
	  //my_win = new_win(height, width, starty,--startx);
	  break;
	case KEY_RIGHT:
	  //delete_win(my_win);
	  //my_win = new_win(height, width, starty,++startx);
	  break;
	case KEY_UP:
	  //delete_win(my_win);
	  //my_win = new_win(height, width, --starty,startx);
	  break;
	case KEY_DOWN:
	  //delete_win(my_win);
	  //my_win = new_win(height, width, ++starty,startx);
	  break;	
	}
    }
		
  endwin();			/* End curses mode		  */
}
