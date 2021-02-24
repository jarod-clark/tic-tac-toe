CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD
OBJECTS = main.o board.o position.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = tictactoe

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
