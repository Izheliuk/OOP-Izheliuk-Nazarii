#include "Injector.h"
#include <cassert> // Для використання assert()
#include <iostream>
using namespace std;

void testCartFunctionality() {
    Injector injector;
    Cart* cart = injector.createCart();

    // Test adding products to cart
    assert(cart->getTotal() == 0); // Перевіряємо, що кошик пустий спочатку

    // Додаємо продукти до кошика
    TechProduct* laptop = injector.createTechProduct("Laptop", 1200, "HP");
    cart->addToCart(laptop);
    assert(cart->getTotal() == 1200); // Перевіряємо, що вартість кошика збільшилась

    Car* toyota = injector.createCar("Toyota", "Camry", 2022, 25000);
    cart->addToCart(toyota);
    assert(cart->getTotal() == 26200); // Перевіряємо, що вартість кошика збільшилась ще раз


    cart->removeFromCart(laptop);
    cart->removeFromCart(toyota);
    // Test removing products from cart
    // Створюємо продукти і додаємо їх до кошика
    TechProduct* laptop2 = injector.createTechProduct("Laptop", 1200, "HP");
    cart->addToCart(laptop2);
    Car* toyota2 = injector.createCar("Toyota", "Camry", 2022, 25000);
    cart->addToCart(toyota2);

    // Видаляємо один з продуктів з кошика
    cart->removeFromCart(laptop2);
    assert(cart->getTotal() == 25000); // Перевіряємо, що вартість кошика змінилась

    // Видаляємо всі продукти з кошика
    cart->removeFromCart(toyota2);
    assert(cart->getTotal() == 0); // Перевіряємо, що кошик знову порожній

    delete laptop2;
    delete toyota2;

    delete cart;
    cout << "Everything is fine, great, great" << endl;

}

void testProductClasses() {
    Injector injector;

    // Test TechProduct
    TechProduct* laptop = injector.createTechProduct("Laptop", 1200, "HP");
    assert(laptop->getName() == "Laptop");
    assert(laptop->getPrice() == 1200);
    assert(laptop->getBrand() == "HP");
    assert(laptop->getDescription() == "Tech product: Laptop by HP, price: $1200.000000");

    delete laptop;

    // Test Car
    Car* toyota = injector.createCar("Toyota", "Camry", 2022, 25000);
    assert(toyota->getDescription() == "Car: Toyota Camry (2022, 25000.000000)");

    delete toyota;
    cout << "Everything is fine, great, great";
}

int main() {
    testCartFunctionality();
    testProductClasses();

    return 0;
}
