#pragma once

#include <iostream>

#define NUM_NOTES 10

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getPitch();

protected:
  // Cmaj7 -  arpeggio
  float melody[NUM_NOTES] = {60, 60, 67, 60, 64, 64, 55, 60, 55, 64};
  // the index of the current note - readIndex
  int index;
};
