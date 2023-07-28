#include <iostream>
#include "contact.h"
#include "book.h"

int main()
{
    std::cout << "______ Welcome to the console Address Book  _______" << std::endl;
    int choise{};
    Book my_book;
    do {
        std::cout << "1. Add contact\n2. Delete contact\n3. Edit contact\n4. Search\n0. Exit" << std::endl;
        std::cin >> choise;
        std::cin.ignore();
        switch ( choise ) {
            case 1 : my_book.addContact();
                break;
            case 2 : my_book.remove();
                break;
            case 3 : my_book.update();
                break;
            case 4 : my_book.search();
                break;  
            case 0 : break;
            default:  std::cout << "Invalid input! Pleas try again." << std::endl;
                break;
        }
    } while ( choise );
}
