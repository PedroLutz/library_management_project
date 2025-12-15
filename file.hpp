#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include "book.hpp"
#include <fstream>
#include "book_vector.hpp"
#include <mutex>

class FileManager {
    private:
        static std::mutex mtx;
        static std::fstream f;

    public:
        FileManager(){};

        static void writeBookVectorInFile(BookVector &bookVector);
        static void readBookVectorFromFile(BookVector &bookVector);
};

#endif