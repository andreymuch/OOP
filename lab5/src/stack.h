#pragma once
#include <iostream>
#include <iterator>
#include <memory_resource>

template <typename T>
class Stack {
private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head = nullptr;
    std::pmr::polymorphic_allocator<Node> allocator;

public:
    Stack(std::pmr::memory_resource* resource) : allocator(resource) {}
    Stack(const Stack& other) = default;

    ~Stack() {
        while (head) {
            Node* temp = head;
            head = head->next;
            allocator.destroy(temp);
            allocator.deallocate(temp, 1);
        }
    }
    Stack& operator= (const Stack& other) = default;

    void push(const T& value) {
        Node* new_node = allocator.allocate(1);
        allocator.construct(new_node, Node{value, head});
        head = new_node;
    }

    void pop() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        allocator.destroy(temp);
        allocator.deallocate(temp, 1);
    }

    T& top() {
        if (!head) {
            throw std::runtime_error("Стек пуст!");
        }
        return head->value;
    }

    bool empty() const {
        return head == nullptr;
    }

    class Iterator {
    private:
        Node* current;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* node) : current(node) {}

        T& operator*() const { return current->value; }
        T* operator->() const { return &(current->value); }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }


        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};
