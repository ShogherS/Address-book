#ifndef CONTACT
#define CONTACT
#include <string>
class Contact 
{
    std::string _name;
    std::string _phone;
    std::string _email;

    public:
    Contact(const std::string& n, const std::string& p, const std::string& e) : _name{n}, _phone{ p }, _email{ e } {}
    Contact() = default;
    const std::string& getName() const { return _name;}
    const std::string& getPhone() const { return _phone; }
    const std::string& getEmail() const { return _email; }
    void setName( const std::string& name) { _name = name; }
    void setPhone( const std::string& phone) { _phone = phone; }
    void setEmail( const std::string& mail) { _email = mail; } 
    std::string  print() const {
        std::string info = "Name: " + _name + " Phone: " + _phone + " Email: " + _email;
        return info;
    }
};

#endif
