SRC_DIR := src
TARGET_EXE := registration

DEBUG :=
DEBUGF := $(if $(DEBUG),-g -ggdb3)

all: $(SRC_DIR)/*.cpp
	g++ $(SRC_DIR)/*.cpp -o $(TARGET_EXE)

clean:
	rm -rf $(TARGET_EXE)

redo: clean all