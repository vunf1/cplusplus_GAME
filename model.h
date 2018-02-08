#include <iostream>
#include "libsqlitepp/libsqlite.hpp" //DB Library SQLite3
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input

using namespace std;



bool login(string user,string password){
	/*ckeck credicials if correct send true*/



	    auto checkQ = db.get_statement();
	    checkQ->set_sql("SELECT COUNT(*) from player Where id="+transformToQuote(user)+" AND password="+transformToQuote(password)+"");
	    checkQ->prepare();
	    checkQ->step();
	    if(checkQ->get_int(0)==1){
	    	return 1;
	    }else{
	    	return 0;
	    }






}


bool addScore(string user,int score){//Joao
	/* Take username and +score to add to the player actual score*/
	
		int addPoints;

		auto cur = db.get_statement();
        cur->set_sql( "SELECT score from player where id="+transformToQuote(user)+"; ");
        cur->prepare();
        while( cur->step() ){
        	//listItens.push_back(cur->get_text(0));

          addPoints=cur->get_int(0); 
        
        }
        addPoints=addPoints+score;
        //cout<<addPoints<<endl;

		auto add = db.get_statement();
        add->set_sql( "UPDATE player SET score=? WHERE id="+transformToQuote(user)+" ;");
        add->prepare();
        add->bind(1,addPoints);
        add->step();

}





bool upLevel(string user,int levelUP){//Joao
	/* Level up x times(levelUP) to the player user*/
	
		int plusLevel;

		auto cur = db.get_statement();
        cur->set_sql( "SELECT level from player where id="+transformToQuote(user)+"; ");
        cur->prepare();
        while( cur->step() ){
        	//listItens.push_back(cur->get_text(0));

          plusLevel=cur->get_int(0); 
        
        }
        plusLevel=plusLevel+levelUP;

		auto add = db.get_statement();
        add->set_sql( "UPDATE player SET level=? WHERE id="+transformToQuote(user)+" ;");
        add->prepare();
        add->bind(1,plusLevel);
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






bool checkUP(string user,string password){//Joao
	/*check if username and password exist on db*/


	 	    
	    auto checkQ = db.get_statement();
	    checkQ->set_sql("SELECT COUNT(*) from player Where id="+transformToQuote(user)+" and password="+transformToQuote(password)+"");
	    checkQ->prepare();
	    checkQ->step();
	    if(checkQ->get_int(0)==1){
	    	return 1;
	    }else{
	    	return 0;
	    }


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
