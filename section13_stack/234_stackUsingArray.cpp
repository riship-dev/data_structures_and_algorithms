#include <bits/stdc++.h>
using namespace std;

class Stack {
    private:
        int size;
        int top;
        int *items;
    public:
        Stack(int size) : size(size), top(-1), items(new int[size]) {}
        ~Stack() { delete [] items; }

        bool isFull() { return top == size - 1; }
        bool isEmpty() { return top == -1; }
        
        void push(int item) {
            if (isFull()) return;
            items[++top] = item;
        }
        void pushMany(vector <int> items) { for (int i = 0; i < items.size() && !isFull(); i++) push(items[i]); }
        int pop() {
            if (isEmpty()) return -1;
            return items[top--];
        }

        void display() {
            if (top == -1) return;
            for (int i = top; i >= 0; i--) cout << items[i] << " ";
            cout << endl;
        }
        
        int peek(int index) {
            if (index < 0 || index > top) return -1;
            return items[top - index];
        }
        int getTop() { 
            if (isEmpty()) return -1;
            return items[top]; 
        }
};

int main() {
    
}