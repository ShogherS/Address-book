#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
struct Contact{
    std::string fname;
    std::string lname;
    std::string address;
    std::string number;
    std::string email;
};
void add();
void remove();
void edit();
void search();
void print();
void saveClose();
void init(Contact*);
std::vector<Contact*> addressBook;
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
void saveClose(){
    std::ofstream file;
    file.open("My_address_book.txt", std::ios::app);
    if ( file.is_open()) {
        for(auto*& elem: addressBook) {
            file << elem->fname << ',' << elem->lname << ',' << elem->address << ',' <<elem->number << ',' << elem->email << std::endl;
         }
         std::cout << "All addresses are seved in file" << std::endl;
    }
    file.close();
    for (auto*& elem: addressBook) {
        delete elem;
        elem = nullptr;
    }
}
void init(Contact* contact){
    do{
    std::cout << "Enter a First name" << std::endl;
    std::cin>> contact->fname;
    } while(size(contact->fname) ==0);
    std::cout << "Enter Last name" << std::endl;
    std::cin>> contact->lname;
    do{
        std::cout <<"Enter a phone number"<< std::endl;
        std::cin>> contact->number;
    } while (size(contact->number)!= 9);
    do {
    std::cout << "Enter email " << std::endl;
    std::cin>> contact->email;
    } while ( contact->email.find('@') == std::string::npos);
    std::cout<< "Enter an Address" <<std::endl;
    std::cin.ignore();
    std::getline(std::cin , contact->address);
}
void add(){
    Contact* contact = new Contact;
    init(contact);
    addressBook.push_back(contact);
    std::cout << "The contact is added" << std::endl;
}
void remove(){
    std::string name;
    std::cout << "Serach the element" <<std::endl;
    std::cin >> name;
    bool found = false;
    for (auto iter = addressBook.begin() ; iter != addressBook.end(); ++iter) {
        if ((*iter)->fname == name) {
            addressBook.erase(iter);
            found = true;
        }
    }
    if( found ) {
        std::cout << " All names with "<< name  <<"  was removed" << std::endl;
    } else {
        std::cout << "A name was not found" << std::endl;
    }
}
void edit(){
    std::string name;
    std::cout << "Serach the element" <<std::endl;
    std::cin >> name;
    bool found  = false;
    for(auto*& elem : addressBook) {
        if(elem->fname == name) {
                init(elem);
                found = true;
            }
        }
        if ( found) {
            std::cout << "The contact was changed" << std::endl;
        } else {
            std::cout <<"The contact was not found" << std::endl;
    }
}

void search(){
 
}    
void print(){
    std::cout << "_____________Address Book____________"<< std::endl;
    int i = 1;
    for (auto elem: addressBook) {
        std::cout << i << ". "<<elem->fname << "   " << elem->lname<< "    " << elem->address << "     " << elem->number << std::endl;
        ++i;
    }
    std::cout <<  "_____________  The End  ____________"<< std::endl;

}
