#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <mutex>

class Logger {
private:
    std::mutex mtx;
    Logger() {}  
public:
    static Logger& instance() {
        static Logger inst;  
        return inst;
    }

    void log(const std::string& msg);
};

#endif