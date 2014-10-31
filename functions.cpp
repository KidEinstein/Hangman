#include "functions.h"
QString ReadWords()
{
    QList<QString> wordList;
    QString filename=":files/words.txt";
    QFile wordFile(filename);
    wordFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&wordFile);
    QString word;
    in>>word;
    wordList.append(word);
    //QString wordText = in.readAll();
    wordFile.close();
    return word;
}

