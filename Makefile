TESTDIR	 = test
SOURCE 	 = src/wniemiec/util/cpp
BINARY	 = bin
DIST 	 = dist
INCLUDE  = include
CC	 	 = g++ 
FLAGS	 = -c
LFLAGS	 = -std=c++17

all: 
	rm -rf $(BINARY)
	mkdir $(BINARY)
	$(CC) $(FLAGS) $(SOURCE)/StringUtils.cpp -o $(BINARY)/StringUtils.o $(LFLAGS)

clean:
	rm -f *.o
	cmake --build $(TESTDIR) --target clean-all

.PHONY: test
test:
	cmake $(TESTDIR)/CMakeLists.txt
	make -C $(TESTDIR)
	$(TESTDIR)/runTests

.PHONY: dist
dist:
	rm -rf $(DIST)
	mkdir $(DIST)
	cp $(BINARY)/StringUtils.o $(DIST)
	cp $(INCLUDE)/wniemiec/util/cpp/StringUtils.hpp $(DIST)

