# compiler
CXX = g++

# compiler flags
CXXFLAGS = -Wall

# add /Shell dir to include path
# replace space in dir name with '\ '
# workaround for make not working with dirs with spaces in names
INC = -I${shell pwd | sed 's/ /\\ /g'}

# files to be linked
FILES = src/main.cc

all:
	${CXX} ${CXXFLAGS} -std=c++11 ${INC} ${FILES} -o ds

clean:
	rm ds
 