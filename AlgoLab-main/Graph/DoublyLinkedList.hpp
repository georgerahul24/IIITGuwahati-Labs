#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "UndirectedGraphWithWeights.hpp"
#include <iostream>


class DoublyLinkedList {
public:
    struct Node {
        Vertex *data;
        Node *prev;
        Node *next;
        Vertex *representative;

        Node(Vertex *data) {
            prev = nullptr;
            next = nullptr;
            this->data = data;
            this->representative = nullptr;
        }

        Node(Vertex* data, Vertex *representative) {
            prev = nullptr;
            next = nullptr;
            this->data = data;
            this->representative = representative;
        }
    };


    Node *head;
    Node *tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Function to add an element to the end of the list
    void push_back(Vertex *value) {
        Node *newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void push_back(Vertex *value,Vertex * rep) {
        Node *newNode = new Node(value,rep);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }


    // Function to add an element to the beginning of the list
    void push_front(Vertex* value) {
        Node *newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Function to remove the element at the end of the list
    void pop_back() {
        if (tail != nullptr) {
            Node *temp = tail;
            if (tail == head) {
                head = tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            size--;
        }
    }

    // Function to remove the element at the beginning of the list
    void pop_front() {
        if (head != nullptr) {
            Node *temp = head;
            if (head == tail) {
                head = tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            size--;
        }
    }

    // Function to get the size of the list
    size_t getSize() const {
        return size;
    }

    // Function to check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }


    // Function to display the elements of the list
    void display() const {
        Node *current = head;
        while (current != nullptr) {
            std::cout << current->data->value << "(" <<current->representative->value << ")" << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    static void mergeAndChangeRepresentative(DoublyLinkedList *l1, DoublyLinkedList *l2) {
        l2->tail->next= nullptr;
        l1->tail->next = l2->head;
        l1->tail = l2->tail;
        Vertex* rep = l1->head->representative;
        Node *curr = l2->head;
        while (curr != nullptr) {
            curr->representative = rep;
            curr = curr->next;
        }
        l1->size += l2->size;

    }
    // Function to find the first occurrence of a specific value in the list
    Node *find(Vertex *value) {
        Node *current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;  // Return the node containing the value
            }
            current = current->next;
        }
        return nullptr;  // Value not found
    }


};

#endif // DOUBLYLINKEDLIST_HPP
