

/* FUTURE USE : ORGANIZE FUNCTION IN IT*/
#include <ncurses.h>//LOAD ncurses library
#include <iterator>
#include <algorithm>
#include <sstream>
//#INCLUDE "FINAL_LEVEL_MAZE.H" THIS FILE HAVE ALMOST ALL INFO ABOUT NCURSES CODE YOU WILL NEED

bool running = true;
short int playerX = 2; // sets player starting position
short int playerY = 2; // sets player starting position
short int x,y;

int resizeterm(int lines, int columns);//Create a bug on terminal !DONT WORK , maybe futher use
char map[13][63] =
{  //draws a  map with an array in order to create the maze

    "                                                              ",
    " ____________________________________________________________ ",
    "| x                                                          |",
    "|                                                            |",
    "|                                                        ====|",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                        ====|",
    "|                                                            |",
    "|                                                            |",
    "|____________________________________________________________|"};







// Draw Map
// 
void drawMap()//Joao 
{
  /*Print map on console*/
    getmaxyx(stdscr,y,x);
    noecho();
    mvprintw(0,x/3,"Welcome to third floor"); //iqra contributed in the spelling changes of this code line
  for (int i = 0; i < 13; i++) {
    // addstr is nCurses equiv
      // of cout or printw
      move(i+2,x/5);
      addstr(map[i]);
      addstr("\n");
    }
}



void storyONboard(){

  getmaxyx(stdscr,y,x);
  if(playerX==34 && playerY==7){

  mvprintw(15,0,"You walk over and enter the room across from you, inside you are met with a creepy sight.\n Countless damaged dolls stare back at you with lifeless eyes, all of them in different stages of decay and wear and tear.\n Suppressing a shiver you walk further inside and glance around.");
  mvprintw(19,x/5,"Y =  What will you do? Search the room more closely or leave?");


  }
}

void keyPosition(){

  mvprintw(1,0,"X = %i ",playerX);
  mvprintw(1,8,"Y = %i ",playerY);

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


}

// Main game update
void update()//Joao
{

  drawMap();
  getUserInput();
  refresh();
  clear();
}

void endGame(){//Joao


    mvprintw(0,x/4," ======================================");
    mvprintw(1,x/4," @         YOU  FINISH  THE           @");
    mvprintw(2,x/4," @              GAME                  @");
    mvprintw(3,x/4,"    CONGRATULATIONS %s                 ",detailInfo[0].c_str());
    mvprintw(4,x/4," @    YOU WILL RECEIVE 100 POINTS     @");
    mvprintw(5,x/4," @         AND LEVEL UP               @");
    mvprintw(6,x/4," ======================================");
    getch();

}

void floor_3() //Joao
{
    
  // Initate nCurses display


  initscr();
  while( running== true ) {

    keyPosition();
    storyONboard();
    update();
       
      }
  // End nCurses display
  endwin();
}
