#include "commpay.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CommPay w;
    //Загружаю тему пользователя
    QString personalTheme, personalThemeLoader;
    QSettings *Presetting = new QSettings("Config.ini", QSettings::IniFormat);
    personalTheme = Presetting->value("Pattern/Theme").toString();
    personalThemeLoader = "BreezeStyleSheets/" + personalTheme + ".qss";
    //Устанавливаю stylesheet
    QFile Style(personalThemeLoader);
    Style.open(QFile::ReadOnly | QFile::Text);
    QTextStream StyleStream(&Style);
    qApp->setStyleSheet(StyleStream.readAll());
    //Считываю значения тарифов
    w.coefficient[0] = Presetting->value("Coefficient/Rent").toFloat();
    w.coefficient[1] = Presetting->value("Coefficient/Electricity").toFloat();
    w.coefficient[2] = Presetting->value("Coefficient/Gas").toFloat();
    w.coefficient[3] = Presetting->value("Coefficient/ColdWater").toFloat();
    w.coefficient[4] = Presetting->value("Coefficient/HotWater").toFloat();
    w.coefficient[5] = Presetting->value("Coefficient/Heating").toFloat();
    //Считываю значение валюты пользователя в цифровом виде
    w.NumKeyVal = Presetting->value("Valuta/Personal").toFloat();
    //Перевожу валюту пользователя цифрового вида в буквенную с помощыю кодировок второго файла
    w.LettKeyVal = Presetting->value(QString("ValutaCODE/%1").arg(QString::number(w.NumKeyVal))).toString();
    //Закрываю ini-файлы
    delete Presetting;
    //Отображаю окно программы
    w.show();
    return a.exec();
}
