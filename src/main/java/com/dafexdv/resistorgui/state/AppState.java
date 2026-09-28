package com.dafexdv.resistorgui.state;

import com.dafexdv.resistorgui.domain.DigitResistorColor;
import com.dafexdv.resistorgui.domain.MultiplierResistorColor;
import com.dafexdv.resistorgui.domain.Resistor;
import com.dafexdv.resistorgui.domain.ToleranceResistorColor;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.ArrayList;
import java.util.List;

public final class AppState {

    private static final Logger LOGGER = LogManager.getLogger(AppState.class);

    public static final Resistor DEFAULT_RESISTOR = Resistor.of(
            DigitResistorColor.RED,
            DigitResistorColor.RED,
            MultiplierResistorColor.BROWN,
            ToleranceResistorColor.GOLDEN
    );

    private final List<AppStateListener> listeners = new ArrayList<>();

    private Resistor resistor;

    public AppState(Resistor resistor) {
        this.resistor = resistor;
        LOGGER.debug("AppState initialized with resistor: {}", resistor);
    }

    public AppState() {
        this(DEFAULT_RESISTOR);
    }

    public Resistor getResistor() {
        return resistor;
    }

    public void updateResistorBand1(DigitResistorColor band1) {
        if (resistor.band1() == band1) {
            return;
        }

        LOGGER.debug("Updating resistor band 1: {} -> {}", this.resistor.band1(), band1);

        resistor = resistor.withBand1(band1);
        notifyListeners();
    }

    public void updateResistorBand2(DigitResistorColor band2) {
        if (resistor.band2() == band2) {
            return;
        }

        LOGGER.debug("Updating resistor band 2: {} -> {}", this.resistor.band2(), band2);

        resistor = resistor.withBand2(band2);
        notifyListeners();
    }

    public void updateResistorBand3(MultiplierResistorColor band3) {
        if (resistor.band3() == band3) {
            return;
        }

        LOGGER.debug("Updating resistor band 3: {} -> {}", this.resistor.band3(), band3);

        resistor = resistor.withBand3(band3);
        notifyListeners();
    }

    public void updateResistorBand4(ToleranceResistorColor band4) {
        if (resistor.band4() == band4) {
            return;
        }

        LOGGER.debug("Updating resistor band 4: {} -> {}", this.resistor.band4(), band4);

        resistor = resistor.withBand4(band4);
        notifyListeners();
    }

    public void resetResistor() {
        LOGGER.debug("Resetting resistor: {} -> {}", this.resistor, DEFAULT_RESISTOR);

        resistor = DEFAULT_RESISTOR;
        notifyListeners();
    }

    public void addListener(AppStateListener listener) {
        listeners.add(listener);
        LOGGER.debug("Listener added: {}", listener);
    }

    public void notifyListeners() {
        LOGGER.trace("Notifying {} state listeners", listeners.size());

        for (var listener : listeners) {
            listener.onStateChanged();
        }
    }

}
