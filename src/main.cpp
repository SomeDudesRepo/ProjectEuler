#include "mainwindow.h"

#include <QApplication>

#include "log.h"

int main(int argc, char *argv[])
{
    int result(0);
    try
    {
        QApplication a(argc, argv);
        Log("-- App start --");
        MainWindow w;
        w.show();
        result = a.exec();
        Log("-- App end --");
    }
    catch(const std::string& s)
    {
        result = 1;
        Log("Exception: " + s);
    }
    catch(...)
    {
        result = 1;
        Log("Exception: unknown");
    }

    return result;
}
