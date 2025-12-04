#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

class BinarySearchTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;

        Node(char val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertRecursive(Node* current, char val) {
        if (current == nullptr) {
            return new Node(val);
        }

        if (val < current->data) {
            current->left = insertRecursive(current->left, val);
        }
        else {
            current->right = insertRecursive(current->right, val);
        }

        return current;
    }

    void preorderRecursive(Node* current) const {
        if (current == nullptr) return;

        std::cout << current->data; 
        preorderRecursive(current->left);
        preorderRecursive(current->right);
    }

    void destroyRecursive(Node* current) {
        if (current != nullptr) {
            destroyRecursive(current->left);
            destroyRecursive(current->right);
            delete current;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroyRecursive(root);
    }

    void insert(char val) {
        root = insertRecursive(root, val);
    }

    void printPreorder() const {
        preorderRecursive(root);
        std::cout << std::endl; 
    }
    
    bool isEmpty() const {
        return root == nullptr;
    }
    
    void clear() {
        destroyRecursive(root);
        root = nullptr;
    }
};

#endif 