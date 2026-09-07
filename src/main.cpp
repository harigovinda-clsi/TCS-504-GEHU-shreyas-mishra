#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "10_PaymentTypes.cpp"
#include "12_TicketPrinter.cpp"
#include "13_BookingService.cpp"

void displaySeatLayout(Show* show) {
    std::cout << "\n" << show->getScreen()->getScreenName() << " " << show->getStartTime() << "\n";
    std::cout << show->getMovie()->getTitle() << "\n";

    auto printTier = [&](const std::string& name, SeatType type) {
        std::cout << std::left << std::setw(10) << name;
        for (const auto& ss : show->getShowSeats()) {
            if (ss.getSeat().getType() == type) {
                std::string statusStr = ss.isAvailable() ? "[]" : "[X]";
                std::cout << ss.getSeat().getSeatNumber() << statusStr << " ";
            }
        }
        std::cout << "\n";
    };

    printTier("SILVER", SeatType::SILVER);
    printTier("GOLD", SeatType::GOLD);
    printTier("PLATINUM", SeatType::PLATINUM);
    std::cout << "([] = available [X] = booked)\n\n";
}

int main() {
    // Domain Setup
    Movie m1("3 Idiots", "Hindi", 170);
    Movie m2("Interstellar", "English", 169);

    Screen sc1("Screen-1");
    sc1.addSeat(Seat("A1", SeatType::SILVER));
    sc1.addSeat(Seat("A2", SeatType::SILVER));
    sc1.addSeat(Seat("A3", SeatType::SILVER));
    sc1.addSeat(Seat("A4", SeatType::SILVER));
    sc1.addSeat(Seat("B1", SeatType::GOLD));
    sc1.addSeat(Seat("B2", SeatType::GOLD));
    sc1.addSeat(Seat("B3", SeatType::GOLD));
    sc1.addSeat(Seat("C1", SeatType::PLATINUM));
    sc1.addSeat(Seat("C2", SeatType::PLATINUM));

    Show show1("SH101", &m1, &sc1, "06:00 PM");

    // Pre-book initial seats for layout demonstration
    if (auto* seatA2 = show1.findShowSeat("A2")) seatA2->bookSeat();
    if (auto* seatB3 = show1.findShowSeat("B3")) seatB3->bookSeat();

    BookingService bookingService;
    Customer customer("John Doe", "9876543210");

    while (true) {
        std::cout << "===== MOVIE TICKET BOOKING =====\n";
        std::cout << "1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit\nChoose: ";
        int choice;
        if (!(std::cin >> choice) || choice == 0) break;

        if (choice == 1) {
            std::cout << "[1] " << m1.getTitle() << " (" << m1.getLanguage() << ", " << m1.getDuration() << " min)\n";
            std::cout << "[2] " << m2.getTitle() << " (" << m2.getLanguage() << ", " << m2.getDuration() << " min)\n";
        } else if (choice == 2) {
            std::cout << "Choose movie (1 for 3 Idiots): ";
            int mChoice; std::cin >> mChoice;
            if (mChoice != 1) { std::cout << "Invalid Choice!\n"; continue; }

            std::cout << "[1] Screen-1 06:00 PM\nChoose show: ";
            int sChoice; std::cin >> sChoice;

            displaySeatLayout(&show1);

            std::cout << "Enter seat count: ";
            int count; std::cin >> count;
            std::vector<ShowSeat*> selectedSeats;
            bool valid = true;

            for (int i = 0; i < count; ++i) {
                std::cout << "Enter seat code: ";
                std::string sCode; std::cin >> sCode;
                ShowSeat* ss = show1.findShowSeat(sCode);
                if (!ss || !ss->isAvailable()) {
                    std::cout << "Seat " << sCode << " unavailable or invalid!\n";
                    valid = false;
                    break;
                }
                selectedSeats.push_back(ss);
            }

            if (!valid) continue;

            double total = PriceCalculator::calculateTotal(selectedSeats);
            std::cout << "TOTAL: Rs." << total << "\n";
            std::cout << "Pay by: 1.UPI 2.Card 3.Cash > ";
            int pChoice; std::cin >> pChoice;

            std::unique_ptr<Payment> payment;
            if (pChoice == 1) payment = std::make_unique<UpiPayment>();
            else if (pChoice == 2) payment = std::make_unique<CardPayment>();
            else if (pChoice == 3) payment = std::make_unique<CashPayment>();

            Booking* b = bookingService.createBooking(customer, &show1, selectedSeats, payment.get());
            if (b) {
                TicketPrinter::printTicket(*b);
            }
        } else if (choice == 3) {
            std::cout << "Enter Booking ID to cancel: ";
            std::string bId; std::cin >> bId;
            bookingService.cancelBooking(bId);
        } else if (choice == 4) {
            std::cout << "Enter Booking ID: ";
            std::string bId; std::cin >> bId;
            Booking* b = bookingService.findBooking(bId);
            if (b && b->getStatus() == BookingStatus::CONFIRMED) {
                TicketPrinter::printTicket(*b);
            } else {
                std::cout << "No active booking found.\n";
            }
        }
    }
    return 0;
}
