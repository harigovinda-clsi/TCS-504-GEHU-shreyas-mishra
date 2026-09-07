#pragma once
#include <string>
#include <vector>
#include "05_Show.cpp"
#include "07_Customer.cpp"

class Booking {
private:
    static int nextBookingId; // OOP Concept: Static Member (Unique ID sequence across instances)
    std::string bookingId;
    Customer customer;        // OOP Concept: Aggregation (Customer details)
    Show* show;              // OOP Concept: Aggregation (Points to Show)
    std::vector<ShowSeat*> bookedSeats; // OOP Concept: Aggregation (References seats)
    double totalAmount;
    BookingStatus status;

public:
    Booking(Customer customer, Show* show, std::vector<ShowSeat*> seats, double amount)
        : customer(customer), show(show), bookedSeats(seats), totalAmount(amount), status(BookingStatus::CONFIRMED) {
        // OOP Concept: 'this' Keyword & Static Variable Mutation
        this->bookingId = "BK" + std::to_string(nextBookingId++);
    }

    std::string getBookingId() const { return bookingId; }
    Show* getShow() const { return show; }
    const std::vector<ShowSeat*>& getBookedSeats() const { return bookedSeats; }
    double getTotalAmount() const { return totalAmount; }
    BookingStatus getStatus() const { return status; }

    void cancel() {
        this->status = BookingStatus::CANCELLED;
        for (auto* ss : bookedSeats) {
            if (ss != nullptr) {
                ss->releaseSeat();
            }
        }
    }
};

// C++17 inline static variable definition
inline int Booking::nextBookingId = 1001;
