#ifndef XSE_SERVER_H
#define XSE_SERVER_H 1
#include <string>

namespace Xse {
    class HttpServer{
        public:
            explicit HttpServer(const std::string& address, const std::string& port,
      const std::string& doc_root);
            ~HttpServer();
            void Start();

        private:
            std::string maddress;
            std::string mport;
            std::string mdoc_root;
    };
}
#endif