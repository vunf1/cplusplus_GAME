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
	if((y>=2 && y<=4) && (x>=15 && x<=24))
		Surgery_room1();

	if((y>=2  && y<=4) && (x>=44 && x<=54))
		Surgery_room2();

	if((x>=28 && x<=37) && (y>=10 && y<=11))
		Surgery_toilet();
}

void story()
{
	cout << "ENTRASTE NA STORY" << endl;
}

void actions()
{
	switch(currentRoom)
	{
		case 0:
			break;

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case -1: //in case you are not inside a room, still thinking if this will be usefull
			break;

	}
}

void keywordChecker()
{
	//function to check for keywords related to the possible actions in this floor
	return;
}