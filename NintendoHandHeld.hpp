#ifndef NINTENDOHANDHELD_HPP
#define NINTENDOHANDHELD_HPP
#include "Console.hpp"

class NintendoHandheld : public Console {
private:
    bool hasStylus;
    bool modifiedScreens;
public:
    NintendoHandheld(std::string serial, bool stylus, bool moddedScreens) 
        : Console(serial, "Nintendo"), hasStylus(stylus), modifiedScreens(moddedScreens) {}
    
    std::string diagnoseHardware() const override final {
        std::string diag = "Diagnosing " + manufacturer + " handheld (SN: " + serialNumber + "). ";
        diag += hasStylus ? "Stylus present. " : "Stylus missing. ";
        diag += modifiedScreens ? "Custom IPS screens detected." : "Stock screens detected.";
        return diag;
    }
};
#endif