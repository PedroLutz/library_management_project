#include <iostream>
#include "book.hpp"
#include <cstdlib>
#include <memory>

class Menu
{
private:
    static Genre getGenre()
    {
        size_t g;
        std::cout << "Select genre: \n\n";
        std::cout << "1. Fiction\n";
        std::cout << "2. Science Fiction\n";
        std::cout << "3. Romance\n";
        std::cout << "4. Horror\n";

        std::cin >> g;
        std::cin.ignore();

        return (Genre)(g - 1);
    }

public:
    static void main(size_t &option)
    {
        system("clear");
        std::cout << "Library Management System\n\n";
        std::cout << "1. Add book\n";
        std::cout << "2. List books\n";
        std::cout << "3. Remove book\n";
        std::cout << "4. Search book\n";
        std::cout << "5. Update book\n";
        std::cout << "0. Exit\n\n";

        std::cout << "Type the desired option: ";

        std::cin >> option;
        std::cin.ignore();
    }

    static GenericBook promptNewBook(bool isNew)
    {
        system("clear");
        std::string name;
        std::cout << "Book name: ";
        std::getline(std::cin, name);

        std::string author;
        std::cout << "Author: ";
        std::getline(std::cin, author);

        unsigned short int year;
        std::cout << "Year: ";
        std::cin >> year;
        std::cin.ignore();

        Genre genre = FICTION; //if isNew = false, the genre here doesnt matter
        if(isNew) genre = getGenre();

        return {name, author, year, genre};
    }

    static size_t promptIdOrTitle()
    {
        system("clear");
        size_t option;
        std::cout << "1. By id; 2. By title; 0. Go back\n";
        std::cin >> option;
        std::cin.ignore();
        return option;
    }

    static std::string promptGetTitle(){
        system("clear");
        std::string title;
        std::cout << "Type the title:\n";
        std::getline(std::cin, title);
        return title;
    }

    static size_t promptGetId(){
        system("clear");
        size_t id;
        std::cout << "Type the id:\n";
        std::cin >> id;
        std::cin.ignore();
        return id;
    }

    static void pause(){
        std::cout << "\nType anything to continue...";
        std::cin.get();
    }

    static void warning(std::string&& str){
        system("clear");
        std::cerr << str;
        pause();
    }
};