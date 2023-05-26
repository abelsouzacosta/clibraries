SRC = src/
OBJ = obj/
INC = include/
BIN = bin/
LIBDEST = /usr/local/lib/
HEADERDEST = /home/junior/lib/include/
FANCYDIR = ./fancyarray/
FANCYOBJ = fancy.o
FANCYLIBNAME = libfancy.a
CONSOLEDIR = ./console/
CONSOLEOBJ = console.o
CONSOLELIBNAME = libconsole.a
STROPSDIR = ./strops/
STROPSOBJ = strops.o
STROPSLIBNAME = libstrops.a
PERFCLOCKDIR =./perfclock/
PERFCLOCKOBJ = perfclock.o
PERFCLOCKLIBNAME = libperfclock.a 


.PHONY: all fancy console strops perfclock clean

all: fancy console strops perfclock clean

fancy: $(FANCYDIR)$(OBJ)$(FANCYOBJ)
	ar rcs $(FANCYDIR)$(BIN)$(FANCYLIBNAME) $<
	cp $(FANCYDIR)$(BIN)$(FANCYLIBNAME) $(LIBDEST)
	cp $(FANCYDIR)$(INC)fancy.h $(HEADERDEST)

$(FANCYDIR)$(OBJ)$(FANCYOBJ): $(FANCYDIR)$(SRC)fancy.c
	gcc -I $(FANCYDIR)$(INC) -c $< -o $@

console: $(CONSOLEDIR)$(OBJ)$(CONSOLEOBJ)
	ar rcs $(CONSOLEDIR)$(BIN)$(CONSOLELIBNAME) $<
	cp $(CONSOLEDIR)$(BIN)$(CONSOLELIBNAME) $(LIBDEST)
	cp $(CONSOLEDIR)$(INC)console.h $(HEADERDEST)

$(CONSOLEDIR)$(OBJ)$(CONSOLEOBJ): $(CONSOLEDIR)$(SRC)console.c
	gcc -I $(CONSOLEDIR)$(INC) -c $< -o $@

strops: $(STROPSDIR)$(OBJ)$(STROPSOBJ)
	ar rcs $(STROPSDIR)$(BIN)$(STROPSLIBNAME) $<
	cp $(STROPSDIR)$(BIN)$(STROPSLIBNAME) $(LIBDEST)
	cp $(STROPSDIR)$(INC)strops.h $(HEADERDEST)

$(STROPSDIR)$(OBJ)$(STROPSOBJ): $(STROPSDIR)$(SRC)strops.c
	gcc -I $(STROPSDIR)$(INC) -c $< -o $@

perfclock: $(PERFCLOCKDIR)$(OBJ)$(PERFCLOCKOBJ)
	ar rcs $(PERFCLOCKDIR)$(BIN)$(PERFCLOCKLIBNAME) $<
	cp $(PERFCLOCKDIR)$(BIN)$(PERFCLOCKLIBNAME) $(LIBDEST)
	cp $(PERFCLOCKDIR)$(INC)perfclock.h $(HEADERDEST)

$(PERFCLOCKDIR)$(OBJ)$(PERFCLOCKOBJ): $(PERFCLOCKDIR)$(SRC)perfclock.c
	gcc -I $(PERFCLOCKDIR)$(INC) -c $< -o $@

clean:
	rm -rf $(FANCYDIR)$(BIN)$(FANCYLIBNAME) $(FANCYDIR)$(OBJ)$(FANCYOBJ)
	rm -rf $(CONSOLEDIR)$(BIN)$(CONSOLELIBNAME) $(CONSOLEDIR)$(OBJ)$(CONSOLEOBJ)
	rm -rf $(STROPSDIR)$(BIN)$(STROPSLIBNAME) $(STROPSDIR)$(OBJ)$(STROPSOBJ)
	rm -rf $(PERFCLOCKDIR)$(BIN)$(PERFCLOCKLIBNAME) $(PERFCLOCKDIR)$(OBJ)$(PERFCLOCKOBJ)
