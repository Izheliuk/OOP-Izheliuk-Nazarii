#include "TechProduct.h"

TechProduct::TechProduct(std::string name, double price, std::string brand) : Product(name, price), brand(brand) {}

std::string TechProduct::getBrand() const {
    return brand;
}

std::string TechProduct::getDescription() const {
    return "Tech product: " + getName() + " by " + getBrand() + ", price: $" + std::to_string(getPrice());
}
