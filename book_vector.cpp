#include "book_vector.hpp"
#include "exceptions.hpp"


void BookVector::addBook(std::string n, std::string a, unsigned short int y, Genre g, bool isNew){
    std::lock_guard<std::mutex> lock(mtx);
    bookVector.push_back(BookFactory::create(n, a, y, g));
    if(isNew) logger.log("New book added! \"" + n + "\", by " + a);
}

void BookVector::removeBookById(size_t id){
    std::lock_guard<std::mutex> lock(mtx);
    if(id >= bookVector.size()) throw std::out_of_range(
            "Delete operation failed: Index " + 
            std::to_string(id) + 
            " is out of bounds for vector size " + 
            std::to_string(bookVector.size()));
    auto foundBook = getBookById(id);
    bookVector.erase(bookVector.begin() + id);
    logger.log("\"" + foundBook->getName() + "\", by " + foundBook->getAuthor() + " is no longer available!");
};

std::shared_ptr<Book> BookVector::getBookById(size_t id){
    if(id >= bookVector.size()) throw std::out_of_range(
            "Search operation failed: Index " + 
            std::to_string(id) + 
            " is out of bounds for vector size " + 
            std::to_string(bookVector.size()));
    return bookVector.at(id);
}

std::shared_ptr<Book> BookVector::getBookByTitle(std::string &name, size_t &id){
    for(size_t i = 0; i < bookVector.size(); i++){
        if(bookVector.at(i)->getName() == name){
            id = i;
            return bookVector.at(i);
        }
    }
    return nullptr;
}

void BookVector::updateById(size_t id, std::string n, std::string a, unsigned short int year){
    std::lock_guard<std::mutex> lock(mtx);
    if(id >= bookVector.size()) throw std::out_of_range(
            "Update operation failed: Index " + 
            std::to_string(id) + 
            " is out of bounds for vector size " + 
            std::to_string(bookVector.size()));
    GenericBook oldBook = {bookVector.at(id)->getName(), bookVector.at(id)->getAuthor(), bookVector.at(id)->getYear(), bookVector.at(id)->getGenre()};
    bookVector.at(id)->update(n, a, year);
    logger.log("\"" + oldBook.name + "\", by " + oldBook.author + " has been updated to \"" + n + "\", by " + a + "!");
}

void BookVector::updateByTitle(std::string oldTitle, std::string newTitle, std::string a, unsigned short int year){
    size_t id;
    auto foundBook = this->getBookByTitle(oldTitle, id);
    if(foundBook == nullptr) throw std::runtime_error(
        "Update operation failed: Title: " +
        oldTitle + " not found ");
    GenericBook oldBook = {foundBook->getName(), foundBook->getAuthor(), foundBook->getYear(), foundBook->getGenre()};
    foundBook->update(newTitle, a, year);
    logger.log("\"" + oldTitle + "\", by " + oldBook.author + " has been updated to \"" + newTitle + "\", by " + a + "!");
}

void BookVector::printAllBooks(){
    for(size_t i = 0; i < bookVector.size(); i++){
        std::cout << "ID: " << i << "\n";
        bookVector.at(i)->printBook();
        std::cout << "\n\n";
    }
}

std::vector<std::shared_ptr<Book>> &BookVector::getBookVector(){
    return bookVector;
}