NAME = metodos

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/$(NAME)

CC = g++

CFLAGS = -W -Wall -pedantic -std=c++11 -MMD -g3
INCLUDES = -Iinclude

SRC = ${wildcard $(SRC_DIR)/*.cpp}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.cpp=.o}}}

.PHONY: clean depend dist-clean 

all:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)
	$(MAKE) $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Building $@
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(TARGET): $(OBJ)
	@echo Building $@
	$(CC) $(OBJ) -o $@ 

clean:
	@echo Cleaning...
	@find . -name *.o -exec rm {} \;
	@find . -name *.d -exec rm {} \;
	@rm -rf *~ *.o prog out.txt

dist-clean: clean
	@find . -name *.a -exec rm {} \;
	@rm -rf $(TARGET)

-include $(OBJ:.o=.d)
