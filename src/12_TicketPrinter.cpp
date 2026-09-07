#pragma once
#include <iostream>
#include <iomanip>
#include "08_Booking.cpp"

// Single Responsibility Principle: Ticket formatting and rendering view
class TicketPrinter {
public:
    static void printTicket(const Booking& booking) {
        std::cout << "\n================ TICKET ================\n";
        std::cout << "Booking ID: " << booking.getBookingId() << "\n";
        std::cout << "Movie     : " << booking.getShow()->getMovie()->getTitle() << "\n";
        std::cout << "Screen    : " << booking.getShow()->getScreen()->getScreenName() 
                  << " " << booking.getShow()->getStartTime() << "\n";
        std::cout << "Seats     : ";
        const auto& seats = booking.getBookedSeats();
        for (size_t i = 0; i < seats.size(); ++i) {
            std::cout << seats[i]->getSeat().getSeatNumber()
                      << (i + 1 < seats.size() ? ", " : "");
        }
        std::cout << "\nAmount    : Rs." << booking.getTotalAmount() << "\n";
        std::cout << "Status    : CONFIRMED\n";
        std::cout << "========================================\n\n";
    }
};
