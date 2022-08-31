#include<bits/stdc++.h>
#include <string>

class StudentClass
{
  std::string name;
  int start;
  int end;

    public:
        //defualt 
        StudentClass();
        ~StudentClass();
        //new constructor 
        StudentClass(std::string, int, int);

        //getters
        std::string getName();
        int getStart();
        int getEnd();

        //setters
        void setName(std::string);
        void setStart(int);
        void setEnd(int);
};