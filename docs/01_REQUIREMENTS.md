# Functional & Non-Functional Requirements

## Functional Requirements (FR)

* **FR1 - Movie Listing:** The system shall display all currently playing movies, showing their title, language, and duration in minutes.
* **FR2 - Show Selection:** Given a selected movie, the system shall list all scheduled shows, displaying the screen identifier and start time for each show.
* **FR3 - Seat Layout Display:** Given a selected show, the system shall render the seat layout organized by tier (SILVER, GOLD, PLATINUM) with the explicit status (`AVAILABLE` or `BOOKED`) for every seat.
* **FR4 - Booking:** A customer selects one or more seat numbers for a show. If any selected seat is already `BOOKED`, the whole booking is rejected and no seat changes state. Booking is confirmed only after payment succeeds.
* **FR5 - Pricing:** The system shall compute the total booking amount by seat types: SILVER = ₹150, GOLD = ₹250, PLATINUM = ₹400.
* **FR6 - Payment:** Exactly one method (UPI / Card / Cash) per booking. If payment fails, seats are released and booking status becomes `FAILED`.
* **FR7 - Ticket Printing:** Upon successful payment, the system shall display a ticket containing the unique Booking ID, Movie Title, Screen Name, Show Time, List of Booked Seats, Total Amount, and Status (`CONFIRMED`).
* **FR8 - Cancellation:** Given a valid Booking ID, the system shall update the booking status to `CANCELLED` and restore all associated seats to `AVAILABLE` status for that show.

## Non-Functional Requirements (NFR)

* **NFR1 - Modularity:** Each class must reside in its own dedicated source file with clear encapsulation.
* **NFR2 - Extensibility (Open/Closed):** Adding new payment methods (e.g., NetBanking) must require creating a derived class without modifying existing payment or orchestration logic.
* **NFR3 - Input Validation & Safety:** The system must gracefully handle invalid console inputs, out-of-range menu selections, and unavailable seat requests without crashing or altering state.
