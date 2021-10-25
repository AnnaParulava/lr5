#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qstring.h>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_doubleValidator(-1000, 999999, 6, this)
{
    ui->setupUi(this);
    connect(ui->pushButton_plus, SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_root, SIGNAL(clicked()),this, SLOT(operations()));

    //Обработка вводимых значений
    m_doubleValidator.setNotation(QDoubleValidator::ScientificNotation);
    ui->lineEdit_1->setValidator(&m_doubleValidator);
    ui->lineEdit_2->setValidator(&m_doubleValidator);

    connect(ui->lineEdit_1, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineEdit_2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender(); //на какую кнопку нажали

    double x, y;
    double z = 0;

    //Считаем значение из первого lineEdit
    QString S1 = ui->lineEdit_1->text();
    //Переведем значение в число
    x = S1.toDouble();

    //Считаем значение из второго lineEdit
    QString S2 = ui->lineEdit_2->text();

    //Переведем значение в число
    y = S2.toDouble();

    if(button -> text() == "+"){
        z = x + y;
    }

    else if(button -> text() == "—"){
        z = x - y;
    }

    else if(button -> text() == "×"){
        z = x * y;
    }

    else if(button -> text() == "÷"){
        z = x / y;
    }

    //Выведем результат
    ui->lineEdit_result->setText(QString("%1").arg(z));

    if(button -> text() == "√"){
        QString res = "";
        x = sqrt(x);
        y = sqrt(y);
        res += "x1= " + QString("%1").arg(x);
        res+=" ";
        res += "x2= "+ QString("%1").arg(y);

        ui->lineEdit_result->setText(res);
    }
}



void MainWindow::on_btnClear_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_result->clear();
}

