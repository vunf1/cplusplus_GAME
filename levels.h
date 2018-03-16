/*GAME IDEIA TEST - BETTER IDEIA APPEAR - USING CURSES*/
#include <algorithm>
#include <sstream>
#include <iterator>//for split string into words separelaty to compare with a vector
#include <cstring>
#include <string>
#include <locale.h>

/* Use cordenates like [x,y] on the floor and z to indicate the floor ,Player start on 0,0,0 Up and Down (Floors), North(+y) , South(-y) , West(-x) , East(+x) , [-1,-1,z] unvaiable in all floors, when reach [x,y,z] position, that means a room, only on door location is posible to enter and LOOK for items after find n items can go up */
// REMEMBER c++ is static language , with that i mean all functions need to have a struct frist can't load last but last can load frist

///////////////////////////////////////// VARIABLES /////////////////////////////////////////////////

int coorX=0;
int coorY=0;
int coorZ=3;
bool counter;
bool running=true;
int currentRoom=-1;

short int playerX = 3; // sets player starting position
short int playerY = 2; // sets player starting position
short int x,y;

vector<string> floorNames={string("Basement"),string("Lobby"),string("Psychiatric"),string("Surgery"),string("Pediatrics")};





void endFloor(){//Joao

    clear();
    refresh();
	  noecho();
    getmaxyx(stdscr,y,x);
    

    attron(COLOR_PAIR(coorZ));
    mvprintw(3,x/5,"                                       ");

    attroff(COLOR_PAIR(coorZ));

    mvprintw(4,x/5," \a           YOU  FINISHED              ");
    mvprintw(5,x/5,"            %s FLOOR                 ",floorNames[coorZ+1].c_str());
    mvprintw(6,x/5,"        CONGRATULATIONS %s             ",detailInfo[0].c_str());
    mvprintw(7,x/5,"       YOU WILL RECEIVE 20 POINTS      ");
    mvprintw(8,x/5,"              AND LEVEL UP             ");

    attron(COLOR_PAIR(coorZ));
    mvprintw(10,x/5,"        PRESS ENTER TO CONTINUE...     ");
    attroff(COLOR_PAIR(coorZ));

    addScore(detailInfo[0],20);
    upLevel(detailInfo[0],1);

    getch();
    refresh();
    clear();
}





#include "maps/psychiatricWard.h"
#include "maps/childrenWard.h"
#include "maps/surgeryandlobbyFloors.h"

void keycode(){//Joao
  /*TEST porpose - SHOW KEY pressed by user (decimal/string value)*/

    noecho(); //dont show on the printw the key pressed
     //raw(); instead of wait he direct inject (theory), good for arrow keys,TRUE arrow keys shutdown the program
    int key;
    //27 is the keycode for ESC 
    printw("Press any key to know the keycode ");
    while((key=wgetch(stdscr))!=27){

        mvprintw(0,0,"Keycode %d and the character inputed is %c",key,key);//%d for decimal keycode and %c for character key

        mvprintw(1,0,"Press any key to know the keycode ");
        refresh();
    }


}






  char childrenWard[13][63] =
{  //draws a  map with an array in order to create the childrenWard floor

    "                                                              ",
    " ____________________________________________________________ ",
    "| |          |           |          |                  |     |",
    "| |          |           |                             |     |",
    "| |          |           |          |                  |     |",
    "| |**  *************   **            ******************      |",
    "| |                                                          |",
    "| |                                          ====/  \\        |",
    "|+++__++ ++  +++                                             |",
    "|       +       +             ********_*     ====\\  /        |",
    "|       +       +            (          )             |   |  |",
    "|_______+_______+____________(__________)_____________|___|__|"
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
    "|                                                          ==|",
    "|                                                          / |",
    "|       /  \\                |====  ====|                   ==|",
    "|      |    |               |          |                     |",
    "|_______\\__/________________|__________|_____________________|"
};

  char psychiatric[13][63] =
{  //draws a  map with an array in order to create the psychiatric floor

    "                                                              ",
    " ____________________________________________________________ ",
    "|              |                        |    |         |     |",
    "|              |                        |    |               |",
    "|              |                        |    |=========|     |",
    "|=====   ======|                        |                    |",
    "|                                                            |",
    "|                                                            |",
    "|===  =======  =======  =====  =====  ==|                 ---|",
    "|        |        |       |      |      |                    |",
    "|        |        |       |      |      |                 ---|",
    "|________|________|_______|______|______|____________________|"
};

char lobby[13][63] =
{  //draws a  map with an array in order to create the lobby floor

    "                                                              ",
    " ___________________________/\\/\\/\\/\\__________________________",
    "|                                                            |",
    "|                                                         ___|",
    "|                                                            |",
    "|                                                         ___|",
    "|                                                            |",
    "|                                                            |",
    "|--------------------------        --------------------------|",
    "|                         |        |                         |",
    "|                         \\        /                         |", //llifts
    "|_________________________|========|_________________________|"
};

  char basement[13][63] =
{  //draws a  map with an array in order to create the basement floor

    " ____________________________________________________________ ",
    "|     |        |                             |         |     |",
    "|     |        |                             |         |     |",
    "|                                            |===   ===|     |",
    "|             ________                                       |",
    "|             |      |                                       |",
    "|             |______|                                       |",
    "|===  ====|                                                  |",
    "|         |                                         //=   =\\|",
    "|         |                                        ||       ||",
    "|_________|________________________________________||_______||"

};

void drawMap(auto& map)//Joao 
{
  /*Print map on console*/
    getmaxyx(stdscr,y,x);

    map[playerY][playerX]='x';
    noecho();
    
    mvprintw(0,x/3,"Welcome to %i Floor (%s) ",coorZ,floorNames[coorZ+1].c_str()); //iqra contributed in the spelling changes of this code line

  for (int i = 0; i < 13; i++) {
    // addstr is nCurses equiv
      // of cout or printw
      move(i+2,x/7);

      addstr(map[i]);
      addstr("\n");
    }
  checkRoom(playerX, playerY);
}




void keyPosition(){//Joao
  mvprintw(1,15,"X = %i %i",playerX,currentRoom);
  mvprintw(1,25,"  Y = %i ",playerY);
}


string getUserInput(auto& map)//Joao && Diogo
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
     echo();
    	getmaxyx(stdscr,y,x);
	    string sentence;

		attron(COLOR_PAIR(5));
	   	   mvprintw(14,(x/8)+2,"Insert your command: ");
		attroff(COLOR_PAIR(5));
	   	   sentence=get_line();
	   	   transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    if(coorZ==3){//Joao
    	//Keyword Handle for floor 3

	   	   refresh();
		   	   if(keywordChecker4children(sentence)==string("look") || keywordChecker4children(sentence)==string("take") || keywordChecker4children(sentence)==string("exit") || keywordChecker4children(sentence)==string("help") || keywordChecker4children(sentence)==string("check") || keywordChecker4children(sentence)==string("down"))
		   	   {

			   	   	if(keywordChecker4children(sentence)==string("look")){
			   	   		game.itensLook(currentRoom,coorZ);
			   	   	};


			   	   if(keywordChecker4children(sentence)==string("take")){//show itens on that room
			   	   //done

			   	   		game.takeItem(currentRoom,coorZ);
			   	   };



			   	   if(keywordChecker4children(sentence)==string("exit")){
			   	   	//exit go to main menu
			   	    running=false;
			   	   };


					if(keywordChecker4children(sentence)==string("help")){
						//"help" handle function
						//Done
						game.helpBoard();
						
			   	   };



					if(keywordChecker4children(sentence)==string("check")){
						//"help" handle function
						
						game.checkBoard();
						
			   	   };
					if(keywordChecker4children(sentence)==string("down")){
						//"help" handle function
						
						game.finishFloor();
						
			   	   };






		   	   }else{game.invalidInput();}

    }

    if(coorZ==2){//Diogo
      echo();
      getmaxyx(stdscr,y,x);

	    string sentence;

	   
      attron(COLOR_PAIR(5));
      mvprintw(14,(x/8)+2,"Insert your command: ");
      attroff(COLOR_PAIR(5));

      sentence=get_line();
      refresh();

      for(int idx=0; idx<3; idx++)
      {
        bool trigger=false;
        switch(idx)
        {
          case 0:
          trigger = keyWordChecker(sentence, "exit");
          if(trigger)
            running=false;
          break;

          case 1:
          trigger = keyWordChecker(sentence, "look");
          if(trigger)
            switch(currentRoom)
            {
              case 1:
                refresh();

                attron(COLOR_PAIR(2));
                mvprintw(y/8,(x/3),"There are no items on this room");
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(0));
                mvprintw((y/8)+1,(x/2)-5,"Try other room");
                attroff(COLOR_PAIR(0));

                getch();
                clear();
              break;

              case 2:
                refresh();

                attron(COLOR_PAIR(2));
                mvprintw(y/8,(x/3),"There are no items on this room");
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(0));
                mvprintw((y/8)+1,(x/2)-5,"Try other room");
                attroff(COLOR_PAIR(0));

                getch();
                clear();
              break;

              case 3:
                refresh();

                attron(COLOR_PAIR(2));
                mvprintw(y/8,(x/3),"There are no items on this room");
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(0));
                mvprintw((y/8)+1,(x/2)-5,"Try other room");
                attroff(COLOR_PAIR(0));

                getch();
                clear();
              break;

              case 4:
                refresh();

                attron(COLOR_PAIR(3));
                mvprintw(y/8,(x/3)+4,"You can see something in the corner of the room");
                attroff(COLOR_PAIR(3));


                attron(COLOR_PAIR(2));
                mvprintw((y/8)+1,(x/3)-9,"It's a lever!");
                attroff(COLOR_PAIR(2));
                mvprintw((y/8)+1,(x/3),"    - Would you like to pull the lever? (y/n)");
                char answer;
                answer = getch();
                if(answer=='Y' && answer == 'y')
                  lever=true;

                getch();
                clear();
              break;

              case -1:
                refresh();

                attron(COLOR_PAIR(3));
                mvprintw(y/8,x/6,"Nothing to see on the hallway! Try entering the rooms.");
                attroff(COLOR_PAIR(3));

                getch();
                clear();
              break;

              default:
              break;
              }
            break;

            case 2:
            trigger = keyWordChecker(sentence, "down");
              if(trigger)
                if(lever==true)
                  coorZ=1;

            break;
        }
      }
    }

    if(coorZ== 1){//Luke

    	//Keyword Handle for floor 1

    	
    }
    if(coorZ== 0){//Diogo
      echo();
      getmaxyx(stdscr,y,x);

      string sentence;

     
      attron(COLOR_PAIR(5));
      mvprintw(14,(x/8)+2,"Insert your command: ");
      attroff(COLOR_PAIR(5));

      sentence=get_line();
      refresh();

      for(int idx=0; idx<3; idx++)
      {
        bool trigger=false;
        switch(idx)
        {
          case 0:
          trigger = keyWordChecker(sentence, "exit");
          if(trigger)
            running=false;
          break;

          case 1:
          trigger = keyWordChecker(sentence, "look");
          if(trigger)
            switch(currentRoom)
            {
              case -1:
                refresh();

                attron(COLOR_PAIR(3));
                mvprintw(y/8,x/6,"Nothing to see on the hallway! Try entering the rooms.");
                attroff(COLOR_PAIR(3));

                getch();
                clear();
              break;

              default:
              break;
              }
            break;

            case 2:
            trigger = keyWordChecker(sentence, "open");
              if(trigger)
                if(lever==true)
                  coorZ=1;

            break;
        }
      }
    	
    }
    if(coorZ== -1){//Mariya & Iqra

    	//Keyword Handle for floor -1

    	
    }


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
      checkArea();
      getUserInput(psychiatric);
      refresh();
      clear();
      break;

    case 2:
      drawMap(surgery);
      getUserInput(surgery);
      refresh();
      clear();
      break;

    case 3:
    playerItemBoard(detailInfo[0]);
    playerInfo2vector(detailInfo[0]);
      drawMap(childrenWard);
      storyONboard();
      getUserInput(childrenWard);
      refresh();
      clear();
      break;
  }

  
}



/*
string checkKeyWord(auto& path2)
{//Joao

	/*Accept the user input all line and convert into a vector to compare to other vector were are the possible paths/commands to use on the game if none exist send false as response*/
/*
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

}*/


void INTRO(){//Joao

getmaxyx(stdscr,y,x);
refresh();
noecho();
		mvprintw(y/10,(x/8)+13,"Welcome");
	attron(COLOR_PAIR(3));
		mvprintw((y/10),(x/8)+21,"%s",detailInfo[0].c_str());
	attroff(COLOR_PAIR(3));

		mvprintw(y/10,(x/8)+21+detailInfo[0].length()," to ASAP Game");



		mvprintw((y/8)+1,(x/10),"Hi, before you start i will do a review about what can you do:");
		mvprintw((y/8)+2,(x/10)+10,"look - Find item on the rooms");
		mvprintw((y/8)+3,(x/10)+10,"take - Grab item on the rooms");
		mvprintw((y/8)+4,(x/10)+10,"check - Show your item status");
		mvprintw((y/8)+5,(x/10)+10,"help - Show more keywords");
	attron(COLOR_PAIR(2));
		mvprintw((y/8)+7,(x/10),"WARNING - To input insert any key less arrow or PRESS ENTER and trigger ");
		mvprintw((y/8)+8,(x/10),"          the comand input. First key will not be accept, type again    ");
		mvprintw((y/8)+9,(x/10),"          IF you do a spelling error press enter and type again         ");
		mvprintw((y/8)+10,(x/10),"          backspace and delete keys not avaiable.                       ");
	attroff(COLOR_PAIR(2));
		mvprintw((y/8)+12,(x/2)-20,"Press any key to continue ...");

getch();
clear();
refresh();
//echo();



}


void floor_3() //Joao
{

	running=true;
  initscr();

    start_color();

    init_pair(3, use_default_colors(), COLOR_CYAN);
    init_pair(2, use_default_colors(), COLOR_RED);
    init_pair(1, use_default_colors(), COLOR_GREEN);
    init_pair(0, use_default_colors(), COLOR_RED);
    init_pair(4, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(5, COLOR_GREEN, use_default_colors());
/*
while(true){
//keycode();
	    string sentence;
	   
	   	   //move(13+4, 3); 
	   	   mvprintw(14,0,"Insert your command: \n");
	   	   sentence=get_line();

	   	   mvprintw(16,0,"%s",sentence.c_str());
	   	  // mvprintw(17,0,"%s",keywordChecker4children(sentence).c_str());
	   	   if(keywordChecker4children(sentence)=="look"){
	   	   	mvprintw(17,0,"OKOKOKOK");
	   	   }


}*/

  //endFloor();
    INTRO();
    game.startUP();
  curs_set(0); //Cursor visibility , 0 none - 1 visible - 2 barely visible
  
  while( running== true ) {

    //keyPosition();
    update();
    }
  endwin();
  // End nCurses display
}
