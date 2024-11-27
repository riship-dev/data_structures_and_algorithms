#include <bits/stdc++.h>
using namespace std;

class Tree_Node {
    public:
        Tree_Node *left_child;
        int data;
        Tree_Node *right_child;

        Tree_Node(int data) : left_child(nullptr), data(data), right_child(nullptr) {}
};

class Binary_Search_Tree {
    private:
        Tree_Node *root;

        Tree_Node *helper_delete_node(Tree_Node *root, int data) {
            if (root == nullptr) return root;

            if (data < root->data) root->left_child = helper_delete_node(root->left_child, data);
            else if (data > root->data) root->right_child = helper_delete_node(root->right_child, data);
            else {
                if (root->left_child == nullptr) {
                    Tree_Node *temporary = root->right_child;
                    delete root;
                    return temporary;
                } else if (root->right_child == nullptr) {
                    Tree_Node *temporary = root->left_child;
                    delete root;
                    return temporary;
                }
                Tree_Node *temporary = find_minimum_right_descendant(root->right_child);
                root->data = temporary->data;
                root->right_child = helper_delete_node(root->right_child, temporary->data);
            }
            return root;
        }
        Tree_Node* find_minimum_right_descendant(Tree_Node *node) {
            while (node->left_child != nullptr) node = node->left_child;
            return node;
        }

        int helper_height(Tree_Node *root) {
            int height_left_child, height_right_child;
            if (root == nullptr) return 0;
            height_left_child = helper_height(root->left_child);
            height_right_child = helper_height(root->right_child);
            return height_left_child > height_right_child ? height_left_child + 1 : height_right_child + 1;
        }

    public:
        Binary_Search_Tree() : root(nullptr) {}

        void insert(int data) {
            if (root == nullptr) {
                root = new Tree_Node(data);
                return;
            }
            Tree_Node *current = root;
            Tree_Node *parent = nullptr;
            while (current != nullptr) {
                parent = current;
                if (current->data < data) current = current->right_child;
                else if (current->data > data) current = current->left_child;
                else return;
            }
            Tree_Node *new_node = new Tree_Node(data);
            if (parent->data < data) parent->right_child = new_node;
            else parent->left_child = new_node;
        }
        void insert_many(vector <int> data_array) { for (int i = 0; i < data_array.size(); i++) insert(data_array[i]); }
        void delete_node(int data) { root = helper_delete_node(root, data); }
        Tree_Node* search(int data) {
            Tree_Node *current = root;
            while (current != nullptr) {
                if (current->data == data) return current;
                else if (current->data < data) current = current->right_child;
                else current = current->left_child;
            }
            return nullptr;
        }
        int height() { return helper_height(root); }
};

int main() {}