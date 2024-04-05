#include "Cart.h"
#include "TechProduct.h"
#include "CarProduct.h" 
#include <iostream>

int main() {
    TechProduct* laptop = new TechProduct("Laptop", 1200, "HP");
    TechProduct* smartphone = new TechProduct("Smartphone", 800, "Samsung");
    TechProduct* headphones = new TechProduct("Headphones", 200, "Hator");

    Car* toyota = new Car("Toyota", "Camry", 2022, 25000);

    Cart cart;
    cart.addToCart(laptop);
    cart.addToCart(smartphone);
    cart.addToCart(headphones);
    cart.addToCart(toyota); 

    std::cout << "Total: $" << cart.getTotal() << std::endl;

    std::cout << "Items in cart:" << std::endl;
    for (const auto& item : cart.getItems()) {
        std::cout << item->getDescription() << std::endl;
    }

    cart.removeFromCart(laptop);

    cout << std::endl;

    std::cout << "Total after removal: $" << cart.getTotal() << std::endl;

    std::cout << "Items in cart avter removal:" << std::endl;
    for (const auto& item : cart.getItems()) {
        std::cout << item->getDescription() << std::endl;
    }

    delete laptop;
    delete smartphone;
    delete headphones;
    delete toyota;

    return 0;
}
