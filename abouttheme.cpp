#include "abouttheme.h"
#include "ui_abouttheme.h"

aboutTheme::aboutTheme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutTheme)
{
    ui->setupUi(this);
}

aboutTheme::~aboutTheme()
{
    delete ui;
}

void aboutTheme::on_close_clicked()
{
    close();
}
