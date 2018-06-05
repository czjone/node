#ifndef XSE_MACROS_HPP
#define XSE_MACROS_HPP 1
#   define XSE_DELETE(p)                    do { delete (p); (p) = nullptr; } while(0)
#   define XSE_DELETE_ARRAY(p)              do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#   define XSE_FREE(p)                      do { if(p) { free(p); (p) = nullptr; } } while(0)
#   define XSE_BREAK_IF(EXPRESS)            if(EXPRESS) break;
#   define XSE_ROOT_NS_NAME Xse
#   define XSE_NS_BEGIN namespace XSE_ROOT_NS_NAME {
#   define XSE_NS_END }
#   define XSE_NS_USING using namespace XSE_ROOT_NS_NAME 

#   ifndef XSE_ASSERT
#       define XSE_ASSERT(e,...) 
#   endif

#endif

// #define XSE_NS_EXT_NAME Extentions
// #define XSE_NS_EXT_BEGIN(_NS_) XSE_NS_BEGIN namespace _NS_ {
// #define XSE_NS_EXT_END XSE_NS_END }
// #define XSE_NS_EXT_USING(_NS_) XSE_NS_USING;using namespace _NS_
// #endif