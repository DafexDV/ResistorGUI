#ifndef RESISTORGUI_UI_MAIN_WINDOW_HPP
#define RESISTORGUI_UI_MAIN_WINDOW_HPP

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

#endif