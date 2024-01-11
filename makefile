SRC= $(wildcard Private/*.cpp) 
INC= -I./Public/

snake: $(SRC)
	g++ $(SRC) $(INC) -std=c++11 -lncurses -o snake -lpthread

SRC= $(filter-out Private/main.cpp, $(wildcard Private/*.cpp)) $(wildcard tests/*.cpp)
INC= -I./doctest/doctest/ -I./Public/
test: $(SRC)
	g++ $(SRC) $(INC) -std=c++11 -lncurses -o test -lpthread
