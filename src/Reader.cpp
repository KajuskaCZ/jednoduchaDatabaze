#include "Reader.h"


Reader::Reader()
{
}


Reader::~Reader()
{
}

bool Reader::readingInput(string fileName) {
	ifstream inFile;
	string line;
	string tmp;

	inFile.open(fileName);
	if (inFile.fail()) {
		return false;
	}

	while (getline(inFile, line)) {
		if (line.size() < 13) {
			cout << "Bad command." << endl;
			return false;
		}
		if (line[0] == 'L') {
			Load* load = new Load;
			load->makeCommand(database, line);
		}
		if (line[0] == 'C') {
			Create* create = new Create;
			create->makeCommand(database, line);
		}
		if (line[0] == 'I') {
			Insert* insert = new Insert;
			insert->makeCommand(database, line);
		}
		if (line[0] == 'D') {
			Delete* deleteTable = new Delete;
			deleteTable->makeCommand(database, line);
		}
		if (line[0] == 'S') {
			if (line[1] == 'A') {
				Save* save = new Save;
				save->makeCommand(database, line);
			}
			if (line[1] == 'E') {
				Select* select = new Select;
				select->makeCommand(database, line);
			}
		}
	}
	inFile.close();
	return true;
}
