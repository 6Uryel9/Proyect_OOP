#ifndef CONSOLE_HPP
#define CONSOLE_HPP
#include <string>

class Console {
protected:
    std::string serialNumber;
    std::string manufacturer;
public:
    Console(std::string serial, std::string maker) : serialNumber(serial), manufacturer(maker) {}
    
    // Virtual destructor guarantees correct destruction chain
    virtual ~Console() = default;
    
    // Pure virtual method makes this class Abstract
    virtual std::string diagnoseHardware() const = 0;
};
#endif