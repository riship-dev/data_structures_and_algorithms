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

class ExpressionUtilities {
    public:
        static bool isOperator(char character) {
            return 
                character == '+'
                || character == '-'
                || character == '*'
                || character == '/'
                || character == '^';  
        }
        static bool isOpeningParenthesis(char character) {
            return 
                character == '('
                || character == '['
                || character == '{'; 
        }
        static bool isClosingParenthesis(char character) {
            return 
                character == ')'
                || character == ']'
                || character == '}'; 
        }
        static int precedence(char _operator) {
            if (_operator == '^') return 3;
            if (_operator == '*' || _operator == '/') return 2;
            if (_operator == '+' || _operator == '-') return 1;
            return 0;
        }
};
string toPostfix(string expression) {
    int lengthOf_expression = expression.length();
    Stack stack(lengthOf_expression);
    string postfix = "";

    for (int i = 0; i < lengthOf_expression; i++) {
        if (ExpressionUtilities::isOperator(expression[i])) {
            while (!stack.isEmpty() && ExpressionUtilities::precedence(stack.getTop()) >= ExpressionUtilities::precedence(expression[i])) postfix += stack.pop();
            stack.push(expression[i]);
        } else if (ExpressionUtilities::isOpeningParenthesis(expression[i])) {
            stack.push(expression[i]);
        } else if (ExpressionUtilities::isClosingParenthesis(expression[i])) {
            while (!ExpressionUtilities::isOpeningParenthesis(stack.getTop())) postfix += stack.pop();
            stack.pop();
        } else {
            postfix += expression[i];
        }
    }
    while (!stack.isEmpty()) postfix += stack.pop();

    return postfix;
}

void runTests() {
    struct Test {
        string infix;
        string expectedPostfix;
    };

    Test tests[] = {
        {"A+B", "AB+"},                         // Simple expression
        {"A+B*C", "ABC*+"},                     // Operator precedence (* over +)
        {"(A+B)*C", "AB+C*"},                   // Parentheses to change precedence
        {"A*B+C/D", "AB*CD/+"},                 // Multiple operators with precedence
        {"A+B*C-D/E", "ABC*+DE/-"},             // Mixed operators with subtraction
        {"(A+B)*(C-D)", "AB+CD-*"},             // Nested expressions
        {"((A+B)*C)-(D/E)", "AB+C*DE/-"},       // Deeply nested expressions
        {"A+B*(C-D)-E/F*G", "ABCD-*+EF/G*-"},   // Multiple precedence layers and operators
        {"A^B+C", "AB^C+"},                     // Exponent operator with lower precedence
        {"A+(B*C-(D/E^F)*G)*H", "ABC*DEF^/G*-H*+"}, // Complex expression with all operators
        {"A+B-C", "AB+C-"},                     // Simple expression with addition and subtraction
        {"A*(B+C*D)-E", "ABCD*+*E-"},           // Multiple precedence with subtraction
        {"A+B*C^D-E/F", "ABCD^*+EF/-"},         // Mixed expression with exponent and division
        {"A*(B+C)*(D+E)", "ABC+*DE+*"},         // Nested multiplication
        {"(A+(B*C-(D/E^F)*G)*H)", "ABC*DEF^/G*-H*+"} // Complex with full parentheses
    };

    for (const auto& test : tests) {
        string result = toPostfix(test.infix);
        cout << "Infix: " << test.infix << endl;
        cout << "Expected Postfix: " << test.expectedPostfix << endl;
        cout << "Result Postfix: " << result << endl;
        cout << "Test " << (result == test.expectedPostfix ? "Passed" : "Failed") << endl;
        cout << "-----------------------------------" << endl;
    }
}

int main() { runTests(); }