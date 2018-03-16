


struct storyFunctions{
public:

	void startUP(){

		getmaxyx(stdscr,y,x);
		clear();
		refresh();


		attron(COLOR_PAIR(2));

		mvprintw(y/10,(x/8)+13,"Welcome ");
		mvprintw((y/10),(x/8)+21,"%s",detailInfo[0].c_str());
		mvprintw(y/10,(x/8)+21+detailInfo[0].length()," to the Hospital");

		attroff(COLOR_PAIR(2));

		attron(COLOR_PAIR(1));
		mvprintw((y/10)+1,0,"You slowly wake up at the third floor, wearily opening your eyes, only to be greeted with a piercing headache that causes you to clutch your head. After a moment you are able to regain your senses and look around at your surroundings. ");
		attroff(COLOR_PAIR(1));


		mvprintw(y/10+6,(x/8)+21,"...");
		/*
The first things you can pick out is that you are in a room in what seems to be an old hospital bed from the old pieces of equipment that lay abandoned nearby.
 With a groan you slowly pull yourself out of the bed as you stand up. You try hard to think back to how you could have possibly ended up here, but all your mind does is draw blanks repeatedly. You frown, its as if your mind has been wiped clean. You can’t remember anything… After a moment you decide that you need to get the hell out of this place, with a quick glance through the small gaps of the boarded up window you can discern that you are at the top floor of this building.*/
		
		wgetch(stdscr);

		clear();

		mvprintw(y/10,0,"More...");
		attron(COLOR_PAIR(5));
		mvprintw((y/10)+1,0,"The first things you can pick out is that you are in a room in what seems to be an old hospital bed from the old pieces of equipment that lay abandoned nearby. With a groan you slowly pull yourself out of the bed as you stand up. You try hard to think back to how you could have possibly ended up here, but all your mind does is draw blanks repeatedly. You frown, its as if your mind has been wiped clean. You cant remember anything ... After a moment you decide that you need to get the hell out of this place, with a quick glance through the small gaps of the boarded up window you can discern that you are at the top floor of this building.");
		attroff(COLOR_PAIR(5));

		mvprintw((y/10)+11,(x/8)+21,"==>");

		wgetch(stdscr);

		clear();


	}


	void invalidInput(){//Joao
		/*Table to show player Items like an inventory*/
								clear();
								refresh();
								//line 0
				    				attron(COLOR_PAIR(5));
					   	    	mvprintw((y/5)-1,(x/2)-5,"Hi %s ",detailInfo[0].c_str());
				    				attroff(COLOR_PAIR(5));
				    				attron(COLOR_PAIR(1));
					   	    	mvprintw((y/5),(x/3),"Invalid input");
				    				attroff(COLOR_PAIR(1));
					   	    	mvprintw((y/5)+1,(x/3),"type help for know key words");
				    				getch();
								clear();

}

	void checkBoard(){//Joao
		/*Table to show player Items like an inventory*/
								clear();
								refresh();
								//line 0
				    				attron(COLOR_PAIR(5));
					   	    	mvprintw((y/5)-1,(x/2)-5,"Hi %s ",detailInfo[0].c_str());
				    				attroff(COLOR_PAIR(5));
					   	    	mvprintw((y/5),(x/3)-5,"Level: %s Score: %s ",detailInfo[1].c_str(),detailInfo[2].c_str());
				    				attron(COLOR_PAIR(1));
					   	    	mvprintw((y/5)+1,(x/3),"means you have that item");
				    				attroff(COLOR_PAIR(1));

								//line 1
					   	    	mvprintw((y/5)+2,(x/3)-8,"Key");
				    				attron(COLOR_PAIR(stoi(playerItem[0])));
					   	    	mvprintw((y/5)+2,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[0])));

								//line 2
					   	    	mvprintw((y/5)+3,(x/3)-8,"Sword");
				    				attron(COLOR_PAIR(stoi(playerItem[1])));
					   	    	mvprintw((y/5)+3,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[1])));

					   	    	//line 3
								mvprintw((y/5)+4,(x/3)-8,"Shoes");
									attron(COLOR_PAIR(stoi(playerItem[2])));
					   	    	mvprintw((y/5)+4,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[2])));


					   	    	//line 4
					   	    	mvprintw((y/5)+5,(x/3)-8,"FlashLight");
					   	    		attron(COLOR_PAIR(stoi(playerItem[3])));
					   	    	mvprintw((y/5)+5,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[3])));

					   	    	//line 5
					   	    	mvprintw((y/5)+6,(x/3)-8,"Bandages");
					   	    		attron(COLOR_PAIR(stoi(playerItem[4])));
					   	    	mvprintw((y/5)+6,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[4])));

					   	    	//line 5
					   	    	mvprintw((y/5)+7,(x/3)-8,"Scalpel");
					   	    		attron(COLOR_PAIR(stoi(playerItem[5])));
					   	    	mvprintw((y/5)+7,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[5])));

					   	    	//line 5
					   	    	mvprintw((y/5)+8,(x/3)-8,"Stethscope");
					   	    		attron(COLOR_PAIR(stoi(playerItem[6])));
					   	    	mvprintw((y/5)+8,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[6])));

					   	    	//line 5
					   	    	mvprintw((y/5)+9,(x/3)-8,"ID Card");
					   	    		attron(COLOR_PAIR(stoi(playerItem[7])));
					   	    	mvprintw((y/5)+9,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[7])));

					   	    	//line 5
					   	    	mvprintw((y/5)+10,(x/3)-8,"Needles");
					   	    		attron(COLOR_PAIR(stoi(playerItem[8])));
					   	    	mvprintw((y/5)+10,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[8])));

					   	    	//line 5
					   	    	mvprintw((y/5)+11,(x/3)-8,"Thumb");
					   	    		attron(COLOR_PAIR(stoi(playerItem[9])));
					   	    	mvprintw((y/5)+11,(x/3)+5,"        ");
				    				attroff(COLOR_PAIR(stoi(playerItem[9])));
								getch();
								clear();



		}





	void helpBoard(){//Joao
								clear();
								refresh();
								//line 0
				    				attron(COLOR_PAIR(3));
					   	    	mvprintw(y/5,(x/3)+4,"Game KeyWords:");
				    				attroff(COLOR_PAIR(3));

								//line 1
				    				attron(COLOR_PAIR(2));
					   	    	mvprintw((y/5)+1,(x/3)-8,"exit ");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/5)+1,(x/3)-3,"- Exit the game , go main menu");

								//line 2
				    				attron(COLOR_PAIR(1));
					   	    	mvprintw((y/5)+2,(x/3)-8,"help ");
				    				attroff(COLOR_PAIR(1));
					   	    	mvprintw((y/5)+2,(x/3)-3,"- show game words");

					   	    	//line 3
									attron(COLOR_PAIR(0));
								mvprintw((y/5)+3,(x/3)-8,"look ");
				    				attroff(COLOR_PAIR(0));
					   	    	mvprintw((y/5)+3,(x/3)-3,"- show items on each room, player position important");


					   	    	//line 4
					   	    		attron(COLOR_PAIR(4));
					   	    	mvprintw((y/5)+4,(x/3)-8," take ");
				    				attroff(COLOR_PAIR(4));
					   	    	mvprintw((y/5)+4,(x/3)-3,"- take item if exist in that room");

					   	    	//line 5
					   	    		attron(COLOR_PAIR(3));
					   	    	mvprintw((y/5)+5,(x/3)-8," check ");
				    				attroff(COLOR_PAIR(3));
					   	    	mvprintw((y/5)+5,(x/3)-3,"- show the itens you have");
					   	    	//line 6
					   	    		attron(COLOR_PAIR(3));
					   	    	mvprintw((y/5)+5,(x/3)-8,"down ");
				    				attroff(COLOR_PAIR(3));
					   	    	mvprintw((y/5)+5,(x/3)-3,"- go to next floor");
								getch();
								clear();





		}

void itensLook(int room,int floor){


	switch(floor){

		case 3:{

			if(room==0){


									refresh();

				    				attron(COLOR_PAIR(2));
					   	    		mvprintw(y/8,(x/3)+4,"There are no items on Main Hall");
				    				attroff(COLOR_PAIR(2));
					   	    		mvprintw((y/8)+1,(x/3)+4,"enters a room and finds items");
									getch();
									clear();
		}
			if(room==1 ||room==4 ||room==6 ){


								refresh();

				    				attron(COLOR_PAIR(2));
					   	    		mvprintw(y/8,(x/3),"There are no items on this room");
				    				attroff(COLOR_PAIR(2));


				    				attron(COLOR_PAIR(0));
					   	    	mvprintw((y/8)+1,(x/2)-5,"Try other room");
				    				attroff(COLOR_PAIR(0));

								getch();
								clear();
		}
			if(room==2){


								refresh();

				    				attron(COLOR_PAIR(3));
					   	    	mvprintw(y/8,(x/3)+4,"In this room Exist one Item");
				    				attroff(COLOR_PAIR(3));


				    				attron(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3)-9,"Toy Sword");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3),"    - used by kids to create headaches to others");

								getch();
								clear();
		}


		if(room==3){


								refresh();

				    				attron(COLOR_PAIR(3));
					   	    	mvprintw(y/8,(x/3)+4,"In this room Exist one Item");
				    				attroff(COLOR_PAIR(3));


				    				attron(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3)-9,"Shoes");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3),"\t- used not to fall on the glass floor");

								getch();
								clear();
		}


		if(room==5){


								refresh();

				    				attron(COLOR_PAIR(3));
					   	    	mvprintw(y/8,(x/3)+4,"In this room Exist one Item");
				    				attroff(COLOR_PAIR(3));


				    				attron(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3)-9,"Flashlight");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3),"\t- used to light up dark rooms");

								getch();
								clear();
		}

	if(room==7||room==8){


								refresh();

				    				attron(COLOR_PAIR(3));
					   	    	mvprintw(y/8,(x/3)+4,"In this room Exist one Item");
				    				attroff(COLOR_PAIR(3));


				    				attron(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3)-9,"ID Card");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3),"\t- used to access stairs on the building");

								getch();
								clear();
		}












				
			};
		}

	}




void takeItem(int room,int floor){
switch(floor){

		case 3:
		{

			if(room==0){

							refresh();
				    				attron(COLOR_PAIR(4));
					   	    	mvprintw(y/8,(x/3),"No avaiable itens");
				    				attroff(COLOR_PAIR(4));
					   	    	mvprintw((y/8)+1,(x/3),"On the main hall");
					   	    	mvprintw((y/8)+2,(x/3),"only inside rooms");

							wgetch(stdscr);
							clear();

						}	


			if(room==1 || room==4|| room==6){

							refresh();
				    				attron(COLOR_PAIR(4));
					   	    	mvprintw(y/8,(x/3),"No avaiable itens %i",playerItem[0]);
				    				attroff(COLOR_PAIR(4));
					   	    	mvprintw((y/8)+1,(x/3),"On this room");

							wgetch(stdscr);
							clear();

						}	



			if(room==2){


						if(haveItem(detailInfo[0],"Sword")==0){
							itemTurnedON(detailInfo[0],"Sword");
							refresh();
				    				attron(COLOR_PAIR(4));
					   	    	mvprintw(y/8,(x/3),"You grab the item");
				    				attroff(COLOR_PAIR(4));
					   	    	mvprintw((y/8)+1,(x/3),"Toy Sword (+2)");

							getch();
							clear();

    						addScore(detailInfo[0],2);
						}else{
							refresh();
				    				attron(COLOR_PAIR(2));
					   	    	mvprintw(y/8,(x/3),"You already have his item");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3),"Toy Sword");

							getch();
							clear();


						}		
				

						}




			if(room==3){


						if(haveItem(detailInfo[0],"Shoes")==0){
							itemTurnedON(detailInfo[0],"Shoes");
							refresh();
				    				attron(COLOR_PAIR(4));
					   	    	mvprintw(y/8,(x/3)+5,"You grab the item");
				    				attroff(COLOR_PAIR(4));
					   	    	mvprintw((y/8)+1,(x/3)+10,"Shoes (+5)");
					   	    	mvprintw((y/8)+2,(x/3),"Now you can go thow the stairs");
					   	    	mvprintw((y/8)+3,(x/3),"and dont lose any score");
					   	    	mvprintw((y/8)+4,(x/3),"but remember you need a ID");
					   	    	mvprintw((y/8)+4,(x/3),"for access the stairs");
							getch();
							clear();

    						addScore(detailInfo[0],5);
						}else{
							refresh();
				    				attron(COLOR_PAIR(2));
					   	    	mvprintw(y/8,(x/3),"You already have his item");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3)+3,"Shoes");

							getch();
							clear();


						}		
				

						}
				
	
				

			}
			if(room==5){


					if(haveItem(detailInfo[0],"Flashlight")==0){
							itemTurnedON(detailInfo[0],"Flashlight");
							refresh();
				    				attron(COLOR_PAIR(4));
					   	    	mvprintw(y/8,(x/3),"You grab the item");
				    				attroff(COLOR_PAIR(4));
					   	    	mvprintw((y/8)+1,(x/3)+3,"Flashlight (+2)");

							getch();
							clear();

    						addScore(detailInfo[0],2);
					}else{
							refresh();
				    				attron(COLOR_PAIR(2));
					   	    	mvprintw(y/8,(x/3),"You already have his item");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3)+10,"Flashlight");

							getch();
							clear();


			}		
				

						}




			if(room==7||room==8){


					if(haveItem(detailInfo[0],"ID_Card")==0){
							itemTurnedON(detailInfo[0],"ID_Card");
							refresh();
				    				attron(COLOR_PAIR(4));
					   	    	mvprintw(y/8,(x/3),"You grab the item");
				    				attroff(COLOR_PAIR(4));
					   	    	mvprintw((y/8)+1,(x/3)+3,"ID Card (+5)");
					   	    	mvprintw((y/8)+2,(x/3),"Now you can go thow the stairs");
					   	    	mvprintw((y/8)+3,(x/3),"and dont lose any score");

							getch();
							clear();

    						addScore(detailInfo[0],5);
					}else{
							refresh();
				    				attron(COLOR_PAIR(2));
					   	    	mvprintw(y/8,(x/3),"You already have his item");
				    				attroff(COLOR_PAIR(2));
					   	    	mvprintw((y/8)+1,(x/3)+3,"ID Card");

							getch();
							clear();


						}		
				

			}
				
		};


	}

void finishFloor(){
	if(currentRoom==9){
		if(haveItem(detailInfo[0],"ID_Card")==1){
			endFloor();
			coorZ=2;
		}else{

				refresh();
					mvprintw(y/8,(x/3),"You dont have an ID");
				    attron(COLOR_PAIR(2));
					mvprintw((y/8)+1,(x/3),"ID Card needed");
				    attroff(COLOR_PAIR(2));

				getch();
				clear();

		}


	}else{
				refresh();
					mvprintw(y/8,(x/3),"You need to be at the stairs");
				    attron(COLOR_PAIR(2));
					mvprintw((y/8)+1,(x/3),"(ID Card needed)");
				    attroff(COLOR_PAIR(2));

				getch();
				clear();

	}

}




};

storyFunctions game;


void storyONboard(){//Joao

  getmaxyx(stdscr,y,x);

  if(coorZ==3)
  {//Joao

  	  if(playerX>=3 && playerX<=12 && playerY>=2 && playerY<=6)
  	  {//Room 1
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Start UP");
  		  if(playerX>=3 && playerX<=12 && playerY>=2 && playerY<=4){

  			currentRoom=1;
  		  mvprintw(0,0,"Room:(IN)");
  		  }
  
  	  }



  	  if(playerX>=14 && playerX<=24 && playerY>=2 && playerY<=6)
  	  {//Room 2
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Baby Room");
  		  if(playerX>=14 && playerX<=24 && playerY>=2 && playerY<=4){

  			currentRoom=2;
  		  mvprintw(0,0,"Room:(IN)");
  		  }
  
  	  }

  	  if(playerX>=35 && playerX<=54 && playerY>=2 && playerY<=4)
  	  {//Room 3
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Older Children Ward");
  			if(playerX>=37 && playerX<=54 && playerY>=2 && playerY<=4){

  			currentRoom=3;
  		  mvprintw(0,0,"Room:(IN)");
  			}
  	  }

  	  if(playerX>=1 && playerX<=7 && playerY>=7 && playerY<=10)
  	  {//Room 4
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Shoot");
  		  if((playerX==4 && playerY==7)||(playerX==5 && playerY==7)){
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Shoot (LOCKED)");
	  		currentRoom=4;}
  
  	  }

  	  if(playerX>=9 && playerX<=15 && playerY>=7 && playerY<=10)
  	  {//Room 5
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Toys Room");
  		  if(playerX>=9 && playerX<=15 && playerY>=9 && playerY<=10){

  			currentRoom=5;
  		  mvprintw(0,0,"Room:(IN)");
  		  }
  
  	  }

  	  if(playerX>=30 && playerX<=39 && playerY>=8 && playerY<=10)
  	  {//Room 6
  			
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Shut");
  		  if(playerX==38 && playerY==8)
  		  {
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Shut (LOCKED)");
  			currentRoom=6;
  		}
  	  
  
  	  }

  	  if(playerX>=44 && playerX<=48 && playerY==8)
  	  {//Room 7
  			currentRoom=7;
  		  mvprintw(0,0,"Room:(IN)");
  		  mvprintw(1,0,"Pediatrician Room");
  
  	  }

  	  if(playerX>=49 && playerX<=52 && playerY>=7 && playerY<=9)
  	  {//Room 8
  			currentRoom=8;
  		  mvprintw(0,0,"Room:(IN)");
  		  mvprintw(1,0,"Reception");
  
  	  }

  	  if(playerX>=53 && playerX<=59 && playerY>=9 && playerY<=10)
  	  {//Stairs
  			currentRoom=9;
  		  mvprintw(0,0,"Room:");
  		  mvprintw(1,0,"Stair");
  
  	  }











  }}



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

	vector<string> possiblePath={string("look"),string("exit"),string("take"),string("check"),string("help"),string("down")};


	for(int x=0; x <= 5;x++)
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