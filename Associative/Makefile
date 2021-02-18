CXX=g++
CFLAGS= -Wall -O2
SRC=asc.cc
HDR= map.h map=def.h set.h set=def.h
OBJ=$(SRC: .cc =.o)
EXE=asc

.PHONY: default clean

default: $(EXE)
	./$(EXE) 1>output.log
	cat output.log
	
	
%.o: %.cc $(HDR)
	$(CXX) $(CFLAGS) -c $(SRC)
	
	
$(EXE): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(EXE)
	
clean:
	rm -f asc *.o *.log
