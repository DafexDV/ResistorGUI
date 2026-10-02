#include "ResistorGUI/ui/KindSwitcher.hpp"

#include <QHBoxLayout>

KindSwitcher::KindSwitcher(AppState& state, QWidget* parent)
    : QWidget(parent),
      _state(state)
{
    initUI();
}

void KindSwitcher::initUI()
{
    QButtonGroup* group = new QButtonGroup(this);

    QHBoxLayout* layout = new QHBoxLayout(this);

    for (auto value : RESISTOR_KINDS)
    {
        QPushButton* button = createToggleButton(group, value);

        connect(button, &QPushButton::toggled, this, [this, button, value](bool checked) {
            if (checked) {
                _state.switchKind(value);
            }
        });

        layout->addWidget(button);
    }
}

QPushButton* KindSwitcher::createToggleButton(QButtonGroup* group, ResistorKind value)
{
    QPushButton* button = new QPushButton(
        QString::fromStdString(to_string(value)),
        this
    );
    button->setCheckable(true);

    if (value == _state.currentResistorKind())
    {
        button->toggle();
    }

    connect(button, &QPushButton::toggled, this, [this, button, value](bool checked) {
        if (checked) {
            _state.switchKind(value);
        }
    });

    group->addButton(button);

    return button;
}
