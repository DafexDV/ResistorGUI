package com.dafexdv.resistorgui.domain;

import java.text.NumberFormat;
import java.util.Locale;
import java.util.Objects;

public final class Resistor {

    private static final NumberFormat NUMBER_FORMAT = NumberFormat.getCompactNumberInstance(Locale.getDefault(), NumberFormat.Style.SHORT);

    static  {
        NUMBER_FORMAT.setMaximumFractionDigits(1);
    }

    private final DigitResistorColor band1;
    private final DigitResistorColor band2;
    private final MultiplierResistorColor band3;
    private final ToleranceResistorColor band4;

    private Resistor(DigitResistorColor band1, DigitResistorColor band2, MultiplierResistorColor band3, ToleranceResistorColor band4) {
        this.band1 = Objects.requireNonNull(band1);
        this.band2 = Objects.requireNonNull(band2);
        this.band3 = Objects.requireNonNull(band3);
        this.band4 = Objects.requireNonNull(band4);
    }

    public double resistance() {
        double digitValue = band1.value() * 10 + band2.value();
        return digitValue * band3.value();
    }

    public DigitResistorColor band1() {
        return band1;
    }

    public DigitResistorColor band2() {
        return band2;
    }

    public MultiplierResistorColor band3() {
        return band3;
    }

    public ToleranceResistorColor band4() {
        return band4;
    }

    public static Resistor of(DigitResistorColor band1, DigitResistorColor band2, MultiplierResistorColor band3, ToleranceResistorColor band4) {
        return new Resistor(band1, band2, band3, band4);
    }

    public Resistor withBand1(DigitResistorColor band1) {
        return Resistor.of(band1, band2, band3, band4);
    }

    public Resistor withBand2(DigitResistorColor band2) {
        return Resistor.of(band1, band2, band3, band4);
    }

    public Resistor withBand3(MultiplierResistorColor band3) {
        return Resistor.of(band1, band2, band3, band4);
    }

    public Resistor withBand4(ToleranceResistorColor band4) {
        return Resistor.of(band1, band2, band3, band4);
    }

    @Override
    public String toString() {
        return NUMBER_FORMAT.format(resistance()) +
                "Ω" +
                "   " +
                "±" +
                band4.value();
    }

}
