#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QtWidgets>
#include "pushButton.h"
QList<QString> ReadWords();
QString ChooseWord();
void GuessLetter(Button button, QList<QChar> lettersGuessed);


#endif // FUNCTIONS_H
