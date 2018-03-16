//when you leave a room set currentRoom to -1
//5 rooms

using namespace std;

int currentRoom=-1;
bool lever=false;

void lobby_hallway()
{
	mvprintw(0, 0, "Lobby Hallway        ");
	currentRoom=-1;
}

