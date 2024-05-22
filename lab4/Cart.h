// Cart.h
#ifndef CART_H
#define CART_H

#include "ListNode.h"

class Cart {
private:
    ListNode* head;

public:
    Cart() : head(nullptr) {}
    ~Cart();

    void addToCart(Product* product);
    void removeFromCart(Product* product);
    double getTotal() const;
    const ListNode* getItems() const;
};

#endif // CART_H
