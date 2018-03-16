//3 Rooms
//y= 16 For printing story

using namespace std;

int currentRoom;
bool print=false;

void BasementRoom1()
{
    mvprintw(0, 0, "Trash");
    
}

void BasementRoom2()
{
    mvprintw(0,0, "You have found a corpse which resembles Dr.Arnold, do you wish to investigate further? : ");
    addScore(detailInfo[0],+5); 
    
    mvprintw(16,0, "You gained 5 points and you have %i",stoi(detailInfo[2]));
}

void BasementRoom3()
{
    mvprintw(0,0, "Incinerator");
    		
}

void BasementRoom4()
{
    mvprintw(0,0, "Exit Chest: Enter the chest room for a chance to finish the game and leave");
    addScore(detailInfo[0],+7); 
    
    mvprintw(16,0, "You gained 7 points and you have %i",stoi(detailInfo[2]));
    void drawMap()
}


//All the trigger points for the Story are above

void checkArea()
{
    if(coorZ==1)
    {
        if(playerY>=2 && playerY<=4 && playerX>=46 && playerX<=55){
				BasementRoom3();}
	
	    if(playerY>=9  && playerY<=9 && playerX>=58 && playerX<=60){
				BasementRoom1();}
	
		if(playerX==40 && playerY>=6 && playerY<=7){
				BasementRoom2();
        }
        if(playerX>=34 && playerX<=39 && playerY>=8 && playerY<=10)
		{		
            BasementRoom4();
        }
      
    }
}

void itemsLook(int room,int floor){//Joao


	switch(floor){

		case 3:{

			if(room==0){ //basement floor and body/maze chest


									refresh();

				    				attron(COLOR_PAIR(2));
					   	    		mvprintw(y/8,(x/3)+4,"There are no items within your reach");
				    				attroff(COLOR_PAIR(2));
					   	    		mvprintw((y/8)+1,(x/3)+4,"enters a room and finds items");
									getch();
									clear();
		}
			if(room==1 ||room==4 ||room==6 ){ //ttrash and incinerator


								refresh();

				    				attron(COLOR_PAIR(2));
					   	    		mvprintw(y/8,(x/3),"There are no items in this room");
				    				attroff(COLOR_PAIR(2));


				    				attron(COLOR_PAIR(0));
					   	    	mvprintw((y/8)+1,(x/2)-5,"Try other room");
				    				attroff(COLOR_PAIR(0));

								getch();
								clear();
		}
   