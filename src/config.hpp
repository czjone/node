#ifndef NODE_CONFIG_H
#define NODE_CONFIG_H 1

#define ENABLE_EXECUTE_BIN 1 


//plantform define
#define PLANTFORM_TARGET_MAC	1
#define PLANTFORM_TARGET_WIN	2
#define PLANTFORM_TARGET_LINUX	3

//define ARCHITECTURE
#define ARCHITECTURE_DEF		32
#define ARCHITECTURE_32  		32
#define ARCHITECTURE_64			64

#if WIN32
#	include <SDKDDKVer.h>
#	include <stdio.h>
#	include <tchar.h>
#	include <assert.h>
#	include <stdlib.h>
#	include <windows.h>
#	include <IO.h>
#	include <direct.h>
#	include <String.h>
#	include <atlbase.h>  
#endif

#if (WIN32 && DEBUG)
#	define IS_DEBUG 1
#endif

#define IS_OUT_LOG 1

#if (WIN32 || WIN64)
#	define ARC_WINDOWS 1
#	if WIN32
#		ifndef ARCHITECTURE_32
#			define ARCHITECTURE_32 1
#		endif
#	else
#		define ARCHITECTURE_64 1
#	endif
#else
#	undef ARC_WINDOWS
#endif


#if (IS_DEBUG > 0)
#	define ASSERT(str,...) assert(str ,##__VA_ARGS__)
#	define LOG(str,...)	printf(str ,##__VA_ARGS__); printf("\n")
#	define LOG_IF(exp, str,...) do{if(exp){	printf(str ,##__VA_ARGS__); printf("\n");}}while(0)
#elif(IS_OUT_LOG)
#	define ASSERT(str,...) assert(str ,##__VA_ARGS__)
#	define LOG(str,...)	printf(str ,##__VA_ARGS__); printf("\n")
#	define LOG_IF(exp, str,...) do{if(exp){	printf(str ,##__VA_ARGS__); printf("\n");}}while(0)
#else
#	define ASSERT(str,...) assert(str ,##__VA_ARGS__)
#	define LOG(str,...)
#	define LOG_IF(exp,str,...)
#endif

#ifdef DELETE 
#	undef DELETE
#endif
#	define DELETE(__T__) do{if(__T__) delete __T__; __T__=nullptr;}while(0);

#ifdef FREE
#	undef FREE
#endif
#	define FREE(__T__) do{if(__T__) free(__T__); __T__=nullptr;}while(0);

#define ERROR_NOT_FOUND_FILE -1000


#endif