#pragma once

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
