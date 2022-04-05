TARGET_EXE := registration

DEBUG :=
DEBUGF := $(if $(DEBUG),-g -ggdb3)

all: registration.h registration.cpp
	g++ registration.cpp -o $(TARGET_EXE)

obj: registration.h
	g++ registration.h -o registration.o

clean:
	rm -rf $(OUT_DIR) $(TARGET_EXE)

redo: clean all