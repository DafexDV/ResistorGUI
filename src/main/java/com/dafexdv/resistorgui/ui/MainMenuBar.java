package com.dafexdv.resistorgui.ui;

import com.dafexdv.resistorgui.Utils;
import com.dafexdv.resistorgui.state.AppState;

import javax.swing.*;
import java.awt.*;

public final class MainMenuBar extends JMenuBar {

    public MainMenuBar(AppState state) {
        JMenu fileMenu = new JMenu("File");

        JMenuItem resetMenuItem = new JMenuItem("Reset");
        resetMenuItem.addActionListener(e -> {
            state.resetResistor();
        });
        fileMenu.add(resetMenuItem);

        add(fileMenu);

        JMenu helpMenu = new JMenu("Help");

        JMenuItem aboutMenuItem = new JMenuItem("About");
        aboutMenuItem.addActionListener(e -> {
            Window window = Utils.getWindow(this);
            AboutDialog dialog = new AboutDialog((Frame) window);
            dialog.setVisible(true);
        });
        helpMenu.add(aboutMenuItem);

        add(helpMenu);
    }

}
