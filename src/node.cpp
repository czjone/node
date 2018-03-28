#include "config.hpp"
#include "node.hpp"
#include "log.hpp"
#include "server.hpp"
#include <exception>

using namespace Xse;

#if ENABLE_EXECUTE_BIN
int main(int argc,char** arg){
    try{
        // if (argc != 4)
        // {
        //     std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
        //     std::cerr << "  For IPv4, try:\n";
        //     std::cerr << "    receiver 0.0.0.0 80 .\n";
        //     std::cerr << "  For IPv6, try:\n";
        //     std::cerr << "    receiver 0::0 80 .\n";
        //     return 1;
        // }
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