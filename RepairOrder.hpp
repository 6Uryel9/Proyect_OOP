#ifndef REPAIRORDER_HPP
#define REPAIRORDER_HPP
#include "Customer.hpp"
#include "Console.hpp"
#include "RepairItem.hpp"
#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>

class RepairOrder {
private:
    std::string orderId;
    const Customer* customer;          // Aggregation: non-owning reference
    std::unique_ptr<Console> console;  // Composition: exclusive heap ownership
    std::vector<RepairItem> usedParts; // Composition: dynamic collection
    double laborCost;
public:
    RepairOrder(std::string id, const Customer* c, std::unique_ptr<Console> cons, double labor)
        : orderId(id), customer(c), console(std::move(cons)), laborCost(labor) {}
    
    void addRepairItem(std::string partName, double cost, int quantity) {
        // Enforcing a real invariant via exceptions
        if (cost <= 0) {
            throw std::invalid_argument("Part cost must be strictly positive.");
        }
        usedParts.push_back(RepairItem(partName, cost, quantity));
    }

    double calculateTotalCost() const noexcept {
        double total = laborCost;
        // Range-based loop used as requested (no <algorithm>)
        for (const auto& item : usedParts) { 
            total += item.calculateSubtotal();
        }
        return total;
    }

    void printReceipt() const {
        std::cout << "\n TICKET: " << orderId << " .\n";
        std::cout << "Customer: " << customer->getContactInfo() << "\n";
        
        // Polymorphic dispatch! Calls the specific override
        std::cout << "Device Diagnostic: " << console->diagnoseHardware() << "\n";
        std::cout << "Parts Used:\n";
        for (const auto& item : usedParts) {
            std::cout << "  - " << item << "\n"; // uses overloaded operator<<
        }
        std::cout << "Labor Cost: $" << laborCost << "\n";
        std::cout << "TOTAL: $" << calculateTotalCost() << "\n";
    }
};
#endif