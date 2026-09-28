package com.dafexdv.resistorgui;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Locale;

public final class ApplicationPaths {

    private static final String APPLICATION_NAME = "ResistorGUI";

    /**
     * Create all the application directories
     */
    public static void initialize() throws IOException {
        Files.createDirectories(dataDirectory());
        // at the moment, we're not using config directory,
        // but it will be used soon
        //Files.createDirectories(configDirectory());
        Files.createDirectories(logDirectory());
    }

    public static Path dataDirectory() {
        return switch (platform()) {
            case WINDOWS -> windowsDataDirectory();
            case MACOS -> macosDataDirectory();
            case LINUX -> linuxDataDirectory();
        };
    }

    public static Path configDirectory() {
        return switch (platform()) {
            case WINDOWS -> windowsConfigDirectory();
            case MACOS -> macosConfigDirectory();
            case LINUX -> linuxConfigDirectory();
        };
    }

    public static Path logDirectory() {
        return switch (platform()) {
            case WINDOWS -> windowsDataDirectory().resolve("logs");
            case MACOS -> macosDataDirectory().resolve("Logs");
            case LINUX -> linuxDataDirectory().resolve("logs");
        };
    }

    private static Path windowsDataDirectory() {
        return Path.of(
                environment("APPDATA"),
                APPLICATION_NAME
        );
    }

    private static Path windowsConfigDirectory() {
        return windowsDataDirectory();
    }

    private static Path macosDataDirectory() {
        return Path.of(
                userHome(),
                "Library",
                "Application Support",
                APPLICATION_NAME
        );
    }

    private static Path macosConfigDirectory() {
        return Path.of(
                userHome(),
                "Library",
                "Preferences",
                APPLICATION_NAME
        );
    }

    private static Path linuxDataDirectory() {
        return Path.of(
                environmentOrDefault(
                        "XDG_DATA_HOME",
                        Path.of(userHome(), ".local", "share").toString()
                ),
                APPLICATION_NAME.toLowerCase(Locale.ROOT)
        );
    }

    private static Path linuxConfigDirectory() {
        return Path.of(
                environmentOrDefault(
                        "XDG_CONFIG_HOME",
                        Path.of(userHome(), ".config").toString()
                ),
                APPLICATION_NAME.toLowerCase(Locale.ROOT)
        );
    }

    private static String userHome() {
        return System.getProperty("user.home");
    }

    private static String environment(String name) {
        String value = System.getenv(name);

        if (value == null || value.isBlank()) {
            throw new IllegalStateException(
                    "Environment variable not defined: " + name
            );
        }

        return value;
    }

    private static String environmentOrDefault(String name, String defaultValue) {
        String value = System.getenv(name);
        return value == null || value.isBlank() ? defaultValue : value;
    }

    private static Platform platform() {
        String os = System.getProperty("os.name")
                .toLowerCase(Locale.ROOT);

        if (os.contains("win")) {
            return Platform.WINDOWS;
        }

        if (os.contains("mac")) {
            return Platform.MACOS;
        }

        if (os.contains("nux") || os.contains("nix")) {
            return Platform.LINUX;
        }

        throw new UnsupportedOperationException(
                "Unsupported operating system: " + os
        );
    }

    private ApplicationPaths() {
    }

    private enum Platform {
        WINDOWS,
        MACOS,
        LINUX
    }

}
