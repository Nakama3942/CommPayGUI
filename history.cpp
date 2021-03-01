#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    //Открываю файл, где будет храниться история
    QFile history("History.txt");
    if (history.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream Dopys(&history);
        historyOutput = Dopys.readAll();
    }
    history.close();
    ui->Hist->setReadOnly(true);
    ui->Hist->setText(historyOutput);
}

History::~History()
{
    delete ui;
}

void History::on_closeder_clicked()
{
    close();
}
