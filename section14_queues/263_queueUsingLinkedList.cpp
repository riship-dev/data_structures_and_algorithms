#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) : data(data), next(nullptr) {}
};

class Queue {
    private:
        Node *front;
        Node *rear;
    public:
        Queue() : front(nullptr), rear(nullptr) {}

        void enqueue(int data) {
            Node *newNode = new Node(data);
            if (newNode == nullptr) return;
            if (front == nullptr) {
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }
        int dequeue() {
            if (front == nullptr) return -1;
            Node *toDelete = front;
            front = front->next;
            int deleted = toDelete->data;
            delete toDelete;
            if (front == nullptr) rear = nullptr;
            return deleted;
        }

        void display() {
            Node *current = front;
            while (current) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << " ";
        }
};

int main() {

}