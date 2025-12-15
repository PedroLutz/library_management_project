/*
Fazer Library Management System 2.0 - avançado
STL avançada, templates, ponteiros inteligentes, multithreading, arquivos binários, design patterns
gerenciar livros (adicionar, remover, listar, buscar) com containers STL avançados (CHECK)
persistência em arquivo binário e backup automático (CHECK)
playlists de leitura compartilhadas via smart pointers (CHECK)
operações concorrentes seguras com threads e mutex (CHECK)
notificações via pattern observer (CHECK)
criação de livros de diferentes tipos via factory (CHECK)
tratamento robusto de erros com exceções (CHECK)
interface de console completa com menus (CHECK)
logs de operações com timestamps (CHECK)
memória gerenciada corretamente (RAII + smart pointers) (CHECK)
testar todas as funcionalidades em cenários combinados (adicionar, remover, notificar, ordenar, thread-safe)
*/

#include "menu.hpp"
#include "file.hpp"
#include "book_vector.hpp"
#include "book.hpp"

int main()
{
    BookVector bookVector;
    size_t option;

    FileManager::readBookVectorFromFile(bookVector);
    bool shouldStayInLoop = true;
    while (shouldStayInLoop)
    {
        Menu::main(option);

        switch (option)
        {
        case (1):
        {
            GenericBook genBook = Menu::promptNewBook(true);
            bookVector.addBook(genBook.name, genBook.author, genBook.year, genBook.genre, true);
            break;
        }

        case (2):
        {
            system("clear");
            bookVector.printAllBooks();
            Menu::pause();
            break;
        }

        case (3):
        {
            size_t id = Menu::promptGetId();
            if (id >= bookVector.getBookVector().size())
            {
                Menu::warning("The ID is not valid!");
                break;
            }
            bookVector.removeBookById(id);
            break;
        }

        case (4):
        {
            size_t choice = Menu::promptIdOrTitle();
            switch (choice)
            {
            case (1):
            {
                size_t id = Menu::promptGetId();
                if (id >= bookVector.getBookVector().size())
                {
                    Menu::warning("The ID is not valid!");
                    break;
                }
                auto foundBook = bookVector.getBookById(id);
                std::cout << "ID: " << id << "\n";
                foundBook->printBook();
                Menu::pause();
                break;
            }

            case (2):
            {
                std::string title = Menu::promptGetTitle();
                size_t id;
                auto foundBook = bookVector.getBookByTitle(title, id);
                if (foundBook == nullptr)
                {
                    Menu::warning("Book not found!");
                    break;
                }
                std::cout << "ID: " << id << "\n";
                foundBook->printBook();
                Menu::pause();
                break;
            }
            default:
                break;
            }
            break;
        }

        case (5):
        {
            size_t choice = Menu::promptIdOrTitle();
            switch (choice)
            {
            case (1):
            {
                size_t id = Menu::promptGetId();
                if (id >= bookVector.getBookVector().size())
                {
                    Menu::warning("The ID is not valid!");
                    break;
                }
                auto foundBook = bookVector.getBookById(id);
                GenericBook newInfo = Menu::promptNewBook(false);
                bookVector.updateById(id, newInfo.name, newInfo.author, newInfo.year);
                break;
            }

            case (2):
            {
                std::string title = Menu::promptGetTitle();
                size_t id;
                auto foundBook = bookVector.getBookByTitle(title, id);
                if (foundBook == nullptr)
                {
                    Menu::warning("Book not found!");
                    break;
                }
                GenericBook newInfo = Menu::promptNewBook(false);
                bookVector.updateByTitle(foundBook->getName(), newInfo.name, newInfo.author, newInfo.year);
                break;
            }
            default:
                break;
            }
            break;
        }

        case (0):
        {
            shouldStayInLoop = false;
            break;
        }
        }
    }

    FileManager::writeBookVectorInFile(bookVector);

    return 0;
}