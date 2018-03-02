

/* FUTURE USE : ORGANIZE FUNCTION IN IT*/
#include <ncursesw/ncurses.h>//LOAD ncurses library
#include <iterator>
#include <algorithm>
#include <sstream>


//IDEAL SIZE
#define WIDTH 80
#define HEIGHT 24 


//#INCLUDE "FINAL_LEVEL_MAZE.H" THIS FILE HAVE ALMOST ALL INFO ABOUT NCURSES CODE YOU WILL NEED

bool running = true;
short int playerX = 2; // sets player starting position
short int playerY = 2; // sets player starting position
short int x,y;


void keycode(){//Joao
  /*TEST porpose - SHOW KEY pressed by user (decimal/string value)*/


    noecho(); //dont show on the printw the key pressed
    raw(); //instead of wait he direct inject (theory), good for arrow keys,TRUE arrow keys shutdown the program
    int key;
    //27 is the keycode for ESC 
    printw("Press any key to know the keycode ");
    while((key=wgetch(stdscr))!=27){

        mvprintw(0,0,"Keycode %d and the character inputed is %c",key,key);//%d for decimal keycode and %c for character key

        mvprintw(1,0,"Press any key to know the keycode ");
        refresh();
    }


}

char map[13][63] =
{  //draws a  map with an array in order to create the maze

    "                                                              ",
    " ____________________________________________________________ ",
    "| x                                                          |",
    "|                                                            |",
    "|                                                            |",
    "|                                                    \u02E9====|",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
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
      move(i+2,x/6);
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
  /*Test porpose - show player position on window*/

  mvprintw(1,0,"X = %i ",playerX);
  mvprintw(1,8,"Y = %i ",playerY);

}

// Detect Char input
// and move player in direction





int getUserInput()//Joao
{

char userInput = getch();//grab key pressed by user
    /*
int ch = wgetch(stdscr);
     switch (ch) 
     {
          case 259: //user pressed up arrow  
             {short int playerY2 = playerY - 1;
                           if (map[playerY2][playerX] == ' ') 
                           {
                             map[playerY][playerX] = ' ';
                             playerY--;
                             map[playerY][playerX] = 'x';
                           }}
          case 260:  // user pressed left arrow key 
             {short int playerX2 = playerX - 1;
                           if (map[playerY][playerX2] == ' ') 
                           {
                             map[playerY][playerX] = ' ';
                             playerX--;
                             map[playerY][playerX] = 'x';
                           }}
          case 261:  // user pressed right arrow key 
             {short int playerX2 = playerX + 1;
                           if (map[playerY][playerX2] == ' ') 
                           {
                             map[playerY][playerX] = ' ';
                             playerX++;
                             map[playerY][playerX] = 'x';
                           }}
          case 258:  // user pressed  down arrow key 
             {short int playerY2 = playerY + 1;
                           if (map[playerY2][playerX] == ' ') 
                           {
                             map[playerY][playerX] = ' ';
                             playerY++;
                             map[playerY][playerX] = 'x';
                           }}
     }
*/












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

}
  

// Main game update
void update()//Joao
{

  drawMap();
  getUserInput();
  refresh();
  clear();
}

void endFloor(){//Joao


    getmaxyx(stdscr,y,x);
    mvprintw(0,x/4," ======================================");
    mvprintw(1,x/4," @         YOU  FINISH  THIS           @");
    mvprintw(2,x/4," @       FLOOR CALLED TOP LEVEL        @");
    mvprintw(3,x/4,"    CONGRATULATIONS %s                 ",detailInfo[0].c_str());
    mvprintw(4,x/4," @      YOU WILL RECEIVE 20 POINTS     @");
    mvprintw(5,x/4," @          AND LEVEL UP               @");
    mvprintw(6,x/4," ======================================");
    getch();
    addScore(detailInfo[0],20);
    refresh();
    clear();

}

void floor_3() //Joao
{
    
  // Initate nCurses display
setlocale(LC_ALL, "");
  initscr();
    keypad(stdscr, TRUE);// It enables the reading of function/special keys like F1, F2, arrow keys etc. 
    
    //keycode();
    
  while( running== true ) { 

    keyPosition();
    storyONboard();//story
    update();//map load
       
      }
  endwin();
  // End nCurses display
}
