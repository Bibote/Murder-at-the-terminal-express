##############################################################################################
# 
# On command line:
#
# make all = Create project
#
# make clean = Clean project files.
#
# To rebuild project do "make clean" and "make all".
#

##############################################################################################
# Start of default section
#

TRGT = 
CC   = $(TRGT)gcc
CP   = $(TRGT)objcopy
AS   = $(TRGT)gcc -x assembler-with-cpp
HEX  = $(CP) -O ihex 
BIN  = $(CP) -O binary 


# List all default C defines here, like -D_DEBUG=1
DDEFS = 

# List all default directories to look for include files here
DINCDIR = 

# List the default directory to look for the libraries here
DLIBDIR =

# List all default libraries here
#DLIBS =  -lc -lm
#DLIBS =  -lc -lm
#DLIBS =  

#
# End of default section
##############################################################################################

##############################################################################################
# Start of user section
#

# Define project name here
PROJECT = toolbox

# List all user C define here, like -D_DEBUG=1
UDEFS = 

# Define ASM defines here
UADEFS = 

# List C source files here
SRC  = ./toolbox.c \
      ./util.c \
      ./gehio.c \
 
# List the user directory to look for the libraries here
ULIBDIR =

# List all user libraries here
ULIBS = 

# Define optimisation level here
OPT = -O0
#OPT = -Os

#
# End of user defines
##############################################################################################


INCDIR  = $(patsubst %,-I%,$(DINCDIR) $(UINCDIR))
LIBDIR  = $(patsubst %,-L%,$(DLIBDIR) $(ULIBDIR))
DEFS    = $(DDEFS) $(UDEFS)
ADEFS   = $(DADEFS) $(UADEFS)
OBJS    = $(SRC:.c=.o)
LIBS    = $(DLIBS) $(ULIBS)

#CPFLAGS = $(MCFLAGS) $(OPT) -gdwarf-2 -g2 -Wall -Wstrict-prototypes -fverbose-asm -Wa,-ahlms=$(<:.c=.lst) $(DEFS)
CPFLAGS = $(MCFLAGS) $(OPT) -gdwarf-2 -g2 -Wall -fverbose-asm -Wa,-ahlms=$(<:.c=.lst) $(DEFS)

# Generate dependency information
CPFLAGS += -MD -MP -MF .dep/$(@F).d

#
# makefile rules
#

all: $(OBJS) $(PROJECT) 

%o : %c
	$(CC) -c $(CPFLAGS) -I . $(INCDIR) $< -o $@

$(PROJECT): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@


clean:
	-rm -f $(OBJS)
	-rm -f $(PROJECT)
	-rm -f $(SRC:.c=.c.bak)
	-rm -f $(SRC:.c=.lst)
	-rm -fR .dep

# 
# Include the dependency files, should be the last of the makefile
#
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

# *** EOF ***
