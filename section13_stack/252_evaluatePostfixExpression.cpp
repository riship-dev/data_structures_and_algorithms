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
        int pop() {
            if (isEmpty()) return -1;
            return items[top--];
        }
};

class ExpressionUtilities {
    public:
        static bool isOperator(char character) { return character == '+' || character == '-' || character == '*' || character == '/' || character == '^'; }
        static int evaluate(char _operator, int leftOperand, int rightOperand) {
            switch (_operator) {
                case '+': return leftOperand + rightOperand;
                case '-': return leftOperand - rightOperand;
                case '*': return leftOperand * rightOperand;
                case '/': return leftOperand / rightOperand;
                case '^': return pow(leftOperand, rightOperand); 
                default: return 0;
            }
        }
};

int evaluatePostfix(string expression) {
    int lengthOf_expression = expression.length();
    Stack stack(lengthOf_expression);
    for (int i = 0; i < lengthOf_expression; i++) {
        if (ExpressionUtilities::isOperator(expression[i])) {
            int rightOperand = stack.pop();
            int leftOperand = stack.pop();
            int result = ExpressionUtilities::evaluate(expression[i], leftOperand, rightOperand);
            stack.push(result);
        } else {
            stack.push(expression[i] - '0');
        }
    }
    return stack.pop();
}

void runTests() {
    vector<pair<string, int>> testCases = {
        {"53+", 8},              // 5 + 3 = 8
        {"82-", 6},              // 8 - 2 = 6
        {"52*", 10},             // 5 * 2 = 10
        {"84/", 2},              // 8 / 4 = 2
        {"23^", 8},              // 2 ^ 3 = 8
        {"53+82-*", 48},         // (5 + 3) * (8 - 2) = 8 * 6 = 48
        {"54+82/-", 5},          // (5 + 4) - (8 / 2) = 9 - 4 = 5
        {"34+52*+", 17},         // 3 + 4 + (5 * 2) = 3 + 4 + 10 = 17
        {"53+62+*84/-", 62},     // ((5 + 3) * (6 + 2)) - (8 / 4) = 64 - 2 = 62
        {"56+72-*83+/", 5},      // ((5 + 6) * (7 - 2)) / (8 + 3) = 55 / 11 = 5
        {"12+3*", 9},            // (1 + 2) * 3 = 9
        {"345*+", 23},           // 3 + (4 * 5) = 23
        {"562+-", -3},           // (5 - 6) + 2 = -1 + 2 = -3
        {"56+73-*", 44},         // (5 + 6) * (7 - 3) = 11 * 4 = 44
    };

    for (const auto &testCase : testCases) {
        string expression = testCase.first;
        int expected = testCase.second;
        int result = evaluatePostfix(expression);

        cout << "Postfix Expression: " << expression << endl;
        cout << "Expected Result: " << expected << endl;
        cout << "Evaluated Result: " << result << endl;
        
        if (result == expected) {
            cout << "Test Passed" << endl;
        } else {
            cout << "Test Failed" << endl;
        }
        cout << "-----------------------------------" << endl;
    }
}

int main() { runTests(); }