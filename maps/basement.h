//3 Rooms
//y= 16 For printing story

using namespace std;

int currentRoom;
bool print=false;

void basementRoom1()
{
    mvprintw(0, 0, "Doctor's Office");
    
}

void PsychiatricRoom2()
{
    mvprintw(0,0, "Double Doors");
    
}

void PsychiatricRoom3()
{
    mvprintw(0,0, "First Cell");
    		
}

void PsychiatricRoom4()
{
    mvprintw(0,0, "Second Cell");
    
}

void PsychiatricRoom5()
{
    mvprintw(0,0, "Third Cell");
    
    
}

void PsychiatricRoom6()
{
    mvprintw(0,0, "Fourth Cell");
    
    
}

void PsychiatricRoom7()
{
    mvprintw(0,0, "Fifth Cell");
    
    
}

void PsychiatricRoom8()
{
    
    
    mvprintw(0,0, "Boiler Room");
    addScore(detailInfo[0],-5); 
    
    mvprintw(16,0, "You Lost 5 points and you have %i",stoi(detailInfo[2]));
}

void PsychiatricRoom9()
{
    mvprintw(2,70, "Stairs");
    
}

//All the trigger points for the Story are above

void checkArea()
{
    if(coorZ==1)
    {
        if(playerY>=2 && playerY<=4 && playerX>=46 && playerX<=55){
				PsychiatricRoom1();}
	
	    if(playerY>=9  && playerY<=9 && playerX>=58 && playerX<=60){
				PsychiatricRoom9();}
	
		if(playerX==40 && playerY>=6 && playerY<=7){
				PsychiatricRoom2();
        }
        if(playerX>=34 && playerX<=39 && playerY>=8 && playerY<=10)
		{		
            PsychiatricRoom3();
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
    
   