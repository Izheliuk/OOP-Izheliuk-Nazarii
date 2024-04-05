#include "Cart.h"

void Cart::addToCart(Product* product) {
    items.push_back(product);
}

double Cart::getTotal() const {
    double total = 0;
    for (const auto& item : items) {
        total += item->getPrice();
    }
    return total;
}

const std::vector<Product*>& Cart::getItems() const {
    return items;
}

void Cart::removeFromCart(Product* product) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == product) {
            delete *it; 
            items.erase(it); 
            return; 
        }
    }
}