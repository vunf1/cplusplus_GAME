#include <iostream>
#include "libsqlite3/libsqlite.hpp" //DB Library SQLite3
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <vector> 
#include <iomanip>
using namespace std;








#include <typeinfo>




bool haveItem(auto& user,auto& item){
//test

	auto itemQ = db.get_statement();

	itemQ->set_sql("SELECT "+string(item)+" FROM playerHasitem WHERE playerID=?  ;");
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

}





bool upLevel(string user,int levelUP){//Joao
	/* Level up x times(levelUP) to the player user*/
	
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
        cur->set_sql( "SELECT * from itens where floor=?; ");
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
	int j,i;

    try
    {
	        // open database
	    int numberOFacc;

	    /* COUNT NUMBER OS ACC IN DB*/
        auto count = db.get_statement();
        count->set_sql( "SELECT COUNT(*) "
        	"from player ;");
        count->prepare();
        count->step();
        numberOFacc=count->get_int(0);
        //cout<<numberOFacc<<endl;
        /*For create a table with 1 2 3 4 5 as place for players ideia to improve*/


        cout<<"************************"<<endl;

        cout<<"	Ranking "<<endl;
        cout<<"| NICKNAME | SCORE | LEVEL |"<<endl;


        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player  ORDER BY score DESC; ");
        cur->prepare();

        cout<<"----------------------- "<<endl;
        while(cur->step()){

        	cout << cur->get_text(0) <<setfill(' ')<< setw(5) <<cur->get_text(3)<<setw(10)<< cur->get_text(2) << setw(20)<< endl;
        

        	cout<<setfill('-')<<setw(28)<<"-"<<endl;


        }

        cout<<"************************"<<endl; 


    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}




bool checkUser(string user){//Joao


	 	    
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
		while(password.length()<8)
		{
			cout<<"Need to have at least 8 digits\t"<<endl;

			cout<<"Password :\t";
			cin>>password;

		}

		//cout<<"User: "<<user<<" password : "<<password<<endl;


	   
 

	    auto insertQ = db.get_statement();
			insertQ->set_sql( "INSERT INTO player VALUES ("+transformToQuote(user)+", "+transformToQuote(password)+", 0, 0) ;" );
			insertQ->prepare();
			/*insertQ->bind( 1, user );
			insertQ->bind( 2, password );
			*/	
			if(insertQ->step()== SQLITE_OK ){
				cout<<"********************************"<<endl;
				cout<<"* Account created successfully *"<<endl;
				cout<<"********************************"<<endl;
				
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








char playerInfo(string user){



        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from player  where id=? ;");
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

void alterPass(string password,string user){//Joao




   
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

