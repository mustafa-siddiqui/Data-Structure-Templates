# compiler
CXX = g++

# compiler flags
CXXFLAGS = -Wall

# add /Shell dir to include path
# replace space in dir name with '\ '
# workaround for make not working with dirs with spaces in names
INC = -I${shell pwd | sed 's/ /\\ /g'}

# files to be linked
FILES = logging/src/logger.cc logging/src/states/logger-debug-enabled-state.cc logging/src/states/logger-debug-disabled-state.cc

MAIN_FILE_FOR_LINKED_LIST = src/linkedListUsage.cc
MAIN_FILE_FOR_NODE = src/nodeUsage.cc

# Generate binaries for all files in src/
all node linkedlist &: node linkedlist

node:
	${CXX} ${CXXFLAGS} -std=c++14 ${INC} ${FILES} ${MAIN_FILE_FOR_NODE} -o node

linkedlist:
	${CXX} ${CXXFLAGS} -std=c++14 ${INC} ${FILES} ${MAIN_FILE_FOR_LINKED_LIST} -o ll

redirect:
	${CXX} ${CXXFLAGS} -std=c++14 ${INC} ${FILES} -o ds > makeLog.txt 2>&1

debug:
	${CXX} ${CXXFLAGS} -std=c++14 ${INC} ${FILES} -DDEBUG -o ds

clean:
	rm -f ds && rm -f DSLinkedList && rm -f ll && rm -f node
 