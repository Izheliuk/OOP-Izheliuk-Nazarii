#include "Injector.h"

TechProduct* Injector::createTechProduct(const std::string& name, double price, const std::string& brand) {
    return new TechProduct(name, price, brand);
}

Car* Injector::createCar(const std::string& brand, const std::string& model, int year, double price) {
    return new Car(brand, model, year, price);
}

Cart* Injector::createCart() {
    return new Cart();
}
