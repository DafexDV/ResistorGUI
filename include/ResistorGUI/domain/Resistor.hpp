#ifndef RESISTORGUI_DOMAIN_RESISTOR_HPP
#define RESISTORGUI_DOMAIN_RESISTOR_HPP

#include <memory>
#include <stdexcept>
#include "ResistorGUI/domain/ResistorBand.hpp"
#include "ResistorGUI/domain/ResistorKind.hpp"

class Resistor
{
public:
    virtual ~Resistor() = default;

    virtual ResistorKind kind() const = 0;

    virtual double resistance() const = 0;

    virtual double tolerance() const = 0;

    virtual DigitResistorBand digitBand(unsigned int index) const = 0;
    virtual MultiplierResistorBand multiplierBand() const = 0;
    virtual ToleranceResistorBand toleranceBand() const = 0;

    virtual TempCoResistorBand tempCoBand() const
    {
        throw std::logic_error("Operation not supported");
    }

    virtual unsigned int digitBandCount() const = 0;

    virtual std::string to_string() const;
};

#endif
