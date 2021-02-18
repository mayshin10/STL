CXX=g++
CFLAGS= -Wall -Werror
SRC=adp.cc
HDR= ../Sequence/vector/vector.h stack.h stack-def.h queue.h queue-def.h pri-queue.h pri_queue-def.h 
OBJ=$(SRC: .cc =.o)
EXE=adp

.PHONY: default clean

default: $(EXE)
	./$(EXE) 1>adp.log
	cat adp.log
	
	
%.o: %.cc $(HDR)
	$(CXX) $(CFLAGS) -c $(SRC)
	
	
$(EXE): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(EXE)
	
clean:
	rm -f $(EXE) *.o *.log
