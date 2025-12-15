#ifndef BOOK_VECTOR_HPP
#define BOOK_VECTOR_HPP

#include <vector>
#include <mutex>
#include "book.hpp"
#include "logger.hpp"

class User;

class BookVector {
    private:
        std::vector<std::shared_ptr<Book>> bookVector;

        std::mutex mtx;
        Logger &logger = Logger::instance();

    public:
        BookVector() {};

        void addBook(std::string n, std::string a, unsigned short int y, Genre g, bool isNew);
        void removeBookById(size_t id);
        std::shared_ptr<Book> getBookById(size_t id);
        std::shared_ptr<Book> getBookByTitle(std::string &name, size_t &id);
        void updateById(size_t id, std::string n, std::string a, unsigned short int year);
        void updateByTitle(std::string oldTitle, std::string newTitle, std::string a, unsigned short int year);
        void printAllBooks();

        std::vector<std::shared_ptr<Book>>& getBookVector();
};

#endif