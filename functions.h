#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QtWidgets>
QList<QString> ReadWords();
QString ChooseWord();
void Button::slotButtonClicked(QList<QChar> lettersGuessed);
#endif // FUNCTIONS_H
