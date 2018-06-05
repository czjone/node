#include "config.hpp"
#include "node.hpp"
#include "log.hpp"
#include "version.hpp"
#include "server.hpp"
#include <exception>

using namespace Xse;

#if ENABLE_EXECUTE_BIN
int main(int argc,char** arg){
    try{
        Log::Debug(Xse::getVersionString());
        Log::Debug("node server starting...");
        Xse::HttpServer server(arg[1],arg[2],arg[3]);
        server.Start();
        return 1;  
    }
    catch(std::exception &e){
        Log::Error(e.what());
    };
    return 0;
}
#endif