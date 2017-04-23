#ifndef LOAD_H
#define	LOAD_H

#include "Commands.h"

/// Child class of Commands for load database from file.
class Load : public Commands {
public:
	//! Default empty constructor
	Load();
	//! Default empty virtual destructor.
	virtual ~Load();
	//! Overridden method for parse and call loadDatabase.
	/**
			\param database Current database.
			\param line One command to parse.
			\return True if evrything was successful.
	*/
	bool makeCommand(Database & databaze, string line);

private:

	//! Method for load database from file.
	/**
			\param database Current database.
			\param fileName Name of file.
			\return True if evrything was successful.
	*/
	bool loadDatabase(Database & databaze, string fileName);
};

#endif	/* LOAD_H */
