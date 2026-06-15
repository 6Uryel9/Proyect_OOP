#include "Customer.hpp"
#include "NintendoHandheld.hpp"
#include "RepairOrder.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    try {
        // 1. Aggregation Example: Customer lives independently in local scope
        Customer cust1("Manuel", "442-325-2356");

        // 2. Polymorphism & Smart Pointers: Create derived object via base unique_ptr
        std::unique_ptr<Console> myDevice = std::make_unique<NintendoHandheld>("DSi-XL-90210", true, false);

        // 3. RepairOrder takes exclusive ownership of the Console (moved), and observes Customer (reference)
        RepairOrder order("ORD-001", &cust1, std::move(myDevice), 1100);

        // 4. Add valid items to the vector (Composition)
        order.addRepairItem("Upper LCD Screen Replacement", 320, 1);
        order.addRepairItem("Data Transfer Cable & Sync", 200, 1);

        // 5. Print receipt utilizing overloaded operator<< and polymorphism
        order.printReceipt();

        // 6. Demonstrate Exception Handling / Invariant enforcement
        std::cout << "\nAttempting to add an invalid part...\n";
        order.addRepairItem("Free Promo Sticker", 0.00, 1); // Should throw invalid_argument

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}