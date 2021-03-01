#ifndef ABOUTTHEME_H
#define ABOUTTHEME_H

#include <QWidget>

namespace Ui {
class aboutTheme;
}

class aboutTheme : public QWidget
{
    Q_OBJECT

public:
    explicit aboutTheme(QWidget *parent = nullptr);
    ~aboutTheme();

private slots:
    void on_close_clicked();

private:
    Ui::aboutTheme *ui;
};

#endif // ABOUTTHEME_H
