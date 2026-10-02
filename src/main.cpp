#include <QApplication>
#include "ResistorGUI/ui/MainWindow.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    AppState state;

    MainWindow window(state);
    window.show();

    return app.exec();
}
