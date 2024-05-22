#ifndef TECHPRODUCT_H
#define TECHPRODUCT_H

#include "Product.h"
#include <string>

class TechProduct : public Product {
private:
    std::string brand;

public:
    TechProduct(std::string name, double price, std::string brand);

    std::string getBrand() const;

    virtual std::string getDescription() const override;
};

#endif
