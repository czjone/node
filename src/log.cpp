#include "log.hpp"
#include <iostream>

using namespace Xse;

void Xse::Log::Write(Log::Type type, const std::string &message)
{
    switch (type)
    {
    case Log::Type::DEBUG_INFO:
    {
        std::cout << message << std::endl;
        break;
    }
    case Log::Type::INFO:
    {
        break;
    }
    case Log::Type::WARN:
        break;
    case Log::Type::ERROR:
        break;
    case Log::Type::FATAL:
        break;
    default:
        break;
    }
}

void Xse::Log::Debug(const std::string &message)
{
    Write(Log::DEBUG_INFO, message);
}

void Xse::Log::Error(const std::string &message)
{
    Write(Log::ERROR, message);
}

void Xse::Log::Fatal(const std::string &message)
{
    Write(Log::FATAL, message);
}

void Xse::Log::Info(const std::string &message)
{
    Write(Log::INFO, message);
}
