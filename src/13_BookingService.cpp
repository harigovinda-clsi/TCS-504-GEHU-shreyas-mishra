#pragma once
#include <iostream>
#include <vector>
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "11_PriceCalculator.cpp"

// System Orchestrator: Coordinates seat availability, payment, and transaction state
class BookingService {
private:
    std::vector<Booking> bookings;

public:
    Booking* createBooking(Customer customer, Show* show, std::vector<ShowSeat*> seats, Payment* payment) {
        // FR4 Validation: Reject whole booking if any selected seat is unavailable
        for (auto* ss : seats) {
            if (ss == nullptr || !ss->isAvailable()) {
                std::cout << "Error: One or more selected seats are already BOOKED!\n";
                return nullptr;
            }
        }

        double totalAmount = PriceCalculator::calculateTotal(seats);

        // Dependency Inversion Principle: Uses abstract Payment interface
        if (payment == nullptr || !payment->pay(totalAmount)) {
            std::cout << "Payment Failed! Seats released.\n";
            return nullptr; // FR6: Failed payment releases hold
        }

        // Atomic lock: Transition seats to BOOKED state only after payment succeeds
        for (auto* ss : seats) {
            ss->bookSeat();
        }

        bookings.emplace_back(customer, show, seats, totalAmount);
        return &bookings.back();
    }

    bool cancelBooking(const std::string& bookingId) {
        for (auto& b : bookings) {
            if (b.getBookingId() == bookingId && b.getStatus() == BookingStatus::CONFIRMED) {
                b.cancel(); // FR8: Restores seats to AVAILABLE
                std::cout << "Booking " << bookingId << " cancelled successfully.\n";
                return true;
            }
        }
        std::cout << "Invalid or already cancelled Booking ID.\n";
        return false;
    }

    Booking* findBooking(const std::string& id) {
        for (auto& b : bookings) {
            if (b.getBookingId() == id) return &b;
        }
        return nullptr;
    }
};
