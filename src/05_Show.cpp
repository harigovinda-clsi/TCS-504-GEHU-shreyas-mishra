#pragma once
#include <string>
#include <vector>
#include "01_Movie.cpp"
#include "03_Screen.cpp"
#include "06_ShowSeat.cpp"

class Show {
private:
    std::string showId;
    const Movie* movie;   // OOP Concept: Aggregation (Show borrows Movie)
    const Screen* screen; // OOP Concept: Aggregation (Show borrows Screen)
    std::string startTime;
    std::vector<ShowSeat> showSeats; // OOP Concept: Composition (Show owns ShowSeats)

public:
    Show(std::string showId, const Movie* movie, const Screen* screen, std::string startTime)
        : showId(showId), movie(movie), screen(screen), startTime(startTime) {
        
        // Instantiate runtime seat status from physical screen template
        if (screen != nullptr) {
            for (const auto& seat : screen->getSeats()) {
                showSeats.emplace_back(seat);
            }
        }
    }

    std::string getShowId() const { return showId; }
    const Movie* getMovie() const { return movie; }
    const Screen* getScreen() const { return screen; }
    std::string getStartTime() const { return startTime; }
    std::vector<ShowSeat>& getShowSeats() { return showSeats; }

    ShowSeat* findShowSeat(const std::string& seatNo) {
        for (auto& ss : showSeats) {
            if (ss.getSeat().getSeatNumber() == seatNo) {
                return &ss;
            }
        }
        return nullptr;
    }
};
