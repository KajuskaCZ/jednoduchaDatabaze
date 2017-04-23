#ifndef COMMANDS_H
#define	COMMANDS_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Database.h"
using namespace std;

/// Abstract class for database commands.
class Commands {
public:
	//! Default empty constructor.
	Commands();
	//! Default empty virtual destructor.
	virtual ~Commands();

	//! Abstract method for making commands.
	/**
			\param database Current database.
			\param line One command to parse.
			\return True if evrything was successful.
	*/
	virtual bool makeCommand(Database & database, string line) = 0;
private:

};

#endif	/* COMMANDS_H */