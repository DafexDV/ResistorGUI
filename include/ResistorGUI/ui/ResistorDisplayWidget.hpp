#ifndef RESISTORGUI_UI_RESISTOR_DISPLAY_WIDGET_HPP
#define RESISTORGUI_UI_RESISTOR_DISPLAY_WIDGET_HPP

#include <QWidget>
#include <QLabel>
#include "ResistorGUI/state/AppState.hpp"

class ResistorDisplayWidget final : public QWidget
{
    Q_OBJECT

public:
    explicit ResistorDisplayWidget(
        AppState& state,
        QWidget* parent = nullptr
    );

private:
    AppState& _state;
    QLabel* _resistanceLabel;

    void initUI();
};

#endif