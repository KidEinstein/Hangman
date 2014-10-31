
#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>
namespace Ui {
class Button;
}

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button();
    ~Button();
private slots:
    void slotButtonClicked(bool checked=false);
private:
    Ui::Button *ui;
};

#endif // PUSHBUTTON_H
