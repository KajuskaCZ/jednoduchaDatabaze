#include "Reader.h"

int main(int argc, char** argv) {
	Reader a;

	if (argc != 2) {
		cout << "Too few arguments." << endl;
		return 1;
	}

	a.readingInput(argv[1]);

	return 0;
}