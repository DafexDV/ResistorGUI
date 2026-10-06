#pragma once

#include <stdint.h>
#include <string>
#include <vector>

struct ResistorBandRgb
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

enum class DigitResistorBand
{
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GRAY,
    WHITE
};

inline const std::vector<DigitResistorBand> DIGIT_RESISTOR_BANDS{
    DigitResistorBand::BLACK,
    DigitResistorBand::BROWN,
    DigitResistorBand::RED,
    DigitResistorBand::ORANGE,
    DigitResistorBand::YELLOW,
    DigitResistorBand::GREEN,
    DigitResistorBand::BLUE,
    DigitResistorBand::VIOLET,
    DigitResistorBand::GRAY,
    DigitResistorBand::WHITE
};

double resistor_color_value(DigitResistorBand);
const ResistorBandRgb* resistor_color_rgb(DigitResistorBand);
std::string to_string(DigitResistorBand);

enum class MultiplierResistorBand
{
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GRAY,
    WHITE,
    GOLDEN,
    SILVER
};

inline const std::vector<MultiplierResistorBand> MULTIPLIER_RESISTOR_BANDS{
    MultiplierResistorBand::BLACK,
    MultiplierResistorBand::BROWN,
    MultiplierResistorBand::RED,
    MultiplierResistorBand::ORANGE,
    MultiplierResistorBand::YELLOW,
    MultiplierResistorBand::GREEN,
    MultiplierResistorBand::BLUE,
    MultiplierResistorBand::VIOLET,
    MultiplierResistorBand::GRAY,
    MultiplierResistorBand::WHITE,
    MultiplierResistorBand::GOLDEN,
    MultiplierResistorBand::SILVER
};

double resistor_color_value(MultiplierResistorBand);
const ResistorBandRgb* resistor_color_rgb(MultiplierResistorBand);
std::string to_string(MultiplierResistorBand);

enum class ToleranceResistorBand
{
    RED,
    ORANGE,
    GREEN,
    BLUE,
    VIOLET,
    GOLDEN,
    SILVER
};

inline const std::vector<ToleranceResistorBand> TOLERANCE_RESISTOR_BANDS{
    ToleranceResistorBand::RED,
    ToleranceResistorBand::ORANGE,
    ToleranceResistorBand::GREEN,
    ToleranceResistorBand::BLUE,
    ToleranceResistorBand::VIOLET,
    ToleranceResistorBand::GOLDEN,
    ToleranceResistorBand::SILVER
};

double resistor_color_value(ToleranceResistorBand);
const ResistorBandRgb* resistor_color_rgb(ToleranceResistorBand);
std::string to_string(ToleranceResistorBand);

enum class TempCoResistorBand
{
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GRAY
};

inline const std::vector<TempCoResistorBand> TEMP_CO_RESISTOR_BANDS{
    TempCoResistorBand::BLACK,
    TempCoResistorBand::BROWN,
    TempCoResistorBand::RED,
    TempCoResistorBand::ORANGE,
    TempCoResistorBand::YELLOW,
    TempCoResistorBand::GREEN,
    TempCoResistorBand::BLUE,
    TempCoResistorBand::VIOLET,
    TempCoResistorBand::GRAY
};

double resistor_color_value(TempCoResistorBand);
const ResistorBandRgb* resistor_color_rgb(TempCoResistorBand);
std::string to_string(TempCoResistorBand);
