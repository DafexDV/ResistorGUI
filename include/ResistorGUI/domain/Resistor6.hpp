#pragma once

#include "ResistorGUI/domain/Resistor.hpp"

class Resistor6 final : public Resistor
{
private:
    DigitResistorBand _band1;
    DigitResistorBand _band2;
    DigitResistorBand _band3;
    MultiplierResistorBand _band4;
    ToleranceResistorBand _band5;
    TempCoResistorBand _band6;

public:
    Resistor6(
        DigitResistorBand band1,
        DigitResistorBand band2,
        DigitResistorBand band3,
        MultiplierResistorBand band4,
        ToleranceResistorBand band5,
        TempCoResistorBand band6)
        : _band1(band1),
          _band2(band2),
          _band3(band3),
          _band4(band4),
          _band5(band5),
         _band6(band6) {
          };

    ResistorKind kind() const override
    {
        return ResistorKind::SixBands;
    }

    double resistance() const override
    {
        double value =
            resistor_color_value(this->_band1) * 100 +
            resistor_color_value(this->_band2) * 10 +
            resistor_color_value(this->_band3);

        double multiplier = resistor_color_value(this->_band4);

        return value * multiplier;
    }

    double tolerance() const override
    {
        return resistor_color_value(this->_band5);
    }

    double temperatureCoefficient() const override
    {
        return resistor_color_value(this->_band6);
    }

    DigitResistorBand digitBand(unsigned int index) const override
    {
        switch (index)
        {
        case 0:
            return _band1;
        case 1:
            return _band2;
        case 2:
            return _band3;
        default:
            throw std::invalid_argument(
                "Invalid digital index: " + std::to_string(index));
        }
    }

    MultiplierResistorBand multiplierBand() const override
    {
        return _band4;
    }

    ToleranceResistorBand toleranceBand() const override
    {
        return _band5;
    }

    TempCoResistorBand tempCoBand() const override
    {
        return _band6;
    }

    unsigned int digitBandCount() const override
    {
        return 3;
    }

    void setDigitBand(unsigned int index, DigitResistorBand band) override
    {
        switch (index)
        {
        case 0:
            _band1 = band;
            break;
        case 1:
            _band2 = band;
            break;
        case 2:
            _band3 = band;
            break;
        default:
            throw std::invalid_argument(
                "Invalid index for digit band: " + std::to_string(index));
        }
    }

    void setMultiplierBand(MultiplierResistorBand band) override
    {
        _band4 = band;
    }

    void setToleranceBand(ToleranceResistorBand band) override
    {
        _band5 = band;
    }

    void setTempCoBand(TempCoResistorBand band) override
    {
        _band6 = band;
    }

    std::string to_string() const override;
};
