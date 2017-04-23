#ifndef INSERT_H
#define	INSERT_H

#include "Commands.h"

/// Child class of Commands for insrt new values to table.
class Insert : public Commands {
public:
	//! Default empty constructor.
	Insert();
	//! Default empty virtual destructor.
	virtual ~Insert();
	//! Overridden method for parse and call addValues.
	/**
			\param database Current database.
			\param line One command to parse.
			\return True if evrything was successful.
	*/
	bool makeCommand(Database & databaze, string line);

private:

	//! Method for insert new values in table.
	/**
			\param database Current database.
			\param tableName Name of table.
			\param input Names od values.
			\parav valuesNumer Number of values.
			\return True if evrything was successful.
	*/
	bool addValues(Database & databaze, string tableName, string input, int valuesNumber);
	
	//! Method for checking corretness of database types.
	/**
			\param valueType Database type.
			\param value Table value for checking.
	\return True if evrything was successful.
	*/
	bool values(string valueType, string value);
};

#endif	/* INSERT_H */
