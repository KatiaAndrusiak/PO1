CXX = g++
CFLAGS = -Wall -g
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
all:program
program:$(OBJ)
	$(CXX) $(CFLAGS) $^ -o exec
%.o:%.cpp %.h
	$(CXX) $(CFLAGS) -c $<
clean:
	rm -rf $(OBJ) exec
run: exec
	./exec
valgrind: exec
	valgrind --tool=memcheck ./exec
.PHONY: clean all valgrind
