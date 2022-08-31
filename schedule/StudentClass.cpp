#include "StudentClass.h"

StudentClass::StudentClass()
{
  name = "";
  start = 0;
  end = 0;
}

StudentClass::~StudentClass(){}

StudentClass::StudentClass(std::string _name, int _start, int _end)
{
  name = _name;
  start = _start;
  end = _end;
}
  
// Getters
std::string StudentClass::getName()
{
  return name;
}
int StudentClass::getStart()
{
  return start;
}
int StudentClass::getEnd()
{
  return end;
}

// Setters
void StudentClass::setName(std::string _name)
{
  name = _name;
}
void StudentClass::setStart(int _start)
{
  start = _start;
}
void StudentClass::setEnd(int _end)
{
  end = _end;
}