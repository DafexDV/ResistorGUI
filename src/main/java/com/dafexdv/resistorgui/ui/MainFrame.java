package com.dafexdv.resistorgui.ui;

import com.dafexdv.resistorgui.domain.DigitResistorColor;
import com.dafexdv.resistorgui.domain.MultiplierResistorColor;
import com.dafexdv.resistorgui.domain.Resistor;
import com.dafexdv.resistorgui.domain.ToleranceResistorColor;
import com.dafexdv.resistorgui.state.AppState;

import javax.swing.*;
import java.awt.*;

public final class MainFrame extends JFrame {

    private static final Resistor DEFAULT_RESISTOR = Resistor.of(
            DigitResistorColor.RED,
            DigitResistorColor.RED,
            MultiplierResistorColor.BROWN,
            ToleranceResistorColor.GOLDEN
    );

    private final AppState state;

    public MainFrame() {
        this.state = new AppState(DEFAULT_RESISTOR);

        setTitle("Resistor GUI");
        setLayout(new BorderLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(400, 220);
        setResizable(false);

        addComponents();
    }

    private void addComponents() {
        var resistorComponent = new ResistorDisplayComponent(state);

        add(resistorComponent, BorderLayout.CENTER);

        var resistorInputsComponent = new ResistorInputsComponent(state);

        add(resistorInputsComponent, BorderLayout.SOUTH);
    }

}
