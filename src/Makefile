# (C) Copyright 2013
# Alex Waterman <imNotListening@gmail.com>
#
# complex is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# complex is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#

# Some defaults for a Linux machine.
ifeq ($(CC),)
CC := gcc
endif

ifeq ($(LD),)
LD := ld
endif

ifeq ($(CFLAGS),)
CFLAGS := -O3 -ggdb -Wall
endif

ifeq ($(CPPFLAGS),)
CPPFLAGS := -Iinclude -D_COMPLEX_PREC=8
endif

objs = arith.o


#
# Just build an object file. This makes inclusing this code in another project
# fairly straight forward.
all: $(objs)
	$(LD) -r -o complex.o $(objs)

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

so:

clean:
	rm -f *.o