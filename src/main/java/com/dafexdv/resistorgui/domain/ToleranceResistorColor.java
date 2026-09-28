package com.dafexdv.resistorgui.domain;

import org.jspecify.annotations.Nullable;

import java.awt.*;
import java.text.DecimalFormat;
import java.text.NumberFormat;

public enum ToleranceResistorColor implements ResistorColor {
    BROWN(1, new Color(65, 25, 0)),
    RED(2, Color.RED),
    GREEN(0.5, Color.GREEN),
    BLUE(0.25, Color.BLUE),
    VIOLET(0.1, new Color(128, 0, 255)),
    GOLDEN(5, new Color(212, 175, 55)),
    SILVER(10, new Color(192, 192, 192));

    private static final DecimalFormat DECIMAL_FORMAT = new DecimalFormat("0.##");

    private final double value;
    private final Color awtColor;

    ToleranceResistorColor(double value, Color awtColor) {
        this.value = value;
        this.awtColor = awtColor;
    }

    @Override
    public double value() {
        return value;
    }

    @Override
    public Color awtColor() {
        return awtColor;
    }

    @Override
    public String toString() {
        return "±" + DECIMAL_FORMAT.format(value);
    }

    public static @Nullable ToleranceResistorColor fromValue(double value) {
        for (ToleranceResistorColor trc : values()) {
            if (trc.value == value) {
                return trc;
            }
        }
        return null;
    }
}
