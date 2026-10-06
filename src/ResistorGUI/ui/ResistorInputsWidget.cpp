#include "ResistorGUI/ui/ResistorInputsWidget.hpp"
#include "ResistorGUI/domain/ResistorBand.hpp"
#include "ResistorGUI/Utils.hpp"

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <iostream>

template <typename T>
static QComboBox *createResistorComboBox(
    const std::vector<T> &values,
    std::type_identity_t<T> initial,
    QWidget *parent = nullptr)
{
    auto *comboBox = new QComboBox(parent);

    for (T value : values)
    {
        const ResistorBandRgb *rgb = resistor_color_rgb(value);

        QPixmap pixmap(10, 10);
        pixmap.fill(QColor(rgb->r, rgb->g, rgb->b));

        comboBox->addItem(
            QIcon(pixmap),
            QString::fromStdString(to_string(value)),
            static_cast<int>(value));
    }

    int index = comboBox->findData(static_cast<int>(initial));

    if (index != -1)
    {
        comboBox->setCurrentIndex(index);
    }

    return comboBox;
}

ResistorInputsWidget::ResistorInputsWidget(AppState &state, QWidget *parent)
    : QWidget(parent), _state(state), _digitComboBoxes({})
{
    connect(
        &_state,
        &AppState::switchedKind,
        this,
        [this]() {
            clearUI();
            initUI();
        }
    );

    initUI();
}

void ResistorInputsWidget::clearUI()
{
    _digitComboBoxes.clear();
    _multiplierComboBox = nullptr;
    _toleranceComboBox = nullptr;
    _tempCoComboBox = nullptr;

    if (QLayout* oldLayout = layout())
    {
        while (QLayoutItem* item = oldLayout->takeAt(0))
        {
            if (QWidget* widget = item->widget())
            {
                widget->hide();
                widget->deleteLater();
            }
            delete item;
        }
        delete oldLayout;
    }
}

void ResistorInputsWidget::initUI()
{
    auto &resistor = _state.currentResistor();
    int digitBandCount = resistor.digitBandCount();

    QGridLayout *layout = new QGridLayout(this);

    int row = 0;
    int column = 0;

    for (unsigned int i = 0; i < digitBandCount; i++)
    {
        auto *digitLabel = new QLabel(this);
        digitLabel->setText(
            QString::fromStdString("Digit #" + std::to_string(i + 1)));

        layout->addWidget(digitLabel, row, column);

        row = 1;

        auto *digitComboBox = createResistorComboBox(
            DIGIT_RESISTOR_BANDS,
            resistor.digitBand(i),
            this);
        connect(
            digitComboBox,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            [this, digitComboBox, i](int index)
            {
                int value = digitComboBox->itemData(index).toInt();

                _state.updateCurrentResistorDigitalBand(i, static_cast<DigitResistorBand>(value));
            });

        layout->addWidget(digitComboBox, row, column);
        _digitComboBoxes.push_back(digitComboBox);

        row = 0;
        column += 1;
    }

    auto *multiplierLabel = new QLabel(this);
    multiplierLabel->setText("Multiplier");
    layout->addWidget(multiplierLabel, row, column);

    row = 1;

    _multiplierComboBox = createResistorComboBox(
        MULTIPLIER_RESISTOR_BANDS,
        resistor.multiplierBand(),
        this);
    connect(
        _multiplierComboBox,
        QOverload<int>::of(&QComboBox::currentIndexChanged),
        this,
        [this](int index)
        {
            int value = _multiplierComboBox->itemData(index).toInt();
            _state.updateCurrentResistorMultiplierBand(static_cast<MultiplierResistorBand>(value));
        });

    layout->addWidget(_multiplierComboBox, row, column);

    row = 0;
    column += 1;

    auto *toleranceLabel = new QLabel(this);
    toleranceLabel->setText("Tolerance");
    layout->addWidget(toleranceLabel, row, column);

    row = 1;

    _toleranceComboBox = createResistorComboBox(
        TOLERANCE_RESISTOR_BANDS,
        resistor.toleranceBand(),
        this);
    connect(
        _toleranceComboBox,
        QOverload<int>::of(&QComboBox::currentIndexChanged),
        this,
        [this](int index)
        {
            int value = _toleranceComboBox->itemData(index).toInt();
            _state.updateCurrentResistorToleranceBand(static_cast<ToleranceResistorBand>(value));
        });

    layout->addWidget(_toleranceComboBox, row, column);

    row = 0;
    column += 1;

    if (typeid(resistor) == typeid(Resistor6))
    {
        auto *tempCoLabel = new QLabel(this);
        tempCoLabel->setText("Temp. Co.");
        layout->addWidget(tempCoLabel, row, column);

        row = 1;

        _tempCoComboBox = createResistorComboBox(
            TEMP_CO_RESISTOR_BANDS,
            resistor.tempCoBand(),
            this);
        connect(
            _tempCoComboBox,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            [this](int index)
            {
                int value = _tempCoComboBox->itemData(index).toInt();
                _state.updateCurrentResistorTempCoBand(static_cast<TempCoResistorBand>(value));
            });
        layout->addWidget(_tempCoComboBox, row, column);
    }
    else
    {
        _tempCoComboBox = nullptr;
    }
}
