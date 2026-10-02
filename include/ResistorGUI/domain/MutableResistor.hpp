#ifndef RESISTORGUI_DOMAIN_MUTABLE_RESISTOR_HPP
#define RESISTORGUI_DOMAIN_MUTABLE_RESISTOR_HPP

#include "ResistorGUI/domain/Resistor.hpp"

class MutableResistor : public Resistor
{
public:

    virtual void setDigitBand(unsigned int index, DigitResistorBand band) = 0;

    virtual void setMultiplierBand(MultiplierResistorBand band) = 0;

    virtual void setToleranceBand(ToleranceResistorBand band) = 0;

    virtual void setTempCoBand(TempCoResistorBand band)
    {
        throw std::logic_error("Operation not supported");
    }
};

#endif