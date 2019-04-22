#pragma once
#include <iostream>
#include <string>

class String
{
    public:
        String();
        int length();
        char* begin();
        char* end();
        void clear();
        char at(int index);
        char front();
        char back();
        //void concat(s addString);

    private:

}