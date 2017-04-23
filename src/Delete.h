#ifndef DELETE_H
#define	DELETE_H

#include "Commands.h"

/// Child class of Commands for deleting table.
class Delete : public Commands {
public:
	//! Default empty constructor.
	Delete();
	//! Default empty virtual destructor.
	virtual ~Delete();
	//! Overridden method for parse and call delTable.
	/**
			\param database Current database.
			\param line One command to parse.
			\return True if evrything was successful.
	*/
	bool makeCommand(Database & databse, string line);

private:
	//! Method for deleting table.
	/**
			\param database Current database.
			\param tableName Name of table.
			\return True if evrything was successful.
	*/
	bool delTable(Database & database, string tableName);
};

#endif	/* DELETE_H */
