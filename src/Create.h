#ifndef CREATE_H
#define	CREATE_H

#include "Commands.h"

/// Child class of Commands for creating new table in database.
class Create : public Commands {
public:
	//! Default empty constructor.
	Create();
	//! Default empty virtual destructor.
	virtual ~Create();

	//! Overridden method for parse table and call addTable.
	/**
			\param database Current database.
			\param line One command to parse.
			\return True if evrything was successful.
	*/
	bool makeCommand(Database & database, string line);

private:
	//! Method for add new table.
	/**
			\param database Current database.
			\param name Name of table.
			\param columns Number of table columns.
			\param input Names of columns.
			\return True if evrything was successful.
	*/
	bool addTable(Database & database, string name, int columns, string input);
};

#endif	/* CREATE_H */
