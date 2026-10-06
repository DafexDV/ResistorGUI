#pragma once

#include <QObject>
#include <memory>
#include "ResistorGUI/domain/Resistor.hpp"
#include "ResistorGUI/domain/Resistor4.hpp"
#include "ResistorGUI/domain/Resistor5.hpp"
#include "ResistorGUI/domain/Resistor6.hpp"

class AppState final : public QObject
{
    Q_OBJECT

public:
    explicit AppState(QObject *parent = nullptr);

    const Resistor& currentResistor() const
    {
        return *_currentResistor;
    }

    const ResistorKind currentResistorKind() const
    {
        return _currentResistor->kind();
    }

    void updateCurrentResistorDigitalBand(unsigned int index, DigitResistorBand band);

    void updateCurrentResistorMultiplierBand(MultiplierResistorBand band);

    void updateCurrentResistorToleranceBand(ToleranceResistorBand band);

    void updateCurrentResistorTempCoBand(TempCoResistorBand band);

    void switchKind(ResistorKind newKind);

    void resetResistors();

signals:
    void stateChanged();
    void switchedKind();
    void currentResistorChanged();

private:
    std::unique_ptr<Resistor4> _resistor4;
    std::unique_ptr<Resistor5> _resistor5;
    std::unique_ptr<Resistor6> _resistor6;
    Resistor* _currentResistor;

    template <typename Getter, typename Setter, typename T>
    void updateCurrentResistorBand(Getter getter, Setter setter, T band);
};
