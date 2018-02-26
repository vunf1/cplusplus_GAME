
#include <iostream>
#include "libsqlite3/libsqlite.hpp" //DB Library SQLite3

#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <vector>
using namespace std;

/* FUTURE USE : ORGANIZE FUNCTION IN IT*/
#include <ncurses.h>



bool running = true;
short int playerX = 2; // sets player starting position
short int playerY = 2; // sets player starting position
short int x,y;
char map[13][43] =
{  //draws a  map with an array in order to create the maze

    "                                       ",
    " _____________________________________ ",
    "| x                                   |",
    "|                                     |",
    "|                                 ====|",
    "|                                 ║   |",
    "|                                 ║   |",
    "|                                     |",
    "|                                 ====|",
    "|                                     |",
    "|_____________________________________|"};







// Draw Map
// 
void drawMap()//Joao
{
  /*Print map on console*/
    getmaxyx(stdscr,y,x);
    noecho();
    mvprintw(0,x/3,"Welcome to thitd floor");
  for (int i = 0; i < 13; i++) {
    // addstr is nCurses equiv
      // of cout or printw
      move(i+2,x/5);
      addstr(map[i]);
      addstr("\n");
    }
}



void keyPosition(){

  mvprintw(6,3,"X = %s ",playerX);
  mvprintw(7,3,"Y = %s ",playerY);

}

// Detect Char input
// and move player in direction
bool getUserInput()//Joao
{

char userInput = getch();//grab key pressed by user
    
  if (userInput == 'w') {
    short int playerY2 = playerY - 1;
    if (map[playerY2][playerX] == ' ') {
      map[playerY][playerX] = ' ';
      playerY--;
      map[playerY][playerX] = 'x';
    }
  }

  if (userInput == 'a') {
    short int playerX2 = playerX - 1;
    if (map[playerY][playerX2] == ' ') {
      map[playerY][playerX] = ' ';
      playerX--;
      map[playerY][playerX] = 'x';
    }
  }

  if (userInput == 's') {
    short int playerY2 = playerY + 1;
    if (map[playerY2][playerX] == ' ') {
      map[playerY][playerX] = ' ';
      playerY++;
      map[playerY][playerX] = 'x';
    }
  }

  if (userInput == 'd') {
    short int playerX2 = playerX + 1;
    if (map[playerY][playerX2] == ' ') {
      map[playerY][playerX] = ' ';
      playerX++;
      map[playerY][playerX] = 'x';
    }
  }
  ;

   /* if((playerY==6&&playerX==3)||(playerY==10&&playerX==2)){
        
        
        endGame(vector);
        running=false;
    }
*/

}

// Main game update
void update()//Joao
{

  drawMap();
  getUserInput();
  refresh();
  clear();
}

void endGame(auto& info){//Joao


    transform(info.begin(),info.end(),info.begin(),::toupper);
    mvprintw(0,x/4," ======================================");
    mvprintw(1,x/4," @         YOU  FINISH  THE           @");
    mvprintw(2,x/4," @              GAME                  @");
    mvprintw(3,x/4,"    CONGRATULATIONS %s                 ",info[0].c_str());
    mvprintw(4,x/4," @    YOU WILL RECEIVE 100 POINTS     @");
    mvprintw(5,x/4," @         AND LEVEL UP               @");
    mvprintw(6,x/4," ======================================");
    getch();

}

void floor_3(auto& vector) //Joao
{
  // Initate nCurses display


  initscr();
  keyPosition();
  while( running== true ) {

    update();

       
      }
  // End nCurses display
  endwin();
}
