#include "dialog.h"
#include "ui_dialog.h"
#include <QtWidgets>
#include "pushButton.h"
#include "functions.h"
QList<QString> *lettersGuessed = new QList<QString>();
QListWidget *letterList;
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
        connect(button[i],SIGNAL(clicked()),button[i],SLOT(slotButtonClicked()));
    }
    //QLabel *wordLabel = new QLabel(this);
    //ui->listWidget->addItems(ReadWords());
    letterList->addItems(*lettersGuessed);
    layout->addWidget(letterList);
    QString chosenWord=ChooseWord();
    QLabel *label = new QLabel(chosenWord, this);
    layout->addWidget(label);








    this->setLayout(layout);
}

Dialog::~Dialog()
{
    delete ui;
}
void updateList()
{
    letterList->addItems(*lettersGuessed);
    letterList->show();

}

void Button::slotButtonClicked(bool checked)
{
    GuessLetter(*lettersGuessed, this);
    updateList();
    this->setDisabled(true);
}
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
    srand (time(NULL));
    QList<QString> *wordList = new QList<QString>(ReadWords());

    QString word=wordList->value(rand() % wordList->length());
    return word;
}

void GuessLetter(QList<QString> lettersGuessed,Button *button)
{
    QString letter = button->text().at(0);
    qDebug()<<button->text().at(0);
    lettersGuessed.append(letter);
    qDebug()<<lettersGuessed.length();

}
