#pragma once
#include "02_Seat.cpp"

// Encapsulates seat state FOR A SPECIFIC SHOW instance
class ShowSeat {
private:
    Seat seat;
    SeatStatus status;

public:
    explicit ShowSeat(Seat seat) : seat(seat), status(SeatStatus::AVAILABLE) {}

    bool isAvailable() const { return status == SeatStatus::AVAILABLE; }

    void bookSeat() { status = SeatStatus::BOOKED; }
    void releaseSeat() { status = SeatStatus::AVAILABLE; }

    Seat getSeat() const { return seat; }
    SeatStatus getStatus() const { return status; }
};
