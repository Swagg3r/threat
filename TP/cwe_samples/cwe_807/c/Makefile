# Creative Commons Attribution-ShareAlike 3.0 License -
# This work is licensed under the Creative Commons Attribution-Share Alike
# 3.0 License. To view a copy of this license,
# visit http://creativecommons.org/licenses/by-sa/3.0/legalcode;
# or, (b) send a letter to Creative Commons, 171 2nd Street, Suite 300, San
# Francisco, California, 94105, USA.
#
# Originally created : Mataru
#
CC=gcc
CFLAGS=-m32 -g 
LDFLAGS=-m32

SRC = $(wildcard *.c)
HDR = $(wildcard *.h)
OBJ = $(SRC:.c=.o)
POC = $(SRC:.c=.poc)
PAT = $(SRC:.c=.c.patch)

EXEC=dns_auth

.PHONY: all depend poc clean mrproper 

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) "$^" $(LDFLAGS) -o "$@"

poc: $(EXEC)
	sh $(POC)

# Manages dependencies (compilation, ie from cpp to object file)
depend: .depend

.depend: $(SRC) $(HDR)
	$(CC) -MM $(CFLAGS) "$(SRC)" > .depend

-include .depend

clean: 
	rm -f $(OBJ)
	rm -f *~ 
	rm -f *#*
	rm -f .depend

mrproper: clean
	rm -f $(EXEC)
