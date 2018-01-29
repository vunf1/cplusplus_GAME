#include <iostream>
#include "libsqlitepp/libsqlite.hpp"

#include <string> // String Library
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input

using namespace std;

char user[50],password[50];
int op;




char checkDB(){




    try
    {
	    sqlite::sqlite db( "dbPlayer.sqlite" );    // open database

        string userInput;
        getline( cin, userInput );

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



int createCharater(){

	cout<<"Input Username and password (split by space)\t";
	cin>>user>>password;
	cout<<"User: "<<user<<" password :"<<password<<endl;

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
				cout<<"Input Username and password (split by space)"<<endl;
				cin>>user>>password;
				break;
			case 3:
				cout<<"Input Username and password (split by space)"<<endl;
				cin>>user>>password;
				break;
			case 4:
				cout<<"Input Username"<<endl;
				cin>>user;
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
	cout<<"		!   3- Reset     !"<<endl;
	cout<<"		!   4- More      !"<<endl;
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
				cout<<"OPEN SOMETHING ON 2"<<endl;
				break;
			case 3:
				cout<<"OPEN SOMETHING ON 3"<<endl;
				break;
			case 4:
				moreOpction();
				break;
			case 5://TEST REMOVE
				checkDB();
				break;
			default:
				cout<<endl;
				cout<<"Wrong Number! Try Again"<<endl;
				main();
				break;
		}
	return 0;
}
