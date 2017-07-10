CXX = g++
CXXFLAGS = -O2
TARGET = a.exe
SRCS = main.cpp appLogger.cpp
OBJS := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
clean:
	rm -f $(TARGET) $(OBJS)

# Header Dependency
main.o: appLogger.h
appLogger.o: appLogger.h
