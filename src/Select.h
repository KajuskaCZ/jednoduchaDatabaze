#ifndef SELECT_H
#define	SELECT_H

#include "Commands.h"

/// Child class of Commands for select.
class Select : public Commands {
public:
	//! Default empty constructor
	Select();
	//! Default empty virtual destructor.
	virtual ~Select();

	//! Overridden method for parse, select and call selectTableWhere.
	/**
			\param database Current database.
			\param line One command to parse.
			\return True if evrything was successful.
	*/
	bool makeCommand(Database & database, string line);

private:
	//! Method for command select with where.
	/**
			\param database Current database.
			\param line One command to parse.
			\return True if evrything was successful.
	*/
	bool selectTableWhere(Database & database, string line);
};

#endif	/* SELECT_H */
