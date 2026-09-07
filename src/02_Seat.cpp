#pragma once
#include <string>

enum class SeatType { SILVER, GOLD, PLATINUM };
enum class SeatStatus { AVAILABLE, BOOKED };
enum class BookingStatus { CONFIRMED, FAILED, CANCELLED };

// OOP Concept: Encapsulation (Physical seat specifications)
class Seat {
private:
    std::string seatNumber;
    SeatType type;

public:
    Seat(std::string seatNumber, SeatType type)
        : seatNumber(seatNumber), type(type) {}

    std::string getSeatNumber() const { return seatNumber; }
    SeatType getType() const { return type; }
};
