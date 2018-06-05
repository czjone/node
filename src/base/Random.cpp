// //
// //  Random.cpp
// //  game_huoying
// //
// //  Created by solyess on 7/13/16.
// //
// //

// #include "Random.hpp"
// #include <random>
// #include <stdio.h>
// #include <stdlib.h>


// /*********************************************************************************************************************/
// //TODO::有数据溢出BUG，seed 只能用int32
// #if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
// static  LLONG multiplier = 0x5DEECE66DLL;
// static  LLONG addend     = 0xBLL;
// static  LLONG  mask      = (1LL << 48) - 1;
// #else
//  static  LLONG multiplier = 0x5DEECE66DL;
//  static  LLONG addend     = 0xBL;
//  static  LLONG mask       = (1LL << 48) - 1;
// #endif

// //CRandom::CRandom():
// //seed(0)
// //{
// //    
// //}

// LLONG strtoll_e(const char* str){
//     LLONG ret;
//     char *endptr;
//     return strtoll(str, &endptr, 10);
//     //return strtol(str, &endptr, 10);
// }

// CRandom::CRandom(const char* seed):
// #if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
// seed(strtoll_e(seed))
// #else
// //seed(atof(seed))
// seed(strtoll_e(seed))
// #endif
// {
//     CCLOG("%s",seed);
// #if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
//     CCLOG("ctor seed:%I64d", this->seed);
// #elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
//     CCLOG("ctor seed:%lld", this->seed);
// #else
// 	CCLOG("ctor seed:%lld", this->seed);
// #endif
// 	this->seed = (this->seed ^ multiplier) & mask;
// }

// CRandom::~CRandom(void){
//     }

// LLONG CRandom::nextInt(const char* boundstr){
// //    #if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
// //    LLONG bound = strtoll_e(boundstr);
// //    // CCLOG("nextInt bound:%lld",bound);
// //    #else
// //    //LLONG bound = atof(boundstr);
// //    LLONG bound = strtoll_e(boundstr);
// //    // CCLOG("nextInt bound:%ld",bound);
// //    #endif
    
//     int bound = (int)strtoll_e(boundstr);
    
//     CCASSERT(bound>0, "bound must be positive.");
//     int r = next(31);
//     // CCLOG("get random 1:%lld",r);
//     int m = bound - 1;
//     if ((bound & m) == 0) {// i.e., bound is a power of 2
//         r = (int) ((bound * (LLONG) r) >> 31);
//         // CCLOG("get random 2:%lld",r);
//     }
//     else {
//         // CCLOG("get m:%lld",m);
//         // CCLOG("get model:%lld",(r % bound));
//         // CCLOG("get custom:%lld",mod(r,bound));
//         for (int u = r; u - (r = u % bound) + m < 0; u = next(31)){
//             // CCLOG("get random 3:%lld",r);
//             ;
//         }
//     }
// //    CCLOG("out ret:%d",r);
    
//     return r;
// }

// LLONG CRandom::nextInt(){
//     return this->next(32);
// }

// int CRandom::next(int bits){
// /***64位可正常工作，32位有问题****/
// //    LLONG oldseed;
// //    LLONG nextseed;
// //    oldseed = this->seed;
// //    nextseed = (oldseed * multiplier + addend) & mask;
// //    this->seed = nextseed;
// //    LLONG ret = (LLONG)(nextseed >> (48 - bits));
// //    // CCLOG("next bound:%lld",this->seed );
// //    // CCLOG("ret:%lld",ret);
// //    return  ret;
    
// //    bool is32Bite = sizeof(long) == 4;
    
//     LLONG oldseed;
//     LLONG nextseed;
//     oldseed = this->seed;
//     nextseed = (oldseed * multiplier + addend) & mask;
//     this->seed = nextseed;
//     int ret = (int)(nextseed >> (48 - bits));
//     // CCLOG("next bound:%lld",this->seed );
//     // CCLOG("ret:%lld",ret);
//     return  ret;
// }

// void CRandom::test(){
// //    long seed =1468380054325L;
// //    CRandom roandom(seed);
// //    for(int i = 0;i < 20; i ++){
// //        int r = roandom.nextInt(1000);
// //        printf(">>>>>>> roandom val:%d \n",r);
// //    }
// }


