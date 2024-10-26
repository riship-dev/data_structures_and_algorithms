#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int item;
        Node *next;

        Node(int item) : item(item), next(nullptr) {}
};
class Stack {
    private:
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

        bool isEmpty() { return top == nullptr; }
        
        void push(int item) {
            Node *newNode = new Node(item);
            if (isEmpty()) {
                top = newNode;
                return;
            }
            newNode->next = top;
            top = newNode;
        }
        void pushMany(vector <int> items) { for (int i = 0; i < items.size(); i++) push(items[i]); }
        int pop() {
            if (isEmpty()) return -1;
            Node *toPop = top;
            top = top->next;
            int poppedItem = toPop->item; 
            delete toPop; 
            return poppedItem;
        }

        void display() {
            Node *current = top;
            while (current) {
                cout << current->item << " ";
                current = current->next;
            }
            cout << endl;
        }

        int peek(int index) {
            Node *current = top;
            for (int i = 0; i < index; i++) current = current->next;
            return current->item;
        }
        int getTop() { return top->item; }
};

int main() {

}