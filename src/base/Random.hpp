#ifndef Random_hpp
#define Random_hpp

#include <stdio.h>
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#   define LLONG long long 
#else
#   define LLONG long long
#endif

class CRandom {
private:
    LLONG seed;
    
public:
    //CRandom();
    CRandom(const char* seed);
    virtual ~CRandom(void);
    
    LLONG nextInt(const char* boundstr);
    LLONG nextInt();
    int luaSupports();
private:
    int next(int bits);
    
public:
    static void test();
};
#endif /* Random_hpp */
