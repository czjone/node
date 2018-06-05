#include "server.hpp"
#include <boost/asio.hpp>
#include "network/http/server.hpp"

Xse::HttpServer::HttpServer(
    const std::string& address,
    const std::string& port,
    const std::string& doc_root)
:maddress(address),
mport(port),
mdoc_root(doc_root){
    
}
Xse::HttpServer::~HttpServer(){

}
void Xse::HttpServer::Start(){
    http::server::server s(this->maddress, this->mport, this->mdoc_root);
    s.run();
}