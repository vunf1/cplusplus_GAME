
#include <iostream>
#include "libsqlite3/libsqlite.hpp" //DB Library SQLite3

#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <vector>
using namespace std;

/* FUTURE USE : ORGANIZE FUNCTION IN IT*/
#include <ncurses.h>





//vector<char> listItens;

void keycode(){//Joao
    //initscr();
    noecho(); //dont show on the printw the key pressed
    raw(); //instead of wait he direct inject (teory), good for arrow keys,TRUE arrow keys shutdown the program
    int key;
    //27 is the keycode for ESC 
    printw("Press any key to know the keycode ");
    while((key=getch())!=27){
        move(2,3);
        printw("Keycode %d and the character inputed is %c",key,key);//%d for decimal keycode and %c for character key
        move(0,0);
        printw("Press any key to knnow the keycode ");
        refresh();
    }


    endwin();
}



/*
void welcomeIntro(){

    int x,y;
    start_color();
    curs_set(0);//turn off the blanking input
    init_pair(1,COLOR_YELLOW,COLOR_BLACK);// frist parameter set variable to be injected on 1 pairs, second parameter is for letters and third is for background color
    getmaxyx(stdscr,y,x);//Grab the Max Witdh && Height of the actual console window
    move(y/10,x/4);//move to middle of the console window
    attron(COLOR_PAIR(1));//active an attribute on next printw
    printw("Welcome to the Game");//cout while using ncurses
    attroff(COLOR_PAIR(1));//desative the bold on previous printw



}
*/
/*
void Game(){
    
    initscr();//start mini canvas for console
    move(5,10);//move to x position and y
    printw("cout during canvas");//cout while using ncurses
    mvprintw(6,10,"Something");//move and prinw function together

    refresh();//for all previous code appear on console
    getch();//for end the program when user press a key
    endwin();//end canvas on console
    

    //keycode(); //function to know key pressed

    initscr();//start mini canvas for console

    keycode();


    refresh();//for all previous code appear on console
    
    getch();//for end the program when user press a key
    endwin();//end canvas on console


//do{
    cin>>doIT;

    switch(doIt){
    case "help":
        cout<<"Options:"<<endl;
        cout<<"1 - look"<<endl;
        cout<<"2 - go to <room name>"<<endl;
        pressAnyToContinue();
        Game();
    case "look":
        cout<<"OKOK"<<endl;
        break;



    }











//}while(doIT!='Q' || doIT!='q');




}*/

bool running = true;
short int playerX = 2; // sets player starting position
short int playerY = 2; // sets player starting position
short int x,y;
char map[12][41] =  //draws a  map with an array in order to create the maze
{
    "                                        ",
    " ______________________________________ ",
    "| x   2222                            1|",
    "|111        33333                   1 1|",
    "|1  1 1                               1|",
    "|1  1  1                              1|",
    "|1  1  1   123456                     1|",
    "|1 1  1                               1|",
    "|1   1                                1|",
    "|1  1                                 1|",
    "|  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
    "<>                                      "
};
// Draw Map
// 
void drawMap()//Joao
{
    getmaxyx(stdscr,y,x);
    noecho();
    mvprintw(0,x/3,"Welcome to final level");
    mvprintw(1,x/5,"Reach the end of the maze to finish the game");
  for (int i = 0; i < 12; i++) {
    // addstr is nCurses equiv
    // of cout or print
    move(i+2,x/5);
    addstr(map[i]);
    addstr("\n");
    }
}


// Detect Char input
// and move player in direction
bool getUserInput()//Joao
{
char userInput = getch();
    
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
void endGame(auto& info){//Joao

    mvprintw(0,x/4," ======================================");
    mvprintw(1,x/4," @         YOU  FINISH  THE           @");
    mvprintw(2,x/4," @              GAME                  @");
    mvprintw(3,x/4,"    CONGRATULATIONS %s                 ",info[0].c_str());
    mvprintw(4,x/4," @    YOU WILL RECEIVE 100 POINTS     @");
    mvprintw(5,x/4," @         AND LEVEL UP               @");
    mvprintw(6,x/4," ======================================");
    getch();

}

/*

if((playerY==11&&playerX==3)||(playerY==11&&playerX==2)){
        mvprintw(15,3,"Congratz");
    }


if(map[playerY][playerX]==map[3][13]){
        mvprintw(15,3,"Congratz");
    }
*/ 
void Game(auto& vector) //Joao
{
  // Initate nCurses display


  initscr();

  while( running== true ) {

    update();

    if((playerY==10&&playerX==3)||(playerY==10&&playerX==2)){
        
        
        endGame(vector);
        running=false;
    }

  //mvprintw(15,0," X:%d Y:%d", playerX, playerY);
  }
    addScore(vector[0],100);
    upLevel(vector[0],1);
  // End nCurses display
  endwin();
}
