//when you leave a room set currentRoom to -1
//5 rooms

using namespace std;

int currentRoom=-1;

void Surgery_room1()
{
	mvprintw(10, 70, "ROOM 1");
	currentRoom=1;
}

void Surgery_room2()
{
	mvprintw(10, 70, "ROOM 2");
	currentRoom=2;
}

void Surgery_toilet()
{
	mvprintw(10, 70, "TOILET");
	currentRoom=3;
}

void checkRoom(int x, int y)
{
	//check the coordinates and alter the currentRoom variable.
	if(coorZ==2){	
			if((y>=2 && y<=4) && (x>=15 && x<=24))
				Surgery_room1();
	
			if((y>=2  && y<=4) && (x>=44 && x<=54))
				Surgery_room2();
	
			if((x>=28 && x<=37) && (y>=10 && y<=11))
				Surgery_toilet();
		}
}

void story()
{
	cout << "ENTRASTE NA STORY" << endl;
}

void actions(int action)
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
					//code here
					move(20, 03);
					printw("This room feels rather empty, someone probably robbed this building before.");
					exit(0);
				break;

				case 2:
					//code here
				break;

				case 3:
					//code here
				break;

				case -1:
					//code here
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
		cout << sentence[idx] << endl;

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

void checkForActions(string sentence)
{
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
			break;
		}
	}
}

