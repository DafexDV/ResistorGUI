#pragma once

#include <QMainWindow>
#include "ResistorGUI/state/AppState.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(AppState& state, QWidget* parent = nullptr);

private:
    AppState& _state;

    void initUI();
};
