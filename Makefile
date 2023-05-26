SRC = src/
OBJ = obj/
INC = include/
BIN = bin/
LIBDEST = /usr/local/lib/
HEADERDEST = /home/junior/lib/include/
FANCYDIR = ./fancyarray/
FANCYOBJ = libfancy.o
FANCYLIBNAME = libfancy.a


fancy:
	gcc -I $(FANCYDIR)$(INC) -c $(FANCYDIR)$(SRC)fancy.c -o $(FANCYDIR)$(OBJ)$(FANCYOBJ)
	ar rcs $(FANCYDIR)$(BIN)$(FANCYLIBNAME) $(FANCYDIR)$(OBJ)$(FANCYOBJ)
	sudo cp $(FANCYDIR)$(BIN)$(FANCYLIBNAME) $(LIBDEST)
	cp $(FANCYDIR)$(INC)fancy.h $(HEADERDEST)

all:
	make fancy
