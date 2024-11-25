#include <bits/stdc++.h>
using namespace std;

class Tree_Node {
    public:
        Tree_Node *left_child;
        int data;
        Tree_Node *right_child;

        Tree_Node(int data) : left_child(nullptr), data(data), right_child(nullptr) {}
};

class Node {
    public:
        Tree_Node *data;
        Node *next;

        Node(Tree_Node *data) : data(data), next(nullptr) {}
};
class Queue {
    private:
        Node *front;
        Node *rear;
    public:
        Queue() : front(nullptr), rear(nullptr) {}

        void enqueue(Tree_Node *data) {
            Node *new_node = new Node(data);
            if (!new_node) return;
            if (front == nullptr) {
                front = rear = new_node;
                return;
            }
            rear->next = new_node;
            rear = new_node;
        }
        Tree_Node* dequeue() {
            if (front == nullptr) return nullptr;
            Node *to_delete = front;
            front = front->next;
            Tree_Node *deleted_data = to_delete->data;
            delete to_delete;
            if (front == nullptr) rear = nullptr;
            return deleted_data;
        }
        bool is_empty() { return front == nullptr; }

        void display() {
            Node *current = front;
            while (current) {
                cout << current->data->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

class Binary_Tree {
    private:
        Tree_Node *root = nullptr;
    public:
        void create() {
            Tree_Node *parent, *child;
            Queue queue;
            int root_data;
            cout << "Root data?: "; cin >> root_data;
            root = new Tree_Node(root_data);
            queue.enqueue(root);

            while (!queue.is_empty()) {
                parent = queue.dequeue();
                int child_data;
                printf("Left child data of %d?: ", parent->data); cin >> child_data;
                if (child_data != -1) {
                    child = new Tree_Node(child_data);
                    parent->left_child = child;
                    queue.enqueue(child);
                }
                printf("Right child data of %d?: ", parent->data); cin >> child_data;
                if (child_data != -1) {
                    child = new Tree_Node(child_data);
                    parent->right_child = child;
                    queue.enqueue(child);
                }
            }
        }
        Tree_Node* get_root() { return root; } 
};

int main() {
    Binary_Tree binary_tree_1;
    binary_tree_1.create();
}