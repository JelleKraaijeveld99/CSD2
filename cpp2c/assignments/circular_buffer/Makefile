CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -g -std=c++17
LDFLAGS= -ljack
SOURCE= EmptyCircBuffer.o main.o
TARGET= circular_buff

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o