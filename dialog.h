#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class Button;
}
namespace Ui {
class Dialog;
}
class Button;
class Dialog;
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
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void UpdateLabels();
    ~Dialog();
signals:
    void buttonClicked();
private slots:
    void slotButtonClicked();
private:
    Ui::Dialog *ui;

    void CreateButtons();
    QString chosenWord;
    QLabel *label;
    QGridLayout *layout;
    Button *button[26];
    QLabel *letterLabel[10];


};






#endif // DIALOG_H
