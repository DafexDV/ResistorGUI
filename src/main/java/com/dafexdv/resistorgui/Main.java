package com.dafexdv.resistorgui;

import com.dafexdv.resistorgui.state.AppState;
import com.dafexdv.resistorgui.ui.MainFrame;
import com.formdev.flatlaf.FlatLightLaf;

public final class Main {

    public static void main(String[] args) {
        FlatLightLaf.setup();

        AppState state = new AppState();

        MainFrame mainFrame = new MainFrame(state);
        mainFrame.setVisible(true);
    }

}
