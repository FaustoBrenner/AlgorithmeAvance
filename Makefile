TARGET_EXE := registration

PARTIES := partieA.cpp partieB.cpp partieC.cpp partieD.cpp partieE.cpp

DEBUG :=
DEBUGF := $(if $(DEBUG),-g -ggdb3)

all: main.cpp $(PARTIES)
	g++ $(PARTIES) main.cpp -o $(TARGET_EXE)

clean:
	rm -rf *.o $(TARGET_EXE)

redo: clean all