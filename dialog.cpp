#include "dialog.h"
#include "ui_dialog.h"
#include <QtWidgets>
#include "functions.h"
#include <QDebug>
#include <QSignalMapper>

QList<QString> lettersGuessed;
QListWidget *letterList;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    layout = new QGridLayout(this);
    CreateButtons();
    //QLabel *wordLabel = new QLabel(this);
    //ui->listWidget->addItems(ReadWords());
    //QListWidget *wordList = new QListWidget(this);
    //wordList->addItems(ReadWords());
    //layout->addWidget(wordList);
    chosenWord=ChooseWord();
    QLabel *label = new QLabel(chosenWord, this);
    layout->addWidget(label);
    letterList = new QListWidget(this);
    letterList->addItems(lettersGuessed);
    layout->addWidget(letterList);
    for(int i=0; i<chosenWord.length(); i++)
    {
        letterLabel[i] =  new QLabel();

    }
    this->setLayout(layout);
}

Dialog::~Dialog()
{
    delete ui;
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

void GuessLetter(Button* button)
{
    QString letter = button->text().at(0);
    lettersGuessed.append(letter);
    qDebug()<<lettersGuessed;
    letterList->clear();
    letterList->addItems(lettersGuessed);
    letterList->show();
}

void Dialog::CreateButtons()
{
    QSignalMapper* signalMapper = new QSignalMapper(this);
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
        //connect(button[i],SIGNAL(pressed()),button[i],SLOT(slotButtonClicked()));
        connect(button[i],SIGNAL(pressed()),this,SLOT(slotButtonClicked()));




    }

}

void Dialog::UpdateLabels()
{



    for(int i=0; i<chosenWord.length(); i++)
    {

        qDebug()<<QString(chosenWord.at(i));
        if(lettersGuessed.contains(QString(chosenWord.at(i)).toUpper()))
        {

            letterLabel[i]->setText(chosenWord.at(i));
        }
        else
        {
            letterLabel[i]->setText("_");
        }



        layout->addWidget(letterLabel[i], 4, i);
        letterLabel[i]->show();

    }

}
void Dialog::slotButtonClicked()
{
    Button* temp = qobject_cast<Button* >(QObject::sender());
    GuessLetter(temp);
    temp->setDisabled(true);
    UpdateLabels();

}


