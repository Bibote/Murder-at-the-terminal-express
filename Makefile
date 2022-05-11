TARGET = orientexpress
MAIN = $(SRC_DIR)/myshell0.c
OBJS = $(OBJ_DIR)/talk.o
OBJS += $(OBJ_DIR)/history.o
OBJS += $(OBJ_DIR)/help.o
OBJS += $(OBJ_DIR)/lookAround.o
OBJS += $(OBJ_DIR)/pwd.o
OBJS += $(OBJ_DIR)/wheretogo.o
SRCFS = $(BIN_DIR)/talk
SRCFS += $(BIN_DIR)/history
SRCFS += $(BIN_DIR)/help
SRCFS += $(BIN_DIR)/lookAround
SRCFS += $(BIN_DIR)/pwd
SRCFS += $(BIN_DIR)/wheretogo
OBJ_DIR = ./obj
SRC_DIR = ./src
BIN_DIR = ./executables
PROGS = $(patsubst %.c,%,$(OBJ_DIR))
CFLAGS = -Wall


$(TARGET) : $(MAIN) $(OBJS) $(SRCFS)
	gcc $(CFLAGS) $(MAIN) -o $(TARGET)

$(SRCFS) : $(BIN_DIR)/%: $(OBJ_DIR)/%.o
	mkdir -p $(BIN_DIR)
	gcc -O2 $(CFLAGS)  -o $@ $<
	
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	gcc -c -MD $(CFLAGS) $< -o $@


#-include $(OBJ_DIR)/*.d

.PHONY: clean
clean:
	rm -f "./History/history.txt"
	rm -f orientexpress
	rm -r -f $(OBJ_DIR)
	rm -r -f $(BIN_DIR)