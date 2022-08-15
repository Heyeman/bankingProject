
#include "dal.h"
using namespace std;
using namespace sql;

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "8520";
const string db = "banking";

    Driver* driver;
    Connection* con;
    
userDetails userFetch(string userName, string role) {
    Statement* stmt;
    ResultSet* res;
   
    driver = get_driver_instance();
  
    con = driver->connect(server, username, password);
           if (con->isValid()) {
        cout << "valid conn" << endl;}
   
    userDetails user;

    try {
        stmt = con->createStatement();
   
        stmt->execute("use " + db);

      
        res = stmt->executeQuery("select * from users where accountNumber = "+userName);
        
        
        while (res->next()) {
            user.fName = res->getString(2);
            user.accountNumber = res->getInt(1);
            user.password = res->getString(3);
            user.isFound = true;
            return user;
      } 

        



    }
    catch (SQLException e) {
        cout << "**********" << e.what() << endl;
        return user;
    }

    return user;
}


bool createUser(userDetails user, string role) {

    Statement* stmt;
    PreparedStatement* pstmt;

    driver = get_driver_instance();

    con = driver->connect(server, username, password);
    if (con->isValid()) {
        cout << "valid conn" << endl;
    }

    try {
        stmt = con->createStatement();
        stmt->execute("use " + db);
       
        pstmt = con->prepareStatement("insert into users(fname, lname, gender, amount) values (?,?,?,?)");
        string gend;
        gend += user.gender;
        pstmt->setString(1, user.fName);
        pstmt->setString(2, user.lName);
        pstmt->setString(3, gend);
        pstmt->setInt(4, user.amount);
       
     
        pstmt->execute();

        return true;
    }
    catch (SQLException e) {
        cout << "**********" << e.what() << endl;
        return false;
        
    }

}


userDetails fetchUser(int accountNumber) {

    Statement* stmt;
    ResultSet* res;

    driver = get_driver_instance();

    con = driver->connect(server, username, password);
    if (con->isValid()) {
        cout << "valid conn" << endl;
    }

    userDetails user;

    try {
        stmt = con->createStatement();

        stmt->execute("use " + db);


        res = stmt->executeQuery("select * from users where accountNumber = " + accountNumber);

        

        while (res->next()) {
            user.accountNumber = res->getInt(1);
            user.fName = res->getString(2);
            user.lName = res->getString(3);
            user.gender = res->getString(4)[0];
            user.amount = res->getInt(5);
            user.password = res->getString(6);
            
            
            user.isFound = true;
            return user;
        }
        





    }
    catch (SQLException e) {
        cout << "**********" << e.what() << endl;
        return user;
    }

    return user;
}