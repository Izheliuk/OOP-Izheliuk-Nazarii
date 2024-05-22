#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Injector.h"
#include "Cart.h"

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
    void on_addProductButton_clicked();
    void on_removeProductButton_clicked();

private:
    Ui::MainWindow *ui;
    Injector injector;
    Cart *cart;
    void updateCartDisplay();
};

#endif // MAINWINDOW_H
