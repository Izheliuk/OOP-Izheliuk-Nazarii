#include "Cart.h"

Cart::~Cart() {
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
}

void Cart::addToCart(Product* product) {
    ListNode* newNode = new ListNode(product);
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Cart::removeFromCart(Product* product) {
    if (!head)
        return;

    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current) {
        if (current->data == product) {
            if (prev)
                prev->next = current->next;
            else
                head = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

double Cart::getTotal() const {
    double total = 0;
    ListNode* current = head;
    while (current) {
        total += current->data->getPrice();
        current = current->next;
    }
    return total;
}

const ListNode* Cart::getItems() const {
    return head;
}
