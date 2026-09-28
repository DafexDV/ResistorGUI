package com.dafexdv.resistorgui;

import javax.swing.*;
import java.awt.*;

public final class Utils {

    public static ImageIcon getAppImageIcon() {
        return new ImageIcon(Utils.class.getResource("/assets/icon.png"), "Resistor GUI");
    }

    public static Window getWindow(Component component) {
        return SwingUtilities.getWindowAncestor(component);
    }

}
