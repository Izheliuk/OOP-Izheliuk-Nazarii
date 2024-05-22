#ifndef INJECTOR_H
#define INJECTOR_H

#include "TechProduct.h"
#include "CarProduct.h"
#include "Cart.h"

class Injector {
public:
    Injector() = default;

    TechProduct* createTechProduct(const std::string& name, double price, const std::string& brand);
    Car* createCar(const std::string& brand, const std::string& model, int year, double price);
    Cart* createCart();
};

#endif 
