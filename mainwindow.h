#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDoubleValidator>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void operations();
    void on_changed();

    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
    QDoubleValidator m_doubleValidator;
};
#endif // MAINWINDOW_H
