struct Contact{
    std::string fname;
    std::string lname;
    std::string address;
    std::string number;
    std::string email;
};

std::vector<Contact*> addressBook;
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
      std::cout << "Serach the element" <<std::endl;
     std::cin >> name;
     bool found  = false;
     for(auto*& elem : addressBook) {
         if(elem->fname == name) {
                 found = true;
             }
         }
         if ( found) {
              std::cout << "The contact was found" << std::endl;
          } else {
              std::cout <<"The contact was not found" << std::endl;
      }
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
