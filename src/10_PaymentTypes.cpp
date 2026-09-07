#pragma once
#include <iostream>
#include "09_Payment.cpp"

// OOP Concept: Inheritance & Runtime Polymorphism
class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "[UPI] Rs." << amount << " paid successfully\n";
        return true;
    }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "[CARD] Rs." << amount << " paid successfully\n";
        return true;
    }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "[CASH] Rs." << amount << " paid successfully\n";
        return true;
    }
};
