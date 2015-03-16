#ifndef _STRCONV
#define _STRCONV

#include <sstream>

int stoi(const std::string& s) {
    std::istringstream str(s);
    int i;
    str >> i;
    return i;
}

float stof(const std::string& s) {
    std::istringstream str(s);
    float i;
    str >> i;
    return i;
}


#endif
