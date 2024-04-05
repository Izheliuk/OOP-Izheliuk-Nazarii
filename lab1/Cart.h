#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"

using namespace std;

class Cart {
private:
    std::vector<Product*> items;

public:
    void addToCart(Product* product);

    void removeFromCart(Product* product);

    double getTotal() const;

    const std::vector<Product*>& getItems() const;
};

#endif 