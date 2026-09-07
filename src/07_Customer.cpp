#pragma once
#include <string>

class Customer {
private:
    std::string name;
    std::string phone;

public:
    Customer(std::string name, std::string phone) : name(name), phone(phone) {}

    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
};
