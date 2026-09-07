#pragma once
#include <vector>
#include "06_ShowSeat.cpp"

// Single Responsibility Principle: Isolated pricing calculations
class PriceCalculator {
public:
    static constexpr double SILVER_PRICE = 150.0;
    static constexpr double GOLD_PRICE = 250.0;
    static constexpr double PLATINUM_PRICE = 400.0;

    static double getPrice(SeatType type) {
        switch (type) {
            case SeatType::SILVER: return SILVER_PRICE;
            case SeatType::GOLD: return GOLD_PRICE;
            case SeatType::PLATINUM: return PLATINUM_PRICE;
        }
        return 0.0;
    }

    static double calculateTotal(const std::vector<ShowSeat*>& seats) {
        double total = 0.0;
        for (const auto* ss : seats) {
            if (ss != nullptr) {
                total += getPrice(ss->getSeat().getType());
            }
        }
        return total;
    }
};
