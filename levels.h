#include <algorithm>


/* Use cordenates like [x,y] on the floor and z to indicate the floor ,Player start on 0,0,0 Up and Down (Floors), North(+y) , South(-y) , West(-x) , East(+x) , [-1,-1,z] unvaiable in all floors, when reach [x,y,z] position, that means a room, only on door location is posible to enter and LOOK for items after find n items can go up */



// REMEMBER FRIST LEVEL == LAST FUNCTION , and so on, c++ is static language , with that i mean all functions need to have a struct frist can't load last but last can load frist


//Globals variable for this 'header'
int coorX=0;
int coorY=0;
int coorZ=3;
string pathToGo;


void playerPosition(){//Joao
	cout<<endl;
	cout<<"You at position:"<<endl;
	cout<<"X ="<<coorX<<endl;
	cout<<"Y ="<<coorY<<endl;
	cout<<"Floor ="<<coorZ<<endl;
	cout<<endl;
}


































void third_floor(auto& user_data){
	cout<<"Welcome to this floor "+user_data[0]<<endl;
}


bool top_floor(auto& user_data){//Joao
	playerPosition();
	cout<<"Hello "+user_data[0]<<endl;
	cout<<"Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n It h survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchangedn It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."<<endl;
		cout<<endl;
		cin>>pathToGo;
		transform(pathToGo.begin(),pathToGo.end(),pathToGo.begin(),::tolower);

		if((coorX<0 ) || (coorY<0) || (coorZ==2) || (coorZ==4))
		{

			if(coorZ==4)
			{
				cout<<"You can't go that way, nothing in there"<<endl;

				pressAnyToContinue();
				top_floor(user_data);
			}
			if(coorZ==2)
			{
				if(haveItem(user_data[0],"Key")==true)
				{
					cout<<"Moving into Floor 2 be careful in there"<<endl;

					pressAnyToContinue();
					clearCon();
					third_floor(user_data);
				}else{
					cout<<"You cant go because you dont have a precious item to go down"<<endl;

					pressAnyToContinue();

					clearCon();
					top_floor(user_data);
				}
			}
			if(coorX<0  || coorY<0 ){

				cout<<"You hit a Wall, congratz you broke a nose (-10 score)"<<endl;
				addScore(user_data[0],-10);

				pressAnyToContinue();
				clearCon();
				coorY=0;
				coorX=0;
				top_floor(user_data);

			}
		}





		while(pathToGo=="north"){
			coorY ++;
			top_floor(user_data);
		}
		while(pathToGo=="south"){
			coorY --;
			top_floor(user_data);
		}
		while(pathToGo=="west"){
			coorX --;
			top_floor(user_data);
		}
		while(pathToGo=="east"){
			coorX ++;
			top_floor(user_data);
		}
		
}



