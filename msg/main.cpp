#include "messagebox.h"
#include <QApplication>
#define A2W(str) QString::fromLocal8Bit(str)

#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CustomMessageBox w(CustomMessageBox::CUSTOM_MESSAGE_QUESTION,QString("提示"),QString("你好，很高兴又和你见面了"));
    w.show();

    return a.exec();
}
