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


    create_gameOver();

    guessesLeft=10;
    guessesLeftLabel = new QLabel("Guesses Left: "+QString::number(guessesLeft),this);
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
    layout->addWidget(guessesLeftLabel);
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
void Dialog::create_gameOver()
{
    gameOver = new QMessageBox(this);
    gameOver->setText("Sorry you ran out of guesses");
    gameOver->addButton(QMessageBox::Close);
    gameOver->addButton(QMessageBox::Reset);
    gameOver->button(QMessageBox::Reset)->setText("New Game");
    gameOver->setIcon(QMessageBox::Warning);
    //connect(gameOver->QMessageBox::Close,SIGNAL()
    connect(gameOver->button(QMessageBox::Close),SIGNAL(clicked()),this,SLOT(close()));
    connect(gameOver->button(QMessageBox::Reset),SIGNAL(clicked()),this,SLOT(reset()));
}

void Dialog::CreateButtons()
{
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



    guessesLeftLabel->setText("Guesses Left: "+QString::number(guessesLeft));
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
    guessesLeft-=1;

    if(guessesLeft==0)
    {
        gameOver->show();
    }


    Button* temp = qobject_cast<Button* >(QObject::sender());
    GuessLetter(temp);
    temp->setDisabled(true);
    UpdateLabels();

}
void Dialog::reset()
{
    if ( this->layout != NULL )
    {
        QLayoutItem* item;
        while ( ( item = this->layout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete this->layout;
    }

    guessesLeft=10;
    guessesLeftLabel = new QLabel("Guesses Left: "+QString::number(guessesLeft),this);
    layout = new QGridLayout(this);
    CreateButtons();
    lettersGuessed.clear();
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


