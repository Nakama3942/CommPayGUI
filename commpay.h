#ifndef COMMPAY_H
#define COMMPAY_H

#define DEBUG

#include "history.h"
#include "aboutprogram.h"
#include "abouttheme.h"

#include <QTranslator>
#include <QEvent>
#include <QSettings>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QTextStream>
#include <QMessageBox>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CommPay; }
QT_END_NAMESPACE

class CommPay : public QMainWindow
{
    Q_OBJECT

public:
    CommPay(QWidget *parent = nullptr);
    ~CommPay();
    /*
    1 коэффициент - тариф за квартплату
    2 - за электричество до 100 кВт
    3 - за электричество от 100 кВт
    4 - за газ
    5 - за холодную воду
    6 - за гарячую воду
    7 - за отопление
    */
    float coefficient[6] = {}; //Хранит коэффициенты тарифов
    QString LettKeyVal; //Хранит буквенную кодировку валюты пользователся
    QString newtariff;
    int NumKeyVal;
    QDir HistDir;

protected:
    void changeEvent(QEvent * event) override;

private:
    Ui::CommPay *ui;
    QTranslator qtLanguageTranslator;
    QString Operation , TariffSTR, MeterReading, TenantsSTR, Sum, Out, statusOut;
    int CustomValue, Tenants;
    float fee;

private slots:
    void on_Rent_toggled(bool checked);
    void on_Electricity_toggled(bool checked);
    void on_Gas_toggled(bool checked);
    void on_ColdWater_toggled(bool checked);
    void on_HotWater_toggled(bool checked);
    void on_Heating_toggled(bool checked);

    void on_IndiTenants_textChanged();
    void on_Indication_textChanged();
    void Render();

    void on_checkNewTariff_toggled(bool checked);
    void on_safeTariff_clicked();
    void on_recalculate_clicked();
    void on_updateValuta_clicked();

    void on_aboutProgram_triggered();
    void on_aboutQt_triggered();

    void on_saver_clicked();
    void on_open_triggered();
    void on_clear_triggered();

    void on_rusRU_triggered();
    void on_rusUA_triggered();
    void on_uaUA_triggered();
    void on_enUS_triggered();

    void on_light_triggered();
    void on_dark_triggered();
    void on_aboutTheme_triggered();
};
#endif // COMMPAY_H
