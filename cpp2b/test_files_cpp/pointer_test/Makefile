CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -g -std=c++17
LDFLAGS= -ljack
SOURCE=  main.o synth.o
TARGET= synthesizer 

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
