#include "version.hpp"

#define VER_CODE 1
#define VER_STR  "0.0.1"

int Xse::getVersionCode(){
    return VER_CODE;
}

std::string Xse::getVersionString(){
    return VER_STR;
}