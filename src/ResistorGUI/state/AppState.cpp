#include "ResistorGUI/state/AppState.hpp"

#include <memory>
#include <qtmetamacros.h>
#include <stdexcept>
#include <functional>

inline const Resistor4 DEFAULT_RESISTOR4{
    DigitResistorBand::RED,
    DigitResistorBand::RED,
    MultiplierResistorBand::BROWN,
    ToleranceResistorBand::GOLDEN};

inline const Resistor5 DEFAULT_RESISTOR5{
    DigitResistorBand::RED,
    DigitResistorBand::RED,
    DigitResistorBand::BLACK,
    MultiplierResistorBand::BLACK,
    ToleranceResistorBand::GOLDEN};

inline const Resistor6 DEFAULT_RESISTOR6{
    DigitResistorBand::RED,
    DigitResistorBand::RED,
    DigitResistorBand::BLACK,
    MultiplierResistorBand::BLACK,
    ToleranceResistorBand::GOLDEN,
    TempCoResistorBand::VIOLET};

AppState::AppState(QObject *parent) : QObject(parent)
{
    _resistor4 = std::make_unique<Resistor4>(DEFAULT_RESISTOR4);
    _resistor5 = std::make_unique<Resistor5>(DEFAULT_RESISTOR5);
    _resistor6 = std::make_unique<Resistor6>(DEFAULT_RESISTOR6);
    _currentResistor = _resistor4.get();
}

template <typename Getter, typename Setter, typename T>
void AppState::updateCurrentResistorBand(Getter getter, Setter setter, T band)
{
    if (std::invoke(getter, _currentResistor) == band)
    {
        return;
    }

    std::invoke(setter, _currentResistor, band);

    emit currentResistorChanged();
    emit stateChanged();
}

void AppState::updateCurrentResistorDigitalBand(unsigned int index, DigitResistorBand band)
{
    auto existing = _currentResistor->digitBand(index);

    if (existing == band)
    {
        return;
    }

    _currentResistor->setDigitBand(index, band);

    emit currentResistorChanged();
    emit stateChanged();
}

void AppState::updateCurrentResistorMultiplierBand(MultiplierResistorBand band)
{
    updateCurrentResistorBand(
        &MutableResistor::multiplierBand,
        &MutableResistor::setMultiplierBand,
        band
    );
}

void AppState::updateCurrentResistorToleranceBand(ToleranceResistorBand band)
{
    updateCurrentResistorBand(
        &MutableResistor::toleranceBand,
        &MutableResistor::setToleranceBand,
        band
    );
}

void AppState::updateCurrentResistorTempCoBand(TempCoResistorBand band)
{
    updateCurrentResistorBand(
        &MutableResistor::tempCoBand,
        &MutableResistor::setTempCoBand,
        band
    );
}

void AppState::switchKind(ResistorKind newKind)
{
    if (currentResistorKind() == newKind)
    {
        return;
    }

    switch (newKind)
    {
    case ResistorKind::FourBands:
        _currentResistor = _resistor4.get();
        break;
    case ResistorKind::FiveBands:
        _currentResistor = _resistor5.get();
        break;
    case ResistorKind::SixBands:
        _currentResistor = _resistor6.get();
        break;
    default:
        throw std::invalid_argument(
            "Invalid resistor kind");
    }

    emit switchedKind();
    emit stateChanged();
}

void AppState::resetResistors()
{
    auto kind = currentResistorKind();

    _resistor4 = std::make_unique<Resistor4>(DEFAULT_RESISTOR4);
    _resistor5 = std::make_unique<Resistor5>(DEFAULT_RESISTOR5);
    _resistor6 = std::make_unique<Resistor6>(DEFAULT_RESISTOR6);

    switch (kind)
    {
    case ResistorKind::FourBands:
        _currentResistor = _resistor4.get();
        emit currentResistorChanged();
        emit stateChanged();
        break;
    case ResistorKind::FiveBands:
        _currentResistor = _resistor5.get();
        emit currentResistorChanged();
        emit stateChanged();
        break;
    case ResistorKind::SixBands:
        _currentResistor = _resistor6.get();
        emit currentResistorChanged();
        emit stateChanged();
        break;
    default:
        throw std::invalid_argument("Invalid resistor kind");
    }
}
