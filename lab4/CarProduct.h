#ifndef CARPRODUCT_H
#define CARPRODUCT_H

#include "Product.h"

class CarProduct : public Product {
public:
    CarProduct(std::string name, double price);

    virtual std::string getDescription() const override = 0;
};

class Car : public CarProduct {
private:
    std::string brand;
    std::string model;
    int year;

public:
    Car(std::string brand, std::string model, int year, double price);

    std::string getDescription() const override;
};

#endif 
