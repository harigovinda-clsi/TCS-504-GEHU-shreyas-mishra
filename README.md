```markdown
# Movie Ticket Booking System — Terminal Simulation & Architecture

An object-oriented C++17 console application simulating an end-to-end movie ticket reservation platform. Built for **TCS-504: Object-Oriented Programming**, this system models real-world cinema operations including dynamic seat state management, multi-tier pricing, polymorphic payment handling, ticket generation, and transaction rollbacks.

---

## 🚀 Quickstart & Compilation

Compile all source modules directly using any C++17 compatible compiler:

```bash
# Build executable
g++ -std=c++17 src/*.cpp -o cinema_booking

# Run interactive simulation
./cinema_booking

```

---

## 📂 Repository Structure

```text
.
├── README.md
├── LICENSE
├── docs/
│   ├── 01_REQUIREMENTS.md
│   ├── 02_NOUN_VERB_ANALYSIS.md
│   ├── 03_CLASS_DESIGN.md
│   ├── 04_RELATIONSHIPS.md
│   ├── 05_SOLID_PRINCIPLES.md
│   └── diagrams/
│       ├── class_diagram.mmd
│       └── sequence_diagram.mmd
└── src/
    ├── 01_Movie.cpp
    ├── 02_Seat.cpp
    ├── 03_Screen.cpp
    ├── 04_Cinema.cpp
    ├── 05_Show.cpp
    ├── 06_ShowSeat.cpp
    ├── 07_Customer.cpp
    ├── 08_Booking.cpp
    ├── 09_Payment.cpp
    ├── 10_PaymentTypes.cpp
    ├── 11_PriceCalculator.cpp
    ├── 12_TicketPrinter.cpp
    ├── 13_BookingService.cpp
    └── main.cpp

```

---

## 💻 Simulation Trace & Walkthrough

Below is a complete execution log generated during system runtime, demonstrating state transitions across operations.

### Scenario 1: Initial Menu & Seat Availability Grid

Upon selecting a show, the system queries the target `Show` instance and renders current seat availability by tier (`[]` = Available, `[X]` = Booked).

```text
===== MOVIE TICKET BOOKING =====
1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit
Choose: 2
Choose movie (1 for 3 Idiots): 1
[1] Screen-1 06:00 PM
Choose show: 1

Screen-1 06:00 PM
3 Idiots
SILVER    A1[] A2[X] A3[] A4[] 
GOLD      B1[] B2[] B3[X] 
PLATINUM  C1[] C2[] 
([] = available [X] = booked)

```

---

### Scenario 2: Successful Multi-Seat Booking (UPI Payment)

The user selects seats `A1` (Silver, ₹150) and `C1` (Platinum, ₹400). The system computes the aggregate price, executes the payment strategy, locks the seats, and outputs a formatted ticket.

```text
Enter seat count: 2
Enter seat code: A1
Enter seat code: C1
TOTAL: Rs.550
Pay by: 1.UPI 2.Card 3.Cash > 1
[UPI] Rs.550 paid successfully

================ TICKET ================
Booking ID: BK1001
Movie     : 3 Idiots
Screen    : Screen-1 06:00 PM
Seats     : A1, C1
Amount    : Rs.550
Status    : CONFIRMED
========================================

```

---

### Scenario 3: Real-Time Seat Lock Verification

Re-inspecting the seat layout confirms that `A1` and `C1` have dynamically updated from `[]` to `[X]`.

```text
Screen-1 06:00 PM
3 Idiots
SILVER    A1[X] A2[X] A3[] A4[] 
GOLD      B1[] B2[] B3[X] 
PLATINUM  C1[X] C2[] 
([] = available [X] = booked)

```

---

### Scenario 4: Concurrency / Double-Booking Prevention (FR4)

Attempting to reserve an already booked seat (`A1`) immediately halts transaction execution without modifying state.

```text
Enter seat count: 1
Enter seat code: A1
Seat A1 unavailable or invalid!

```

---

### Scenario 5: Booking Cancellation & Automatic Seat Release (FR8)

Cancelling `BK1001` restores `A1` and `C1` to `AVAILABLE` status for that specific show.

```text
Choose: 3
Enter Booking ID to cancel: BK1001
Booking BK1001 cancelled successfully.

# Layout post-cancellation:
SILVER    A1[] A2[X] A3[] A4[] 
GOLD      B1[] B2[] B3[X] 
PLATINUM  C1[] C2[] 

```

---

## 🛠️ Architecture & SOLID Mapping

| SOLID Principle | Implementation Detail | Location |
| --- | --- | --- |
| **Single Responsibility (SRP)** | Isolated pricing logic (`PriceCalculator`) and ticket layout rendering (`TicketPrinter`) from data objects. | `src/11_PriceCalculator.cpp`<br>

<br>`src/12_TicketPrinter.cpp` |
| **Open/Closed (OCP)** | New payment channels (e.g., NetBanking, Crypto) can be added by extending `Payment` without modifying `BookingService`. | `src/09_Payment.cpp`<br>

<br>`src/10_PaymentTypes.cpp` |
| **Liskov Substitution (LSP)** | Derived payment classes (`UpiPayment`, `CardPayment`) seamlessly fulfill the base `Payment` contract at runtime. | `src/10_PaymentTypes.cpp` |
| **Interface Segregation (ISP)** | Public interfaces remain minimal and tightly scoped to individual domain entity needs. | `src/01_Movie.cpp` - `src/08_Booking.cpp` |
| **Dependency Inversion (DIP)** | High-level `BookingService` interacts exclusively with the abstract `Payment` interface, not concrete types. | `src/13_BookingService.cpp` |

---

## 📋 Requirements Coverage Matrix

* **FR1 (Movie Listing):** Implemented in `Movie` class & displayed via CLI option 1.
* **FR2 (Show Selection):** Filtered via `Show` and `Screen` aggregation mapping.
* **FR3 (Seat Layout):** Rendered dynamically in 3 tiers via `displaySeatLayout()`.
* **FR4 (Atomic Booking):** Enforced by `BookingService::createBooking()`.
* **FR5 (Tiered Pricing):** Calculated via static pricing matrix in `PriceCalculator`.
* **FR6 (Payment Processing):** Polymorphic method execution returning transaction status.
* **FR7 (Ticket Generation):** Formatted summary display via `TicketPrinter`.
* **FR8 (Cancellation Handling):** Triggered by `Booking::cancel()`, unsetting runtime seat locks.

```

```
