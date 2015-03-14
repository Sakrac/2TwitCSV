![2TwitCSV](/media/2twitcsv.png)
Distribution of characters used in 2TwitCSV.h  

Implementation of a CSV parser in less than 280 bytes (two tweets)

Fixes
-----

 - Handling quoted special characters such as empty ("") or containing a single quote ("""") or commas (",") was fixed. Previously would cause total bork of the table.

Supports
--------

 - All kinds of line endings (LF CR, CR LF, CR, LF)
 - All 8-bit character code representations supported
 - Quoted cell strings with internal double quotes undoubled and internal line endings and commas ignored
 - Stomps over original file data with zero terminated string versions of the cells

Shortcomings
------------

 - Single column with empty cells contradicts with the support for line endings (may be ignored if empty and unquoted)
 - No 16-bit character code representation support
 - Was the unreadbility mentioned?
 - Both the array of cell string pointers and the CSV file itself may need to be padded by 1 element in memory.
 - Does not handle lines with different number of cells on each

The only significant thing in this repo is 2twitcsv.h which can be included in the middle of a parsing function.

Usage
-----

In a function where a char pointer **p** points to an in-memory csv file and int **l** is the size of that file and an array of const char pointers **o** points to an array with at least the number of resulting cells, insert **#include "2twitcsv.h"**. **c** will be the number of columns and **r** the number of rows.
