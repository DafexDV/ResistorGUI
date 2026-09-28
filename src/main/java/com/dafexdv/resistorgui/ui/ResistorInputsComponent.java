package com.dafexdv.resistorgui.ui;

import com.dafexdv.resistorgui.domain.DigitResistorColor;
import com.dafexdv.resistorgui.domain.MultiplierResistorColor;
import com.dafexdv.resistorgui.domain.ResistorColor;
import com.dafexdv.resistorgui.domain.ToleranceResistorColor;
import com.dafexdv.resistorgui.state.AppState;
import com.dafexdv.resistorgui.state.AppStateListener;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionListener;

public final class ResistorInputsComponent extends JPanel implements AppStateListener {

    private final AppState state;

    private ResistorColorComboBox<DigitResistorColor> digit1ComboBox;
    private ResistorColorComboBox<DigitResistorColor> digit2ComboBox;
    private ResistorColorComboBox<MultiplierResistorColor> multiplierComboBox;
    private ResistorColorComboBox<ToleranceResistorColor> toleranceComboBox;

    public ResistorInputsComponent(AppState state) {
        this.state = state;
        this.state.addListener(this);

        setLayout(new GridBagLayout());
        setBorder(new EmptyBorder(10, 10, 10, 10));

        addComponents();
    }

    public void addComponents() {
        var gbc = new GridBagConstraints();
        gbc.insets = new Insets(2, 2, 2, 2);


        var digit1Frame = new JLabel("Digit 1");
        gbc.gridx = 0;
        gbc.gridy = 0;

        add(digit1Frame, gbc);

        digit1ComboBox = new ResistorColorComboBox<>(
                DigitResistorColor.values(),
                state.getResistor().band1(),
                e -> {
                    state.updateResistorBand1((DigitResistorColor) digit1ComboBox.getSelectedItem());
                }
        );
        gbc.gridy = 1;

        add(digit1ComboBox, gbc);

        var digit2Frame = new JLabel("Digit 2");
        gbc.gridx = 1;
        gbc.gridy = 0;

        add(digit2Frame, gbc);

        digit2ComboBox = new ResistorColorComboBox<>(
                DigitResistorColor.values(),
                state.getResistor().band2(),
                e -> {
                    state.updateResistorBand2((DigitResistorColor) digit2ComboBox.getSelectedItem());
                }
        );
        gbc.gridy = 1;

        add(digit2ComboBox, gbc);

        var multiplierFrame = new JLabel("Multiplier");
        gbc.gridx = 2;
        gbc.gridy = 0;

        add(multiplierFrame, gbc);

        multiplierComboBox = new ResistorColorComboBox<>(
                MultiplierResistorColor.values(),
                state.getResistor().band3(),
                e -> {
                    state.updateResistorBand3((MultiplierResistorColor) multiplierComboBox.getSelectedItem());
                }
        );
        gbc.gridy = 1;

        add(multiplierComboBox, gbc);

        var toleranceFrame = new JLabel("Tolerance");
        gbc.gridx = 3;
        gbc.gridy = 0;

        add(toleranceFrame, gbc);

        toleranceComboBox = new ResistorColorComboBox<>(
                ToleranceResistorColor.values(),
                state.getResistor().band4(),
                e -> {
                    state.updateResistorBand4((ToleranceResistorColor) toleranceComboBox.getSelectedItem());
                }
        );
        gbc.gridy = 1;

        add(toleranceComboBox, gbc);
    }

    @Override
    public void onStateChanged() {
        digit1ComboBox.setSelectedItem(state.getResistor().band1());
        digit2ComboBox.setSelectedItem(state.getResistor().band2());
        multiplierComboBox.setSelectedItem(state.getResistor().band3());
        toleranceComboBox.setSelectedItem(state.getResistor().band4());
    }

    private static final class ResistorColorComboBox<T extends ResistorColor> extends JComboBox<T> {

        ResistorColorComboBox(T[] values, T initial, ActionListener actionListener) {
            setModel(new DefaultComboBoxModel<>(values));
            setSelectedItem(initial);
            addActionListener(actionListener);
            setRenderer((list, value, index, isSelected, cellHasFocus) -> {
                JLabel label = new JLabel(value.toString());
                label.setIcon(new ColorIcon(value.awtColor(), 10));
                return label;
            });
        }

    }

}
