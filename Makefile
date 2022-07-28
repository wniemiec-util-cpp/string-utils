CC	 	 = g++ 
FLAGS	 = -c
LFLAGS	 = -std=c++17
TESTDIR	 = test
SOURCE 	 = src/wniemiec/util/cpp
BINARY	 = bin

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
