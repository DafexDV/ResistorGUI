#include "ResistorGUI/domain/Resistor6.hpp"
#include "ResistorGUI/Utils.hpp"

std::string Resistor6::to_string() const
{
    std::string str;

    double resistance = this->resistance();
    double tolerance = this->tolerance();
    double temperatureCoefficient = this->temperatureCoefficient();

    return abbreviated_number(resistance) +
        "Ω" +
        "   " +
        "±" +
        compact_number(tolerance) +
        "   " +
        compact_number(temperatureCoefficient) +
        "ppm/K";
}
