package com.dafexdv.resistorgui.ui;

import com.dafexdv.resistorgui.domain.Resistor;
import com.dafexdv.resistorgui.state.AppState;
import com.dafexdv.resistorgui.state.AppStateListener;

import javax.swing.*;
import java.awt.*;

public final class ResistorDisplayComponent extends JPanel implements AppStateListener {

    private final AppState state;

    private JLabel label;

    public ResistorDisplayComponent(AppState state) {
        this.state = state;
        this.state.addListener(this);

        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

        addComponents();
    }

    private void addComponents() {
        ResistorPicture picture = new ResistorPicture(state);

        add(picture);

        label = new JLabel(state.getResistor().toString());
        label.setFont(getFont().deriveFont(16.0f));
        label.setAlignmentX(Component.CENTER_ALIGNMENT);
        label.setAlignmentY(Component.TOP_ALIGNMENT);

        add(label);

        add(Box.createVerticalGlue());
    }

    @Override
    public void onStateChanged() {
        label.setText(state.getResistor().toString());
    }

    private static final class ResistorPicture extends JPanel implements AppStateListener {

        private static final Color WIRE_COLOR = new Color(192, 192, 192);
        private static final Color BODY_COLOR = new Color(217, 180, 119);

        private static final int WIRE_HEIGHT = 6;

        private static final int BODY_WIDTH = 160;
        private static final int BODY_HEIGHT = 40;
        private static final int BODY_CENTER_HEIGHT = 30;

        private static final int BAND_WIDTH = 12;

        private final AppState state;

        ResistorPicture(AppState state) {
            this.state = state;
            state.addListener(this);

            setPreferredSize(new Dimension(260, 80));
            setOpaque(false);
        }

        @Override
        protected void paintComponent(Graphics g) {
            Resistor resistor = state.getResistor();

            Graphics2D g2 = (Graphics2D) g.create();

            g2.setRenderingHint(
                    RenderingHints.KEY_ANTIALIASING,
                    RenderingHints.VALUE_ANTIALIAS_ON
            );

            int centerX = getWidth() / 2;
            int centerY = getHeight() / 2;

            int bodyX = centerX - BODY_WIDTH / 2;
            int bodyY = centerY - BODY_HEIGHT / 2;

            int wireY = centerY - WIRE_HEIGHT / 2;

            // Left wire
            g2.setColor(WIRE_COLOR);
            g2.fillRect(
                    0,
                    wireY,
                    bodyX,
                    WIRE_HEIGHT
            );

            // Right wire
            g2.fillRect(
                    bodyX + BODY_WIDTH,
                    wireY,
                    getWidth() - (bodyX + BODY_WIDTH),
                    WIRE_HEIGHT
            );

            // Body
            g2.setColor(BODY_COLOR);

            Polygon body = new Polygon();

            body.addPoint(bodyX, centerY - BODY_HEIGHT / 2);
            body.addPoint(bodyX + 20, centerY - BODY_CENTER_HEIGHT / 2);
            body.addPoint(bodyX + BODY_WIDTH - 20, centerY - BODY_CENTER_HEIGHT / 2);
            body.addPoint(bodyX + BODY_WIDTH, centerY - BODY_HEIGHT / 2);

            body.addPoint(bodyX + BODY_WIDTH, centerY + BODY_HEIGHT / 2);
            body.addPoint(bodyX + BODY_WIDTH - 20, centerY + BODY_CENTER_HEIGHT / 2);
            body.addPoint(bodyX + 20, centerY + BODY_CENTER_HEIGHT / 2);
            body.addPoint(bodyX, centerY + BODY_HEIGHT / 2);

            g2.fillPolygon(body);

            // band1
            g2.setColor(resistor.band1().awtColor());

            g2.fillRect(
                    bodyX + 30,
                    bodyY,
                    BAND_WIDTH,
                    BODY_HEIGHT
            );

            // band2
            g2.setColor(resistor.band2().awtColor());

            g2.fillRect(
                    bodyX + 60,
                    bodyY,
                    BAND_WIDTH,
                    BODY_HEIGHT
            );

            // band3 (multiplier)
            g2.setColor(resistor.band3().awtColor());

            g2.fillRect(
                    bodyX + 90,
                    bodyY,
                    BAND_WIDTH,
                    BODY_HEIGHT
            );

            // band4 (tolerance)
            g2.setColor(resistor.band4().awtColor());

            g2.fillRect(
                    bodyX + 125,
                    bodyY,
                    BAND_WIDTH,
                    BODY_HEIGHT
            );

            g2.dispose();
        }

        @Override
        public void onStateChanged() {
            repaint();
        }

    }

}
