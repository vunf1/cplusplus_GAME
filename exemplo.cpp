#include <iostream>
#include "libsqlitepp/libsqlite.hpp" //DB Library SQLite3

#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input

using namespace std;

char user[30];
char password[20];
int op;





void removeCharater(){


	    sqlite::sqlite db( "dbPlayer" );    // open database

        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player; ");
        cur->prepare();




}









char checkDB(){//Testes




    try
    {
	    sqlite::sqlite db( "dbPlayer" );    // open database

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
	string matrix[2][3];
    try
    {
	    sqlite::sqlite db( "dbPlayer" );    // open database
	    int numberOFacc;

	    /* COUNT NUMBER OS ACC IN DB*/
        auto count = db.get_statement();
        count->set_sql( "SELECT COUNT(*) "
        	"from player");
        count->prepare();
        count->step();
        numberOFacc=count->get_int(0);
        cout<<numberOFacc<<endl;



    	int counts=0;
	    string matrix[numberOFacc][3];
        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player  ORDER BY score DESC; ");
        cur->prepare();
        cout<<"************************"<<endl;

        cout<<"	Ranking "<<endl;
        cout<<"NICKNAME   	SCORE "<<endl;

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













int checkUser(string user){


	 	sqlite::sqlite db( "dbPlayer" );    
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
	/*Transform variables into quotes to SQL Query*/
	return string("'") + var + string("'");
}


char createCharater(){//Joao

	bool check;
	try{

	 	sqlite::sqlite db( "dbPlayer" ); 

		cout<<" ###  Let's create your account  ###"<<endl;

		cout<<"Input Username you wish if not exist already	\t";
		cin>>user;

	    //cout<<checkQ->get_int(0)<<endl;
	    check=checkUser(user);

	    while(check==1)
	    {

				cout<<"**************************"<<endl;
				cout<<"*	ERROR            *"<<endl;
				cout<<"*  ------------------    *"<<endl;
				cout<<"* Nickname in use        *"<<endl;
				cout<<"*        SORRY           *"<<endl;
				cout<<"**************************"<<endl;

				cout<<"Input Username if not exist already	\t";
				cin>>user;
				check=checkUser(user);

	    }


		while(strlen(password)<8)
		{

			cout<<"Password at least 8 digits\t"<<endl;
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


void clearCon()// Joao
    {
    /*Create 100 lines in the console giving the ideia of clean*/
    	
    cout << string( 100, '\n' );
    }


void moreOpction(){//Joao


	cout<<endl;
	cout<<"	   More Opctions - Charater Creation"<<endl;
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
				createCharater();
				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			default:
				clearCon();
				cout<<endl;
				cout<<"Wrong Number! Try Again"<<endl;
				moreOpction();
				break;
		}




}








int main() //Joao
{
	int op;
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
				break;
			case 3:

				moreOpction();
				break;
			case 4:
				break;
			case 5://TEST REMOVE
				createCharater();
				break;
			default:
				cout<<endl;
				cout<<"Wrong Number! Try Again"<<endl;
				main();
				break;
		}
	return 0;
}
