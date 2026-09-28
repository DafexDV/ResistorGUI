package com.dafexdv.resistorgui.domain;

import org.jspecify.annotations.Nullable;

import java.awt.*;
import java.text.NumberFormat;

public enum DigitResistorColor implements ResistorColor {
    BLACK(0, Color.BLACK),
    BROWN(1, new Color(65, 25, 0)),
    RED(2, Color.RED),
    ORANGE(3, Color.ORANGE),
    YELLOW(4, Color.YELLOW),
    GREEN(5, Color.GREEN),
    BLUE(6, Color.BLUE),
    VIOLET(7, new Color(128, 0, 255)),
    GRAY(8, Color.GRAY),
    WHITE(9, Color.WHITE);

    private final double value;
    private final Color awtColor;

    DigitResistorColor(int value, Color awtColor) {
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
        return String.format("%.0f", value);
    }

    public static @Nullable DigitResistorColor fromValue(int value) {
        for (DigitResistorColor drc : values()) {
            if (drc.value == value) {
                return drc;
            }
        }
        return null;
    }

    public static @Nullable DigitResistorColor fromAwtColor(Color awtColor) {
        for (DigitResistorColor drc : values()) {
            if (drc.awtColor == awtColor) {
                return drc;
            }
        }
        return null;
    }
}
