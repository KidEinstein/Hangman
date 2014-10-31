#include "functions.h"
QList<QString> ReadWords()
{
    QList<QString> wordList;
    QString filename=":files/words.txt";
    QFile wordFile(filename);
    wordFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&wordFile);
    QString word;
    while(in>>word)
    {
        wordList.append(word);
    }
    wordList.append(word);
    //QString wordText = in.readAll();
    wordFile.close();
    return wordList;
}

