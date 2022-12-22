CC := g++
CFLAGS := -Wall -g
TARGET := SpaceJet
LDFLAGS= -lSDL2 -lSDL2_image -w -Ofast

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp ObjectModel/*.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp ObjectModel/*.cpp, %.o ObjectModel/*.o, $(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 
clean:
	rm -rf $(TARGET) *.o
	
.PHONY: all clean