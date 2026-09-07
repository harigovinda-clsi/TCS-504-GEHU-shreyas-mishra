# SOLID Architectural Mapping

## Applied Principles

* **Single Responsibility Principle (SRP):**
  * `PriceCalculator` strictly handles price calculation rules[cite: 1].
  * `TicketPrinter` strictly handles string formatting and console display[cite: 1].
  * `Booking` records transaction state without performing input reading or console rendering[cite: 1].

* **Open/Closed Principle (OCP):**
  * Adding a new payment method (e.g., `NetBankingPayment`) requires creating a derived class from `Payment` without modifying existing code in `BookingService` or `Booking`[cite: 1].

* **Dependency Inversion Principle (DIP):**
  * `BookingService` depends on the high-level `Payment` abstraction rather than instantiating concrete classes like `CardPayment` internally[cite: 1].

## Architectural Trade-off Choice
* **Deliberately Excluded Feature:** Persistent Database / Disk File Storage[cite: 1].
* **Justification:** To focus strictly on core Object-Oriented System Design, runtime memory lifecycle management, and clean dependency decoupling without introducing external I/O file handles or external library dependencies[cite: 1].
