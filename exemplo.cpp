#include <iostream>
#include "libsqlitepp/libsqlite.hpp" //DB Library SQLite3
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input

using namespace std;
//GLOBAL Variables
char user[30];
char password[20];
int op;
char loginUser[50];
sqlite::sqlite db("dbPlayer");




#include "functions.h"


void pressAnyToContinue(){//Joao
	cout << "Press any key to continue.";
	cin.ignore();
	cin.get();
}



void clearCon()// Joao
    {
    /*Create 100 lines in the console giving the ideia of clean*/
    	
    cout << string( 100, '\n' );
    }


char checkDB(){//Joao




    try
    {
	        // open database

        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player; ");
        cur->prepare();
    
        while( cur->step() )
            cout << cur->get_text(0) << ", "<<cur->get_text(1) << ", "<<cur->get_text(2) << ", "<<cur->get_text(3) << endl;
        cout << endl;

    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

}



char rankingScore(){//Joao
	int j,i;

    try
    {
	        // open database
	    int numberOFacc;

	    /* COUNT NUMBER OS ACC IN DB*/
        auto count = db.get_statement();
        count->set_sql( "SELECT COUNT(*) "
        	"from player");
        count->prepare();
        count->step();
        numberOFacc=count->get_int(0);
        //cout<<numberOFacc<<endl;
        /*For create a table with 1 2 3 4 5 as place for players ideia to improve*/


        cout<<"************************"<<endl;

        cout<<"	Ranking "<<endl;
        cout<<"NICKNAME   	SCORE "<<endl;

        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player  ORDER BY score DESC; ");
        cur->prepare();

        while(cur->step()){

        	cout <<" "<< cur->get_text(0) << "		"<<cur->get_text(3) << endl;
        cout << endl;



        }

        cout<<"************************"<<endl;


    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}



int checkUser(string user){//Joao


	 	    
	    auto checkQ = db.get_statement();
	    checkQ->set_sql("SELECT COUNT(*) from player Where id=?");
	    checkQ->prepare();
		checkQ->bind( 1, user);
	    checkQ->step();
	    if(checkQ->get_int(0)==1){
	    	return 1;
	    }else{
	    	return 0;
	    }


}

string transformToQuote( const string& var ) { // Joao
	/*Transform variables into quotes to SQL Query

	To pass a string by reference, you use the data type string&.

	Adding the const qualifier to a reference (or a pointer) just says that the code promises not to alter the contents of the object being referenced (or being pointed to). Using const does not mean that the object occupies a read-only area of memory.*/
	return string("'") + var + string("'");
}


char createCharacter(){//Joao

	bool check;
	try{

	 	 

		cout<<" ###  Let's create your account  ###"<<endl;

		cout<<"Input Username 	\t";
		cin>>user;
		/*
		if(user=="quit"||"Quit"||"QUit"||"QUIt"||"QUIT"||"quiT"||"quIT"||"qUIT"){
			cout<<"That word is reserved for quit the game"<<endl;
			cout<<"If you want to exit from this, type again 'quit'"<<endl;

			cout<<"Input Username 	\t";
			cin>>user;

				if(user=="quit"||"Quit"||"QUit"||"QUIt"||"QUIT"||"quiT"||"quIT"||"qUIT"){
					return 0;
				}


		}*/

	    //cout<<checkQ->get_int(0)<<endl;
	    check=checkUser(user);

	    while(check==1)
	    {

				cout<<"**************************"<<endl;
				cout<<"*	ERROR            *"<<endl;
				cout<<"*  ------------------    *"<<endl;
				cout<<"* Username in use        *"<<endl;
				cout<<"*        SORRY           *"<<endl;
				cout<<"**************************"<<endl;

				cout<<"Input an Username that not exist already	\t";
				cin>>user;
				check=checkUser(user);

	    }


		cout<<"Password (at least 8 digits)\t";
		cin>>password;
		while(strlen(password)<8)
		{
			cout<<"Need to have at least 8 digits\t"<<endl;

			cout<<"Password :\t";
			cin>>password;

		}

		//cout<<"User: "<<user<<" password : "<<password<<endl;


	   
 

	    auto insertQ = db.get_statement();
			insertQ->set_sql( "INSERT INTO player VALUES ("+transformToQuote(user)+", "+transformToQuote(password)+", 0, 0)" );
			insertQ->prepare();
			/*insertQ->bind( 1, user );
			insertQ->bind( 2, password );
			*/	
			if(insertQ->step()== SQLITE_OK ){
				cout<<"********************************"<<endl;
				cout<<"* Account created successfully *"<<endl;
				cout<<"********************************"<<endl;
				
			}
			




	}
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }


}




int checkUP(string user,string password){//Joao
	/*check if username and password exist on db*/


	 	    
	    auto checkQ = db.get_statement();
	    checkQ->set_sql("SELECT COUNT(*) from player Where id=? and password=?");
	    checkQ->prepare();
		checkQ->bind( 1, user);
		checkQ->bind( 2, password);
	    checkQ->step();
	    if(checkQ->get_int(0)==1){
	    	return 1;
	    }else{
	    	return 0;
	    }


}




int removeCharacter(){//Joao

		bool OK;
		cout<<"Username \t";
		cin>>user;
		cout<<"Password \t";
		cin>>password;
		OK=checkUP(user,password);
		if (OK==true){
   
		    auto checkQ = db.get_statement();
		    checkQ->set_sql("Delete from player Where id=?");
		    checkQ->prepare();
			checkQ->bind( 1, user);

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



 void alterUser(string user,string username){//Joao


   
		    auto checkQ = db.get_statement();
		    checkQ->set_sql("UPDATE player SET id = ? WHERE id=?;");
		    checkQ->prepare();
			checkQ->bind( 1, username);
			checkQ->bind( 2, user);

			if(checkQ->step()== SQLITE_OK ){
				cout<<"********************************"<<endl;
				cout<<"* Account update  successfully *"<<endl;
				cout<<"********************************"<<endl;
				
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


void alterPass(string password,string user){




   
		    auto checkQ = db.get_statement();
		    checkQ->set_sql("UPDATE player SET password = ? WHERE id=?;");
		    checkQ->prepare();
			checkQ->bind( 1, password);
			checkQ->bind( 2, user);

			if(checkQ->step()== SQLITE_OK ){
				cout<<"********************************"<<endl;
				cout<<"* Password update successfully *"<<endl;
				cout<<"********************************"<<endl;
				
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
	cout<<"	   More Opctions - Character Creation"<<endl;
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

		switch(op) //Joao
		{
			case 0:
				clearCon();
				cout<<endl;
				cout<<"Wrong Number! Try Again"<<endl;
				main();
				break;
			case 1:
				cout<<"OPEN SOMETHING ON 1"<<endl;
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
				grabItensfloor(2);
				break;
			default:
				cout<<endl;
				cout<<"Wrong Number! Try Again"<<endl;
				main();
				break;
		}
	return 0;
}
