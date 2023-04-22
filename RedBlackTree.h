#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <chrono>
class RedBlackTree {
    enum Color { RED, BLACK };

    class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node* parent;
        Color color;

        Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
    };
private:
    Node* root;

    void leftRotate(Node* node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;

        if (rightChild->left != nullptr) {
            rightChild->left->parent = node;
        }

        rightChild->parent = node->parent;

        if (node->parent == nullptr) {
            root = rightChild;
        }
        else if (node == node->parent->left) {
            node->parent->left = rightChild;
        }
        else {
            node->parent->right = rightChild;
        }

        rightChild->left = node;
        node->parent = rightChild;
    }

    void rightRotate(Node* node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;

        if (leftChild->right != nullptr) {
            leftChild->right->parent = node;
        }

        leftChild->parent = node->parent;

        if (node->parent == nullptr) {
            root = leftChild;
        }
        else if (node == node->parent->right) {
            node->parent->right = leftChild;
        }
        else {
            node->parent->left = leftChild;
        }

        leftChild->right = node;
        node->parent = leftChild;
    }

    void fixInsert(Node* node) {
        while (node != root && node->parent->color == RED) {
            if (node->parent == node->parent->parent->left) {
                Node* rightUncle = node->parent->parent->right;

                if (rightUncle != nullptr && rightUncle->color == RED) {
                    node->parent->color = BLACK;
                    rightUncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        leftRotate(node);
                    }

                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rightRotate(node->parent->parent);
                }
            }
            else {
                Node* leftUncle = node->parent->parent->left;

                if (leftUncle != nullptr && leftUncle->color == RED) {
                    node->parent->color = BLACK;
                    leftUncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rightRotate(node);
                    }

                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    leftRotate(node->parent->parent);
                }
            }
        }

        root->color = BLACK;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }

        v->parent = u->parent;
    }

    Node* treeMinimum(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    void fixDelete(Node* node) {
        while (node != root && node->color == BLACK) {
            if (node == node->parent->left) {
                Node* sibling = node->parent->right;

                if (sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    leftRotate(node->parent);
                    sibling = node->parent->right;
                }

                if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                    sibling->color = RED;
                    node = node->parent;
                }
                else {
                    if (sibling->right->color == BLACK) {
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rightRotate(sibling);
                        sibling = node->parent->right;
                    }

                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    leftRotate(node->parent);
                    node = root;
                }
            }
            else {
                Node* sibling = node->parent->left;

                if (sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    rightRotate(node->parent);
                    sibling = node->parent->left;
                }

                if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                    sibling->color = RED;
                    node = node->parent;
                }
                else {
                    if (sibling->left->color == BLACK) {
                        sibling->right->color = BLACK;
                        sibling->color = RED;
                        leftRotate(sibling);
                        sibling = node->parent->left;
                    }

                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rightRotate(node->parent);
                    node = root;
                }
            }
        }

        node->color = BLACK;
    }
public:
    RedBlackTree() : root(nullptr) {}
    RedBlackTree(std::string file_directory)
    {
        root = nullptr;
        std::ifstream file;
        file.open(file_directory);
        if (file.good())
        {
            int size;
            file >> size;

            int element;
            for (int i = 0; i < size; i++)
            {
                file >> element;
                insert(element);
            }
        }
    }
    void insert(int val) {
        Node* newNode = new Node(val);
        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (newNode->data < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        newNode->parent = parent;

        if (parent == nullptr) {
            root = newNode;
        }
        else if (newNode->data < parent->data) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }

        fixInsert(newNode);
    }

    void remove(int val) {
        Node* z = root;

        while (z != nullptr) {
            if (val < z->data) {
                z = z->left;
            }
            else if (val > z->data) {
                z = z->right;
            }
            else {
                break;
            }
        }

        if (z == nullptr) {
            return;
        }
        Node* x;
        Node* y = z;
        Color originalColor = y->color;

        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        }
        else {
            y = treeMinimum(z->right);
            originalColor = y->color;
            x = y->right;

            if (y->parent == z) {
                x->parent = y;
            }
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;

        if (originalColor == BLACK) {
            fixDelete(x);
        }
    }
    Node* find(int val)
    {
        Node* current = root;

        while (current != nullptr) {
            if (val < current->data) {
                current = current->left;
            }
            else if(val>current->data){
                current = current->right;
            }
            else
            {
                return current;
            }
        }

        return nullptr;
    }
    void printHelper(Node* root, std::string indent, bool last) {
        if (root != nullptr) {
            std::cout << indent;

            if (last) {
                std::cout << "L_";
                indent += "  ";
            }
            else {
                std::cout << "|-";
                indent += "| ";
            }

            std::cout << (root->color == RED ? "\033[1;31m" : "") << root->data << "\033[0m\n";
            printHelper(root->left, indent, root->right == nullptr);
            printHelper(root->right, indent, true);
        }
    }
    void printHelper(Node* root, int depth) {
        if (root != nullptr) {
            printHelper(root->right, depth + 1);
            std::cout << std::setw(depth * 4) << "";
            std::cout << (root->color == RED ? "\033[1;31m" : "\033[30;47m") << root->data << "\033[0m\n";
            printHelper(root->left, depth + 1);
        }
    }
    void print() {
        //printHelper(root, "", true);
        printHelper(root, 0);
    }
};

