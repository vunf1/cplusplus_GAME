/*GAME IDEIA TEST - BETTER IDEIA APPEAR - USING CURSES*/
#include <algorithm>
#include <sstream>
#include <iterator>//for split string into words separelaty to compare with a vector
#include <cstring>
#include <string>
#include <ncurses.h>
#include <locale.h>
#include "maps/surgeryFloor.h"

/* Use cordenates like [x,y] on the floor and z to indicate the floor ,Player start on 0,0,0 Up and Down (Floors), North(+y) , South(-y) , West(-x) , East(+x) , [-1,-1,z] unvaiable in all floors, when reach [x,y,z] position, that means a room, only on door location is posible to enter and LOOK for items after find n items can go up */
// REMEMBER c++ is static language , with that i mean all functions need to have a struct frist can't load last but last can load frist

///////////////////////////////////////// VARIABLES /////////////////////////////////////////////////

int coorX=0;
int coorY=0;
int coorZ=2; //set to surgery for testing purposes
bool counter;
bool running=true;




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





char lobby[13][63] =
{  //draws a  map with an array in order to create the lobby floor

    "                                                              ",
    " ____________________________________________________________ ",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|            lobby                                           |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|____________________________________________________________|"
};

  char childrenWard[13][63] =
{  //draws a  map with an array in order to create the childrenWard floor

    "                                                              ",
    " ____________________________________________________________ ",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|         childrenWard                                       |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|____________________________________________________________|"
};

  //toilet, development room, amphitheatre,
  char surgery[13][63] =
{  //draws a  map with an array in order to create the surgery floor

    "                                                              ",
    " ____________________________________________________________ ",
    "|             |          |                 |          |      |",
    "|             |          |                 |          |      |",
    "|             |          |                 |          |      |",
    "|             |====  ====|                 |====  ====|      |",
    "|                                                            |",
    "|                                                         ___|",
    "|                                                            |",
    "|       /  \\                |====  ====|                  ___|",
    "|      |    |               |          |                     |",
    "|_______\\__/________________|__________|_____________________|"
};

  char psychiatric[13][63] =
{  //draws a  map with an array in order to create the psychiatric floor

    "                                                              ",
    " ____________________________________________________________ ",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|            psychiatric                                     |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|____________________________________________________________|"
};

  char basement[13][63] =
{  //draws a  map with an array in order to create the basement floor

    "                                                              ",
    " ____________________________________________________________ ",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|            basement                                        |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|                                                            |",
    "|____________________________________________________________|"
};

short int playerX = 1; // sets player starting position
short int playerY = 2; // sets player starting position
short int x,y;

void drawMap(auto& map)//Joao 
{
  /*Print map on console*/
    getmaxyx(stdscr,y,x);

    map[playerY][playerX]='x';
    noecho();

    mvprintw(0,x/3,"Welcome to floor %i ",coorZ); //iqra contributed in the spelling changes of this code line

  for (int i = 0; i < 13; i++) {
    // addstr is nCurses equiv
      // of cout or printw
      move(i+2,x/5);
      setlocale(LC_ALL, "");

      addstr(map[i]);
      addstr("\n");
    }
  checkRoom(playerX, playerY);
}

void drawRooms(auto& map)
{


}

void storyONboard(){//Joao

  getmaxyx(stdscr,y,x);
  if(playerX==34 && playerY==7){

  mvprintw(15,0,"You walk over and enter the room across from you, inside you are met with a creepy sight.\n Countless damaged dolls stare back at you with lifeless eyes, all of them in different stages of decay and wear and tear.\n Suppressing a shiver you walk further inside and glance around.");
  mvprintw(19,x/5,"Y =  What will you do? Search the room more closely or leave?");
  }
}


void keyPosition(){//Joao

  mvprintw(1,0,"X = %i ",playerX);
  mvprintw(1,8,"Y = %i ",playerY);
}


bool getUserInput(auto& map)//Joao && Diogo
{
	/*Accept arrow from user as input and move player thorw the map other input grab kwyword and perform same tasks*/
  if(getch() == '\033')
  {
    getch();
    noecho();
    switch(getch())
    {
      case 'A':
        if (map[playerY-1][playerX] == ' ') 
        {
          map[playerY][playerX] = ' ';
          playerY--;
        }
      break;

      case 'B':
        if (map[playerY+1][playerX] == ' ') 
        {
          map[playerY][playerX] = ' ';
          playerY++;
        }
      break;

      case 'C':
        if (map[playerY][playerX+1] == ' ')
        {
          map[playerY][playerX] = ' ';
          playerX++;
        }
      break;

      case 'D':
        if (map[playerY][playerX-1] == ' ') 
        {
          map[playerY][playerX] = ' ';
          playerX--;
        }
      break;
    }
  }
  else
  {
    //If the input is not one of the arrows.
    playerX--;
    string sentence;
    getline(cin, sentence);
    //keywordChecker(sentence);

  }
}

// Main game update
void update()//Joao && Diogo
{
  switch(coorZ)
  {
    case -1:
      drawMap(basement);
      getUserInput(basement);
      // checkCoord
      refresh();
      clear();
      break;

    case 0:
      drawMap(lobby); 
      getUserInput(lobby);
      refresh();
      clear();
      break;

    case 1:
      drawMap(psychiatric);
      getUserInput(psychiatric);
      refresh();
      clear();
      break;

    case 2:
      keyPosition();
      drawMap(surgery);
      getUserInput(surgery);
      refresh();
      clear();
      break;

    case 3:
      drawMap(childrenWard);
      storyONboard();
      getUserInput(childrenWard);
      refresh();
      clear();
      break;
  }

  
}


void endGame(){//Joao

    mvprintw(0,x/4," ======================================");
    mvprintw(1,x/4," @       YOU  FINISHED  THIS          @");
    mvprintw(2,x/4," @                LEVEL               @");
    mvprintw(3,x/4,"        CONGRATULATIONS %s             ",detailInfo[0].c_str()	);
    mvprintw(4,x/4," @     YOU WILL RECEIVE 20 POINTS    @");
    mvprintw(5,x/4," @             AND LEVEL UP           @");
    mvprintw(6,x/4," ======================================");
    getch();
}



string checkKeyWord(auto& path2)
{//Joao

	/*Accept the user input all line and convert into a vector to compare to other vector were are the possible paths/commands to use on the game if none exist send false as response*/

	vector<string> path2G;
	counter=0;

	istringstream iss(path2);
	    copy(istream_iterator<string>(iss),istream_iterator<string>(),     back_inserter(path2G));

	vector<string> possiblePath={string("north"),string("south"),string("west"),string("east"),string("up"),string("down")};


	for(int x=0; x <= 5;x++)
	{
		if(find(path2G.begin(), path2G.end(), possiblePath[x]) != path2G.end())
		{
			counter=1;
			return possiblePath[x].c_str();
		}

	}
	if(counter!=0){
		return string("false");
	}

}


void floor_3() //Joao
{ 
  // Initate nCurses display
  initscr();
  curs_set(0); //Cursor visibility , 0 none - 1 visible - 2 barely visible
  while( running== true ) {

    //keyPosition();
    update();
    }
  // End nCurses display
  endwin();
}