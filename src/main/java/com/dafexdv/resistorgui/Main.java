package com.dafexdv.resistorgui;

import com.dafexdv.resistorgui.ui.MainFrame;
import com.formdev.flatlaf.FlatLightLaf;

public final class Main {

    public static void main(String[] args) {
        FlatLightLaf.setup();

        MainFrame mainFrame = new MainFrame();
        mainFrame.setVisible(true);
    }

}
