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
        setLayout(new BorderLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(400, 230);
        setLocationRelativeTo(null);
        setResizable(false);
        setJMenuBar(new MainMenuBar(state));

        addComponents();
    }

    private void addComponents() {
        var resistorComponent = new ResistorDisplayComponent(state);

        add(resistorComponent, BorderLayout.CENTER);

        var resistorInputsComponent = new ResistorInputsComponent(state);

        add(resistorInputsComponent, BorderLayout.SOUTH);
    }

}
