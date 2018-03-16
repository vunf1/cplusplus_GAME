//when you leave a room set currentRoom to -1
//5 rooms


using namespace std;

bool lever=false;

void Surgery_room1()
{
	mvprintw(0, 0, "Surgery Room 1       ");
	currentRoom=1;
}

void lobby_hallway()
{
	mvprintw(0, 0, "Lobby Hallway        ");
	currentRoom=-1;
}

void Surgery_room2()
{
	mvprintw(0, 0, "Surgery Room 2       ");
	currentRoom=2;
}

void Surgery_toilet()
{
	mvprintw(0, 0, "Toilet               ");
	currentRoom=3;
}

void Surgery_storage()
{
	mvprintw(0, 0, "Storage Room         ");
	currentRoom=4;
}


void Surgery_floor()
{
	mvprintw(0, 0, "Surgery Floor Hallway");
	currentRoom=-1;
}

bool kbhit()// Function to detect if there is any keyboad input.
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return true;
    } else {
        return false;
    }
}

void checkRoom(int x, int y)
{
	//check the coordinates and alter the currentRoom variable.
	if(coorZ==2){	
			if((y>=2 && y<=4) && (x>=15 && x<=24))
			{	
				Surgery_room1();
				return;
			}
	
			if((y>=2  && y<=4) && (x>=44 && x<=54))
			{
				Surgery_room2();
				return;
			}
	
			if((x>=28 && x<=37) && (y>=10 && y<=11))
			{
				Surgery_toilet();
				return;
			}

			if((x>=8 && x<=11) && (y>=9 && y<=10))
			{
				Surgery_storage();
				return;
			}
			Surgery_floor();
		}

	if(coorZ==0){
		lobby_hallway();
	}

}


bool keyWordChecker(string sentence, string word)//Diogo
{
	//Function to check if a certain word is present inside a string.
	int wordSize = word.size();

	for(int idx=0, count=0; idx<sentence.size(); idx++)
	{
		if(sentence[idx] == word[count])
		{
			count++;
			if(count == wordSize)
				return true;
		}
		else
			count=0;
	}
	return false;
}
