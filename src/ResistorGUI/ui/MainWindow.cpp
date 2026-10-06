#include "ResistorGUI/ui/MainWindow.hpp"

#include <QVBoxLayout>
#include "ResistorGUI/ui/MainMenuBar.hpp"
#include "ResistorGUI/ui/KindSwitcher.hpp"
#include "ResistorGUI/ui/ResistorDisplayWidget.hpp"
#include "ResistorGUI/ui/ResistorInputsWidget.hpp"

#define WINDOW_WIDTH 560
#define WINDOW_HEIGHT 280

MainWindow::MainWindow(AppState& state, QWidget* parent)
    : QMainWindow(parent),
      _state(state)
{
    setWindowTitle("ResistorGUI");
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    QIcon icon = QIcon::fromTheme("resistor-gui", QIcon(":/icons/resistor-gui.svg"));
    setWindowIcon(icon);

    auto* menuBar = new MainMenuBar(state, this);
    setMenuBar(menuBar);

    initUI();
}

void MainWindow::initUI()
{
    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout(centralWidget);

    KindSwitcher* kindSwitcher = new KindSwitcher(_state, centralWidget);
    ResistorDisplayWidget* displayWidget = new ResistorDisplayWidget(_state, centralWidget);
    ResistorInputsWidget* inputsWidget = new ResistorInputsWidget(_state, centralWidget);

    layout->addWidget(kindSwitcher);
    layout->addWidget(displayWidget, 1);
    layout->addWidget(inputsWidget);

    setCentralWidget(centralWidget);
}
