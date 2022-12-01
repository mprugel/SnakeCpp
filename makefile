SRC= $(wildcard Private/*.cpp)
INC= -I./Public/

snake: $(SRC)
	g++ $(SRC) $(INC) -std=c++11 -lncurses -o snake -lpthread