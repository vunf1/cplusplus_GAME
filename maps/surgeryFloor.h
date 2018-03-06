//when you leave a room set currentRoom to -1
//5 rooms

using namespace std;

int currentRoom=-1;

void Room1()
{
	mvprintw(10, 70, "ROOM 1");
	currentRoom=1;
}

void Room2()
{
	mvprintw(10, 70, "ROOM 2");
	currentRoom=1;
}

void Room3()
{

}

void checkRoom(int x, int y)
{
	//check the coordinates and alter the currentRoom variable.
	if((y>=2 && y<=4) && (x>=15 && x<=24))
		Room1();

	if((y>=2  && y<=4) && (x>=44 && x<=54))
		Room2();
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