#include "CarProduct.h"

CarProduct::CarProduct(std::string name, double price)
    : Product(name, price) {
}

Car::Car(std::string brand, std::string model, int year, double price)
    : CarProduct("Car", price), brand(brand), model(model), year(year) {
}

std::string Car::getDescription() const {
    return "Car: " + brand + " " + model + " (" + std::to_string(year) + ", " + std::to_string(price) + ")";
}
