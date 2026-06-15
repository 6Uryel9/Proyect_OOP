#include "Customer.hpp"
#include "NintendoHandheld.hpp"
#include "RepairOrder.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    try {
        Customer cust1("Manuel", "442-325-2356");

        std::unique_ptr<Console> myDevice = std::make_unique<NintendoHandheld>("DSi-XL-90210", true, false);

        RepairOrder order("ORD-001", &cust1, std::move(myDevice), 1100);

        order.addRepairItem("Upper LCD Screen Replacement", 320, 1);
        order.addRepairItem("Data Transfer Cable & Sync", 200, 1);

        order.printReceipt();

        std::cout << "\nAttempting to add an invalid part...\n";
        order.addRepairItem("Free Promo Sticker", 0.00, 1); 

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}
