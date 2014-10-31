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
    in>>word;
    wordList.append(word);s
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
