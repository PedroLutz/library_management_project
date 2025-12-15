#include "book.hpp"
#include "exceptions.hpp"

Book::Book(std::string n, std::string a, unsigned short int y) : name(n), author(a), year(y) {};

void Book::update(std::string n, std::string a, unsigned short int y) {
    name = n;
    author = a;
    year = y;
}

std::string Book::getName() {
    return name;
}

std::string Book::getAuthor() {
    return author;
}

unsigned short int Book::getYear() {
    return year;
}

FictionBook::FictionBook(std::string n, std::string a, unsigned short int y): Book(n, a, y) {};

Genre FictionBook::getGenre() {
    return FICTION;
};

std::string FictionBook::getGenreStr() {
    return "Fiction";
}

void FictionBook::printBook(){
    std::cout << "Title: " << this->name << "\n";
    std::cout << "Author: " << this->author << "\n";
    std::cout << "Year: " << this->year << "\n";
    std::cout << "Genre: Fiction\n";
};

HorrorBook::HorrorBook(std::string n, std::string a, unsigned short int y): Book(n, a, y) {};

Genre HorrorBook::getGenre() {
    return HORROR;
};

std::string HorrorBook::getGenreStr() {
    return "Horror";
}

void HorrorBook::printBook(){
    std::cout << "Title: " << this->name << "\n";
    std::cout << "Author: " << this->author << "\n";
    std::cout << "Year: " << this->year << "\n";
    std::cout << "Genre: Horror";
};

RomanceBook::RomanceBook(std::string n, std::string a, unsigned short int y): Book(n, a, y) {};

Genre RomanceBook::getGenre() {
    return ROMANCE;
};

std::string RomanceBook::getGenreStr() {
    return "Romance";
}

void RomanceBook::printBook(){
    std::cout << "Title: " << this->name << "\n";
    std::cout << "Author: " << this->author << "\n";
    std::cout << "Year: " << this->year << "\n";
    std::cout << "Genre: Romance" << "\n";
};

ScifiBook::ScifiBook(std::string n, std::string a, unsigned short int y): Book(n, a, y) {};

Genre ScifiBook::getGenre() {
    return SCIFI;
};

std::string ScifiBook::getGenreStr() {
    return "Science Fiction";
}

void ScifiBook::printBook(){
    std::cout << "Title: " << this->name << "\n";
    std::cout << "Author: " << this->author << "\n";
    std::cout << "Year: " << this->year << "\n";
    std::cout << "Genre: Science Fiction";
};

std::shared_ptr<Book> BookFactory::create(std::string name, std::string author, unsigned short int year, Genre genre){
    switch(genre) {
        case FICTION: return std::make_shared<FictionBook>(std::move(name), std::move(author), year);
        case ROMANCE: return std::make_shared<RomanceBook>(std::move(name), std::move(author), year);
        case SCIFI: return std::make_shared<ScifiBook>(std::move(name), std::move(author), year);
        case HORROR: return std::make_shared<HorrorBook>(std::move(name), std::move(author), year);
        default: throw InvalidGenre();
    }
}