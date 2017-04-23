#include "Load.h"

Load::Load(){

}

Load::~Load(){}

bool Load::makeCommand(Database & database, string line) {
	string tmp;
	int i = 0;
	while (line[i] != '\"') {
		if (i == line.size() - 1) {
			cout << "Bad command." << endl;
			return false;
		}
		++i;
	}
	++i;
	while (line[i] != '\"') {
		if (i == line.size() - 1) {
			cout << "Bad command." << endl;
			return false;
		}
		tmp += line[i];
		++i;
	}
	//cout << tmp << endl;
	loadDatabase(database, tmp);
	return true;
}

bool Load::loadDatabase(Database & database, string fileName) {
	ifstream inFile;
	string line;
	string tmp;
	int k = 0;
	int column = 0;

	inFile.open(fileName);
	if (inFile.fail()) {
		return false;
	}

	while (getline(inFile, line)) {
		tmp.clear();
		if (line.size() == 0) {
			k = 0;
			continue;
		}
		if (k == 0) {
			++k;
			database.tables.push_back(Database::Table());
			for (unsigned int i = 0; i < line.size(); ++i) {
				if (line[i] == '(') {
					continue;
				}
				if (line[i] == ' ') {
					database.tables[database.tables.size() - 1].tableName = tmp;
					tmp.clear();
				}
				else if (line[i] == ')') {
					database.tables[database.tables.size() - 1].tableColumns = atoi(tmp.c_str());
					for (int i = 0; i < database.tables[database.tables.size() - 1].tableColumns; ++i) {
						database.tables[database.tables.size() - 1].columnsItems.push_back(vector<string>());
					}
					tmp.clear();
				}
				else {
					tmp += line[i];
				}
			}
			tmp.clear();
		}
		else {
			column = 0;
			for (unsigned int i = 0; i < line.size(); ++i) {
				if (line[i] == ';') {
					database.tables[database.tables.size() - 1].columnsItems[column].push_back(tmp);
					tmp.clear();
					++column;
				}
				else {
					tmp += line[i];
				}
			}
			database.tables[database.tables.size() - 1].columnsItems[column].push_back(tmp);
		}

	}

	/*for (unsigned int i = 0; i < tables.size(); ++i) {
	cout << tables[i].tableName << " (" << tables[i].tableColumns << ")" << endl;
	for (unsigned int j = 0; j < tables[i].columnsItems[0].size(); ++j) {
	for (unsigned int k = 0; k < tables[i].columnsItems.size(); ++k) {
	cout << tables[i].columnsItems[k][j];
	if (k != tables[i].columnsItems.size() - 1) {
	cout << ";";
	}
	}
	cout << endl;
	}
	cout << endl;
	}*/

	cout << "Database loaded from: " << fileName << endl;
	inFile.close();
	return true;
}
