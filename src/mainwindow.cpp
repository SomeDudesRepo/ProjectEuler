#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "log.h"
#include "solutions/problems.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mXmlReader(QApplication::applicationDirPath().toStdString() + "/../../xml/parameters.xml")
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
            case 1: base.reset(new Problem001(std::stoi(params[0]),
                                              std::stoi(params[1]),
                                              std::stoi(params[2])));
                    break;
            case 2: base.reset(new Problem002(std::stoi(params[0]))); break;
            case 3: base.reset(new Problem003(std::stoull(params[0]))); break;
            case 4: base.reset(new Problem004(std::stoull(params[0]), std::stoi(params[1]))); break;
            case 5: base.reset(new Problem005(std::stoull(params[0]), std::stoi(params[1]))); break;
            case 6: base.reset(new Problem006(std::stoull(params[0]), std::stoi(params[1]))); break;
            case 7: base.reset(new Problem007(std::stoull(params[0]))); break;
            case 8: base.reset(new Problem008(params[1], std::stoi(params[0]))); break;
            case 9: base.reset(new Problem009); break;
            case 10: base.reset(new Problem010(std::stoull(params[0]))); break;
            case 11: base.reset(new Problem011(std::stoi(params[0]),
                                               std::stoi(params[1]),
                                               params[2]));
                    break;
            default: throw std::string("No other cases yet!");
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
