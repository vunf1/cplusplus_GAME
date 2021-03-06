#include <iostream>
#include "libsqlite3/libsqlite.hpp" //DB Library SQLite3
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <vector> 
#include <iomanip>

using namespace std;

#include <typeinfo>



char playerItemBoard(auto& user){//Joao
/*SAVE PLAYER INFO INTO VECTOR:
 * THIS VECTOR IS GLOBAL EVERY FUNCTIONS HAVE ACCESS
[0]NICKNAME
[1]LEVEL
[2]SCORE



This file is static futher updates during the game call again this function to update status
*/

        playerItem.clear();
        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from playerHasitem  where PlayerID=? ");
        cur->prepare();
        cur->bind(1,user);

        while(cur->step()){

        	playerItem.emplace_back(cur->get_text(1)) ;
        	playerItem.emplace_back(cur->get_text(2)) ;
        	playerItem.emplace_back(cur->get_text(3)) ;
        	playerItem.emplace_back(cur->get_text(4)) ;
        	playerItem.emplace_back(cur->get_text(5)) ;
        	playerItem.emplace_back(cur->get_text(6)) ;
        	playerItem.emplace_back(cur->get_text(7)) ;
        	playerItem.emplace_back(cur->get_text(8)) ;
        	playerItem.emplace_back(cur->get_text(9)) ;
        	playerItem.emplace_back(cur->get_text(10)) ;
        }
}



bool itemTurnedON(auto& user,auto& item){//Joao
/* Update entity where are the item(attribute*) of the players and set that attribute to 1 , means have now that item and cant grab it again 

NOT handle the response, you handle when call it*/

	auto itemQ = db.get_statement();

	itemQ->set_sql("UPDATE playerHasitem set "+string(item)+" = 1 WHERE PlayerID=?  ;");
	itemQ->prepare();
	itemQ->bind(1, user);
	//itemQ->bind(1, user);
	if(itemQ->step()== SQLITE_OK){
		return 1;
	}else{
		return 0;
	}
}

bool haveItem(auto& user,auto& item){//Joao
/*Will check if user have that item , and return the bool inside record on databse*/

	auto itemQ = db.get_statement();

	itemQ->set_sql("SELECT "+string(item)+" FROM playerHasitem WHERE PlayerID=?  ;");
	itemQ->prepare();
	itemQ->bind(1, user);
	//itemQ->bind(1, user);
	itemQ->step();
	return itemQ->get_int(0);
}



bool checkUP(auto& user,auto& password){//Joao
/*check if username and password exist on db*/

		    auto checkQ = db.get_statement();
		    checkQ->set_sql("SELECT count(*) FROM player WHERE id="+transformToQuote(user)+" and password=? ;");
		    checkQ->prepare();
			checkQ->bind( 1, password);

			checkQ->step();
				
			return checkQ->get_int(0);
}


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
				
        cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
				cout<<YELLOW_TEXT("★\t")WHITE_TEXT("Account ")RED_TEXT("removed")WHITE_TEXT(" successfully")YELLOW_TEXT("\t★")<<endl;
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
				
			}

		}else{

			cout<<"Invalid username or password"<<endl;
			cout<<"try again"<<endl;
			removeCharacter();
		}
}

bool addScore(string user,int score){//Joao
	/* Take username and +score to add to the player actual score*/
	
		int addPoints;

		auto cur = db.get_statement();
        cur->set_sql( "SELECT score from player where id=?; ");
        cur->prepare();
        cur->bind(1,user);
        while( cur->step() ){
        	//listItens.push_back(cur->get_text(0));

          addPoints=cur->get_int(0); 
        }

        addPoints=addPoints+score;
        
        //cout<<addPoints<<endl;
		auto add = db.get_statement();
        add->set_sql( "UPDATE player SET score=?1 WHERE id=?2 ;");
        add->prepare();
        add->bind(1,addPoints);
        add->bind(2,user);
        add->step();
    
        playerInfo2vector(detailInfo[0]); 
}


bool upLevel(string user,int levelUP){//Joao
	/* Level up x times(levelUP) on user*/
	
		int plusLevel;

		auto cur = db.get_statement();
        cur->set_sql( "SELECT level from player where id=?; ");
        cur->prepare();
        cur->bind(1,user);
        while( cur->step() ){
        	
          //listItens.push_back(cur->get_text(0));
          plusLevel=cur->get_int(0); 
        
        }
        plusLevel=plusLevel+levelUP;

		auto add = db.get_statement();
        add->set_sql( "UPDATE player SET level=?1 WHERE id=?2 ;");
        add->prepare();
        add->bind(1,plusLevel);
        add->bind(2,user);
        add->step();
}



char grabItensfloor(int floor){//Joao

		//TESTING
        auto cur = db.get_statement();
        cur->set_sql( "SELECT item from itens where floor=?; ");
        cur->prepare();
        cur->bind(1,floor);
        while( cur->step() ){
        	//listItens.push_back(cur->get_text(0));

          //  cout << cur->get_text(0) << endl;
        
        }
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
	/*Ranking of all users of the game and display inside a personalized table*/
	int j,i;

    try
    {
	    // open database
	    int numberOFacc=1;

	    /* COUNT NUMBER OS ACC IN DB*/
        auto count = db.get_statement();
        count->set_sql( "SELECT COUNT(*) "
        	"from player ;");
        count->prepare();
        count->step();
        //numberOFacc=count->get_int(0);
        //cout<<numberOFacc<<endl;
        /*For create a table with 1 2 3 4 5 as place for players ideia to improve*/

        cout<<"	Ranking "<<endl;

        cout<<"|P.|NICKNAME|SCORE|LEVEL"<<endl;
        cout<<YELLOW_TEXT("★★ ★★ ★★ ★★ ★★ ★★ ★★ ★★ ★★")<<endl;

        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player  ORDER BY score DESC; ");
        cur->prepare();

        cout<<"---------------------------- "<<endl;
        while(cur->step()){
        	string name = cur->get_text(0);
        	string score = cur->get_text(3);

        	cout<<numberOFacc<<". " << cur->get_text(0) << setfill(' ')<< setw(15-name.length()) <<cur->get_text(3)<<setw(10)<< cur->get_text(2) << setw(20)<< endl;
        	cout<<setfill('-')<<setw(28)<<"-"<<endl;
        	numberOFacc++;
        }

        cout<<YELLOW_TEXT("★★ ★★ ★★ ★★ ★★ ★★ ★★ ★★ ★★")<<endl; 
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}


bool checkUser(string user){//Joao
	/*check user username on DB*/

	    auto checkQ = db.get_statement();
	    checkQ->set_sql("SELECT COUNT(*) from player Where id=?;");
	    checkQ->prepare();
		checkQ->bind( 1, user);
	    checkQ->step();
	    if(checkQ->get_int(0)==1){
	    	return 1;
	    }else{
	    	return 0;
	    }
}

bool checkPW(string password){//Joao
	/*NOT IN ?USE PROTOTYPE because bind() dont work*/
 	    
	    auto checkQ = db.get_statement();
	    checkQ->set_sql("SELECT COUNT(*) from player Where password=?;");
	    checkQ->prepare();
		checkQ->bind( 1, password);
	    checkQ->step();
	    if(checkQ->get_int(0)==1){
	    	return 1;
	    }else{
	    	return 0;
	    }
}


char createCharacter(){//Joao
/*Create user account on DB, check if username exist and lenght of pw(<=8)*/
	bool check;
	try{

		cout<<" ###  Let's create your account  ###"<<endl;

		cout<<"Input Username 	\t";
		cin>>user;
	    check=checkUser(user);

	    while(check==1)
	    {

				
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
				cout<<YELLOW_TEXT("★\t")RED_TEXT("ERROR")YELLOW_TEXT("\t★")<<endl;
				cout<<YELLOW_TEXT("★\t")WHITE_TEXT(" ------------------ ")YELLOW_TEXT("\t★")<<endl;
				cout<<YELLOW_TEXT("★\t")WHITE_TEXT("Username in use")YELLOW_TEXT("\t★")<<endl;
				cout<<YELLOW_TEXT("★\t\t")WHITE_TEXT("SORRY")YELLOW_TEXT("\t★")<<endl;
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
				cout<<"Input an Username that not exist already	\t";
				cin>>user;
				check=checkUser(user);

	    }


		cout<<"Password (at least 8 digits)\t";
		cin>>password;
		while(password.length()<8)
		{
			cout<<"Need to have at least 8 digits\t"<<endl;

			cout<<"Password :\t";
			cin>>password;

		}

	    auto insertQ = db.get_statement();
			insertQ->set_sql( "INSERT INTO player VALUES ("+transformToQuote(user)+", "+transformToQuote(password)+", 0, 0) ;" );
			insertQ->prepare();
			/*insertQ->bind( 1, user );
			insertQ->bind( 2, password );
			*/	
			if(insertQ->step()== SQLITE_OK ){
				
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
				cout<<YELLOW_TEXT("★ ")WHITE_TEXT("Account ")GREEN_TEXT("created")WHITE_TEXT(" successfully")YELLOW_TEXT(" ★")<<endl;
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;

				
			}

	    auto insertQ2 = db.get_statement();
			insertQ2->set_sql( "INSERT INTO playerHasitem VALUES (?, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) ;" );
			insertQ2->prepare();
			insertQ2->bind(1,user);
			insertQ2->step();
	}
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}


char playerInfo(string user){//Joao
	/*Find a spefic player and display him into console*/

        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player  where id=? ;");
        cur->prepare();
        cur->bind(1,user);
        cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;

        cout<<"NICKNAME    LEVEL    SCORE "<<endl;

        while(cur->step()){

        	cout <<" "<< cur->get_text(0) << "		"<<cur->get_text(2)<< "	"<<cur->get_text(3) << endl;
        cout << endl;
        }

        cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
}

void alterPass(string password,string user){//Joao
   /*Update user password on DB*/
		    auto checkQ = db.get_statement();
		    checkQ->set_sql("UPDATE player SET password = ? WHERE id=?;");
		    checkQ->prepare();
			checkQ->bind( 1, password);
			checkQ->bind( 2, user);

			if(checkQ->step()== SQLITE_OK ){
				
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
				cout<<YELLOW_TEXT("★ ")WHITE_TEXT("Password ")CYAN_TEXT("updated")WHITE_TEXT(" successfully")YELLOW_TEXT("★")<<endl;
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
				
			}
}


 void alterUser(string user,string username){//Joao
 	/*Update user username on DB*/
  
		    auto checkQ = db.get_statement();
		    checkQ->set_sql("UPDATE player SET id = "+transformToQuote(username)+" WHERE id="+transformToQuote(user)+";");
		    checkQ->prepare();

			if(checkQ->step()== SQLITE_OK ){
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
				cout<<YELLOW_TEXT("★ ")WHITE_TEXT("Username ")CYAN_TEXT("updated")WHITE_TEXT(" successfully")YELLOW_TEXT("★")<<endl;
				cout<<YELLOW_TEXT("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★")<<endl;
			}
 }