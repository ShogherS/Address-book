#ifndef BOOK
#define BOOK
#include <string>
#include <vector>
#include "contact.h"
#include <fstream>
#include <sstream>

class Book
{
    std::vector<Contact*> _book;
    Contact* setContact();
    void inputData();
    void saveData();
       
    public:
    Book();
    void addContact();
    void remove();
    Contact* search();
    void update(); 
    ~Book();
};
Contact* Book:: setContact() {
        std::cout << "Enter a name" <<std::endl;
        std::string n;
        std::getline( std::cin, n);
        std::cout << "Enter phone number" <<std::endl;
        std::string p;
        std::cin >> p;
        std::cin.ignore();
        std::cout << "Enter an email address" << std::endl;
        std::string e;
        std::cin >> e;
        std::cin.ignore();
        Contact* c = new Contact( n, p, e);
        return c;
    }

Book:: Book() {
        inputData();
    }
void Book:: addContact() {
        std::cout << "_______Add a new contact_______" << std::endl;
        _book.push_back( setContact() );
        std::cout << "_______A new contact was added_________" << std::endl;
    }
void Book::remove() {
        std::cout << "Removing contact" << std::endl;
        Contact* c = search();
        if( c == nullptr)
            return;
        for( auto it = _book.begin() ; it != _book.end() ; ++it ) {
            if( c == *it) {
                _book.erase(it);
                std::cout << "The contact was removed" << std::endl;
                return;
            }
        }
    }
Contact* Book::search() {
        std::cout << "_______SEAARCHING FOR CONTACT____________\n" << "Enter a contact info" << std::endl;
        std::string n;
        std::getline( std::cin , n);
        for( const auto& it: _book) {
            if( it->getName() == n || it->getPhone() == n || it->getEmail() == n) {
                std::cout << it->print() << std::endl;
                return it;
            }
        }
        std::cout << "An appropriate element was not found" << std::endl;
        return nullptr;
    }
void Book::update() {
        std::cout <<"Updating contact info" << std::endl;
        Contact* c = search();
        if( c == nullptr )
            return;
        std::cout <<"Update info hear" << std::endl;
        delete c;
        c = setContact(); 
        std::cout << "The contact have been updated" << std::endl;
    }
void Book::inputData() {
        std::ifstream  Fin( "address_book.txt" );
        std::string line, n, e, p;
         
        while ( std::getline( Fin, line ) ) {
            std::istringstream iss(line);
            if( std::getline( iss, n, ' ' ) &&
                std::getline( iss, p, ' ' ) &&
                std::getline( iss, e, ' ') ) {
                _book.push_back( new Contact( n, p, e) );
            }
        }
        Fin.close();
        std::cout << "Contacts have been inported from file" << std::endl;
    } 
void Book::saveData() {
        std::ofstream Fout( "address_book.txt" );
        for( const auto& it : _book ) {
            Fout << it->getName() << " " << it->getPhone() << " " << it->getEmail() << "\n" ;
        }
        Fout.close();
        std::cout << "Contacts have been saved to file" << std::endl;
    }
Book:: ~Book() {
        saveData();
        for( auto& it: _book) {
            delete it;
        }
    _book.clear();
    std::cout << "_________  Thank you! Bye  __________" << std::endl;
    }

#endif
