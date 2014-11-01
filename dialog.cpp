#include "dialog.h"
#include "ui_dialog.h"
#include <QtWidgets>
#include "pushButton.h"
#include "functions.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout(this);
    Button *button[26];
    for(int i=0; i<26; i++)
    {
        button[i] = new Button(this);
        button[i]->setText(QString(i+65));
        if(i<9)
            layout->addWidget(button[i],0,i);
        else if(i>=9 && i<18)
            layout->addWidget(button[i],1,i-9);
        else
            layout->addWidget(button[i],2,i-18);
        connect(button[i],SIGNAL(pressed()),button[i],SLOT(slotButtonClicked()));
    }
    //QLabel *wordLabel = new QLabel(this);
    //ui->listWidget->addItems(ReadWords());
    //QListWidget *wordList = new QListWidget(this);
    //wordList->addItems(ReadWords());
    //layout->addWidget(wordList);
    QString chosenWord=ChooseWord();
    QLabel *label = new QLabel(chosenWord, this);
    layout->addWidget(label);
    letterList = new QListWidget(this);
    letterList->addItems(lettersGuessed);
    layout->addWidget(letterList);









    this->setLayout(layout);
}

Dialog::~Dialog()
{
    delete ui;
}
QList<QString> Dialog::ReadWords()
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

QString Dialog::ChooseWord()
{
    srand (time(NULL));
    QList<QString> *wordList = new QList<QString>(ReadWords());

    QString word=wordList->value(rand() % wordList->length());
    return word;
}

void Dialog::GuessLetter(Button* button)
{
    QString letter = button->text().at(0);
    lettersGuessed.append(letter);
    qDebug()<<lettersGuessed;
    letterList->clear();
    letterList->addItems(lettersGuessed);
    letterList->show();


}
void Button::slotButtonClicked(bool checked)
{
    w.GuessLetter(this);
    this->setDisabled(true);
}
Button::Button(QWidget *parent)
{

}
