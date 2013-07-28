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

CFLAGS := -I../src/include -D_COMPLEX_PREC=8 -Wall -O3 -ggdb

objs := ../src/complex.o

.PHONY: ../src/complex.o

all: $(objs)
	gcc -o sanity $(CFLAGS) complex_test.c $(objs)

../src/complex.o:
	cd ../src && make

clean:
	rm -f sanity
