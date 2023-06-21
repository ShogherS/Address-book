#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "address_book.h"

extern std::vector<Contact*> addressBook;

int main(){
    int choice = 0;
    do{
        std::cout << "_________________Address Book__________________"<<std::endl;
        std::cout << "                     Menue                      "<<std::endl;
        std::cout << "1. Add an addres" <<std::endl;
        std::cout << "2. Delete an address" <<std::endl;
        std::cout << "3. Edit an address" << std::endl;
        std::cout << "4. Search" << std::endl;
        std::cout << "5. See all addresses" <<std::endl;
        std::cout << "0. Exit"<<std::endl;
        std::cin >> choice;
        if (!std::cin) {
            std::cin.clear();
            while(std::cin.get()!= '\n') {
                continue;
            }
            break;
        }
        switch(choice){
            case 1: add();
            break;
            case 2: remove();
            break;
            case 3: edit();
            break;
            case 4: search();
            break;
            case 5: print();
            break;
            case 0: 
                std::cout << "Exiting the address book" << std::endl;
            break;
            default: 
                std::cout << "Invalid input! Please try agin" << std::endl;
            break;
         }
    }while(choice);
    saveClose();  
}
