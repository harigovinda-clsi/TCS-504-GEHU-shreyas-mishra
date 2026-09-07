# Object Relationship Design and Lifetime Justifications

| Pair | Relationship Choice | Justification (Lifetime Test) |
| :--- | :--- | :--- |
| **Cinema - Screen** | Composition ($\blackdiamond$) | Screen belongs exclusively to Cinema[cite: 1]. Destroying Cinema destroys all its physical Screens[cite: 1]. |
| **Screen - Seat** | Composition ($\blackdiamond$) | Physical Seat exists within a specific Screen[cite: 1]. If Screen is destroyed, physical Seats cease to exist[cite: 1]. |
| **Show - Movie** | Aggregation ($\diamond$) | Show borrows a Movie[cite: 1]. Cancelling a Show leaves the Movie existing in the main catalog[cite: 1]. |
| **Show - Screen** | Aggregation ($\diamond$) | Show takes place in a Screen[cite: 1]. Removing a Show does not destroy the physical Screen auditorium[cite: 1]. |
| **Show - ShowSeat** | Composition ($\blackdiamond$) | ShowSeat tracks state for one specific show[cite: 1]. If the Show is removed, its ShowSeats are destroyed[cite: 1]. |
| **Booking - Customer** | Aggregation ($\diamond$) | Customer exists independently of a specific Booking transaction[cite: 1]. |
| **Booking - ShowSeat** | Aggregation ($\diamond$) | Booking references ShowSeats[cite: 1]. Cancelling or deleting a Booking does not delete the physical ShowSeats[cite: 1]. |
| **Booking - Payment** | Composition ($\blackdiamond$) | Payment instance is created exclusively for a Booking transaction[cite: 1]. Deleting the Booking record destroys its payment transaction object[cite: 1]. |
| **Payment - UpiPayment** | Inheritance ($\triangle$) | `UpiPayment` IS-A concrete payment strategy implementing the base `Payment` abstraction[cite: 1]. |
| **BookingService - Booking** | Aggregation ($\diamond$) | `BookingService` manages `Booking` instances, which persist as historical records[cite: 1]. |
