package com.dafexdv.resistorgui;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

public final class BuildProperties {

    private static final Properties properties;

    static {
        properties = new Properties();
        try (InputStream stream = BuildProperties.class.getResourceAsStream("/build.properties")) {
            properties.load(stream);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static String name() {
        return properties.getProperty("name");
    }

    public static String version() {
        return properties.getProperty("version");
    }

    public static String url() {
        return properties.getProperty("url");
    }

}
