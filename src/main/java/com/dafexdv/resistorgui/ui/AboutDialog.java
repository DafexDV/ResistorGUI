package com.dafexdv.resistorgui.ui;

import com.dafexdv.resistorgui.BuildProperties;
import com.dafexdv.resistorgui.Utils;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.net.URI;

public final class AboutDialog extends JDialog {

    public AboutDialog(Frame parent) {
        super(parent);
        addComponents();
        pack();
        setLocationRelativeTo(parent);
    }

    private void addComponents() {

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        panel.setBorder(new EmptyBorder(10, 40, 10, 40));

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);

        ImageIcon icon = Utils.getAppImageIcon();
        Image image = icon.getImage().getScaledInstance(
                32 * 2, 32 * 2, Image.SCALE_SMOOTH
        );

        JLabel label = new JLabel(
                BuildProperties.name(),
                new ImageIcon(image),
                SwingConstants.CENTER
        );

        label.setHorizontalTextPosition(SwingConstants.CENTER);
        label.setVerticalTextPosition(SwingConstants.BOTTOM);
        label.setIconTextGap(8);
        label.setFont(label.getFont().deriveFont(18.0f));
        gbc.gridx = 0;
        gbc.gridy = 0;

        panel.add(label, gbc);

        JPanel listPanel = new JPanel();
        listPanel.setLayout(new BoxLayout(listPanel, BoxLayout.Y_AXIS));

        JLabel versionLabel = new JLabel();
        versionLabel.setText(
                "Version: " + BuildProperties.version()
        );
        listPanel.add(versionLabel);

        JLabel authorLabel = new JLabel("Author: " + "DafexDV");
        listPanel.add(authorLabel);

        JLabel githubLabel = new JLabel("<html>Website</html>");
        githubLabel.setForeground(Color.CYAN);
        githubLabel.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        githubLabel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                githubLabel.setText("<html><u>Website</u></html>");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                githubLabel.setText("<html>Website</html>");
            }

            @Override
            public void mouseClicked(MouseEvent e) {
                String url = BuildProperties.url();

                try {
                    if (Desktop.isDesktopSupported()) {
                        Desktop desktop = Desktop.getDesktop();

                        if (desktop.isSupported(Desktop.Action.BROWSE)) {
                            desktop.browse(URI.create(url));
                            return;
                        }
                    }

                    new ProcessBuilder("xdg-open", url).start();
                } catch (IOException | IllegalArgumentException err) {
                    throw new RuntimeException("Could not open URL", err);
                }
            }
        });
        listPanel.add(githubLabel);

        gbc.gridx = 1;

        panel.add(Box.createHorizontalGlue());

        panel.add(listPanel);

        add(panel);
    }

}
