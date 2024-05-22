#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
protected:
    std::string name;
    double price;

public:
    virtual ~Product() {}
    Product(std::string name, double price);

    std::string getName() const;

    double getPrice() const;

    virtual std::string getDescription() const = 0;
};

#endif
