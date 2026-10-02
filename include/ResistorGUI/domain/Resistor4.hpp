#ifndef RESISTORGUI_DOMAIN_RESISTOR4_HPP
#define RESISTORGUI_DOMAIN_RESISTOR4_HPP

#include "ResistorGUI/domain/MutableResistor.hpp"

class Resistor4 final : public MutableResistor
{
private:
    DigitResistorBand _band1;
    DigitResistorBand _band2;
    MultiplierResistorBand _band3;
    ToleranceResistorBand _band4;

public:
    Resistor4(
        DigitResistorBand band1,
        DigitResistorBand band2,
        MultiplierResistorBand band3,
        ToleranceResistorBand band4)
        : _band1(band1),
          _band2(band2),
          _band3(band3),
          _band4(band4) {
          };

    ResistorKind kind() const override
    {
        return ResistorKind::FourBands;
    }

    double resistance() const override
    {
        double value =
            resistor_color_value(this->_band1) * 10 +
            resistor_color_value(this->_band2);

        double multiplier = resistor_color_value(this->_band3);

        return value * multiplier;
    }

    double tolerance() const override
    {
        return resistor_color_value(this->_band4);
    }

    DigitResistorBand digitBand(unsigned int index) const override
    {
        switch (index)
        {
        case 0:
            return _band1;
        case 1:
            return _band2;
        default:
            throw std::invalid_argument(
                "Invalid index for digit band: " + std::to_string(index));
        }
    }

    MultiplierResistorBand multiplierBand() const override
    {
        return _band3;
    }

    ToleranceResistorBand toleranceBand() const override
    {
        return _band4;
    }

    unsigned int digitBandCount() const override
    {
        return 2;
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
        default:
            throw std::invalid_argument(
            "Invalid index for digit band: " + std::to_string(index));
        }
    }

    void setMultiplierBand(MultiplierResistorBand band) override
    {
        _band3 = band;
    }

    void setToleranceBand(ToleranceResistorBand band) override
    {
        _band4 = band;
    }

};

#endif
