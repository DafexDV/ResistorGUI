package com.dafexdv.resistorgui.domain;

import org.jspecify.annotations.Nullable;

import java.awt.*;
import java.text.DecimalFormat;
import java.text.NumberFormat;

public enum MultiplierResistorColor implements ResistorColor {
    BLACK(1, Color.BLACK),
    BROWN(10, new Color(65, 25, 0)),
    RED(100, Color.RED),
    ORANGE(1_000, Color.ORANGE),
    YELLOW(10_000, Color.YELLOW),
    GREEN(100_000, Color.GREEN),
    BLUE(1_000_000, Color.BLUE),
    VIOLET(10_000_000, new Color(128, 0, 255)),
    GRAY(100_000_000, Color.GRAY),
    WHITE(1_000_000_000, Color.WHITE),
    GOLDEN(0.1, new Color(212, 175, 55)),
    SILVER(0.01, new Color(192, 192, 192));

    private static final NumberFormat COMPACT_FORMAT = NumberFormat.getCompactNumberInstance();
    private static final DecimalFormat DECIMAL_FORMAT = new DecimalFormat("0.##");

    private final double value;
    private final Color awtColor;

    MultiplierResistorColor(double value, Color awtColor) {
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
        if (value < 1) {
            return "×" + DECIMAL_FORMAT.format(value);
        } else {
            return "×" + COMPACT_FORMAT.format(value);
        }
    }

    public static @Nullable MultiplierResistorColor fromValue(double value) {
        for (MultiplierResistorColor mrc : values()) {
            if (mrc.value == value) {
                return mrc;
            }
        }
        return null;
    }

    public static @Nullable MultiplierResistorColor fromAwtColor(Color awtColor) {
        for (MultiplierResistorColor mrc : values()) {
            if (mrc.awtColor == awtColor) {
                return mrc;
            }
        }
        return null;
    }
}
