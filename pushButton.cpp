#include "dialog.h"
#include "functions.h"
void Button::slotButtonClicked(bool checked)
{
    GuessLetter(this);
    this->setDisabled(true);
    QObject* temp = QObject::sender();

}
Button::Button(QWidget *parent)
{

}
