#pragma once
#include <string>
#include <vector>
#include "02_Seat.cpp"

class Screen {
private:
    std::string screenName;
    std::vector<Seat> seats; // OOP Concept: Composition (Screen owns physical Seats)

public:
    explicit Screen(std::string screenName) : screenName(screenName) {}

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    std::string getScreenName() const { return screenName; }
    const std::vector<Seat>& getSeats() const { return seats; }
};
