#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "log.h"
#include "solutions/problem01.h"
#include "solutions/problem02.h"
#include "solutions/problem03.h"
#include "solutions/problem04.h"
#include "solutions/problem05.h"
#include "solutions/problem06.h"
#include "solutions/problem07.h"
#include "solutions/problem08.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mXmlReader("C:/Users/Dan/Documents/GitHub/ProjectEuler/xml/parameters.xml")
{
    ui->setupUi(this);
    auto problems = mXmlReader.GetAvailableProblems();
    for(const auto& problem : problems)
        ui->mCmbProblems->addItem(QString::fromStdString(problem));
    ui->mCmbProblems->setCurrentIndex(ui->mCmbProblems->count() - 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mBtnRun_clicked()
{
    try
    {
        const int problem(ui->mCmbProblems->currentText().toInt());
        const Parameters params(mXmlReader.GetProblemParameters(problem));
        std::unique_ptr<BaseRunnable> base;
        switch (problem)
        {
            case 1: base.reset(new Problem01(std::stoi(params[0]),
                                             std::stoi(params[1]),
                                             std::stoi(params[2])));
                    break;
            case 2: base.reset(new Problem02(std::stoi(params[0]))); break;
            case 3: base.reset(new Problem03(std::stoull(params[0]))); break;
            case 4: base.reset(new Problem04(std::stoull(params[0]), std::stoi(params[1]))); break;
            case 5: base.reset(new Problem05(std::stoull(params[0]), std::stoi(params[1]))); break;
            case 6: base.reset(new Problem06(std::stoull(params[0]), std::stoi(params[1]))); break;
            case 7: base.reset(new Problem07(std::stoull(params[0]))); break;
            case 8: base.reset(new Problem08(params[1], std::stoi(params[0]))); break;
            default: throw "No other cases yet!";
        }
        ui->mLnResult->setText(QString::number(base->GetResult()));
    }
    catch(const std::string& s)
    {
        ui->mLnResult->setText(QString::fromStdString(s));
        Log(s);
    }
    catch(const std::exception& e)
    {
        ui->mLnResult->setText(QString::fromStdString(e.what()));
        Log(e.what());
    }
    catch(...)
    {
        ui->mLnResult->setText("Unexpected exception!");
        Log("Unexpected exception!");
    }
}
