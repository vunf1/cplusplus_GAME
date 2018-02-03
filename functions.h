
#include <iostream>
#include "libsqlitepp/libsqlite.hpp" //DB Library SQLite3

#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <vector>
using namespace std;

/* FUTURE USE : ORGANIZE FUNCTION IN IT*/



//vector<char> listItens;
char grabItensfloor(int floor){



        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from itens where floor=?; ");
        cur->prepare();
        cur->bind(1,floor);
        while( cur->step() ){
        	//listItens.push_back(cur->get_text(0));

          //  cout << cur->get_text(0) << endl;
        
        }


}