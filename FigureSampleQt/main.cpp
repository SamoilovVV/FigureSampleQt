#include "FigureSampleQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FigureSampleQt w;
    w.show();
    return a.exec();
}
