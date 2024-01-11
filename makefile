SRC= $(wildcard Private/*.cpp) $(wildcard tests/*.cpp) 
INC= -I./Public/ -I./doctest/doctest/

snake: $(SRC)
	g++ $(SRC) $(INC) -std=c++11 -lncurses -o snake -lpthread

tests: $(SRC)
	g++ $(SRC) $(INC) -std=c++11 -lncurses -o tests -lpthread
