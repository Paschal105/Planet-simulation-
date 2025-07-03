
CC = g++ 
CFLAGS = -Wall -Werror -pedantic -std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ = CelestialBody.o Universe.o main.o
EXE = NBody

all: $(EXE)

$(EXE): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
%.o: %.cpp %.h
		$(CC) $(CFLAGS) -c $< -o $@
%.o: %.cpp 
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(EXE)

