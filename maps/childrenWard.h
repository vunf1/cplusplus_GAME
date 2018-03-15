
struct storyFunctions{
public:
	int curRoom;

	void startUP(){

		getmaxyx(stdscr,y,x);
		clear();
		refresh();
		attron(COLOR_PAIR(2));

		mvprintw(y/10,(x/8)+13,"Welcome ");
		mvprintw((y/10),(x/8)+21,"%s",detailInfo[0].c_str());
		mvprintw(y/10,(x/8)+21+detailInfo[0].length()," to Hospital");

		attroff(COLOR_PAIR(2));

		attron(COLOR_PAIR(1));
		mvprintw(y/10+1,0,"  You slowly wake up at the third floor, wearily opening your eyes, only to be greeted with a piercing headache that causes you to clutch your head. After a moment you are able to regain your senses and look around at your surroundings. ");
		attroff(COLOR_PAIR(1));


		mvprintw(y/10+5,(x/8)+21,"...");

		
		wgetch(stdscr);
		clear();


	}

	void helpBoard(){//Joao

			refresh();
								//line 0
				    				attron(COLOR_PAIR(3));
					   	    	mvprintw(y/5,(x/3)+4,"Game KeyWords:");
				    				attroff(COLOR_PAIR(3));

								//line 1
				    				attron(COLOR_PAIR(2));
					   	    	mvprintw((y/5)+1,(x/3)-8,"exit");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/5)+1,(x/3)-3,"- Exit the game , go main menu");

								//line 2
				    				attron(COLOR_PAIR(1));
					   	    	mvprintw((y/5)+2,(x/3)-8,"help");
				    				attroff(COLOR_PAIR(1));
					   	    	mvprintw((y/5)+2,(x/3)-3,"- show game words");

					   	    	//line 3
									attron(COLOR_PAIR(0));
								mvprintw((y/5)+3,(x/3)-8,"look");
				    				attroff(COLOR_PAIR(0));
					   	    	mvprintw((y/5)+3,(x/3)-3,"- show items on each room, player position important");


					   	    	//line 4
					   	    		attron(COLOR_PAIR(4));
					   	    	mvprintw((y/5)+4,(x/3)-8,"take");
				    				attroff(COLOR_PAIR(4));
					   	    	mvprintw((y/5)+4,(x/3)-3,"- take item if exist in that room");

					   	    	//line 5
					   	    		attron(COLOR_PAIR(3));
					   	    	mvprintw((y/5)+5,(x/3)-8,"check");
				    				attroff(COLOR_PAIR(3));
					   	    	mvprintw((y/5)+5,(x/3)-3,"- show the itens you have");
			getch();
			clear();





		}

void itensLook(int room,int floor){



}
void itensTake(){


	
}




};

storyFunctions game;


void storyONboard(){//Joao

  getmaxyx(stdscr,y,x);

  if(coorZ==3)
  {//Joao

  	  if(playerX>=3 && playerX<=12 && playerY>=2 && playerY<=5)
  	  {//Room 1
  			game.curRoom=1;
  		  mvprintw(0,0,"Start UP");
  		  mvprintw(17,0,"DDDDDDD");

  
  	  }



  	  if(playerX>=14 && playerX<=24 && playerY>=2 && playerY<=5)
  	  {//Room 2
  			game.curRoom=2;
  		  mvprintw(0,0,"Baby Room");
  
  	  }

  	  if(playerX>=36 && playerX<=54 && playerY>=2 && playerY<=4)
  	  {//Room 3
  			game.curRoom=3;
  		  mvprintw(0,0,"Older Children Ward");
  
  	  }

  	  if(playerX>=1 && playerX<=7 && playerY>=8 && playerY<=10)
  	  {//Room 4
  		game.curRoom=4;
  		  mvprintw(0,0,"Shoot");
  
  	  }

  	  if(playerX>=9 && playerX<=15 && playerY>=8 && playerY<=10)
  	  {//Room 5
  		game.curRoom=5;
  		  mvprintw(0,0,"Toys Room");
  
  	  }

  	  if(playerX>=30 && playerX<=39 && playerY>=9 && playerY<=10)
  	  {//Room 6
  			game.curRoom=6;
  		  mvprintw(0,0,"Shut");
  
  	  }

  	  if(playerX>=44 && playerX<=48 && playerY==8)
  	  {//Room 7
  			game.curRoom=7;
  		  mvprintw(0,0,"Pediatrician Room");
  
  	  }

  	  if(playerX>=49 && playerX<=52 && playerY>=7 && playerY<=9)
  	  {//Room 8
  			game.curRoom=8;
  		  mvprintw(0,0,"Reception");
  
  	  }

  	  if(playerX>=53 && playerX<=59 && playerY>=9 && playerY<=10)
  	  {//Stairs
  			game.curRoom=2;
  		  mvprintw(0,0,"Stair");
  
  	  }
  	  game.curRoom=0;











  }
}


string get_line()
 {//Joao
 	// [ ] Bug Found , backspace dont do the work
    	string result;
      while(true)
      {
        int c = getch();
        if(c == ERR || c == '\n') {

    		erase();
        	return result;}
        else {result += c;} 
      }
 }

string keywordChecker4children(auto& path2)
{//Joao

	/*Accept the user input all line and convert into a vector to compare to other vector were are the possible paths/commands to use on the game if none exist send false as response*/

	vector<string> path2G;
	counter=0;

	istringstream iss(path2);
	    copy(istream_iterator<string>(iss),istream_iterator<string>(),     back_inserter(path2G));

	vector<string> possiblePath={string("look"),string("exit"),string("take"),string("check"),string("help")};


	for(int x=0; x <= 4;x++)
	{
		if(find(path2G.begin(), path2G.end(), possiblePath[x]) != path2G.end())
		{
			counter=1;
			return possiblePath[x].c_str();
		}

	}
	if(counter==0){
		return string("false");
	}
}




/*
void keywordChecker4children(string sentence)
{//Diogo && Joao
	//Function to check what the user has written and act according to it

	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);


        if (string::npos != sentence.find("exit")){
                	actions4children(0);}
        if (string::npos != sentence.find("look"))
        {
                	actions4children(1);

                }
}
*/