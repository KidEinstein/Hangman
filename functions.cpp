#include "functions.h"
#include "stdlib.h"
#include "pushButton.h"
QList<QString> ReadWords()
{
    QList<QString> wordList;
    QString filename=":files/words.txt";
    QFile wordFile(filename);
    wordFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&wordFile);
    QString word;
    while(!wordFile.atEnd())
    {
        in>>word;
        wordList.append(word);
    }
    wordList.append(word);
    //QString wordText = in.readAll();
    wordFile.close();
    return wordList;
}

QString ChooseWord()
{
    QList<QString> *wordList = new QList<QString>(ReadWords());

    QString word=wordList->value(rand() % wordList->length());
    return word;
}

void GuessLetter(Button button, QList<QChar> lettersGuessed)
{
    QChar letter = button.text();
    lettersGuessed.append(letter);

}
