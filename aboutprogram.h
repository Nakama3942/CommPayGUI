#ifndef ABOUTPROGRAM_H
#define ABOUTPROGRAM_H

#include <QWidget>

namespace Ui {
class aboutProgram;
}

class aboutProgram : public QWidget
{
    Q_OBJECT

public:
    explicit aboutProgram(QWidget *parent = nullptr);
    ~aboutProgram();

private slots:
    void on_close_clicked();

private:
    Ui::aboutProgram *ui;
};

#endif // ABOUTPROGRAM_H
