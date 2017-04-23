#include "Delete.h"

Delete::Delete() {

}

Delete::~Delete() {}

bool Delete::makeCommand(Database & database, string line) {
	string tmp;
	int k = 0;
	for (unsigned int i = 0; i < line.size() - 1; ++i) {
		if (line[i] == ' ') {
			++k;
			continue;
		}
		if (k == 2) {
			tmp += line[i];
		}
	}
	//cout << "delete table: " << tmp << endl;
	if (k != 2) {
		cout << "Bad command." << endl;
		return false;
	}
	delTable(database, tmp);
	return true;
}

bool Delete::delTable(Database & database, string tableName) {
	unsigned int index = 0;
	bool exist = false;

	for (unsigned int i = 0; i < database.tables.size(); ++i) {
		if (database.tables[i].tableName == tableName) {
			index = i;
			exist = true;
			break;
		}
	}

	if (!exist) {
		cout << "Table with name " << tableName << " does not exist." << endl;
		return false;
	}

	if (index == database.tables.size() - 1) {
		database.tables.pop_back();
	}
	else {
		for (unsigned int i = index; i < database.tables.size() - 1; ++i) {
			database.tables[i] = database.tables[i + 1];
		}
		database.tables.pop_back();
	}

	return true;
}
