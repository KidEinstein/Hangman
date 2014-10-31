#include "dialog.h"
#include "ui_dialog.h"
#include <QtWidgets>
#include "pushButton.h"
#include "functions.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QList<QChar> lettersGuessed;
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








    this->setLayout(layout);
}

Dialog::~Dialog()
{
    delete ui;
}

