#ifndef XSE_LOG_H
#define XSE_LOG_H 1

#include <string>

namespace Xse {
    class Log {
    public:
    enum Type {
        DEBUG_INFO = 0,
        INFO =      1,
        WARN =      2,
        ERROR =     3,
        FATAL =     4,
    };

    public:
        Log(const Log&) = delete;

        Log& operator=(const Log&) = delete;

        Log& operator&() = delete;

        Log() = delete;
        
        static void Debug(const std::string &message);

        static void Error(const std::string &message);

        static void Fatal(const std::string &message);

        static void Info(const std::string &message);

        private:
            static void Write(Type type,const std::string &message);
    };
} // end Log


#endif