#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "problem01.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mLblResult->setText("Result here");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mBtnRun_clicked()
{
    ui->mLblResult->setText("Result here");
    try
    {
        switch (ui->mCmbProblems->currentText().toInt())
        {
            case 1:
            {
                const Problem01 pr01(2, 7, 10);
                ui->mLblResult->setText(QString::number(pr01.GetResult()));
                break;
            }
            default: throw "No other cases yet!";
        }
        ui->mLblResult->repaint();
    }
    catch(const std::string& s)
    {
        ui->mLblResult->setText(QString::fromStdString(s));
    }
    catch(const std::exception& e)
    {
        ui->mLblResult->setText(QString::fromStdString(e.what()));
    }
    catch(...)
    {
        ui->mLblResult->setText("Unexpected exception!");
    }
}
