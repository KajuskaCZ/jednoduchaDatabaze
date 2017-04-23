#ifndef DATABASE_H
#define	DATABASE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

/// Class represents tables group to database. 
class Database {
public:
	/// Struct represents one table.
	struct Table {
		string tableName; //!< Name of table.
		int tableColumns; //!< Number of table columns.
		vector< vector<string> > columnsItems; //!< Vector of table values.
	};
	vector <Table> tables; //!< Vector of all tables in database.
	string databazeName; //!< Database name.
	//! Default empty constructor.
	Database();
	//! Default empty destructor.
	~Database();

private:

};

#endif	/* DATABASE_H */
