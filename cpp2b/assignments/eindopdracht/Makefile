CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -g -std=c++17
LDFLAGS= -ljack
SOURCE= sine.o main.o oscillator.o square.o saw.o writeToFile.o callback.o synth.o fm_synth.o addSynth.o melody.o jack_module.o uiUtilities.o
TARGET=synthesizer 

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
