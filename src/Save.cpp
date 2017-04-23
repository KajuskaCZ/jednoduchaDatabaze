#include "Save.h"

Save::Save() {

}
Save::~Save() {}

bool Save::makeCommand(Database & database, string line) {
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
	database.databazeName = tmp;
	databazeToFile(database);
	return true;
}

void Save::databazeToFile(Database & database) {
	ofstream outFile(database.databazeName);

	for (unsigned int i = 0; i < database.tables.size(); ++i) {
		outFile << database.tables[i].tableName << " (" << database.tables[i].tableColumns << ")" << endl;
		if (database.tables[i].tableColumns != 0) {
			for (unsigned int j = 0; j < database.tables[i].columnsItems[0].size(); ++j) {
				for (unsigned int k = 0; k < database.tables[i].columnsItems.size(); ++k) {
					outFile << database.tables[i].columnsItems[k][j];
					if (k != database.tables[i].columnsItems.size() - 1) {
						outFile << ";";
					}
				}
				outFile << endl;
			}
		}
		outFile << endl;
	}
	cout << "Database saved to: " << database.databazeName << endl;
	outFile.close();
}