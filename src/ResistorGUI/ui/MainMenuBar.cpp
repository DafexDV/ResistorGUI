#include "ResistorGUI/ui/MainMenuBar.hpp"

#include <QMenu>
#include <QMessageBox>
#include "BuildInfo.hpp"

MainMenuBar::MainMenuBar(AppState& state, QWidget* parent)
    : QMenuBar(parent),
      _state(state)
{
    initUI();
}

void MainMenuBar::initUI()
{
    QMenu* fileMenu = addMenu("File");
    QAction* resetResistors = fileMenu->addAction("Reset all");
    
    connect(
        resetResistors,
        &QAction::triggered,
        this,
        [this]() {
            _state.resetResistors();
        }
    );

    QMenu* helpMenu = addMenu("Help");
    QAction* aboutAction = helpMenu->addAction("About");

    connect(
        aboutAction,
        &QAction::triggered,
        this,
        [this]() {
            QMessageBox::about(
                this,
                QString("About %1").arg(RESISTOR_GUI_NAME),
                QString(
                    "%1 %2\n\n"
                    "Author: %3\n"
                    "License: %4\n"
                    "Github: %5"
                )
                .arg(RESISTOR_GUI_NAME)
                .arg(RESISTOR_GUI_VERSION)
                .arg(RESISTOR_GUI_AUTHOR)
                .arg(RESISTOR_GUI_LICENSE)
                .arg(RESISTOR_GUI_GITHUB)
            );
        }
    );
}
