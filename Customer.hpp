#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <string>

class Customer {
private:
    std::string name;
    std::string phoneNumber;
public:
    Customer(std::string n, std::string p) : name(n), phoneNumber(p) {}
    std::string getContactInfo() const { return name + " (" + phoneNumber + ")"; }
};
#endif