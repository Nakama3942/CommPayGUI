#include "aboutprogram.h"
#include "ui_aboutprogram.h"

aboutProgram::aboutProgram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutProgram)
{
    ui->setupUi(this);
}

aboutProgram::~aboutProgram()
{
    delete ui;
}

void aboutProgram::on_close_clicked()
{
    close();
}
