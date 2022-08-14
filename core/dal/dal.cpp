
#include "Header.h"

using namespace std;
using namespace sql;

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "8520";

    Driver* driver;
    Connection* con;
    

void create(string dbname) {
    Statement* stmt;

    driver = get_driver_instance();
    con = driver->connect(server, username, password);

    if (con->isValid()) {
        cout << "valid conn"<<endl;
    }
    
    stmt = con->createStatement();

    string dbb = "create database if not exists " + dbname;
    cout << "dbname is " << dbb<<endl;
    //dbb.append(dbName);
    try {
        stmt->execute(dbb);

        cout << "created successfully" << endl;
    }
    catch(SQLException e) {
        cout << "error is " << endl;
        cout << e.what()<<endl;
    }
    //stmt->executeQuery("Create table if not exists users(id INT, name varchar(200))");


    delete stmt;


}

void fetch(string dbname, string tbName) {

    Statement* stmt;
    ResultSet* res;
    ResultSetMetaData* resData;
    driver = get_driver_instance();
    con = driver->connect(server, username, password);
    if (con->isValid()) {
        cout << "valid conn" << endl;
    }
    stmt = con->createStatement();
    try {
        stmt->execute("use " + dbname);

        cout << "connected to db" << endl;

    res = stmt->executeQuery("select * from " + tbName);
    resData = res->getMetaData();
    int count = resData->getColumnCount();
    cout << "it has " << count << " entries" << endl;
    for (int i = 0; i < count; i++) {
        cout << resData->getColumnName(i) << endl;
    }
    }
    catch (SQLException e) {
        cout << "Eroooooor  "<<endl;
        cout << e.what() << endl;
    }

}

void checkRun() {
    cout << "this is running ";

}
