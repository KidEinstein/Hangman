#include "dialog.h"
#include <QApplication>
#include <QtWidgets>
#include "pushButton.h"

void ReadWords()
{
    QList<QString> wordList;
    QFile wordFile("/words.txt");
    wordFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&wordFile);
    QString word;
    in>>word;
    wordList.append(word);
    //QString wordText = in.readAll();
    wordFile.close();

}
    
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
