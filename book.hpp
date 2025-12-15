#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <memory>

enum Genre {FICTION, SCIFI, ROMANCE, HORROR};

struct GenericBook {
    std::string name;
    std::string author;
    unsigned short int year;
    Genre genre;
};

class Book{
    protected:
        std::string name;
        std::string author;
        unsigned short int year;

    public:
        Book(std::string n, std::string a, unsigned short int y);

        void update(std::string n, std::string a, unsigned short int y);
        std::string getName();
        std::string getAuthor();
        unsigned short int getYear();
        virtual Genre getGenre() = 0;
        virtual std::string getGenreStr() = 0;
        virtual void printBook() = 0;
};

class FictionBook : public Book {
    private:
        Genre genre = FICTION;

    public:
        FictionBook(std::string n, std::string a, unsigned short int y);
        Genre getGenre() override;
        std::string getGenreStr() override;
        void printBook() override;
};

class HorrorBook : public Book {
    private:
        Genre genre = HORROR;

    public:
        HorrorBook(std::string n, std::string a, unsigned short int y);
        Genre getGenre() override;
        std::string getGenreStr() override;
        void printBook() override;
};

class RomanceBook : public Book {
    private:
        Genre genre = ROMANCE;

    public:
        RomanceBook(std::string n, std::string a, unsigned short int y);
        Genre getGenre() override;
        std::string getGenreStr() override;
        void printBook() override;
};

class ScifiBook : public Book {
    private:
        Genre genre = SCIFI;

    public:
        ScifiBook(std::string n, std::string a, unsigned short int y);
        Genre getGenre() override;
        std::string getGenreStr() override;
        void printBook() override;
};

class BookFactory {
    public:
        static std::shared_ptr<Book> create(std::string name, std::string author, unsigned short int year, Genre genre);
};

#endif