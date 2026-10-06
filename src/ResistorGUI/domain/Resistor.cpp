#include "ResistorGUI/domain/Resistor.hpp"
#include "ResistorGUI/Utils.hpp"

std::string Resistor::to_string() const
{
    std::string str;

    double resistance = this->resistance();
    double tolerance = this->tolerance();

    return abbreviated_number(resistance) +
        "Ω" +
        "   " +
        "±" +
        compact_number(tolerance);
}
