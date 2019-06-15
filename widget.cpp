// 无边框窗口示例
// 左键点击可拖动窗口
// 右键点击可关闭窗口
//

#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 去边框
    // 去除边框 加上原本的窗口属性
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    // 设置边框透明
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap(":/res/qq.png"));
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - p);
    }

    //qDebug() << QString(__func__);
    // 获取窗口坐上脚坐标
    // 我写的 失败
//    int gX = event->globalX();
//    int gY = event->globalY();

//    int x = event->x();
//    int y = event->y();

//    int tempX = gX - x;
//    int tempY = gY - y;

//    this->resize(tempX, tempY);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        // 右击鼠标关闭窗口
        close();
    }
    else if(event->button() == Qt::LeftButton)
    {
        // 左击鼠标
        // 参考视频
        p = event->globalPos() - this->frameGeometry().topLeft();

        // 我写的 失败
//        int gX = event->globalX();
//        int gY = event->globalY();

//        int x = event->x();
//        int y = event->y();

//        int tempX = gX - x;
//        int tempY = gY - y;

//        this->move(tempX, tempY);
        //update();
    }
}
