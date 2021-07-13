#include "commpay.h"
#include "ui_commpay.h"

CommPay::CommPay(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommPay)
{
    ui->setupUi(this);

    //Если загрузка успешна - устанавливаю перевод, а после - перевожу интерфейс
    if(qtLanguageTranslator.load("languages/CommPay_ru_RU.qm"))
        qApp->installTranslator(&qtLanguageTranslator);
    ui->retranslateUi(this);
}
CommPay::~CommPay()
{
    delete ui;
}

void CommPay::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
        ui->retranslateUi(this);
}

void CommPay::on_Rent_toggled(bool checked)
{
    if (checked)
    {
        //Настраиваю отображение некоторых полей
        ui->IndiTenants->setEnabled(true);
        ui->Indication->setEnabled(true);
        ui->inputIndication->setEnabled(true);
        ui->tenants->setEnabled(true);
        //Настраиваю диалог общения с пользователем
        ui->inputIndication->setText("Площадь квартиры: ");
        ui->tenants->setText("Количество проживающих: ");
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[0]), LettKeyVal));
        QSettings *namePersonalValuta = new QSettings("Config.ini", QSettings::IniFormat);
        QString PersonalValuta = namePersonalValuta->value(QString("ValutaName/%1").arg(QString::number(NumKeyVal))).toString();
        delete namePersonalValuta;
        ui->namePersonValuta->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Ваша валюта: %1</span></p></body></html>").arg(PersonalValuta));
        ui->Indication->setText("\0");
        on_IndiTenants_textChanged();
    }
    else
    {
        ui->IndiTenants->setEnabled(false);
        ui->Indication->setEnabled(false);
        ui->inputIndication->setEnabled(false);
        ui->tenants->setEnabled(false);
    }
}

void CommPay::on_Electricity_toggled(bool checked)
{
    if (checked)
    {
        //Настраиваю отображение некоторых полей
        ui->Indication->setEnabled(true);
        ui->inputIndication->setEnabled(true);
        //Настраиваю диалог общения с пользователем
        ui->inputIndication->setText("Количество кВт/час, использованных за месяц: ");
        ui->tenants->setText("Количество проживающих (ненужно)");
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[1]), LettKeyVal));
        QSettings *namePersonalValuta = new QSettings("Config.ini", QSettings::IniFormat);
        QString PersonalValuta = namePersonalValuta->value(QString("ValutaName/%1").arg(QString::number(NumKeyVal))).toString();
        delete namePersonalValuta;
        ui->namePersonValuta->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Ваша валюта: %1</span></p></body></html>").arg(PersonalValuta));
        ui->IndiTenants->setText(0);
        ui->Indication->setText("\0");
        on_Indication_textChanged();
    }
    else
    {
        ui->Indication->setEnabled(false);
        ui->inputIndication->setEnabled(false);
    }
}

void CommPay::on_Gas_toggled(bool checked)
{
    if (checked)
    {
        //Настраиваю отображение некоторых полей
        ui->Indication->setEnabled(true);
        ui->inputIndication->setEnabled(true);
        //Настраиваю диалог общения с пользователем
        ui->inputIndication->setText("Количество кубометров, использованных за месяц: ");
        ui->tenants->setText("Количество проживающих (ненужно)");
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[2]), LettKeyVal));
        QSettings *namePersonalValuta = new QSettings("Config.ini", QSettings::IniFormat);
        QString PersonalValuta = namePersonalValuta->value(QString("ValutaName/%1").arg(QString::number(NumKeyVal))).toString();
        delete namePersonalValuta;
        ui->namePersonValuta->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Ваша валюта: %1</span></p></body></html>").arg(PersonalValuta));
        ui->IndiTenants->setText(0);
        ui->Indication->setText("\0");
        on_Indication_textChanged();
    }
    else
    {
        ui->Indication->setEnabled(false);
        ui->inputIndication->setEnabled(false);
    }
}

void CommPay::on_ColdWater_toggled(bool checked)
{
    if (checked)
    {
        //Настраиваю отображение некоторых полей
        ui->Indication->setEnabled(true);
        ui->inputIndication->setEnabled(true);
        //Настраиваю диалог общения с пользователем
        ui->inputIndication->setText("Количество кубометров, использованных за месяц: ");
        ui->tenants->setText("Количество проживающих (ненужно)");
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[3]), LettKeyVal));
        QSettings *namePersonalValuta = new QSettings("Config.ini", QSettings::IniFormat);
        QString PersonalValuta = namePersonalValuta->value(QString("ValutaName/%1").arg(QString::number(NumKeyVal))).toString();
        delete namePersonalValuta;
        ui->namePersonValuta->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Ваша валюта: %1</span></p></body></html>").arg(PersonalValuta));
        ui->IndiTenants->setText(0);
        ui->Indication->setText("\0");
        on_Indication_textChanged();
    }
    else
    {
        ui->Indication->setEnabled(false);
        ui->inputIndication->setEnabled(false);
    }
}

void CommPay::on_HotWater_toggled(bool checked)
{
    if (checked)
    {
        //Настраиваю отображение некоторых полей
        ui->Indication->setEnabled(true);
        ui->inputIndication->setEnabled(true);
        //Настраиваю диалог общения с пользователем
        ui->inputIndication->setText("Количество кубометров, использованных за месяц: ");
        ui->tenants->setText("Количество проживающих (ненужно)");
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[4]), LettKeyVal));
        QSettings *namePersonalValuta = new QSettings("Config.ini", QSettings::IniFormat);
        QString PersonalValuta = namePersonalValuta->value(QString("ValutaName/%1").arg(QString::number(NumKeyVal))).toString();
        delete namePersonalValuta;
        ui->namePersonValuta->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Ваша валюта: %1</span></p></body></html>").arg(PersonalValuta));
        ui->IndiTenants->setText(0);
        ui->Indication->setText("\0");
        on_Indication_textChanged();
    }
    else
    {
        ui->Indication->setEnabled(false);
        ui->inputIndication->setEnabled(false);
    }
}

void CommPay::on_Heating_toggled(bool checked)
{
    if (checked)
    {
        //Настраиваю отображение некоторых полей
        ui->Indication->setEnabled(true);
        ui->inputIndication->setEnabled(true);
        //Настраиваю диалог общения с пользователем
        ui->inputIndication->setText("Общая площадь квартиры: ");
        ui->tenants->setText("Количество проживающих (ненужно)");
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[5]), LettKeyVal));
        QSettings *namePersonalValuta = new QSettings("Config.ini", QSettings::IniFormat);
        QString PersonalValuta = namePersonalValuta->value(QString("ValutaName/%1").arg(QString::number(NumKeyVal))).toString();
        delete namePersonalValuta;
        ui->namePersonValuta->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Ваша валюта: %1</span></p></body></html>").arg(PersonalValuta));
        ui->IndiTenants->setText(0);
        ui->Indication->setText("\0");
        on_Indication_textChanged();
    }
    else
    {
        ui->Indication->setEnabled(false);
        ui->inputIndication->setEnabled(false);
    }
}

void CommPay::on_IndiTenants_textChanged()
{
    Render();
}

void CommPay::on_Indication_textChanged()
{
    Render();
}

void CommPay::Render()
{
    QString CustomValueSTR = ui->Indication->text();
    CustomValue = CustomValueSTR.toInt();
    if (ui->Rent->isChecked() == 1)
    {
        QString TenantsSTR = ui->IndiTenants->text();
        Tenants = TenantsSTR.toInt();
        fee = Tenants * CustomValue * coefficient[0];
    }
    else if (ui->Electricity->isChecked() == 1)
        fee = CustomValue * coefficient[1];

    else if (ui->Gas->isChecked() == 1)
        fee = CustomValue * coefficient[2];

    else if (ui->ColdWater->isChecked() == 1)
        fee = CustomValue * coefficient[3];

    else if (ui->HotWater->isChecked() == 1)
        fee = CustomValue * coefficient[4];

    else if (ui->Heating->isChecked() == 1)
        fee = CustomValue * coefficient[5];

    QString feeSTR = QString::number(fee);
    ui->Result->setText(QString("%1 %2").arg(feeSTR, LettKeyVal));
}

void CommPay::on_checkNewTariff_toggled(bool checked)
{
    if (checked)
    {
        ui->NewTariff->setEnabled(true);
        ui->safeTariff->setEnabled(true);
    }
    else
    {
        ui->NewTariff->setEnabled(false);
        ui->safeTariff->setEnabled(false);
    }
}

void CommPay::on_safeTariff_clicked()
{
    QSettings *updateCoef = new QSettings("Config.ini", QSettings::IniFormat);
    if (ui->Rent->isChecked() == 1 && ui->NewTariff->text() != "\0")
    {
        updateCoef->setValue("Coefficient/Rent", ui->NewTariff->text());
        updateCoef->sync();
        coefficient[0] = updateCoef->value("Coefficient/Rent").toFloat();
    }
    else if (ui->Electricity->isChecked() == 1 && ui->NewTariff->text() != "\0")
    {
        updateCoef->setValue("Coefficient/Electricity", ui->NewTariff->text());
        updateCoef->sync();
        coefficient[1] = updateCoef->value("Coefficient/Electricity").toFloat();
    }
    else if (ui->Gas->isChecked() == 1 && ui->NewTariff->text() != "\0")
    {
        updateCoef->setValue("Coefficient/Gas", ui->NewTariff->text());
        updateCoef->sync();
        coefficient[2] = updateCoef->value("Coefficient/Gas").toFloat();
    }
    else if (ui->ColdWater->isChecked() == 1 && ui->NewTariff->text() != "\0")
    {
        updateCoef->setValue("Coefficient/ColdWater", ui->NewTariff->text());
        updateCoef->sync();
        coefficient[3] = updateCoef->value("Coefficient/ColdWater").toFloat();
    }
    else if (ui->HotWater->isChecked() == 1 && ui->NewTariff->text() != "\0")
    {
        updateCoef->setValue("Coefficient/HotWater", ui->NewTariff->text());
        updateCoef->sync();
        coefficient[4] = updateCoef->value("Coefficient/HotWater").toFloat();
    }
    else if (ui->Heating->isChecked() == 1 && ui->NewTariff->text() != "\0")
    {
        updateCoef->setValue("Coefficient/Heating", ui->NewTariff->text());
        updateCoef->sync();
        coefficient[5] = updateCoef->value("Coefficient/Heating").toFloat();
    }
    delete updateCoef;
    ui->statusbar->showMessage("Ваш тариф установлен");
}

void CommPay::on_recalculate_clicked()
{
    Render();
    if (ui->Rent->isChecked() != 0)
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[0]), LettKeyVal));

    else if (ui->Electricity->isChecked() != 0)
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[1]), LettKeyVal));

    else if (ui->Gas->isChecked() != 0)
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[2]), LettKeyVal));

    else if (ui->ColdWater->isChecked() != 0)
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[3]), LettKeyVal));

    else if (ui->HotWater->isChecked() != 0)
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[4]), LettKeyVal));

    else if (ui->Heating->isChecked() != 0)
        ui->tariffValue->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Тариф составляет: %1 %2</span></p></body></html>").arg(QString::number(coefficient[5]), LettKeyVal));

    QSettings *namePersonalValuta = new QSettings("Config.ini", QSettings::IniFormat);
    QString PersonalValuta = namePersonalValuta->value(QString("ValutaName/%1").arg(QString::number(NumKeyVal))).toString();
    delete namePersonalValuta;
    ui->namePersonValuta->setText(QString("<html><head/><body><p><span style=\" font-size:11pt;\">Ваша валюта: %1</span></p></body></html>").arg(PersonalValuta));
}

void CommPay::on_updateValuta_clicked()
{
    QSettings *updatePersonValuta = new QSettings("Config.ini", QSettings::IniFormat);
    if (ui->USD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 840);

    else if (ui->EUR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 978);

    else if (ui->GBP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 826);

    else if (ui->JPY->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 392);

    else if (ui->CHF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 756);

    else if (ui->UAH->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 980);

    else if (ui->RUB->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 643);

    else if (ui->BYN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 933);

    else if (ui->CNY->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 156);

    else if (ui->AED->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 784);

    else if (ui->AFN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 971);

    else if (ui->ALL->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 118);

    else if (ui->AMD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 251);

    else if (ui->AOA->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 973);

    else if (ui->ARS->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 132);

    else if (ui->AUD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 136);

    else if (ui->AZN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 944);

    else if (ui->BDT->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 151);

    else if (ui->BGN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 975);

    else if (ui->BHD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 148);

    else if (ui->BIF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 118);

    else if (ui->BND->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 196);

    else if (ui->BOB->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 168);

    else if (ui->BRL->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 986);

    else if (ui->BWP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 172);

    else if (ui->CAD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 124);

    else if (ui->CDF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 976);

    else if (ui->CLP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 152);

    else if (ui->COP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 170);

    else if (ui->CRC->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 188);

    else if (ui->CUP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 192);

    else if (ui->CZK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 203);

    else if (ui->DJF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 262);

    else if (ui->DKK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 208);

    else if (ui->DZD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 112);

    else if (ui->EGP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 818);

    else if (ui->ETB->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 230);

    else if (ui->GEL->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 981);

    else if (ui->GHS->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 936);

    else if (ui->GMD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 270);

    else if (ui->GNF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 324);

    else if (ui->HKD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 344);

    else if (ui->HRK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 191);

    else if (ui->HUF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 348);

    else if (ui->IDR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 360);

    else if (ui->ILS->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 376);

    else if (ui->INR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 356);

    else if (ui->IQD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 368);

    else if (ui->IRR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 364);

    else if (ui->ISK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 352);

    else if (ui->JOD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 400);

    else if (ui->KES->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 404);

    else if (ui->KGS->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 417);

    else if (ui->KHR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 116);

    else if (ui->KPW->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 408);

    else if (ui->KRW->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 410);

    else if (ui->KWD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 414);

    else if (ui->KZT->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 398);

    else if (ui->LAK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 418);

    else if (ui->LBP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 422);

    else if (ui->LKR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 144);

    else if (ui->LYD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 434);

    else if (ui->MAD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 504);

    else if (ui->MDL->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 498);

    else if (ui->MGA->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 969);

    else if (ui->MKD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 807);

    else if (ui->MNT->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 496);

    else if (ui->MRO->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 478);

    else if (ui->MUR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 480);

    else if (ui->MVR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 462);

    else if (ui->MWK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 454);

    else if (ui->MXN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 484);

    else if (ui->MYR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 458);

    else if (ui->MZN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 943);

    else if (ui->NAD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 516);

    else if (ui->NGN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 566);

    else if (ui->NIO->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 558);

    else if (ui->NOK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 578);

    else if (ui->NPR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 524);

    else if (ui->NZD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 554);

    else if (ui->OMR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 512);

    else if (ui->PEN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 604);

    else if (ui->PHP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 608);

    else if (ui->PKR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 586);

    else if (ui->PLN->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 985);

    else if (ui->PYG->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 600);

    else if (ui->QAR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 634);

    else if (ui->RON->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 946);

    else if (ui->RSD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 941);

    else if (ui->SAR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 682);

    else if (ui->SCR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 690);

    else if (ui->SDG->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 938);

    else if (ui->SEK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 752);

    else if (ui->SGD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 702);

    else if (ui->SLL->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 694);

    else if (ui->SOS->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 706);

    else if (ui->SRD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 968);

    else if (ui->SYP->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 760);

    else if (ui->SZL->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 748);

    else if (ui->THB->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 764);

    else if (ui->TJS->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 972);

    else if (ui->TMT->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 795);

    else if (ui->TND->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 788);

    else if (ui->TRY->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 949);

    else if (ui->TWD->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 901);

    else if (ui->TZS->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 834);

    else if (ui->UGX->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 800);

    else if (ui->UYU->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 858);

    else if (ui->UZS->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 860);

    else if (ui->VEF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 937);

    else if (ui->VND->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 704);

    else if (ui->XAF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 950);

    else if (ui->XDR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 960);

    else if (ui->XOF->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 952);

    else if (ui->YER->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 886);

    else if (ui->ZAR->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 710);

    else if (ui->ZMK->isChecked() == 1)
        updatePersonValuta->setValue("Valuta/Personal", 894);

    updatePersonValuta->sync();
    NumKeyVal = updatePersonValuta->value("Valuta/Personal").toFloat();
    QSettings *upgradePersonValuta = new QSettings("Config.ini", QSettings::IniFormat);
    LettKeyVal = upgradePersonValuta->value(QString("ValutaCODE/%1").arg(QString::number(NumKeyVal))).toString();
    delete upgradePersonValuta;
    delete updatePersonValuta;
    ui->statusbar->showMessage("Ваша валюта изменена");
}

void CommPay::on_aboutProgram_triggered()
{
    aboutProgram *abProg = new aboutProgram;
    abProg->show();
}

void CommPay::on_aboutQt_triggered()
{
    QMessageBox::aboutQt(this, "Про Qt");
}

void CommPay::on_saver_clicked()
{
    //Беру текущее время из системы
    QDateTime TimeForRecording(QDateTime::currentDateTime());
    QString Date = TimeForRecording.date().toString(), Time = TimeForRecording.time().toString();
    MeterReading = ui->Indication->text();
    Sum = QString::number(fee);
    if (ui->Rent->isChecked() == 1)
    {
        Operation = "Квартплата";
        TariffSTR = QString::number(coefficient[0]);
        TenantsSTR = ui->IndiTenants->text();
        Out = Date + " " + Time + " " + Operation + ":\tтариф - " + TariffSTR + " , площадь - " + MeterReading + " , проживающих - " + TenantsSTR + " , сумма - " + Sum;
    }
    else if (ui->Electricity->isChecked() == 1)
    {
        Operation = "Электричество";
        TariffSTR = QString::number(coefficient[1]);
        Out = Date + " " + Time + " " + Operation + ":\tтариф - " + TariffSTR + " , показания - " + MeterReading + " , сумма - " + Sum;
    }
    else if (ui->Gas->isChecked() == 1)
    {
        Operation = "Газ";
        TariffSTR = QString::number(coefficient[2]);
        Out = Date + " " + Time + " " + Operation + ":\t\tтариф - " + TariffSTR + " , показания - " + MeterReading + " , сумма - " + Sum;
    }
    else if (ui->ColdWater->isChecked() == 1)
    {
        Operation = "Холодная вода";
        TariffSTR = QString::number(coefficient[3]);
        Out = Date + " " + Time + " " + Operation + ":\tтариф - " + TariffSTR + " , показания - " + MeterReading + " , сумма - " + Sum;
    }
    else if (ui->HotWater->isChecked() == 1)
    {
        Operation = "Горячая вода";
        TariffSTR = QString::number(coefficient[4]);
        Out = Date + " " + Time + " " + Operation + ":\tтариф - " + TariffSTR + " , показания - " + MeterReading + " , сумма - " + Sum;
    }
    else if (ui->Heating->isChecked() == 1)
    {
        Operation = "Отопление";
        TariffSTR = QString::number(coefficient[5]);
        Out = Date + " " + Time + " " + Operation + ":\tтариф - " + TariffSTR + " , показания - " + MeterReading + " , сумма - " + Sum;
    }
    statusOut = "Сохранено: "+ Out;
    ui->statusbar->showMessage(statusOut);
    //Открываю файл, где будет храниться история
    QFile history("History.txt");
    if (history.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append | QIODevice::ExistingOnly))
    {
        QTextStream Dopys(&history);
        Dopys << Out << Qt::endl;
    }
    history.close();
}

void CommPay::on_open_triggered()
{
    History *hist = new History;
    hist->show();
}

void CommPay::on_clear_triggered()
{
    QMessageBox Warn;
    Warn.setIcon(QMessageBox::Warning);
    Warn.setText("Очистить историю?");
    Warn.setInformativeText("Это удалит всю историю за всё время! Будьте внимательны!");
    Warn.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    Warn.setDefaultButton(QMessageBox::Cancel);
    int clearer = Warn.exec();
    switch (clearer)
    {
    case QMessageBox::Cancel:
        break;
    case QMessageBox::Yes:
        QFile history("History.txt");
        if (history.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::ExistingOnly))
            history.close();
        break;
    }
    ui->statusbar->showMessage("История очищена");
}

void CommPay::on_rusRU_triggered()
{
    //Если загрузка успешна - устанавливаю перевод, а после - перевожу интерфейс
    if(qtLanguageTranslator.load("languages/CommPay_ru_RU.qm"))
        qApp->installTranslator(&qtLanguageTranslator);
    ui->retranslateUi(this);

    ui->statusbar->showMessage("Установлен язык: Русский (Россия)");
}

void CommPay::on_rusUA_triggered()
{
    //Если загрузка успешна - устанавливаю перевод, а после - перевожу интерфейс
    if(qtLanguageTranslator.load("languages/CommPay_ru_UA.qm"))
        qApp->installTranslator(&qtLanguageTranslator);
    ui->retranslateUi(this);

    ui->statusbar->showMessage("Установлен язык: Русский (Украина)");
}

void CommPay::on_uaUA_triggered()
{
    //Если загрузка успешна - устанавливаю перевод, а после - перевожу интерфейс
    if(qtLanguageTranslator.load("languages/CommPay_uk_UA.qm"))
        qApp->installTranslator(&qtLanguageTranslator);
    ui->retranslateUi(this);

    ui->statusbar->showMessage("Установлен язык: Украинский");
}

void CommPay::on_enUS_triggered()
{
    //Если загрузка успешна - устанавливаю перевод, а после - перевожу интерфейс
    if(qtLanguageTranslator.load("languages/CommPay_en_US.qm"))
        qApp->installTranslator(&qtLanguageTranslator);
    ui->retranslateUi(this);

    ui->statusbar->showMessage("Установлен язык: Английский (США)");
}

void CommPay::on_light_triggered()
{
    //Сохраняю тему пользователя
    QSettings *Theme = new QSettings("Config.ini", QSettings::IniFormat);
    Theme->setValue("Pattern/Theme", "light");
    delete Theme;
    //Устанавливаю stylesheet
    QFile Style("BreezeStyleSheets/light.qss");
    Style.open(QFile::ReadOnly | QFile::Text);
    QTextStream StyleStream(&Style);
    qApp->setStyleSheet(StyleStream.readAll());
}

void CommPay::on_dark_triggered()
{
    //Сохраняю тему пользователя
    QSettings *Theme = new QSettings("Config.ini", QSettings::IniFormat);
    Theme->setValue("Pattern/Theme", "dark");
    delete Theme;
    //Устанавливаю stylesheet
    QFile Style("BreezeStyleSheets/dark.qss");
    Style.open(QFile::ReadOnly | QFile::Text);
    QTextStream StyleStream(&Style);
    qApp->setStyleSheet(StyleStream.readAll());
}

void CommPay::on_aboutTheme_triggered()
{
    aboutTheme *abTheme = new aboutTheme;
    abTheme->show();
}
