#include <algorithm>


#include <sstream>
#include <algorithm>
#include <iterator>//for split string into words separelaty to compare with a vector

#include <stdio.h>
#include <ctype.h>




/* Use cordenates like [x,y] on the floor and z to indicate the floor ,Player start on 0,0,0 Up and Down (Floors), North(+y) , South(-y) , West(-x) , East(+x) , [-1,-1,z] unvaiable in all floors, when reach [x,y,z] position, that means a room, only on door location is posible to enter and LOOK for items after find n items can go up */



// REMEMBER FRIST LEVEL == LAST FUNCTION , and so on, c++ is static language , with that i mean all functions need to have a struct frist can't load last but last can load frist


//Globals variable for this 'header'
int coorX=0;
int coorY=0;
int coorZ=3;
string correctPath;


void playerPosition(){//Joao
	cout<<endl;
	cout<<"You at position:"<<endl;
	cout<<"X ="<<coorX<<endl;
	cout<<"Y ="<<coorY<<endl;
	cout<<"Floor ="<<coorZ<<endl;
	cout<<endl;
}



bool checkKeyWord(auto& path2)
{

	vector<string> path2G;

	istringstream iss(path2);
	    copy(istream_iterator<string>(iss),
	    istream_iterator<string>(),
        back_inserter(path2G));

	vector<string> possiblePath={string("north"),string("south"),string("west"),string("east"),string("up"),string("down")};


	for(int x=0; x <= 5;x++)
	{
		if(find(path2G.begin(), path2G.end(), possiblePath[x]) != path2G.end())
		{
			correctPath = possiblePath[x].c_str();
			return possiblePath[x].c_str();
		}else{
			return false;
		}

	}

}





























void third_floor(auto& user_data){
	cout<<"Welcome to this floor "+user_data[0]<<endl;
}


bool top_floor(auto& user_data){//Joao
	string pathToGo;
	clearCon();



	playerPosition();
	cout<<"Hello "+user_data[0]<<endl;
	cout<<"Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n It h survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchangedn It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."<<endl;
		cout<<endl;
		 cin.ignore(1000, '\n');
		getline(cin,pathToGo);
		transform(pathToGo.begin(),pathToGo.end(),pathToGo.begin(),::tolower);


 		checkKeyWord(pathToGo);
 		//go2there * = correctPath;

	    if(checkKeyWord(pathToGo)==false){

	    	clearCon();
	    	cout<<endl;
	    	cout<<"What you input isn't an avaiable command for the game "<<endl;
	    	top_floor(user_data);


	    }else{






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

							cout<<"You hit a Wall, congratz you broke your nose (-10 score)"<<endl;
							addScore(user_data[0],-10);

							pressAnyToContinue();
							clearCon();
							coorY=0;
							coorX=0;
							top_floor(user_data);

						}
					}





					while(correctPath=="north"){
						coorY ++;

						pressAnyToContinue();
						top_floor(user_data);
					}
					while(correctPath=="south"){
						coorY --;

						pressAnyToContinue();
						top_floor(user_data);
					}
					while(correctPath=="west"){
						coorX --;

						pressAnyToContinue();
						top_floor(user_data);
					}
					while(correctPath=="east"){
						coorX ++;
						pressAnyToContinue();
						top_floor(user_data);
					}
	    }
}


