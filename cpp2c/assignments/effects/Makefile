CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -g -std=c++17
LDFLAGS= -ljack
SOURCE= circ_buff.o main.o effect.o 
TARGET= test_effects 

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o