#include "ResistorGUI/ui/ResistorDisplayWidget.hpp"
#include "ResistorGUI/domain/Resistor4.hpp"
#include "ResistorGUI/domain/Resistor5.hpp"

#include <QVBoxLayout>
#include <QPainter>
#include <qcolor.h>

#define WIRE_HEIGHT 6
#define BODY_WIDTH 160
#define BODY_HEIGHT 40
#define BODY_CENTER_HEIGHT 30
#define BAND_WIDTH 8

inline const QColor WIRE_COLOR(192, 192, 192);
inline const QColor BODY_COLOR(29, 107, 171);
inline const QColor DARKER_BODY_COLOR(25, 91, 146);

template <typename T>
static QColor get_color_from_resistor_band(T band)
{
    auto rgb = resistor_color_rgb(band);
    return QColor(rgb->r, rgb->g, rgb->b);
}

class ResistorPictureWidget : public QWidget
{

public:
    explicit ResistorPictureWidget(AppState &state, QWidget *parent = nullptr)
        : QWidget(parent),
          _state(state)
    {
        connect(&_state, &AppState::stateChanged, this, qOverload<>(&QWidget::update));
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);

        QPainter painter(this);

        painter.setRenderHint(QPainter::Antialiasing);

        const Resistor &resistor = _state.currentResistor();

        // calculate bodyWidth by resistor
        int bodyWidth = getBodyWidth(resistor);

        int centerX = width() / 2;
        int centerY = height() / 2;

        int bodyX = centerX - bodyWidth / 2;
        int bodyY = centerY - BODY_HEIGHT / 2;

        paintWires(painter, bodyX, bodyWidth, centerY);

        paintBody(painter, bodyX, bodyWidth, centerY);

        paintResistorBands(painter, resistor, bodyX, centerY);
    }

private:
    AppState &_state;

    int getBodyWidth(const Resistor &resistor)
    {
        int bodyWidth;
        if (typeid(resistor) == typeid(Resistor4))
        {
            bodyWidth = 120;
        }
        else if (typeid(resistor) == typeid(Resistor5))
        {
            bodyWidth = 145;
        }
        else if (typeid(resistor) == typeid(Resistor6))
        {
            bodyWidth = 160;
        }
        else
        {
            throw std::invalid_argument("Invalid resistor");
        }
        return bodyWidth;
    }

    void paintWires(QPainter &painter, int bodyX, int bodyWidth, int centerY)
    {
        int wireY = centerY - WIRE_HEIGHT / 2;

        // left wire
        painter.fillRect(0, wireY, bodyX, WIRE_HEIGHT, WIRE_COLOR);

        // right wire
        painter.fillRect(
            bodyX + bodyWidth,
            wireY,
            width() - (bodyX + bodyWidth), WIRE_HEIGHT,
            WIRE_COLOR);
    }

    void paintBody(QPainter &painter, int bodyX, int bodyWidth, int centerY)
    {
        painter.setBrush(BODY_COLOR);
        painter.setPen(DARKER_BODY_COLOR);

        QPolygon polygon;
        polygon << QPoint(bodyX, centerY - BODY_HEIGHT / 2)
                << QPoint(bodyX + 20, centerY - BODY_HEIGHT / 2)
                << QPoint(bodyX + 20, centerY - BODY_CENTER_HEIGHT / 2)
                << QPoint(bodyX + bodyWidth - 20, centerY - BODY_CENTER_HEIGHT / 2)
                << QPoint(bodyX + bodyWidth - 20, centerY - BODY_HEIGHT / 2)
                << QPoint(bodyX + bodyWidth, centerY - BODY_HEIGHT / 2)
                << QPoint(bodyX + bodyWidth, centerY + BODY_HEIGHT / 2)
                << QPoint(bodyX + bodyWidth - 20, centerY + BODY_HEIGHT / 2)
                << QPoint(bodyX + bodyWidth - 20, centerY + BODY_CENTER_HEIGHT / 2)
                << QPoint(bodyX + 20, centerY + BODY_CENTER_HEIGHT / 2)
                << QPoint(bodyX + 20, centerY + BODY_HEIGHT / 2)
                << QPoint(bodyX, centerY + BODY_HEIGHT / 2);

        painter.drawPolygon(polygon);
    }

    void paintResistorBands(QPainter &painter, const Resistor &resistor, int bodyX, int centerY)
    {
        /**
         * On actual resistors, the tolerance band or the TC band (in the case of 6-band resistors)
         * is spaced slightly further away from the others. In terms of the code,
         * the spacing is 5 units greater than the distance between the other bands.
         */
        if (const auto *r4 = dynamic_cast<const Resistor4 *>(&resistor))
        {
            paintResistor4Bands(painter, *r4, bodyX, centerY);
        }
        else if (const auto *r5 = dynamic_cast<const Resistor5 *>(&resistor))
        {
            paintResistor5Bands(painter, *r5, bodyX, centerY);
        }
        else if (const auto *r6 = dynamic_cast<const Resistor6 *>(&resistor))
        {
            paintResistor6Bands(painter, *r6, bodyX, centerY);
        }
        else
        {
            throw std::invalid_argument("Invalid resistor");
        }
    }

    void paintResistor4Bands(QPainter &painter, const Resistor4 &resistor, int bodyX, int centerY)
    {
        painter.fillRect(
            bodyX + 6,
            centerY - BODY_HEIGHT / 2,
            BAND_WIDTH,
            BODY_HEIGHT,
            get_color_from_resistor_band(resistor.digitBand(0)));

        painter.fillRect(
            bodyX + 30,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.digitBand(1)));

        painter.fillRect(
            bodyX + 55,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.multiplierBand()));

        painter.fillRect(
            bodyX + 90,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.toleranceBand()));
    }

    void paintResistor5Bands(QPainter &painter, const Resistor5 &resistor, int bodyX, int centerY)
    {
        painter.fillRect(
            bodyX + 6,
            centerY - BODY_HEIGHT / 2,
            BAND_WIDTH,
            BODY_HEIGHT,
            get_color_from_resistor_band(resistor.digitBand(0)));

        painter.fillRect(
            bodyX + 30,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.digitBand(1)));

        painter.fillRect(
            bodyX + 55,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.digitBand(2)));

        painter.fillRect(
            bodyX + 80,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.multiplierBand()));

        painter.fillRect(
            bodyX + 115,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.toleranceBand()));
    }

    void paintResistor6Bands(QPainter &painter, const Resistor6 &resistor, int bodyX, int centerY)
    {
        painter.fillRect(
            bodyX + 6,
            centerY - BODY_HEIGHT / 2,
            BAND_WIDTH,
            BODY_HEIGHT,
            get_color_from_resistor_band(resistor.digitBand(0)));

        painter.fillRect(
            bodyX + 30,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.digitBand(1)));

        painter.fillRect(
            bodyX + 55,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.digitBand(2)));

        painter.fillRect(
            bodyX + 80,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.multiplierBand()));

        painter.fillRect(
            bodyX + 105,
            centerY - BODY_CENTER_HEIGHT / 2,
            BAND_WIDTH,
            BODY_CENTER_HEIGHT,
            get_color_from_resistor_band(resistor.toleranceBand()));

        painter.fillRect(
            bodyX + 146,
            centerY - BODY_HEIGHT / 2,
            BAND_WIDTH,
            BODY_HEIGHT,
            get_color_from_resistor_band(resistor.tempCoBand()));
    }
};

ResistorDisplayWidget::ResistorDisplayWidget(AppState &state, QWidget *parent)
    : QWidget(parent),
      _state(state)
{
    initUI();

    connect(
        &_state,
        &AppState::stateChanged,
        this,
        [this]() {
            auto str = _state.currentResistor().to_string();
            _resistanceLabel->setText(
                QString::fromStdString(str)
            );
        }
    );
}

void ResistorDisplayWidget::initUI()
{
    ResistorPictureWidget *display = new ResistorPictureWidget(_state, this);
    _resistanceLabel = new QLabel(this);
    _resistanceLabel->setAlignment(Qt::AlignCenter);
    QFont newFont = _resistanceLabel->font();
    newFont.setPointSize(18);
    _resistanceLabel->setFont(newFont);
    _resistanceLabel->setText(
        QString::fromStdString(_state.currentResistor().to_string())
    );

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(display);
    layout->addWidget(_resistanceLabel);
}
