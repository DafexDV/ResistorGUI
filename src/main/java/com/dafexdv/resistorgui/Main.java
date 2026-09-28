package com.dafexdv.resistorgui;

import java.io.IOException;
import java.nio.file.Path;

public final class Main {

    public static void main(String[] args) {
        try {
            ApplicationPaths.initialize();

            Path logFile = ApplicationPaths.logDirectory()
                    .resolve("application.log");

            System.out.println("Log file: " + logFile.toAbsolutePath());

            System.setProperty(
                    "resistorgui.log.file",
                    logFile.toAbsolutePath().toString()
            );
        } catch (IOException e) {
            throw new RuntimeException("Failed to create directories");
        }

        Application.start();
    }

}
