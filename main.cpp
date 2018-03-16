#include <iostream>
#include "libsqlite3/libsqlite.hpp" //DB Library SQLite3
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <limits>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <ncurses.h>
#include <termios.h>

#include "colors.h"
using namespace std;
//GLOBAL Variables
string user;
string password;
int op;
int op2;
sqlite::sqlite db("dbPlayer");


vector<string> detailInfo; /*Global vector - user information*/

vector<string> playerItem;


void hideInput()//Diogo
{

    termios tty;

    tcgetattr(0, &tty);

    /* we want to disable echo */
    tty.c_lflag &= ~ECHO;

    tcsetattr(0, TCSANOW, &tty);
}

void showInput()//Diogo
{
   termios tty;

    tcgetattr(0, &tty);

    /* we want to reenable echo */
    tty.c_lflag |= ECHO;

    tcsetattr(0, TCSANOW, &tty);
}


void pressAnyToContinue(){//Joao
	//wait for enter trigger , hide future type
	cout<<"Press ENTER to continue ...";
	hideInput();


	cin.clear();
	cin.get();
	cin.ignore(INT_MAX,'\n');
	showInput();
}



void clearCon()// Joao
    {//clear log on console
    //system("reset");// reset log console
    system("clear");// clear actual screen log on console
    /*Create 100 lines in the console giving the ideia of clean*/
    //cout << string( 100, '\n' );
    }




string transformToQuote( const string& var ) { // Joao
    /*Transform variables into quotes to SQL Query

    To pass a string by reference, you use the data type string&.

    Adding the const qualifier to a reference (or a pointer) just says that the code promises not to alter the contents of the object being referenced (or being pointed to). Using const does not mean that the object occupies a read-only area of memory.
    DB ERRORS , try receive help from DAvid Croft he didnt fix so use alternative */
    return string("'") + var + string("'");
    clearCon();
}

char playerInfo2vector(auto& user){//Joao
/*SAVE PLAYER INFO INTO VECTOR:
 * THIS VECTOR IS GLOBAL EVERY FUNCTIONS HAVE ACCESS
[0]NICKNAME
[1]LEVEL
[2]SCORE



This file is static futher updates during the game call again this function to update status
*/

        detailInfo.clear();
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
#include "levels.h"
//#include "test/final_level_maze.h"



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
		switch(ans)
		{
			case 'Y':
			case 'y':
			break;

			case 'N':
			case 'n':
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


void modifyOptions(string user,string password){//Joao

			int op;
			cout<<endl;
			cout<<"		      Modify Options"          <<endl;

			cout<<"		▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"<<endl;
			cout<<"		█                         █"<<endl;
			cout<<"		█                         █"<<endl;
			cout<<WHITE_TEXT("		█   ")CYAN_TEXT("1- Modify Username")WHITE_TEXT("    █")<<endl;
			cout<<WHITE_TEXT("		█   ")YELLOW_TEXT("2- Modify Password")WHITE_TEXT("    █")<<endl;
			cout<<"		█                         █"<<endl;
			cout<<"		█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;
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



char findPlayer(){//Joao
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



		cout<<endl;
		cout<<BLUE_TEXT("		  Text Adventure ")<<endl;
		cout<<YELLOW_TEXT("		▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄")<<endl;
		cout<<YELLOW_TEXT("		█                █")<<endl;
		cout<<YELLOW_TEXT("		█                █")<<endl;
		cout<<YELLOW_TEXT("		█   ")CYAN_TEXT("1 - Start")YELLOW_TEXT("    █")<<endl;
		cout<<YELLOW_TEXT("		█   ")BLUE_TEXT("2 - Score")YELLOW_TEXT("    █")<<endl;
		cout<<YELLOW_TEXT("		█   ")GREEN_TEXT("3 - More")YELLOW_TEXT("     █")<<endl;
		cout<<YELLOW_TEXT("		█   ")RED_TEXT("4 - Quit")YELLOW_TEXT("     █")<<endl;
		cout<<YELLOW_TEXT("		█                █")<<endl;
		cout<<YELLOW_TEXT("		█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█")<<endl;
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
							hideInput();
							cout<<"Password\t";
							cin>>pw;
							showInput();
			
							
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
								hideInput();
								cout<<"Password\t";
								cin>>pw;
								showInput();
								checkUP(us,pw);
							}
								playerInfo2vector(us);
								playerItemBoard(us);
							    clearCon();
								//top_floor(detailInfo);
								//Game(detailInfo);//To be loaded after found the key  
								floor_3();
								main();
									
			
							break;}
			case 2:

				clearCon();
				rankingScore();
				pressAnyToContinue();
				clearCon();
				showInput();
				main();
				break;
			case 3:{
			
							clearCon();
							cout<<endl;
							cout<<RED_TEXT("	   More Options - Character Creation")<<endl;
							cout<<WHITE_TEXT("		▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄")<<endl;
							cout<<WHITE_TEXT("		█                █")<<endl;
							cout<<WHITE_TEXT("		█                █")<<endl;
							cout<<WHITE_TEXT("		█")GREEN_TEXT("   1- Create")WHITE_TEXT("    █")<<endl;
							cout<<WHITE_TEXT("		█")MAGENTA_TEXT("   2- Modify")WHITE_TEXT("    █")<<endl;
							cout<<WHITE_TEXT("		█")RED_TEXT("   3- Delete")WHITE_TEXT("    █")<<endl;
							cout<<WHITE_TEXT("		█")WHITE_TEXT("   4- Find")WHITE_TEXT("      █")<<endl;
							cout<<WHITE_TEXT("		█") CYAN_TEXT("   5- Go Back")WHITE_TEXT("   █")<<endl;
							cout<<WHITE_TEXT("		█                █")<<endl;
							cout<<WHITE_TEXT("		█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█")<<endl;
							cout<<endl;
							cout<<"Choose an option \t";
							cin>>op2;
							 while (cin.fail()) 
						    {
						        cin.clear(); // clear input buffer to restore cin to a usable state
						        cin.ignore(INT_MAX, '\n'); // ignore last input
						        cout<<"You can only enter numbers."<<endl;
						        cout<<"Choose an option."<<endl;
						        cin>>op2;
						    }
						    switch(op2) 
								{
									case 1:

										clearCon();
										createCharacter();
										pressAnyToContinue();
										main();
										
										break;
									case 2:
										clearCon();
										modifyAccount();
										pressAnyToContinue();
										main();
										break;
									case 3:

										clearCon();
										removeCharacter();
										pressAnyToContinue();
										clearCon();
										main();
										break;
									case 4:

										clearCon();
										findPlayer();
										pressAnyToContinue();
										clearCon();
										main();
										
										break;
									case 5:

										clearCon();
										main();
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
			default:
				cout<<endl;
				cout<<"Invalid Number! Try Again"<<endl;
				main();
				break;
		}
	return 0;
}

