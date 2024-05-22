#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , cart(injector.createCart())
{
    ui->setupUi(this);

    connect(ui->addProductButton, &QPushButton::clicked, this, &MainWindow::on_addProductButton_clicked);
    connect(ui->removeProductButton, &QPushButton::clicked, this, &MainWindow::on_removeProductButton_clicked);
}

MainWindow::~MainWindow()
{
    delete cart;
    delete ui;
}

void MainWindow::on_addProductButton_clicked()
{
    TechProduct* laptop = injector.createTechProduct("Laptop", 1200, "HP");
    TechProduct* smartphone = injector.createTechProduct("Smartphone", 800, "Samsung");
    TechProduct* headphones = injector.createTechProduct("Headphones", 200, "Hator");
    Car* toyota = injector.createCar("Toyota", "Camry", 2022, 25000);

    cart->addToCart(laptop);
    cart->addToCart(smartphone);
    cart->addToCart(headphones);
    cart->addToCart(toyota);

    updateCartDisplay();
}

void MainWindow::on_removeProductButton_clicked()
{
    QListWidgetItem* selectedItem = ui->cartListWidget->currentItem();
    if (selectedItem) {
        std::string description = selectedItem->text().toStdString();
        const ListNode* current = cart->getItems();
        while (current) {
            if (current->data->getDescription() == description) {
                cart->removeFromCart(current->data);
                delete current->data; // Видаляємо продукт з пам'яті
                break;
            }
            current = current->next;
        }
        updateCartDisplay();
    }
}

void MainWindow::updateCartDisplay()
{
    ui->cartListWidget->clear();
    const ListNode* current = cart->getItems();
    while (current) {
        ui->cartListWidget->addItem(QString::fromStdString(current->data->getDescription()));
        current = current->next;
    }
    ui->totalLabel->setText("Total: $" + QString::number(cart->getTotal()));
}
