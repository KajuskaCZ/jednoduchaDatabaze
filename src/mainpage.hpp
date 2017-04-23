/*!
 * \mainpage Database v. 1.0
 *
 * This is project of Karolina Pikorova to subject PA2 on CTU FIT in Prague.
 * \li Developed on Microsoft Windows 7 OS and Microsoft Visual Studio 2013 Ultimate Update 2.
 * \li Ported to Linux OS on Ubuntu 13.10 and NetBeans 7.4 with gcc 4.8.2.
 *
 * \section sect1 Description
 *
 * This program for working with SQL database.
 * 
 * \section sect2 Use 
 * 
 * \subsection subsect1 Compiling, Documentation and Run
 * 
 * In pikorkar directory type:
 * \code
 * make compile
 * \endcode
 * to compile project.
 * 
 * For documentation type:
 * \code
 * make doc
 * \endcode
 * 
 * For run you can type:
 * \code
 * make run <filename>
 * \endcode
 * where <filename> represents name of file (and his path) with your commands.
 *
 * \subsection subsect2 Indexing text files
 * 
 * You can run program in Terminal by typing
 * \code
 * ./pikorkar <filename>
 * \endcode
 * where <filename> represents name of file (and his path) with your commands.
 * 
 * \subsection subsect3 Commands in <filename>
 *
 * For creating tables use:
 * \code
 * CREATE TABLE <tablename>(<name> <type>, ...);
 * \endcode
 * 
 * For deleting tables:
 * \code
 * DELETE TABLE <tablename>;
 * \endcode
 * 
 * For inserting into tables:
 * \code
 * INSERT INTO <tablename> VALUES(<value>, ...);
 * \endcode
 *
 * For selecting values from tables:
 * \code
 * SELECT <name> FROM <tablename>;
 * \endcode
 *
 * For loading database:
 * \code
 * LOAD DATABASE "<filename>";
 * \endcode
 *
 * For saving database:
 * \code
 * SAVE DATABASE "<filename>";
 * \endcode
 *
 * \subsection subsect4 Types
 * 
 * For string with selected size:
 * \code
 * VARCHAR(<size>)
 * \endcode
 *
 * For integers:
 * \code
 * INTEGER
 * \endcode
 *
 * For dates:
 * \code
 * DATE
 * \endcode
 *
 * For number with floating point:
 * \code
 * DOUBLE
 * \endcode
 *
 */
