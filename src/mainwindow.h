#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>

#include <QMainWindow>

#include "xmlreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_mBtnRun_clicked();

private:
    Ui::MainWindow *ui;
    const std::string mAppPath;
    XmlReader mXmlReader;

    void SetProblemRunning();
};

#endif // MAINWINDOW_H
