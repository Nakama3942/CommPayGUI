#ifndef HISTORY_H
#define HISTORY_H

#include <QFile>

#include <QWidget>

namespace Ui {
class History;
}

class History : public QWidget
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();

private slots:
    void on_closeder_clicked();

private:
    Ui::History *ui;
    QString historyOutput;
};

#endif // HISTORY_H
