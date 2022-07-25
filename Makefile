# compiler
CXX = g++

# compiler flags
CXXFLAGS = -Wall

# add /Shell dir to include path
# replace space in dir name with '\ '
# workaround for make not working with dirs with spaces in names
INC = -I${shell pwd | sed 's/ /\\ /g'}

# files to be linked
FILES = src/main.cc logging/src/logger.cc logging/src/states/logger-debug-enabled-state.cc logging/src/states/logger-debug-disabled-state.cc

all:
	${CXX} ${CXXFLAGS} -std=c++14 ${INC} ${FILES} -o ds

redirect:
	${CXX} ${CXXFLAGS} -std=c++14 ${INC} ${FILES} -o ds > makeLog.txt 2>&1

debug:
	${CXX} ${CXXFLAGS} -std=c++14 ${INC} ${FILES} -DDEBUG -o ds

clean:
	rm ds
 