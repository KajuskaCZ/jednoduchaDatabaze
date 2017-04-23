#include "Select.h"


Select::Select()
{
}

Select::~Select()
{
}

bool Select::makeCommand(Database & database, string line) {
	string tmp;
	unsigned int i = 0;
	string tableName;
	vector<string> columnName;
	bool isAll = false;
	int index = 0;
	bool exist = false;

	int isWhere = 0;
	for (unsigned int j = 0; j < line.size(); ++j) {
		if (line[j] == ',' && line[j + 1] == ' ') {
			++j;
			continue;
		}
		if (line[j] == ' ') {
			++isWhere;
		}
	}

	if (isWhere > 3) {
		selectTableWhere(database, line);
	}
	else {
		while (line[i] != ' ') {
			if (i == line.size() - 1) {
				cout << "Bad command." << endl;
				return false;
			}
			++i;
		}
		++i;

		if (line[i] == '*') {
			isAll = true;
			++i;
		}
		else {
			while (line[i] != ' ') {
				if (line[i] == ',' && line[i + 1] == ' ') {
					columnName.push_back(tmp);
					//cout << tmp << endl;
					++i;
					tmp.clear();
				}
				else {
					tmp += line[i];
				}
				++i;
			}
			columnName.push_back(tmp);
			//cout << tmp << endl;
			tmp.clear();
		}
		++i;

		while (line[i] != ' ') {
			if (i == line.size() - 1) {
				cout << "Bad command." << endl;
				return false;
			}
			++i;
		}
		++i;

		while (i < line.size() - 1) {
			tmp += line[i];
			++i;
		}
		tableName = tmp;
		//cout << tableName << endl;

		for (unsigned int j = 0; j < database.tables.size(); ++j) {
			if (database.tables[j].tableName == tableName) {
				index = j;
				exist = true;
				break;
			}
		}

		if (!exist) {
			cout << "Table with name " << tableName << " does not exist." << endl;
			return false;
		}

		if (isAll) {
			if (database.tables[index].tableColumns != 0) {
				for (unsigned int j = 1; j < database.tables[index].columnsItems[0].size(); ++j) {
					for (unsigned int k = 0; k < database.tables[index].columnsItems.size(); ++k) {
						cout << database.tables[index].columnsItems[k][j];
						if (k != database.tables[index].columnsItems.size() - 1) {
							cout << ";";
						}
					}
					cout << endl;
				}
			}
		}
		else {
			if (database.tables[index].tableColumns != 0) {
				unsigned int size = database.tables[index].columnsItems[0].size();
				for (unsigned int j = 1; j < size; ++j) {
					for (unsigned int k = 0; k < columnName.size(); ++k) {
						for (unsigned int m = 0; m < database.tables[index].columnsItems.size(); ++m) {
							if (database.tables[index].columnsItems[m][1] == columnName[k]) {
								cout << database.tables[index].columnsItems[m][j];
								if (k != columnName.size() - 1) {
									cout << ";";
								}
							}
						}
					}
					cout << endl;
				}
			}
		}
	}
	return true;
}

bool Select::selectTableWhere(Database & database, string line) {
	string tmp;
	unsigned int i = 0;
	int k = 0;
	string table1, table2;
	string value1, value2;
	int tableIndex1 = -1, tableIndex2 = -1;
	int columnIndex1 = -1, columnIndex2 = -1;

	while (k != 3) {
		if (line[i] == ' ') {
			++k;
		}
		++i;
	}

	while (line[i] != ' ') {
		if (line[i] == ',' && line[i + 1] == ' ') {
			table1 = tmp;
			tmp.clear();
			++i;
		}
		else {
			tmp += line[i];
		}
		++i;
	}
	++i;
	table2 = tmp;
	tmp.clear();

	while (line[i] != ' ') {
		if (i == line.size() - 1) {
			cout << "Bad command." << endl;
			return false;
		}
		++i;
	}
	++i;

	while (line[i] != '=') {
		if (i == line.size() - 1) {
			cout << "Bad command." << endl;
			return false;
		}
		tmp += line[i];
		++i;
	}
	++i;
	value1 = tmp;
	tmp.clear();

	while (i < line.size() - 1) {
		tmp += line[i];
		++i;
	}
	value2 = tmp;

	for (unsigned int j = 0; j < database.tables.size(); ++j) {
		if (table1 == database.tables[j].tableName) {
			tableIndex1 = j;
		}
		if (table2 == database.tables[j].tableName) {
			tableIndex2 = j;
		}
	}

	if (tableIndex1 == -1) {
		cout << "Table " << table1 << " does not exist." << endl;
		return false;
	}
	if (tableIndex2 == -1) {
		cout << "Table " << table2 << " does not exist." << endl;
		return false;
	}

	if (database.tables[tableIndex1].tableColumns != 0 || database.tables[tableIndex2].tableColumns != 0) {

		for (unsigned int m = 0; m < database.tables[tableIndex1].columnsItems.size(); ++m) {
			if (database.tables[tableIndex1].columnsItems[m][1] == value1) {
				columnIndex1 = m;
			}
		}
		for (unsigned int m = 0; m < database.tables[tableIndex2].columnsItems.size(); ++m) {
			if (database.tables[tableIndex2].columnsItems[m][1] == value2) {
				columnIndex2 = m;
			}
		}

		if (columnIndex1 == -1) {
			cout << "Column " << value1 << " does not exist." << endl;
			return false;
		}
		if (columnIndex2 == -1) {
			cout << "Column " << value2 << " does not exist." << endl;
		}

		for (unsigned int k = 0; k < database.tables[tableIndex1].columnsItems.size(); ++k) {
			cout << database.tables[tableIndex1].columnsItems[k][1] << ";";
		}
		int columnExist = 0;
		for (unsigned int k = 0; k < database.tables[tableIndex1].columnsItems.size(); ++k) {
			columnExist = 0;
			for (unsigned int n = 0; n < database.tables[tableIndex1].columnsItems.size(); ++n) {
				if (database.tables[tableIndex1].columnsItems[n][1] == database.tables[tableIndex2].columnsItems[k][1] || database.tables[tableIndex2].columnsItems[k][1] == value2) {
					++columnExist;
				}
			}
			if (columnExist == 0) {
				cout << database.tables[tableIndex2].columnsItems[k][1];
				if (k != database.tables[tableIndex2].columnsItems.size() - 1) {
					cout << ";";
				}
			}
		}
		cout << endl;

		int row = 0;
		bool isSame = false;
		for (unsigned int j = 2; j < database.tables[tableIndex1].columnsItems[0].size(); ++j) {
			isSame = false;
			row = 0;
			for (unsigned int m = 2; m < database.tables[tableIndex2].columnsItems[columnIndex2].size(); ++m) {
				if (database.tables[tableIndex2].columnsItems[columnIndex2][m] == database.tables[tableIndex1].columnsItems[columnIndex1][j]) {
					isSame = true;
					row = m;
				}
			}
			if (isSame == false) {
				continue;
			}
			for (unsigned int k = 0; k < database.tables[tableIndex1].columnsItems.size(); ++k) {
				cout << database.tables[tableIndex1].columnsItems[k][j] << ";";
			}

			for (unsigned int k = 0; k < database.tables[tableIndex2].columnsItems.size(); ++k) {
				columnExist = 0;
				for (unsigned int n = 0; n < database.tables[tableIndex1].columnsItems.size(); ++n) {
					if (database.tables[tableIndex1].columnsItems[n][1] == database.tables[tableIndex2].columnsItems[k][1] || database.tables[tableIndex2].columnsItems[k][1] == value2) {
						++columnExist;
					}
				}
				if (columnExist == 0) {
					cout << database.tables[tableIndex2].columnsItems[k][row];
					if (k != database.tables[tableIndex2].columnsItems.size() - 1) {
						cout << ";";
					}
				}
			}
			cout << endl;
		}
	}

	return true;
}
