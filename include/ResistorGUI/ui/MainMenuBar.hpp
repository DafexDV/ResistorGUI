#pragma once

#include <QMenuBar>
#include "ResistorGUI/state/AppState.hpp"

class MainMenuBar final : public QMenuBar
{
public:
    explicit MainMenuBar(AppState& state, QWidget* parent = nullptr);

private:
    AppState& _state;

    void initUI();
};
