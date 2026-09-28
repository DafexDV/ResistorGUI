package com.dafexdv.resistorgui;

import com.dafexdv.resistorgui.state.AppState;
import com.dafexdv.resistorgui.ui.MainFrame;
import com.formdev.flatlaf.FlatDarkLaf;
import com.formdev.flatlaf.FlatLightLaf;
import com.jthemedetecor.OsThemeDetector;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public final class Application {

    private static final Logger LOGGER = LogManager.getLogger(Application.class);

    public static void start() {
        setupFlatLaf();

        AppState state = new AppState();

        MainFrame mainFrame = new MainFrame(state);
        mainFrame.setVisible(true);
    }

    /**
     * Setup flatlaf theme dynamically
     */
    private static void setupFlatLaf() {
        LOGGER.debug("Setting up FlatLaf theme dynamically by theme");

        OsThemeDetector detector = OsThemeDetector.getDetector();

        if (detector.isDark()) {
            FlatDarkLaf.setup();
            LOGGER.info("Dark theme detected, FlatLaf theme set to dark");
        } else {
            FlatLightLaf.setup();
            LOGGER.info("Light theme detected, FlatLaf theme set to light");
        }
    }

}
