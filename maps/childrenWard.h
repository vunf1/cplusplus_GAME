

void storyONboard(){//Joao

  getmaxyx(stdscr,y,x);

  if(coorZ==3)
  {//Joao
  	  if(playerX==34 && playerY==7)
  	  {
  
  		  mvprintw(16,0,"You walk over and enter the room across from you, inside you are met with a creepy sight.\n Countless damaged dolls stare back at you with lifeless eyes, all of them in different stages of decay and wear and tear.\n Suppressing a shiver you walk further inside and glance around.");
  		  mvprintw(20,x/5,"Y =  What will you do? Search the room more closely or leave?");
  
  	  }

  	  if(playerX>=3 && playerX<=12 && playerY>=2 && playerY<=5)
  	  {//Room 1
  
  		  mvprintw(0,0,"Start UP");
  
  	  }



  	  if(playerX>=14 && playerX<=24 && playerY>=2 && playerY<=5)
  	  {//Room 2
  
  		  mvprintw(0,0,"Baby Room");
  
  	  }

  	  if(playerX>=36 && playerX<=54 && playerY>=2 && playerY<=4)
  	  {//Room 3
  
  		  mvprintw(0,0,"Older Children Ward");
  
  	  }

  	  if(playerX>=1 && playerX<=7 && playerY>=8 && playerY<=10)
  	  {//Room 4
  
  		  mvprintw(0,0,"Shoot");
  
  	  }

  	  if(playerX>=9 && playerX<=15 && playerY>=8 && playerY<=10)
  	  {//Room 5
  
  		  mvprintw(0,0,"Toys Room");
  
  	  }

  	  if(playerX>=30 && playerX<=39 && playerY>=9 && playerY<=10)
  	  {//Room 6
  
  		  mvprintw(0,0,"Shut");
  
  	  }

  	  if(playerX>=44 && playerX<=48 && playerY==8)
  	  {//Room 7
  
  		  mvprintw(0,0,"Pediatrician Room");
  
  	  }

  	  if(playerX>=49 && playerX<=52 && playerY>=7 && playerY<=9)
  	  {//Room 7
  
  		  mvprintw(0,0,"Reception");
  
  	  }

  	  if(playerX>=53 && playerX<=59 && playerY>=9 && playerY<=10)
  	  {//Stairs
  
  		  mvprintw(0,0,"Stair");
  
  	  }











  }
}

bool actions4children(int action)
{//Joao && Diogo
	switch(action)
	{
		case 0:
			return running=false;
			break;

		case 1:
			cout << "test" << endl;
			break;
	}
}

void keywordChecker4children(string sentence)
{//Diogo && Joao
	//Function to check what the user has written and act according to it

	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);


        if (string::npos != sentence.find("exit")){
                	actions4children(0);}
}
