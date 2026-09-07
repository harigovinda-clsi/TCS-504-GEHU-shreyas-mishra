# Class Responsibilities and Boundaries

## Core Entity Classes

* **Movie**
  * **Responsibility:** Holds movie metadata (title, language, duration)[cite: 1].
  * **What it Knows:** Title, language, duration in minutes[cite: 1].
  * **What it Does:** Provides read-only getters for movie details.
  * **What it Must NOT Do:** Track showtimes, screens, or ticket availability[cite: 1].

* **Seat**
  * **Responsibility:** Represents one physical seat hardware specification[cite: 1].
  * **What it Knows:** Seat number and seat type (SILVER/GOLD/PLATINUM)[cite: 1].
  * **What it Does:** Exposes seat tier and identification number.
  * **What it Must NOT Do:** Track booking state across different show times[cite: 1].

* **Screen**
  * **Responsibility:** Represents one auditorium containing physical seats[cite: 1].
  * **What it Knows:** Screen number/name and its collection of physical Seats[cite: 1].
  * **What it Does:** Adds and exposes physical seat layout definitions.
  * **What it Must NOT Do:** Schedule show times or process customer bookings[cite: 1].

* **Cinema**
  * **Responsibility:** Represents the overall theatre complex[cite: 1].
  * **What it Knows:** Cinema name and collection of Screens[cite: 1].
  * **What it Does:** Adds and manages auditorium screens.
  * **What it Must NOT Do:** Handle customer payment transactions or seat locks[cite: 1].

* **Show**
  * **Responsibility:** Represents one movie screening on a specific screen at a given time[cite: 1].
  * **What it Knows:** Reference to Movie, reference to Screen, start time, and collection of ShowSeats[cite: 1].
  * **What it Does:** Manages its runtime seat grid and locates specific ShowSeat instances.
  * **What it Must NOT Do:** Calculate pricing logic or print formatted tickets[cite: 1].

* **ShowSeat**
  * **Responsibility:** Encapsulates the runtime status of ONE seat FOR ONE show[cite: 1].
  * **What it Knows:** Physical Seat reference and status (`AVAILABLE`/`BOOKED`)[cite: 1].
  * **What it Does:** Toggles availability state (`bookSeat()`, `releaseSeat()`).
  * **What it Must NOT Do:** Store customer data or process financial transactions[cite: 1].

* **Customer**
  * **Responsibility:** Holds customer contact metadata[cite: 1].
  * **What it Knows:** Name and phone number[cite: 1].
  * **What it Does:** Provides profile details for ticket generation.
  * **What it Must NOT Do:** Perform seat updates or process payment execution[cite: 1].

* **Booking**
  * **Responsibility:** Transaction record for an attempted or confirmed booking[cite: 1].
  * **What it Knows:** Unique booking ID, target Show, booked ShowSeats, total amount, and status[cite: 1].
  * **What it Does:** Stores transaction outcome and handles seat cancellation triggers.
  * **What it Must NOT Do:** Read console input or render UI elements directly[cite: 1].

## Behavior / Service Classes

* **Payment (Abstract)**
  * **Responsibility:** Interface contract for processing payments[cite: 1].
  * **What it Knows:** Interface specification (`virtual bool pay(double amount) = 0`)[cite: 1].
  * **What it Does:** Enforces polymorphic payment execution.
  * **What it Must NOT Do:** Maintain booking state or manipulate seat arrays[cite: 1].

* **UpiPayment / CardPayment / CashPayment**
  * **Responsibility:** Implements concrete payment behavior for a specific transaction channel[cite: 1].
  * **What it Knows:** Specific payment channel details.
  * **What it Does:** Executes channel-specific payment confirmation logic.
  * **What it Must NOT Do:** Alter seat inventory directly[cite: 1].

* **PriceCalculator**
  * **Responsibility:** Converts seat selections into total monetary amounts[cite: 1].
  * **What it Knows:** Price rates per seat tier (SILVER=150, GOLD=250, PLATINUM=400)[cite: 1].
  * **What it Does:** Computes total price for a vector of ShowSeat references.
  * **What it Must NOT Do:** Store booking history or process user payments[cite: 1].

* **TicketPrinter**
  * **Responsibility:** Formats and prints booking tickets to output streams[cite: 1].
  * **What it Knows:** Output formatting rules[cite: 1].
  * **What it Does:** Formats booking parameters into console output.
  * **What it Must NOT Do:** Modify system state, prices, or seat availability[cite: 1].

* **BookingService**
  * **Responsibility:** Orchestrates booking flow end-to-end[cite: 1].
  * **What it Knows:** Vector of active system Bookings[cite: 1].
  * **What it Does:** Coordinates seat availability checks, price evaluation, payment calls, and seat locking[cite: 1].
  * **What it Must NOT Do:** Maintain permanent database persistence.

* **CinemaMenu / main**
  * **Responsibility:** Handles console menu interface and user input parsing[cite: 1].
  * **What it Knows:** Cinema catalog and BookingService instance[cite: 1].
  * **What it Does:** Displays interactive prompt options and redirects commands.
  * **What it Must NOT Do:** Contain core domain business logic or bypass service validations[cite: 1].

## Domain Architectural Distinction: `ShowSeat` vs `Seat`
Physical chair `A1` exists once inside `Screen-1`[cite: 1]. However, its reservation status varies across scheduled shows[cite: 1]. `A1` may be `BOOKED` for the 6 PM show but `AVAILABLE` for the 9 PM show[cite: 1]. Therefore, reservation state belongs to `ShowSeat` (a show instance), preserving physical `Seat` definitions across multiple schedules[cite: 1].
