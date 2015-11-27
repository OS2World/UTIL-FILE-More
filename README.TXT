
Hi !

This is another more. It has features like:
- takes arguments directly following the command
- multiple argument support
- WILDCARD support * ?
- works through pipes |
- input redirection possible <
- much faster than os/2's own more
- supports different window sizes
- will NOT SPOIL your COLORS (like some other mores will do)
- output redirection > is not working very well, type recommended instead

Examples:
more readme more.c
more r*m??
more *c 
type readme | more
more < readme

If you necessarily want to view very large files with more, it will take
a couple of seconds for more to display the first screen. This time is
taken because the program first counts the # of lines in the text file (this 
has the side effect that the text file gets read to your disk cache, hopefully
it will remain there long enough). In this case you can start more quickly by 
using input redirection:
'more < filename' but you'll lose the %-info.

INSTALLATION

Put more.exe to a directory in your path + rename of remove your old more.

KEYS

After each page is displayed, more pauses waiting for a key to be pressed.
Three keys have special meanings:
- 'q' will quit right there
- ENTER will show you four lines more
- 'v' will display version info on the bottom line of the screen
- any other key will show you a new page.


WARRANTY & LICENSING

This program is provided WITHOUT ANY WARRANTY 'as is', so you may use it at 
your own risk. You may freely use it and distribute it but you are not allowed
to take charge for this program.


SOURCE

The source is included here so you can modify it according to your wishes.
You may use parts or all of the source in your program(s) but then the 
original author and the names of the modifiers must be mentioned in the 
comments of your source and you are not allowed to take charge for 
distributing your program. 
This program was compiled with BC++ 1.0 for os/2; wildcard support was
provided by linking the source with WILDARGS.OBJ by Borland.

BUGS

If the last line of a page has tab-characters and thus the line gets
expanded over the width of your screen to the next line, the top line 
of the page will be scrolled away.

This could be (kind of) fixed by repeating the last line on top of the new 
page (well the fix wouldn't be perfect, suppose you have 40 tabs and then
some text :-). Not fixed in this release anyway.

AUTHORS COMMENT

Stephen Lacy has written a more that is extremely fast. When it reaches
the level of doing colors ok, I - too - will probably use it instead.


COMMENTS

If you like this program or find a bug, please send me a note.
The internet address is

lkuru@snakemail.hut.fi

