# Problem Proposal: Handheld Console Repair Manager

## The Problem and Domain
Managing hardware repairs in a technical shop requires tracking diverse incoming devices, customer details, and replacement parts.
The domain involves different types of hardware that require distinct diagnostic approaches. 

## Why it needs OOP
Object-Oriented Programming is essential here to model the natural hierarchy of hardware.
Using runtime polymorphism allows the system to process a queue of diverse devices uniformly without type-switching. 
Encapsulation ensures that repair costs and stock quantities cannot be illegally manipulated , maintaining system invariants.

## Draft Class List & Concept Mapping
1. **Console (Abstract Base):** Demonstrates runtime polymorphism, pure virtual methods, and virtual destructors.
2. **NintendoHandheld (Derived):** Demonstrates inheritance, constructor chaining, and `override`/`final`.
3. **Customer:** Demonstrates encapsulation and RAII .
4. **RepairItem:** Demonstrates operator overloading and value semantics.
5. **RepairOrder:** Demonstrates composition, exclusive heap ownership via `std::unique_ptr<Console>`, the **Rule of Zero**, and exception handling .
