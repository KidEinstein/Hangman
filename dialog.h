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
    QList<QString> ReadWords();
    QString ChooseWord();
    void GuessLetter(Button* button);

private:
    Ui::Dialog *ui;
    QList<QString> lettersGuessed;
    QListWidget *letterList;



};

#endif // DIALOG_H
