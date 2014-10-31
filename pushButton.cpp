#include "pushButton.h"
#include "functions.h"
void Button::slotButtonClicked(bool checked)
{
    GuessLetter(this);
    this->setDisabled(true);
}
Button::Button(QWidget *parent)
{

}
