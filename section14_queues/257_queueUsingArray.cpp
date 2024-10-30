#include <bits/stdc++.h>
using namespace std;

class Queue {
    private:
        int front;
        int rear;
        int size;
        int *items;
    public:
        Queue(int size) : front(-1), rear(-1), size(size), items(new int[size]) {}
        ~Queue() { delete [] items; }

        void enqueue(int item) { 
            if (rear == size - 1) return;
            if (front == -1) front = 0;
            items[++rear] = item;
        }
        int dequeue() { 
            if (front == -1 || front > rear) return -1;
            int removed = items[front++];
            if (front > rear) front = rear = -1;
            return removed;
        }

        void display() {
            if (front == -1) return;
            for (int i = front; i <= rear; i++) cout << items[i] << " ";
            cout << endl;
        }
};

int main() {
    Queue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();
    cout << queue.dequeue() << endl;
    queue.display();
}