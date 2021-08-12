OBJS	= StringUtils.o
SOURCE	= src/wniemiec/data/cpp/StringUtils.cpp
CC	 = g++ 
FLAGS	 = -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -c $(OBJS) $(LFLAGS) -std=c++17

StringUtils.o: src/wniemiec/data/cpp/StringUtils.cpp
	$(CC) $(FLAGS) src/wniemiec/data/cpp/StringUtils.cpp -std=c++17

clean:
	rm -f $(OBJS) $(OUT)
