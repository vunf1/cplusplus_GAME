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
    mvprintw(0,0, "You have found ");
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
        if(playerX>=27 && playerX<=32 && playerY>=8 && playerY<=10)
		{		
            PsychiatricRoom4();
        }
        if(playerX>=19 && playerX<=25 && playerY>=8 && playerY<=10)
		{	
            PsychiatricRoom5();
        }
        if(playerX>=10 && playerX<=17 && playerY>=8 && playerY<=10)
		{		
            PsychiatricRoom6();
        }
        if(playerX>=1 && playerX<=8 && playerY>=8 && playerY<=10)
		{		
            PsychiatricRoom7();
        }
        if(playerX>=1 && playerX<=14 && playerY>=2 && playerY<=5)
		{	
            
            PsychiatricRoom8();
        }
    }
}
    
   