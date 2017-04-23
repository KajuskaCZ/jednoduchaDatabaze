#ifndef SAVE_H
#define	SAVE_H

#include "Commands.h"

/// Child class of Commands for save database to file.
class Save : public Commands {
public:
	//! Default empty constructor
	Save();
	//! Default empty virtual destructor.
	virtual ~Save();
	//! Overridden method for parse and call databazeToFile.
	/**
			\param database Current database.
			\param line One command to parse.
			\return True if evrything was successful.
	*/
	bool makeCommand(Database & database, string line);

private:
	//! Method for save database to file.
	/**
			\param database Current database.
			\return True if evrything was successful.
	*/
	void databazeToFile(Database & database);
};

#endif	/* SAVE_H */
