#include <iostream>
#include "libsqlite3/libsqlite.hpp" //DB Library SQLite3
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <vector>
#include <stdio.h>
#include <ctype.h>



using namespace std;
//GLOBAL Variables
string user;
string password;
int op;
int op2;
sqlite::sqlite db("dbPlayer");


vector<string> detailInfo; /*Global vector - user information*/

void pressAnyToContinue(){//Joao
	cout<<endl;
	cout << "Press ENTER to continue.";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}





void clearCon()// Joao
    {
    //system("reset");// reset log console
    system("clear");// clear actual screen log on console
    /*Create 100 lines in the console giving the ideia of clean*/
    //cout << string( 100, '\n' );
    }




string transformToQuote( const string& var ) { // Joao
    /*Transform variables into quotes to SQL Query

    To pass a string by reference, you use the data type string&.

    Adding the const qualifier to a reference (or a pointer) just says that the code promises not to alter the contents of the object being referenced (or being pointed to). Using const does not mean that the object occupies a read-only area of memory.*/
    return string("'") + var + string("'");
}





char playerInfo2vector(auto& user){
/*SAVE PLAYER INFO INTO VECTOR:
 * THIS VECTOR IS GLOBAL EVERY FUNCTIONS HAVE ACCESS
[0]NICKNAME
[1]LEVEL
[2]SCORE*/


        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player  where id=? ");
        cur->prepare();
        cur->bind(1,user);

        while(cur->step()){

        	detailInfo.emplace_back(cur->get_text(0)) ;
        	detailInfo.emplace_back(cur->get_text(2)) ;
        	detailInfo.emplace_back(cur->get_text(3)) ;



        }



}


#include "model.h"








//#include "final_level_maze.h"



//#include "levels.h"
#include "top_level.h"




void removeCharacter(){//Joao
	/*ask for username and password , if axist delete the data from that user */

		cout<<"Username \t";
		cin>>user;
		cout<<"Password \t";
		cin>>password;


		if (checkUP(user,password)==true){
   
		    auto checkQ = db.get_statement();
		    checkQ->set_sql("Delete from player Where id=?;");
		    checkQ->prepare();
		    checkQ->bind(1,user);

			if(checkQ->step()== SQLITE_OK ){
				cout<<"********************************"<<endl;
				cout<<"* Account removed successfully *"<<endl;
				cout<<"********************************"<<endl;
				
			}

		}else{

			cout<<"Invalid username or password"<<endl;
			cout<<"try again"<<endl;
			removeCharacter();
		}






}



char modifyUser(string user){//Joao
/*Acept the username and ask a new one, check if is the same and if already exist*/

	char ans;
	string username;
	cout<<"What is your new Username ?\t";
	cin>>username;
	if(username==user){
		cout<<endl;
		cout<<"The new username you input is the actual"<<endl;
		cout<<"You want to keep it? (y/n)"<<endl;
		cin>>ans;
		switch(ans){

			case 'y':
			case 'Y':
				break;
			case 'n':
			case 'N':
				modifyUser(user);
				break;
			default:
				cout<<"Wrong answer try again"<<endl;
				modifyUser(user);


		}


	}
	else if(checkUser(username)==true){
		cout<<endl;
		cout<<"Sorry but that username is been using by other player"<<endl;
		cout<<"Choose another one"<<endl;
		modifyUser(user);
	}else{

		alterUser(user,username);




	}




}


void modifyPassword(string pass,string user){//Joao


/*Acept the username and password and check if is the same and if not send to the function who will set that pw on that user*/




	char ans;
	string password;
	cout<<"What is your new password ?\t";
	cin>>password;
	if(password.length()<8){
		cout<<"Password need to have ar least 8 digits";
		modifyPassword(pass,user);
	}
	if(password==pass){
		cout<<endl;
		cout<<"The new password you input is the actual"<<endl;
		cout<<"You want to keep it? (y/n)"<<endl;
		cin>>ans;
		switch(ans)
		{

			case 'y':
			case 'Y':
				break;
			case 'n':
			case 'N':
				modifyPassword(pass,user);
				break;
			default:
				cout<<"Wrong answer try again"<<endl;
				modifyPassword(pass,user);


		}
	}else{

		alterPass(password,user);


	}




}




void modifyOptions(string user,string password){

			int op;
			cout<<endl;
			cout<<"		   Modify Options"<<endl;

			cout<<"		 __________________________"<<endl;
			cout<<"		!                          !"<<endl;
			cout<<"		!                          !"<<endl;
			cout<<"		!   1- Modify Username     !"<<endl;
			cout<<"		!   2- Modify Password     !"<<endl;
			cout<<"		!                          !"<<endl;
			cout<<"		!__________________________!"<<endl;
			cout<<endl;
			cout<<"Choose a number \t";
			cin>>op;
			 while (cin.fail()) //Joao
		    {
		        cin.clear(); // clear input buffer to restore cin to a usable state
		        cin.ignore(INT_MAX, '\n'); // ignore last input
		        cout<<"You can only enter numbers."<<endl;
		        cout<<"Enter a number."<<endl;
		        cin>>op;
		    }
				switch(op) //Joao
				{
					case 0:
						clearCon();
						cout<<endl;
						cout<<"Wrong Number! Try Again"<<endl;
						modifyOptions(user,password);
						break;
					case 1:

						cout<<"I can see you want to change your username"<<endl;
						modifyUser(user);
						break;
					case 2:
						modifyPassword(password,user);
						break;
					default:
						clearCon();
						cout<<endl;
						cout<<"Wrong Number! Try Again"<<endl;
						modifyOptions(user,password);
						break;
				}



}


int modifyAccount()
{//Joao

		//bool OK;
		cout<<"Username \t";
		cin>>user;
		cout<<"Password \t";
		cin>>password;
		if (checkUP(user,password)==true){

			modifyOptions(user,password);

		}else{
			cout<<"Wrong credentials"<<endl;
			cout<<"Try Again"<<endl;
			modifyAccount();

		}


}



char findPlayer(){
	/*ask for the nickname of the player you want to see and ten send to the function who will create a table with that player*/
	string nick;

	cout<<"Who are you looking for?"<<endl;
	cout<<"NICKNAME - \t";
	cin>>nick;
	if(checkUser(nick)==1){
		playerInfo(nick);


	}




}



int main() //Joao
{

		string us;
		string pw;
		string ans;

		cout<<"username"<<endl;
		cin>>us;
		playerInfo2vector(us);
		cout<<detailInfo[0]<<endl;
		floor_3();
		return 0;



		cout<<endl;
		cout<<"		   Text Adventure "<<endl;

		cout<<"		 ________________"<<endl;
		cout<<"		!                !"<<endl;
		cout<<"		!                !"<<endl;
		cout<<"		!   1- Start     !"<<endl;
		cout<<"		!   2- Score     !"<<endl;
		cout<<"		!   3- More      !"<<endl;
		cout<<"		!   4- Quit      !"<<endl;
		cout<<"		!                !"<<endl;
		cout<<"		!________________!"<<endl;
		cout<<endl;
		cout<<"Choose an option. \t";
		cin>>op;

		 while (cin.fail()) //Joao
	    {
	        cin.clear(); // clear input buffer to restore cin to a usable state
	        cin.ignore(INT_MAX, '\n'); // ignore last input
	        cout << "You can only enter numbers."<<endl;
	        cout << "Choose an option"<<endl;
	        cin >> op;
	    }

		switch(op) //Joao
		{
			case 0:
				clearCon();
				cout<<endl;
				cout<<"Invalid Number! Try Again"<<endl;
				main();
				break;
			case 1:{
							cout<<"Username\t";
							cin>>us;
							cout<<"Password\t";
							cin>>pw;
			
							
							while(checkUP(us,pw)!=true)
								{
			
								cout<<"Wrong credentials"<<endl;
								cout<<"Wish go back (y/n)?"<<endl;
								cin>>ans;
								if(ans=="y" ||ans=="Y" || ans=="yes" || ans=="Yes" || ans=="YEs" || ans=="YES" || ans=="yeS" || ans=="yES"){
									main();
									}
			
								cout<<"Username\t";
								cin>>us;
								cout<<"Password\t";
								cin>>pw;
								checkUP(us,pw);
							}
								playerInfo2vector(us);
			
							    clearCon();
								//top_floor(detailInfo);
								//Game(detailInfo);//To be loaded after found the key  
								floor_3();
									
			
							break;}
			case 2:

				clearCon();
				rankingScore();
				pressAnyToContinue();
				main();
				break;
			case 3:{
			
							clearCon();
							cout<<endl;
							cout<<"	   More Options - Character Creation"<<endl;
							cout<<"		 ________________"<<endl;
							cout<<"		!                !"<<endl;
							cout<<"		!                !"<<endl;
							cout<<"		!   1- Create    !"<<endl;
							cout<<"		!   2- Modify    !"<<endl;
							cout<<"		!   3- Delete    !"<<endl;
							cout<<"		!   4- Find      !"<<endl;
							cout<<"		!   5- Go Back   !"<<endl;
							cout<<"		!                !"<<endl;
							cout<<"		!________________!"<<endl;
							cout<<endl;
							cout<<"Choose an option \t";
							cin>>op2;
							 while (cin.fail()) //Joao
						    {
						        cin.clear(); // clear input buffer to restore cin to a usable state
						        cin.ignore(INT_MAX, '\n'); // ignore last input
						        cout<<"You can only enter numbers."<<endl;
						        cout<<"Choose an option."<<endl;
						        cin>>op2;
						    }
						    switch(op2) //Joao
								{
									case 1:

										clearCon();
										createCharacter();
										pressAnyToContinue();
										
										break;
									case 2:
										clearCon();
										modifyAccount();
										pressAnyToContinue();
										
										break;
									case 3:

										clearCon();
										removeCharacter();
										pressAnyToContinue();
										
										break;
									case 4:

										clearCon();
										findPlayer();
										pressAnyToContinue();
										
										break;
									case 5:

										clearCon();
										main();
										pressAnyToContinue();
										
										break;
									default:
										clearCon();
										cout<<endl;
										cout<<"Wrong Number! Try Again"<<endl;
										
										break;
								}

							break;
						}
			case 4:

				clearCon();
				break;
			case 5://TEST REMOVE

					cout<<"Username\t";
					cin>>us;
					cout<<"Password\t";
					cin>>pw;
					checkUP(us,pw);	
				break;
			case 6://TEST REMOVE
			{	
				string usern;
				string passw;
				cout<<"Username ";
				cin>>usern;
				cout<<"Username ";
				cin>>passw;
				checkUP(usern,passw);

				break;
			}
			default:
				cout<<endl;
				cout<<"Invalid Number! Try Again"<<endl;
				main();
				break;
		}
	return 0;
}
