#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QtWidgets>
#include "pushButton.h"
QList<QString> ReadWords();
QString ChooseWord();
void GuessLetter(QList<QString> lettersGuessed, Button* button);


#endif // FUNCTIONS_H
