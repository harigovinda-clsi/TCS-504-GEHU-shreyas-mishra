# Noun-Verb Analysis Table

| Noun/Verb Found | Keep as Class/Method? | Justification |
| :--- | :--- | :--- |
| **Movie** | Class | Domain entity with independent identity, title, language, and duration[cite: 1]. |
| **Seat** | Class | Domain entity representing a physical chair template (number, tier)[cite: 1]. |
| **Seat layout** | Rejected (View/Method) | It is a dynamic presentation of a Show's seats, not a distinct domain object[cite: 1]. |
| **Screen** | Class | Physical auditorium owning physical seats[cite: 1]. |
| **Cinema** | Class | Theatre entity managing physical screens[cite: 1]. |
| **Show** | Class | Links a Movie to a Screen at a specific start time slot[cite: 1]. |
| **ShowSeat** | Class | Manages seat status (`AVAILABLE`/`BOOKED`) for a specific Show instance[cite: 1]. |
| **Customer** | Class | Represents the person placing the booking (name, phone)[cite: 1]. |
| **Booking** | Class | Transaction record holding booking ID, seats, total amount, and status[cite: 1]. |
| **Payment** | Abstract Class | Base abstraction defining the payment contract (`pay()`)[cite: 1]. |
| **UpiPayment / CardPayment / CashPayment** | Derived Classes | Concrete payment implementations executing specific method logic[cite: 1]. |
| **PriceCalculator** | Service Class | Pure calculation engine converting seat lists into pricing totals[cite: 1]. |
| **TicketPrinter** | Service Class | Formatting and console rendering output logic for tickets[cite: 1]. |
| **BookingService** | Orchestrator Class | Runs the booking execution flow end-to-end[cite: 1]. |
| **Price** | Rejected (Attribute) | Numeric property inside `Seat` and `Booking`, not a class[cite: 1]. |
| **Book / Pay / Cancel** | Methods | Core operational verbs mapped as functions inside service/orchestration classes[cite: 1]. |
