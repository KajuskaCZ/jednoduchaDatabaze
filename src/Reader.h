#ifndef READER_H
#define	READER_H

#include "Database.h"
#include "Insert.h"
#include "Load.h"
#include "Save.h"
#include "Delete.h"
#include "Create.h"
#include "Select.h"

/// Class for reading input from file.
class Reader
{
public:
	//! Default empty constructor.
	Reader();
	//! Default empty destructor.
	~Reader();

	//! Reading input from file.
	/**
			\param fileName Name of input file.
			\return True if evrything was successful.
	*/
	bool readingInput(string fileName);

	Database database; //!< Current database.
};

#endif	/* READER_H */
