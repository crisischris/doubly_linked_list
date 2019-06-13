#citation: https://oregonstate.instructure.com/courses/1719543/pages/lecture-makefiles?module_item_id=18712398

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGs += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -w

LDFLAGS = 

SOURCES = *.cpp

HEADERS = *.hpp

OBJS = main.o 
DOCUMENTS = *.pdf *.txt

Linked List: ${SOURCES} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${SOURCES} -o linked_list

${OBJS}: ${SOURCES}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm linked_list 
	rm -R linked_list.dSYM
zip:
	zip lab6_Chris_Nelson.zip ${SOURCES} ${HEADERS} ${DOCUMENTS} makefile

unzip:
	unzip lab6_Chris_Nelson.zip 
