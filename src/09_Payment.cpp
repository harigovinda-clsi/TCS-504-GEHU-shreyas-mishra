#pragma once

// OOP Concept: Abstraction (Abstract Base Class enforcing payment contract)
class Payment {
public:
    virtual ~Payment() = default;
    
    // Pure virtual method for runtime polymorphism
    virtual bool pay(double amount) = 0;
};
