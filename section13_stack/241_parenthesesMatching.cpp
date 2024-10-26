#include <bits/stdc++.h>
using namespace std;

class Stack {
    private:
        int size;
        int top;
        char *items;
    public:
        Stack(int size) : size(size), top(-1), items(new char[size]) {}
        ~Stack() { delete [] items; }

        bool isFull() { return top == size - 1; }
        bool isEmpty() { return top == -1; }
        
        void push(char item) {
            if (isFull()) return;
            items[++top] = item;
        }
        void pushMany(vector<char> items) { for (int i = 0; i < items.size() && !isFull(); i++) push(items[i]); }
        char pop() {
            if (isEmpty()) return '\0';
            return items[top--];
        }

        void display() {
            if (top == -1) return;
            for (int i = top; i >= 0; i--) 
                cout << items[i] << " ";
            cout << endl;
        }
        
        char peek(int index) {
            if (index < 0 || index > top) return '\0';
            return items[top - index];
        }
        char getTop() { 
            if (isEmpty()) return '\0';
            return items[top]; 
        }
};

bool isValid(string expression) {
    int expressionLength = expression.length();
    Stack parentheses(expressionLength);
    for (int i = 0; i < expressionLength; i++) {
        if (
            expression[i] == '('
            || expression[i] == '['
            || expression[i] == '{'
        ) parentheses.push(expression[i]);
        else if (
            expression[i] == ')' && parentheses.getTop() == '('
            || expression[i] == ']' && parentheses.getTop() == '['
            || expression[i] == '}' && parentheses.getTop() == '{'
        ) parentheses.pop(); 
    }
    return parentheses.isEmpty();
}

int main() {
    string expression1 = "{[()]}";
    cout << "expression1 expected: 1" << endl;
    cout << "expression1 returned: " << isValid(expression1) << endl << endl;

    string expression2 = "{[(])}";
    cout << "expression2 expected: 0" << endl;
    cout << "expression2 returned: " << isValid(expression2) << endl << endl;

    string expression3 = "((()))";
    cout << "expression3 expected: 1" << endl;
    cout << "expression3 returned: " << isValid(expression3) << endl << endl;

    string expression4 = "([{}])";
    cout << "expression4 expected: 1" << endl;
    cout << "expression4 returned: " << isValid(expression4) << endl << endl;

    string expression5 = "{[}";
    cout << "expression5 expected: 0" << endl;
    cout << "expression5 returned: " << isValid(expression5) << endl << endl;

    string expression6 = "[{()}]";
    cout << "expression6 expected: 1" << endl;
    cout << "expression6 returned: " << isValid(expression6) << endl << endl;

    string expression7 = "(]";
    cout << "expression7 expected: 0" << endl;
    cout << "expression7 returned: " << isValid(expression7) << endl << endl;

    string expression8 = "";
    cout << "expression8 expected: 1" << endl;
    cout << "expression8 returned: " << isValid(expression8) << endl << endl;

    string expression9 = "{[(()]}";
    cout << "expression9 expected: 0" << endl;
    cout << "expression9 returned: " << isValid(expression9) << endl << endl;

    string expression10 = "{{{{{";
    cout << "expression10 expected: 0" << endl;
    cout << "expression10 returned: " << isValid(expression10) << endl << endl;

    string expression11 = "(((((((())))))))";
    cout << "expression11 expected: 1" << endl;
    cout << "expression11 returned: " << isValid(expression11) << endl << endl;
    
    string expression12 = "{}[]()";
    cout << "expression12 expected: 1" << endl;
    cout << "expression12 returned: " << isValid(expression12) << endl << endl;
    
    string expression13 = "[({[()]}{})]";
    cout << "expression13 expected: 1" << endl;
    cout << "expression13 returned: " << isValid(expression13) << endl << endl;
    
    string expression14 = "{[(])}{}[{}()]";
    cout << "expression14 expected: 0" << endl;
    cout << "expression14 returned: " << isValid(expression14) << endl << endl;
    
    string expression15 = "{(())}[({})]";
    cout << "expression15 expected: 1" << endl;
    cout << "expression15 returned: " << isValid(expression15) << endl << endl;
}