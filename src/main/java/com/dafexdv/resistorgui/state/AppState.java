package com.dafexdv.resistorgui.state;

import com.dafexdv.resistorgui.domain.DigitResistorColor;
import com.dafexdv.resistorgui.domain.MultiplierResistorColor;
import com.dafexdv.resistorgui.domain.Resistor;
import com.dafexdv.resistorgui.domain.ToleranceResistorColor;

import java.util.ArrayList;
import java.util.List;

public final class AppState {

    private final List<AppStateListener> listeners = new ArrayList<>();

    private Resistor resistor;

    public AppState(Resistor resistor) {
        this.resistor = resistor;
    }

    public Resistor getResistor() {
        return resistor;
    }

    public void setResistor(Resistor resistor) {
        this.resistor = resistor;
        notifyListeners();
    }

    public void updateResistorBand1(DigitResistorColor band1) {
        resistor = resistor.withBand1(band1);
        notifyListeners();
    }

    public void updateResistorBand2(DigitResistorColor band2) {
        resistor = resistor.withBand2(band2);
        notifyListeners();
    }

    public void updateResistorBand3(MultiplierResistorColor band3) {
        resistor = resistor.withBand3(band3);
        notifyListeners();
    }

    public void updateResistorBand4(ToleranceResistorColor band4) {
        resistor = resistor.withBand4(band4);
        notifyListeners();
    }

    public void addListener(AppStateListener listener) {
        listeners.add(listener);
    }

    public void notifyListeners() {
        for (var listener : listeners) {
            listener.onStateChanged();
        }
    }

}
