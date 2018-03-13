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
			exit(0);
			break;

		case 1:
			cout << "test" << endl;
			break;
	}
}

void keywordChecker(string sentence)
{
	//Function to check what the user has written and act according to it

	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
	//cout << sentence << endl;

        if (string::npos != sentence.find("exit"))
        	actions(0);
}
