# Proyect_OOP
# Final Project: Handheld Console Repair Manager

## What is this?
This is my final project for the Object-Oriented Programming course. It models a simple inventory and billing system for a repair shop that fixes handheld gaming consoles. I chose this problem because it naturally fits an OOP design hierarchy. The program tracks customer details, runs specific hardware diagnostics depending on the console type, and calculates the final repair bill based on parts and labor.

## How to build and run
To compile the project using the C++14 standard and enable all warnings, open your terminal in the project folder and run this exact command:

`g++ main.cpp -std=c++14 -Wall -o repair_manager`

Then, to execute the program, run:

* **Windows:** `.\repair_manager.exe`
* **Mac/Linux:** `./repair_manager`

## What to expect when running
The program is not interactive. Instead, the `main.cpp` file runs a pre-built scenario to exercise the entire design. 
First, it will print a formatted repair order receipt, which demonstrates polymorphic dispatch by printing the specific diagnostic message of a Nintendo device. Right after that, the program intentionally tries to add a replacement part with a $0.00 cost. This triggers a `std::invalid_argument` exception, which is safely caught and printed to the terminal to demonstrate exception handling.

## Design Rationale & Memory Management
For memory safety, I decided to follow the **Rule of Zero**. I didn't write any custom destructors or copy/move constructors for my business-logic classes. Instead, I delegated all memory management to RAII-compliant types like `std::string`, `std::vector`, and `std::unique_ptr`. This way, the compiler handles cleanups automatically and there are no memory leaks.

Here is how the class relationships and ownership work:
* **Smart Pointers & Heap Ownership:** I used a `std::unique_ptr<Console>` inside the `RepairOrder` class. This represents sole, exclusive ownership of the polymorphic base class. I passed the object using `std::move()`, completely avoiding raw `new` or `delete` calls.
* **Composition:** `RepairOrder` owns a `std::vector<RepairItem>`. This is strict composition because if the order goes out of scope and dies, the vector of parts is destroyed with it.
* **Aggregation:** For the `Customer`, the `RepairOrder` just holds a non-owning raw pointer (`const Customer*`). This is aggregation because the customer object was created in `main()`, lives independently, and outlives the transient repair order.
* **Inheritance & Polymorphism:** `Console` is an abstract base class with a pure virtual `diagnoseHardware()` method and a virtual destructor (to prevent object slicing). The `NintendoHandheld` class inherits from it and overrides the diagnostic method to return specific hardware details.
