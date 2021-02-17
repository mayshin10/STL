CXX=g++
CFLAGS= -Wall -O2
SRC=seq.cc
HDR= vector.h vector-def.h deque.h deque-def.h list.h list-def.h 
OBJ=$(SRC: .cc =.o)
EXE=seq

.PHONY: default clean

default: $(EXE)
	./$(EXE) 1>seq.log
	cat seq.log
	
	
%.o: %.cc $(HDR)
	$(CXX) $(CFLAGS) -c $(SRC)
	
	
$(EXE): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(EXE)
	
clean:
	rm -f main *.o output.log
