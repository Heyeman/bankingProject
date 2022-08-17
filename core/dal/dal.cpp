
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
    


bool createUser(userDetails user, string role) {

    Statement* stmt;
    PreparedStatement* pstmt;

    driver = get_driver_instance();

    con = driver->connect(server, username, password);
   

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


userDetails fetchUser(string userName, string role) {

    Statement* stmt;
    ResultSet* res;

    driver = get_driver_instance();

    con = driver->connect(server, username, password);
    

    userDetails user;

    try {
        stmt = con->createStatement();

        stmt->execute("use " + db);


        res = stmt->executeQuery("select * from users where accountNumber = " + userName);

        

        while (res->next()) {
            if (role == "user") {
                user.accountNumber = res->getInt(1);
            }
            
        
            user.fName = res->getString(2);
            user.lName = res->getString(3);
            user.gender = res->getString(4)[0];
            user.amount = res->getInt(5);
            user.password = res->getString(6);
            user.isActive = res->getBoolean(7);
            
            
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



bool deleteUser(string userName, string role) {

    Statement* stmt;
  

    driver = get_driver_instance();

    con = driver->connect(server, username, password);
    

    try {
        stmt = con->createStatement();
        stmt->execute("use " + db);

        
        
        if (role == "user") {
            //pstmt = con->prepareStatement("update users set isActive = 0 where accountNumber = ?");
            bool res = stmt->execute("update users set isActive = 0 where accountNumber = " + userName);
           
            return true;

        }
       
    }
    catch (SQLException e) {
        cout << "**********" << e.what() << endl;
        return false;

    }
    cout << "biroo" << endl;
    
}

bool updateUser(int accNumber, string field, string value) {


    Statement* stmt;
    PreparedStatement* pstmt;

    driver = get_driver_instance();

    con = driver->connect(server, username, password);


    try {
        stmt = con->createStatement();
        stmt->execute("use " + db);

        string updateStr = "update users set " + field + " = ? where accountNumber = ?";

        pstmt = con->prepareStatement(updateStr);
        
            pstmt->setString(1, value);
   
        pstmt->setInt(2, accNumber);

        pstmt->execute();


        return true;




       

    }
    catch (SQLException e) {
        cout << "**********" << e.what() << endl;
        return false;

    }
    


}



bool createTransaction(transactionDetails transaction) {

    Statement* stmt;
    PreparedStatement* pstmt;

    driver = get_driver_instance();

    con = driver->connect(server, username, password);


    try {
        stmt = con->createStatement();
        stmt->execute("use " + db);

        pstmt = con->prepareStatement("insert into transactions(type, amount, who, whom) values (?,?,?,?)");
       
        pstmt->setString(1, transaction.type);
        pstmt->setInt(2, transaction.amount);
        pstmt->setString(3, transaction.who);
        pstmt->setString(4, transaction.whom);


        pstmt->execute();

        return true;
    }
    catch (SQLException e) {
        cout << "**********" << e.what() << endl;
        return false;

    }
}