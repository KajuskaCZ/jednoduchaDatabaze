#include "Create.h"

Create::Create() {

}

Create::~Create() {}

bool Create::makeCommand(Database & database, string line) {
	string tmp;
	unsigned int i = 0;
	string tableValues;
	int tableColumns = 0;

	while (line[i] != '(') {
		if (i == line.size() - 1) {
			cout << "Bad command." << endl;
			return false;
		}
		if (line[i] == ' ') {
			tmp.clear();
		}
		else{
			tmp += line[i];
		}
		++i;
	}
	++i;
	//cout << "tableName: " << tmp << endl;

	for (unsigned int j = i; j < line.size() - 2; ++j) {
		tableValues += line[j];
		if (line[j] == ',' && line[j + 1] == ' ') {
			tableValues += ' ';
			++tableColumns;
			++j;
		}
	}
	if (tableValues.size() != 0) {
		++tableColumns;
	}
	//cout << "values: " << tableValues << endl;
	//cout << "columns: " << tableColumns << endl;
	addTable(database, tmp, tableColumns, tableValues);
	return true;
}

bool Create::addTable(Database & database, string name, int columns, string input) {
	string line;
	string tmp;
	string tmpName;

	for (unsigned int i = 0; i < database.tables.size(); ++i) {
		if (database.tables[i].tableName == name) {
			cout << "Table with name" << name << " exist." << endl;
			return false;
		}
	}

	database.tables.push_back(Database::Table());
	database.tables[database.tables.size() - 1].tableName = name;
	database.tables[database.tables.size() - 1].tableColumns = columns;

	for (int i = 0; i < columns; ++i) {
		database.tables[database.tables.size() - 1].columnsItems.push_back(vector<string>());
	}

	int k = 0;
	istringstream iss(input);
	while (getline(iss, line)) {
		tmp.clear();
		for (unsigned int i = 0; i < line.size(); ++i) {
			if (line[i] == ' ') {
				tmpName = tmp;
				tmp.clear();
				continue;
			}
			if (line[i] == ',' && line[i + 1] == ' ') {
				database.tables[database.tables.size() - 1].columnsItems[k].push_back(tmp);
				database.tables[database.tables.size() - 1].columnsItems[k].push_back(tmpName);
				tmp.clear();
				++k;
				++i;
			}
			else {
				tmp += line[i];
			}
		}
		database.tables[database.tables.size() - 1].columnsItems[k].push_back(tmp);
		database.tables[database.tables.size() - 1].columnsItems[k].push_back(tmpName);
	}

	/*for (int i = 0; i < columns; ++i) {
	cout << tables[tables.size() - 1].columnsItems[i][0];
	if (i != columns - 1) {
	cout << ";";
	}
	}
	cout << endl;*/

	return true;
}