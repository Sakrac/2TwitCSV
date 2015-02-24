2twitcsv
========

I couldn't find an elegant minimal comma separated value parser so I went overboard and made an unreadable < 280 bytes parser and [twittered](https://twitter.com/Sakrac/status/570029962503147520) about it.

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
 - If the number of columns is inconsistent between rows there may be uninitialized string pointers in the return array

The only significant thing in this repo is 2twitcsv.h which can be included in the middle of a parsing function.

Usage
-----

In a function where a char pointer **p** points to an in-memory csv file and int **l** is the size of that file and an array of const char pointers **o** points to an array with at least the number of resulting cells, insert **#include "2twitcsv.h"**. **c** will be the number of columns and **r** the number of rows.
