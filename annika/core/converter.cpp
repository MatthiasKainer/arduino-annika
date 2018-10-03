#ifndef __CONVERTER_CPP__
#define __CONVERTER_CPP__

enum Range {
  ERROR, WARN, OK, NO_DISTANCE
};

const int GreenRange = 50;
const int YellowRange = 25;
const int RedRange = 10;

enum Direction {
  LEFT,
  STRAIGHT,
  RIGHT,
  UNKNOWN
};

Range convert(unsigned long distance) {
    if(distance >= GreenRange)
    {
      return OK;
    }
    else if(distance >= YellowRange)
    {
      return WARN;
    }
    else if(distance >= RedRange)
    {
      return ERROR;
    }
    else if(distance == 0)
    {
      return NO_DISTANCE;
    }    
}

#endif