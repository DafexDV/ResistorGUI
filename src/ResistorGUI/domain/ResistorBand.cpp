#include "ResistorGUI/domain/ResistorBand.hpp"

#include "ResistorGUI/Utils.hpp"
#include <stdexcept>

static constexpr ResistorBandRgb BLACK{0, 0, 0};
static constexpr ResistorBandRgb BROWN{65, 25, 0};
static constexpr ResistorBandRgb RED{255, 0, 0};
static constexpr ResistorBandRgb ORANGE{255, 200, 0};
static constexpr ResistorBandRgb YELLOW{255, 255, 0};
static constexpr ResistorBandRgb GREEN{0, 255, 0};
static constexpr ResistorBandRgb BLUE{0, 0, 255};
static constexpr ResistorBandRgb VIOLET{128, 0, 255};
static constexpr ResistorBandRgb GRAY{128, 128, 128};
static constexpr ResistorBandRgb WHITE{255, 255, 255};
static constexpr ResistorBandRgb GOLDEN{212, 175, 55};
static constexpr ResistorBandRgb SILVER{192, 192, 192};

double resistor_color_value(DigitResistorBand value)
{
    switch (value)
    {
    case DigitResistorBand::BLACK:
        return 0;
    case DigitResistorBand::BROWN:
        return 1;
    case DigitResistorBand::RED:
        return 2;
    case DigitResistorBand::ORANGE:
        return 3;
    case DigitResistorBand::YELLOW:
        return 4;
    case DigitResistorBand::GREEN:
        return 5;
    case DigitResistorBand::BLUE:
        return 6;
    case DigitResistorBand::VIOLET:
        return 7;
    case DigitResistorBand::GRAY:
        return 8;
    case DigitResistorBand::WHITE:
        return 9;
    default:
        throw std::invalid_argument("Invalid DigitResistorColor");
    }
}

const ResistorBandRgb* resistor_color_rgb(DigitResistorBand value)
{
    switch (value)
    {
    case DigitResistorBand::BLACK:
        return &BLACK;
    case DigitResistorBand::BROWN:
        return &BROWN;
    case DigitResistorBand::RED:
        return &RED;
    case DigitResistorBand::ORANGE:
        return &ORANGE;
    case DigitResistorBand::YELLOW:
        return &YELLOW;
    case DigitResistorBand::GREEN:
        return &GREEN;
    case DigitResistorBand::BLUE:
        return &BLUE;
    case DigitResistorBand::VIOLET:
        return &VIOLET;
    case DigitResistorBand::GRAY:
        return &GRAY;
    case DigitResistorBand::WHITE:
        return &WHITE;
    default:
        throw std::invalid_argument("Invalid DigitResistorColor");
    }
}

std::string to_string(DigitResistorBand value)
{
    return compact_number(resistor_color_value(value));
}

double resistor_color_value(MultiplierResistorBand value)
{
    switch (value)
    {
    case MultiplierResistorBand::BLACK:
        return 1;
    case MultiplierResistorBand::BROWN:
        return 10;
    case MultiplierResistorBand::RED:
        return 100;
    case MultiplierResistorBand::ORANGE:
        return 1000;
    case MultiplierResistorBand::YELLOW:
        return 10000;
    case MultiplierResistorBand::GREEN:
        return 100'000;
    case MultiplierResistorBand::BLUE:
        return 1'000'000;
    case MultiplierResistorBand::VIOLET:
        return 10'000'000;
    case MultiplierResistorBand::GRAY:
        return 100'000'000;
    case MultiplierResistorBand::WHITE:
        return 1'000'000'000;
    case MultiplierResistorBand::GOLDEN:
        return 0.1;
    case MultiplierResistorBand::SILVER:
        return 0.01;
    default:
        throw std::invalid_argument("Invalid MultiplierResistorColor");
    }
}

const ResistorBandRgb* resistor_color_rgb(MultiplierResistorBand value)
{
    switch (value)
    {
    case MultiplierResistorBand::BLACK:
        return &BLACK;
    case MultiplierResistorBand::BROWN:
        return &BROWN;
    case MultiplierResistorBand::RED:
        return &RED;
    case MultiplierResistorBand::ORANGE:
        return &RED;
    case MultiplierResistorBand::YELLOW:
        return &YELLOW;
    case MultiplierResistorBand::GREEN:
        return &GREEN;
    case MultiplierResistorBand::BLUE:
        return &BLUE;
    case MultiplierResistorBand::VIOLET:
        return &VIOLET;
    case MultiplierResistorBand::GRAY:
        return &GRAY;
    case MultiplierResistorBand::WHITE:
        return &WHITE;
    case MultiplierResistorBand::GOLDEN:
        return &GOLDEN;
    case MultiplierResistorBand::SILVER:
        return &SILVER;
    default:
        throw std::invalid_argument("Invalid MultiplierResistorColor");
    }
}

std::string to_string(MultiplierResistorBand value)
{
    return "×" + abbreviated_number(resistor_color_value(value));
}

double resistor_color_value(ToleranceResistorBand value)
{
    switch (value)
    {
    case ToleranceResistorBand::RED:
        return 1;
    case ToleranceResistorBand::ORANGE:
        return 2;
    case ToleranceResistorBand::GREEN:
        return 0.5;
    case ToleranceResistorBand::BLUE:
        return 0.25;
    case ToleranceResistorBand::VIOLET:
        return 0.1;
    case ToleranceResistorBand::GOLDEN:
        return 5;
    case ToleranceResistorBand::SILVER:
        return 10;
    default:
        throw std::invalid_argument("Invalid ToleranceResistorColor");
    }
}

const ResistorBandRgb* resistor_color_rgb(ToleranceResistorBand value)
{
    switch (value)
    {
    case ToleranceResistorBand::RED:
        return &RED;
    case ToleranceResistorBand::ORANGE:
        return &ORANGE;
    case ToleranceResistorBand::GREEN:
        return &GREEN;
    case ToleranceResistorBand::BLUE:
        return &BLUE;
    case ToleranceResistorBand::VIOLET:
        return &VIOLET;
    case ToleranceResistorBand::GOLDEN:
        return &GOLDEN;
    case ToleranceResistorBand::SILVER:
        return &SILVER;
    default:
        throw std::invalid_argument("Invalid ToleranceResistorColor");
    }
}

std::string to_string(ToleranceResistorBand value)
{
    return "±" + compact_number(resistor_color_value(value));
}

double resistor_color_value(TempCoResistorBand value)
{
    switch (value)
    {
    case TempCoResistorBand::BLACK:
        return 250;
    case TempCoResistorBand::BROWN:
        return 100;
    case TempCoResistorBand::RED:
        return 50;
    case TempCoResistorBand::ORANGE:
        return 15;
    case TempCoResistorBand::YELLOW:
        return 25;
    case TempCoResistorBand::GREEN:
        return 20;
    case TempCoResistorBand::BLUE:
        return 10;
    case TempCoResistorBand::VIOLET:
        return 5;
    case TempCoResistorBand::GRAY:
        return 1;
    default:
        throw std::invalid_argument("Invalid TempCoResistorColor");
    }
}

const ResistorBandRgb* resistor_color_rgb(TempCoResistorBand value)
{
    switch (value)
    {
    case TempCoResistorBand::BLACK:
        return &BLACK;
    case TempCoResistorBand::BROWN:
        return &BROWN;
    case TempCoResistorBand::RED:
        return &RED;
    case TempCoResistorBand::ORANGE:
        return &ORANGE;
    case TempCoResistorBand::YELLOW:
        return &YELLOW;
    case TempCoResistorBand::GREEN:
        return &GREEN;
    case TempCoResistorBand::BLUE:
        return &BLUE;
    case TempCoResistorBand::VIOLET:
        return &VIOLET;
    case TempCoResistorBand::GRAY:
        return &GRAY;
    default:
        throw std::invalid_argument("Invalid TempCoResistorColor");
    }
}

std::string to_string(TempCoResistorBand value)
{
    return compact_number(resistor_color_value(value))
        + " "
        + "ppm/K";
}
