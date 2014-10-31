#include "pushButton.h"
void Button::slotButtonClicked(QList<QChar> lettersGuessed);
{
    GuessLetter(this, &lettersGuessed);
    this->setDisabled(true);
}
Button::Button(QWidget *parent)
{

}
