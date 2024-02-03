DD=build

SRC=src
INCLUDE=include
OBJ=$(DD)/obj
TARGET=$(DD)/roccat-iokit

CC=gcc
CFLAGS=-Wall -framework CoreFoundation -framework IOKit

SOURCES=$(wildcard $(SRC)/*.c)
OBJECTS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

default: all

re: clean all

clean:
	@rm -f $(OBJECTS) $(TARGET)
	@printf "Deleting object files ...\n"
	@printf "Deleting executable files ...\n"
	@printf "Clean Success\n"

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -L. -I$(INCLUDE) -o $(TARGET) $(OBJ)/*
	@printf "Building $(TARGET)...\n"

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@$(CC) -I$(INCLUDE) -c $< -o $@
	@printf "Building $@\n"

$(OBJ):
	@mkdir -p $@
	@printf "Creating $(OBJ) dir\n"