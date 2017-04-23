#include "Insert.h"

Insert::Insert() {

}

Insert::~Insert() {}

bool Insert::makeCommand(Database & databaze, string line) {
	string tmp;
	int i = 0;
	int isName = 0;
	string tableValues;
	int valuesNumber = 0;

	while (line[i] != '(') {
		if (i == line.size() - 1) {
			cout << "Bad command." << endl;
			return false;
		}
		if (line[i] == ' ') {
			++isName;
			++i;
			continue;
		}
		if (isName == 2) {
			tmp += line[i];
		}
		++i;
	}
	++i;

	for (unsigned int j = i; j < line.size() - 2; ++j) {
		if (line[j] == '"') {
			continue;
		}
		if (line[j] == ',' && line[j + 1] == ' ') {
			++valuesNumber;
		}
		tableValues += line[j];
	}
	if (tableValues.size() != 0) {
		++valuesNumber;
	}

	//cout << "tableName: " << tmp << endl;
	//cout << "tableValues: " << tableValues << endl;

	addValues(databaze, tmp, tableValues, valuesNumber);
	return true;
}

bool Insert::values(string valueType, string value) {
	if (valueType == "VARCHAR(255)") {
		for (unsigned int i = 0; i < value.size(); ++i) {
			if ((value[i] < 64 || value[i] > 90) && (value[i] < 97 || value[i] > 122))  {
				cout << "Bad format of type VARCHAR." << endl;
				return false;
			}
		}
	}

	if (valueType == "INTEGER") {
		for (unsigned int i = 0; i < value.size(); ++i) {
			if (value[i] < 48 || value[i] > 57) {
				cout << "Bad format of type INTEGER." << endl;
				return false;
			}
		}
	}

	if (valueType == "DATE") {
		if (value.size() != 12) {
			cout << "Bad format of type DATE." << endl;
			return false;
		}
		for (int i = 0; i < 2; ++i) {
			if (value[i] < 48 || value[i] > 57) {
				cout << "Bad format of type DATE." << endl;
				return false;
			}
		}
		if (value[2] != '.') {
			cout << "Bad format of type DATE." << endl;
			return false;
		}
		if (value[3] != ' ') {
			cout << "Bad format of type DATE." << endl;
			return false;
		}
		for (int i = 4; i < 6; ++i) {
			if (value[i] < 48 || value[i] > 57) {
				cout << "Bad format of type DATE." << endl;
				return false;
			}
		}
		if (value[6] != '.') {
			cout << "Bad format of type DATE." << endl;
			return false;
		}
		if (value[7] != ' ') {
			cout << "Bad format of type DATE." << endl;
			return false;
		}
		for (int i = 8; i < 12; ++i) {
			if (value[i] < 48 || value[i] > 57) {
				cout << "Bad format of type DATE." << endl;
				return false;
			}
		}
	}

	if (valueType == "DOUBLE") {
		int k = 0;
		for (unsigned int i = 0; i < value.size(); ++i) {
			if (value[i] < 46 || value[i] > 57) {
				cout << "Bad format of type DOUBLE." << endl;
				return false;
			}
			if (value[i] == 47) {
				cout << "Bad format of type DOUBLE." << endl;
				return false;
			}
			if (value[i] == 46) {
				++k;
			}
		}
		if (k > 1) {
			cout << "Bad format of type DOUBLE." << endl;
			return false;
		}
		if (k == 0) {
			cout << "Bad format of type DOUBLE." << endl;
			return false;
		}
	}

	return true;
}

bool Insert::addValues(Database & databaze, string tableName, string input, int valuesNumber) {
	istringstream iss(input);
	string line;
	string tmp;
	int index = 0;
	int k = 0;
	bool exist = false;

	for (unsigned int i = 0; i < databaze.tables.size(); ++i) {
		if (databaze.tables[i].tableName == tableName) {
			index = i;
			exist = true;
			break;
		}
	}

	if (!exist) {
		cout << "Table with name " << tableName << " does not exist." << endl;
		return false;
	}

	if (valuesNumber != databaze.tables[index].tableColumns) {
		cout << "Bad number of Values: " << valuesNumber << endl;
		return false;
	}

	while (getline(iss, line)) {
		tmp.clear();
		for (unsigned int i = 0; i < line.size(); ++i) {
			if (line[i] == ',' && line[i + 1] == ' ') {
				if (!values(databaze.tables[index].columnsItems[k][0], tmp)) {
					return false;
				}
				databaze.tables[index].columnsItems[k].push_back(tmp);
				tmp.clear();
				++k;
				++i;
			}
			else{
				tmp += line[i];
			}
		}
		if (!values(databaze.tables[index].columnsItems[k][0], tmp)) {
			return false;
		}
		databaze.tables[index].columnsItems[k].push_back(tmp);
	}

	return true;
}
