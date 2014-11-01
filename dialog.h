#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "pushButton.h"
#include <QtWidgets>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    Ui::Dialog *ui;
    void UpdateLabels();
    void CreateButtons();
    QString chosenWord;
    QLabel *label;
    QGridLayout *layout;

};

#endif // DIALOG_H
