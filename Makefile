TARGET_EXE := registration

PARTIES := partieA.cpp partieB.cpp partieC.cpp partieD.cpp partieE.cpp

DEBUG :=
DEBUGF := $(if $(DEBUG),-g -ggdb3)

all: registration.h main.cpp $(PARTIES)
	g++ main.cpp $(PARTIES) -o $(TARGET_EXE)

obj: registration.h
	g++ registration.h -o registration.o

clean:
	rm -rf $(OUT_DIR) $(TARGET_EXE)

redo: clean all