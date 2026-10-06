#include "ResistorGUI/state/AppState.hpp"

#include <QDebug>
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
void AppState::updateCurrentResistorBand(Getter getter, Setter setter, std::string bandTypeName, T band)
{
	auto existing = std::invoke(getter, _currentResistor);

    if (existing == band)
    {
        return;
    }

    std::invoke(setter, _currentResistor, band);

    qInfo().noquote()
        << "Updated current resistor "
        << bandTypeName
        << " band: "
	    << to_string(existing)
        << " -> "
        << to_string(band);

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

    qInfo().noquote()
        << "Updated current resistor digit band #"
        << QString::number(index)
        << ": "
	    << to_string(band)
        << " -> "
        << to_string(band);

    emit currentResistorChanged();
    emit stateChanged();
}

void AppState::updateCurrentResistorMultiplierBand(MultiplierResistorBand band)
{
    updateCurrentResistorBand(
        &Resistor::multiplierBand,
        &Resistor::setMultiplierBand,
        "multiplier",
        band
    );
}

void AppState::updateCurrentResistorToleranceBand(ToleranceResistorBand band)
{
    updateCurrentResistorBand(
        &Resistor::toleranceBand,
        &Resistor::setToleranceBand,
        "tolerance",
        band
    );
}

void AppState::updateCurrentResistorTempCoBand(TempCoResistorBand band)
{
    updateCurrentResistorBand(
        &Resistor::tempCoBand,
        &Resistor::setTempCoBand,
        "temperature coefficient",
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
    default:http://www.gnu.org/licenses/gpl-3.0.html
        throw std::invalid_argument(
            "Invalid resistor kind");
    }

    qInfo()
        << "Switched kind to "
        << to_string(newKind);

    emit switchedKind();
    emit stateChanged();
}

void AppState::resetResistors()
{
    auto kind = currentResistorKind();

    *_resistor4 = DEFAULT_RESISTOR4;
    *_resistor5 = DEFAULT_RESISTOR5;
    *_resistor6 = DEFAULT_RESISTOR6;

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

    qInfo()
        << "Resistors reset";
}
