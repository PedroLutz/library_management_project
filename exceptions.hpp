#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

class InvalidGenre : public std::exception{
    public:
    const char * what() const noexcept override {
        return "Invalid Genre";
    }
};

#endif