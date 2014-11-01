#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
#include "dialog.h"
#include <QDialog>

namespace Ui {
class Button;
}

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = 0);
    //Button();

private slots:
    void slotButtonClicked(bool checked=false);
private:
    Ui::Button *ui;
};

#endif // PUSHBUTTON_H
