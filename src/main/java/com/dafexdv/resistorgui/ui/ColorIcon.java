package com.dafexdv.resistorgui.ui;

import javax.swing.*;
import java.awt.*;

public final class ColorIcon implements Icon {

    private final Color color;
    private final int size;

    public ColorIcon(Color color, int size) {
        this.color = color;
        this.size = size;
    }


    @Override
    public void paintIcon(Component c, Graphics g, int x, int y) {
        g.setColor(color);
        g.fillRect(x, y, size, size);
    }

    @Override
    public int getIconWidth() {
        return size;
    }

    @Override
    public int getIconHeight() {
        return size;
    }

}
