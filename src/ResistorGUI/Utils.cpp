#include "ResistorGUI/Utils.hpp"
#include <iomanip>
#include <sstream>

std::string abbreviated_number(double value)
{
    double divisor = 1;
    std::string suffix;

    const double absValue = std::abs(value);

    if (absValue >= 1'000'000'000)
    {
        divisor = 1'000'000'000;
        suffix = "B";
    }
    else if (absValue >= 1'000'000)
    {
        divisor = 1'000'000;
        suffix = "M";
    }
    else if (absValue >= 1'000)
    {
        divisor = 1'000;
        suffix = "K";
    }

    double newValue = value / divisor;

    return compact_number(newValue) + suffix;
}

std::string compact_number(double value)
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << value;

    std::string str = stream.str();

    while (!str.empty() && str.back() == '0')
        str.pop_back();
    
    if (!str.empty() && str.back() == '.')
        str.pop_back();

    return str;
}
