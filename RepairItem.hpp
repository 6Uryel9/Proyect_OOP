#ifndef REPAIRITEM_HPP
#define REPAIRITEM_HPP
#include <string>
#include <iostream>

class RepairItem {
private:
    std::string partName;
    double cost;
    int quantity;
public:
    RepairItem(std::string name, double c, int q) : partName(name), cost(c), quantity(q) {}
    double calculateSubtotal() const noexcept { return cost * quantity; }
    
    friend std::ostream& operator<<(std::ostream& os, const RepairItem& item) {
        os << item.quantity << "x " << item.partName << " @ $" << item.cost << " = $" << item.calculateSubtotal();
        return os;
    }
};
#endif
