#ifndef RESISTORGUI_UI_KIND_SWITCHER_HPP
#define RESISTORGUI_UI_KIND_SWITCHER_HPP

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include "ResistorGUI/domain/ResistorKind.hpp"
#include "ResistorGUI/state/AppState.hpp"

class KindSwitcher final : public QWidget
{
    Q_OBJECT

public:
    explicit KindSwitcher(AppState& _state, QWidget* parent = nullptr);

private:
    AppState& _state;

    void initUI();

    QPushButton* createToggleButton(QButtonGroup* group, ResistorKind value);
};

#endif