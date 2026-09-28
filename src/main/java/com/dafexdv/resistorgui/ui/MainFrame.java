package com.dafexdv.resistorgui.ui;

import com.dafexdv.resistorgui.Utils;
import com.dafexdv.resistorgui.state.AppState;

import javax.swing.*;
import java.awt.*;

public final class MainFrame extends JFrame {

    private final AppState state;

    public MainFrame(AppState state) {
        this.state = state;

        setTitle("Resistor GUI");
        setIconImage(Utils.getAppImageIcon().getImage());
        setLayout(new GridBagLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(450, 280);
        setLocationRelativeTo(null);
        setResizable(false);
        setJMenuBar(new MainMenuBar(state));

        addComponents();
    }

    private void addComponents() {
        GridBagConstraints gbc = new GridBagConstraints();

        var resistorComponent = new ResistorDisplayComponent(state);
        gbc.gridx = 0;
        gbc.gridy = 0;

        add(resistorComponent, gbc);

        var resistorInputsComponent = new ResistorInputsComponent(state);
        gbc.gridy = 1;

        add(resistorInputsComponent, gbc);
    }

}
