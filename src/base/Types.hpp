#ifndef XSE_TYPES_HPP
#define XSE_TYPES_HPP 1

#include <config.hpp>
//types
#if(ARCHITECTURE_DEF==ARCHITECTURE_64)
	typedef short 				Int32;
	typedef int 				Int64;
	typedef unsigned short 		UInt32;
	typedef unsigned int 		UInt64;
	typedef unsigned char* 		cstring;
	typedef unsigned char		byte;
	typedef unsigned char* 		bytes;
	typedef bool		 		Bool;
	typedef Int32				State;
    typedef long long		    LLong;
#else
	typedef int 				Int32;
	typedef long 				Int64;
	typedef unsigned int 		UInt32;
	typedef unsigned int 		UInt64;
	typedef unsigned char* 		cstring;
	typedef unsigned char		byte;
	typedef unsigned char* 		bytes;
	typedef bool		 		Bool;
	typedef Int32				State;
    typedef long long		    LLong;
#endif

#endif /*end TYPES_H*/