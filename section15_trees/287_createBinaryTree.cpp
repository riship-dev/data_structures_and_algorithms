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
class Stack {
    private:
        class Node {
            public:
                Tree_Node *treeNode;
                Node *next;
                Node(Tree_Node *treeNode) : treeNode(treeNode), next(nullptr) {}
        };

        Node *top;

    public:
        Stack() : top(nullptr) {}
        ~Stack() {
            Node *current = top, *toDelete = nullptr;
            while (current) {
                toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }

        void push(Tree_Node *item) {
            Node *newNode = new Node(item);
            if (is_empty()) {
                top = newNode;
                return;
            }
            newNode->next = top;
            top = newNode;
        }
        Tree_Node* pop() {
            if (is_empty()) return nullptr;
            Node *toPop = top;
            top = top->next;
            Tree_Node *poppedItem = toPop->treeNode;
            delete toPop;
            return poppedItem;
        }
        bool is_empty() { return top == nullptr; }
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
        Tree_Node* get_root_address() { return root; }
};

class Recursive_Tree_Traversals {
    public:
        static void preorder(Tree_Node *current) {
            if (current) {
                printf("%d ", current->data);
                preorder(current->left_child);
                preorder(current->right_child);
            }
        }
        static void inorder(Tree_Node *current) {
            if (current) {
                inorder(current->left_child);
                printf("%d ", current->data);
                inorder(current->right_child);
            }
        }
        static void postorder(Tree_Node *current) {
            if (current) {
                postorder(current->left_child);
                postorder(current->right_child);
                printf("%d ", current->data);
            }
        }
};
class Iterative_Tree_Traversals {
    public:
        static void preorder(Tree_Node *current) {
            Stack stack;
            while (current != nullptr || !stack.is_empty()) {
                if (current != nullptr) {
                    printf("%d ", current->data);
                    stack.push(current);
                    current = current->left_child;
                } else {
                    current = stack.pop();
                    current = current->right_child;
                }
            }
        }
        static void inorder(Tree_Node *current) {
            Stack stack;
            while (current != nullptr || !stack.is_empty()) {
                if (current != nullptr) {
                    stack.push(current);
                    current = current->left_child;
                } else {
                    current = stack.pop();
                    printf("%d ", current->data);
                    current = current->right_child;
                }
            }
        }
        static void levelorder(Tree_Node *current) {
            Queue queue;
            printf("%d ", current->data);
            queue.enqueue(current);
            while (!queue.is_empty()) {
                current = queue.dequeue();
                if (current->left_child != nullptr) {
                    printf("%d ", current->left_child->data);
                    queue.enqueue(current->left_child);
                }
                if (current->right_child != nullptr) {
                    printf("%d ", current->right_child->data);
                    queue.enqueue(current->right_child);
                }
            }
        }
};
class Binary_Tree_Utility {
    public:
        static int count(Tree_Node *current) {
            int count_left_child, count_right_child;
            if (current != nullptr) {
                count_left_child = count(current->left_child);
                count_right_child = count(current->right_child);
                return 1 + count_left_child + count_right_child;
            }
            return 0;
        }
        static int height(Tree_Node *root) {
            int height_left_child, height_right_child;
            if (root == nullptr) return 0;
            height_left_child = height(root->left_child);
            height_right_child = height(root->right_child);
            if (height_left_child > height_right_child) return 1 + height_left_child;
            return 1 + height_right_child;
        }
};

int main() {
    Binary_Tree binary_tree_1;
    binary_tree_1.create();
    cout << Binary_Tree_Utility::count(binary_tree_1.get_root_address());
}