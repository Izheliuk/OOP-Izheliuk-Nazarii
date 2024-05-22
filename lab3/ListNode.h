#ifndef LISTNODE_H
#define LISTNODE_H

#include "Product.h"

class ListNode {
public:
    Product* data;
    ListNode* next;

    ListNode(Product* product) : data(product), next(nullptr) {}
};

#endif
