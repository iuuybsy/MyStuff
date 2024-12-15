#ifndef MYSTUFF_LINKED_LIST_H
#define MYSTUFF_LINKED_LIST_H

#include "allocator.h"
#include "exceptions.h"

namespace mystuff {

    template<typename T>
    class LinkedListNode {
    public:
        LinkedListNode* prev;
        LinkedListNode* next;
        T value;

        LinkedListNode() = default;
        LinkedListNode(const T& value) : value(value) {}
        LinkedListNode(T&& value) : value(std::move(value)) {}

        void detach() {
            prev = next = this->self();
        }

        LinkedListNode* self() {
            return static_cast<LinkedListNode*>(&(*this));
        }
    };

    template<typename T>
    class LinkedListIterator {
    public:
        LinkedListNode<T>* node;

        LinkedListIterator() = default;
        LinkedListIterator(LinkedListNode<T>* node) : node(node) {}

        T& operator*() const {
            return node->value;
        }
        T* operator->() const {
            return &node->value;
        }

        LinkedListIterator& operator++() {
            MYSTUFF_DEBUG(node != nullptr);
            node = node->next;
            return *this;
        }

        LinkedListIterator& operator--() {
            MYSTUFF_DEBUG(node != nullptr);
            node = node->prev;
            return *this;
        }

        bool operator==(const LinkedListIterator& other) const {
            return node == other.node;
        }

        bool operator!=(const LinkedListIterator& other) const {
            return node != other.node;
        }
    };

}

#endif //MYSTUFF_LINKED_LIST_H
