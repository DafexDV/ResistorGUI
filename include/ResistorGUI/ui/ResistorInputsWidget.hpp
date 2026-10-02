#ifndef RESISTORGUI_UI_RESISTOR_INPUTS_WIDGET_HPP
#define RESISTORGUI_UI_RESISTOR_INPUTS_WIDGET_HPP

#include <QWidget>
#include <QComboBox>
#include <qcombobox.h>
#include <vector>
#include "ResistorGUI/state/AppState.hpp"

class ResistorInputsWidget final : public QWidget
{
    Q_OBJECT

public:
    explicit ResistorInputsWidget(AppState& state, QWidget* parent = nullptr);

private:
    AppState& _state;

    std::vector<QComboBox*> _digitComboBoxes;
    QComboBox* _multiplierComboBox;
    QComboBox* _toleranceComboBox;
    QComboBox* _tempCoComboBox;

    void initUI();

};

#endif
