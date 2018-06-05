CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(nodeProject)

################################# c++ 11 supports ############################################
include(CheckCXXCompilerFlag)  
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)  
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)  

add_definitions("-Wundefined-internal")

if(COMPILER_SUPPORTS_CXX11)  
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")  
elseif(COMPILER_SUPPORTS_CXX0X)  
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")  
else()  
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")  
endif()  

#################################### for simple socket ########################################
if(UNIX)
    # linux / normal unix
    add_definitions(-D_LINUX)
    if(CYGWIN)
        # Special Cygwin stuff here
    elseif(APPLE)
        # Special Apple stuff here
        remove_definitions(-D_LINUX)
        add_definitions(-D_DARWIN)
    endif()
elseif(WIN32)
    add_definitions(-DWIN32)
    SET(PROJECT_LIBS Ws2_32.lib)
    if(MINGW)
        # Special MINGW stuff here
    elseif(MSVC)
        # Special MSVC stuff here
        add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS)
    else()
        # No idea what it is, but there's a good chance it's too weird.
        MESSAGE( FATAL_ERROR "Using unknown WIN32 compiler... NOT. Please add to build system." )
    endif()
endif()

# IF (APPLE)
# 	add_compile_options(-x objective-c++)
# 	set(CMAKE_EXE_LINKER_FLAGS "-framework CFNetwork.framework")
# ENDIF(APPLE)

# Enable DEBUG
if(APPLE)
    SET(CMAKE_BUILD_TYPE "Debug") 
    #发布版
    # SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2")   
    #调试版本
    add_definitions(-DDEBUG)
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")   
    
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")    
endif()

#################################### for compiles files ########################################
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/boost/include
)
if(APPLE)
    SET(targetPlatform "mac")
endif()

link_directories(
 	${CMAKE_CURRENT_SOURCE_DIR}/libs/boost/bin/${targetPlatform}/lib
)

link_libraries(
	"libboost_chrono.a"
    "libboost_date_time.a"
    "libboost_exception.a"
    "libboost_filesystem.a"
    "libboost_iostreams.a"
    "libboost_regex.a"
    "libboost_serialization.a"
    "libboost_signals.a"
    "libboost_system.a"
    "libboost_thread.a"
    "libboost_timer.a"
    "libboost_wserialization.a"
)

#Core
# set(SRC_LIST 
#     sclient.cc
# )
AUX_SOURCE_DIRECTORY(src SRC_LIST)
AUX_SOURCE_DIRECTORY(src/network/http SRC_LIST)
AUX_SOURCE_DIRECTORY(src/network/tcp SRC_LIST)
AUX_SOURCE_DIRECTORY(src/network/udp SRC_LIST)
AUX_SOURCE_DIRECTORY(src/network/protocal SRC_LIST)
AUX_SOURCE_DIRECTORY(src/test SRC_LIST)
ADD_EXECUTABLE(node ${SRC_LIST})