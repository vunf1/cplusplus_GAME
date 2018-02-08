#include <iostream>
#include "libsqlitepp/libsqlite.hpp" //DB Library SQLite3
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input




using namespace std;
//GLOBAL Variables
char user[30];
char password[255];
int op;
char loginUser[100];
sqlite::sqlite db("dbPlayer");




void pressAnyToContinue(){//Joao
	cout << "Press ENTER to continue.";
	cin.clear();
	cin.sync();
	cin.ignore();
	cin.get();	

}


void clearCon()// Joao
    {
    /*Create 100 lines in the console giving the ideia of clean*/
    cout << string( 100, '\n' );
    }


#include "functions.h"
#include "model.h"








 void alterUser(string user,string username){//Joao


   
		    auto checkQ = db.get_statement();
		    checkQ->set_sql("UPDATE player SET id = "+transformToQuote(username)+" WHERE id="+transformToQuote(user)+";");
		    checkQ->prepare();

			if(checkQ->step()== SQLITE_OK ){
				cout<<"********************************"<<endl;
				cout<<"* Account update  successfully *"<<endl;
				cout<<"********************************"<<endl;
				
			}



 }





void removeCharacter(){//Joao

		cout<<"Username \t";
		cin>>user;
		cout<<"Password \t";
		cin>>password;


		if (checkUP(user,password)==true){
   
		    auto checkQ = db.get_statement();
		    checkQ->set_sql("Delete from player Where id="+transformToQuote(user)+"");
		    checkQ->prepare();

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






	char ans;
	string password;
	cout<<"What is your new password ?\t";
	cin>>password;
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



char playerInfo(string user){



        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player  where id=? ");
        cur->prepare();
        cur->bind(1,user);
        cout<<"************************"<<endl;

        cout<<"NICKNAME    LEVEL    SCORE "<<endl;

        while(cur->step()){

        	cout <<" "<< cur->get_text(0) << "		"<<cur->get_text(2)<< "	"<<cur->get_text(3) << endl;
        cout << endl;



        }

        cout<<"************************"<<endl;



}

char findPlayer(){
	string nick;

	cout<<"Who are you looking for?"<<endl;
	cout<<"NICKNAME - \t";
	cin>>nick;
	if(checkUser(nick)==1){
		playerInfo(nick);


	}




}



void moreOpction(){//Joao


	cout<<endl;
	cout<<"	   More Options - Character Creation"<<endl;
	cout<<"		 ________________"<<endl;
	cout<<"		!                !"<<endl;
	cout<<"		!                !"<<endl;
	cout<<"		!   1- Create    !"<<endl;
	cout<<"		!   2- Modify    !"<<endl;
	cout<<"		!   3- Delete    !"<<endl;
	cout<<"		!   4- Find      !"<<endl;
	cout<<"		!                !"<<endl;
	cout<<"		!________________!"<<endl;
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
				moreOpction();
				break;
			case 1:
				createCharacter();
				pressAnyToContinue();
				moreOpction();
				break;
			case 2:
				modifyAccount();
				pressAnyToContinue();
				moreOpction();
				break;
			case 3:
				removeCharacter();
				pressAnyToContinue();
				moreOpction();
				break;
			case 4:
				findPlayer();
				pressAnyToContinue();
				moreOpction();
				break;
			default:
				clearCon();
				cout<<endl;
				cout<<"Wrong Number! Try Again"<<endl;
				moreOpction();
				break;
		}




}



int openMenu(){



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
	cout<<"Choose a number \t";
	cin>>op;







	 while (cin.fail()) //Joao
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers."<<endl;
        cout << "Enter a number."<<endl;
        cin >> op;
    }
    return op;

}




int main() //Joao
{
	
		op=openMenu();
		string us;
		string pw;

		switch(op) //Joao
		{
			case 0:
				clearCon();
				cout<<endl;
				cout<<"Wrong Number! Try Again"<<endl;
				main();
				break;
			case 1:
				cout<<"Username\t";
				cin>>us;
				cout<<"Password\t";
				cin>>pw;
				while(login(us,pw)!=true){

					cout<<"Wrong credentials"<<endl;
					cout<<"Username\t";
					cin>>us;
					cout<<"Password\t";
					cin>>pw;
					login(us,pw);
				}
					Game(us);	
				break;
			case 2:
				rankingScore();
				pressAnyToContinue();
				main();
				break;
			case 3:

				moreOpction();
				break;
			case 4:
				break;
			case 5://TEST REMOVE

				cout<<"Username\t";
				cin>>us;
				addScore(us,10);
				break;
			default:
				cout<<endl;
				cout<<"Wrong Number! Try Again"<<endl;
				main();
				break;
		}
	return 0;
}
