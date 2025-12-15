#include "logger.hpp"
#include <fstream>
#include <iostream>
#include <iomanip> // For std::put_time
#include <sstream>

void Logger::log(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx);
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* local_tm = std::localtime(&now_c);
    std::cout << "Current local time: " << std::put_time(local_tm, "%Y-%m-%d %H:%M:%S") << std::endl;

    std::ofstream f("log.txt", std::ios::app);

    if(!f){
        std::cerr << "Error while opening file!\n";
        return;
    }

    f << msg << "; " << std::put_time(local_tm, "%Y-%m-%d %H:%M:%S") << "\n";

    f.close();
}