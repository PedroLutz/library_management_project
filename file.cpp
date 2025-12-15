#include "file.hpp"

std::mutex FileManager::mtx;
std::fstream FileManager::f;

void FileManager::writeBookVectorInFile(BookVector &bookVector){
    std::lock_guard<std::mutex> lock(mtx);
    f.open("data.bin", std::ios::out | std::ios::binary | std::ios::trunc);

    if(!f){
        std::cerr << "Error while opening file!\n";
        return;
    }

    for(auto &b : bookVector.getBookVector()){
        size_t nameLen = b->getName().size();
        f.write(reinterpret_cast<char *>(&nameLen), sizeof(nameLen));
        f.write(b->getName().c_str(), nameLen);

        size_t authorLen = b->getAuthor().size();
        f.write(reinterpret_cast<char *>(&authorLen), sizeof(authorLen));
        f.write(b->getAuthor().c_str(), authorLen);

        unsigned short int year = b->getYear();
        f.write(reinterpret_cast<char *>(&year), sizeof(year));

        Genre genre = b->getGenre();
        f.write(reinterpret_cast<char *>(&genre), sizeof(genre));
    }

    f.close(); 
    f.clear();
}

void FileManager::readBookVectorFromFile(BookVector &bookVector){
    std::lock_guard<std::mutex> lock(mtx);
    f.open("data.bin", std::ios::in | std::ios::binary);
    
    if(!f){
        std::cerr << "Error while opening file!\n";
        return;
    }

    while(true){
        size_t nameLen;
        if(!f.read(reinterpret_cast<char *>(&nameLen), sizeof(nameLen))) break;

        std::string name(nameLen, '\0');
        f.read(&name[0], nameLen); 

        size_t authorLen;
        f.read(reinterpret_cast<char *>(&authorLen), sizeof(authorLen));

        std::string author(authorLen, '\0');
        f.read(&author[0], authorLen);

        unsigned short int year;
        f.read(reinterpret_cast<char *>(&year), sizeof(year));

        Genre genre;
        f.read(reinterpret_cast<char *>(&genre), sizeof(genre));

        bookVector.addBook(name, author, year, genre, false);
    }

    f.close(); 
    f.clear();
}