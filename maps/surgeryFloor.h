//when you leave a room set currentRoom to -1
//5 rooms

using namespace std;

int currentRoom;
bool print=false;

void Surgery_room1()
{
	mvprintw(0, 0, "Surgery Room 1       ");
	currentRoom=1;
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

void Surgery_floor()
{
	mvprintw(0, 0, "Surgery Floor Hallway");
	currentRoom=-1;
}

bool kbhit()
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
			Surgery_floor();
		}
}

void actions(int action) //PRINTW IS NOT WORKING HERE FOR SOME REASON. NTBF
{
	switch(action)
	{
		case 0:
			running=false; 
			break;

		case 1:
			switch(currentRoom)
			{
				case 1:
					//mvprintw(16,0,"This room feels rather empty, someone probably robbed this building before.");
				break;

				case 2:
					mvprintw(16, 0, "Near the top left corner of the room you see something, you should probably take a few steps over there if you want to find out what it is.");
					while(!kbhit())
					{}
					//exit(0);
					//add coord check to see if user steps on the correct place and ask him if he wants to grab the item.
				break;

				case 3:
					//code here
				break;

				case -1:
					//code here
					mvprintw(14,0,"This room feels rather empty, someone probably robbed this building before.");
					pressAnyToContinue();
				break;

				default:
				break;
			}
			break;
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

void checkForActions(string sentence)//Diogo
{
	//Function to determine which actions should be confirmed by searching the sentence
	//that the user sent as input with the keyWordChecker function.
	bool trigger = false;

	for(int idx=0; idx<2/*number of actions available*/; idx++)
	{
		switch(idx)
		{
			case 0:
				trigger=keyWordChecker(sentence, "exit");
				if(trigger==true)
					actions(0);
			break;

			case 1:
				trigger=keyWordChecker(sentence, "look");
				if(trigger==true)
					actions(1);
			break;
		}
	}
}

