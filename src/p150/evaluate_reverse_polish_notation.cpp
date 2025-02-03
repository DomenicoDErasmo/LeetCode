#include <string>
#include <vector>

class Stack {
   public:
    Stack() : _stack({}) {}

    void push(std::string val) { _stack.push_back(val); }

    std::string top() { return _stack.back(); }

    std::string pop() {
        std::string to_return = top();
        _stack.pop_back();
        return to_return;
    }

    bool empty() { return _stack.empty(); }

   private:
    std::vector<std::string> _stack;
};

class Solution {
   public:
    int evalRPN(std::vector<std::string> &tokens) {
        Stack stack;

        for (std::string token : tokens) {
            if (!isOperator(token)) {
                stack.push(token);
            } else {
                int right = std::stoi(stack.pop()), left = std::stoi(stack.pop());
                auto operation = operatorToFunction(token);
                int expression = (this->*operation)(left, right);
                stack.push(std::to_string(expression));
            }
        }

        return std::stoi(stack.top());
    }

   private:
    int (Solution::*operatorToFunction(std::string str))(int, int) {
        if (str == "+") {
            return &Solution::add;
        } else if (str == "-") {
            return &Solution::subtract;
        } else if (str == "*") {
            return &Solution::multiply;
        } else if (str == "/") {
            return &Solution::divide;
        } else {
            return nullptr;
        }
    }

    bool isOperator(std::string str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }

    int add(int left, int right) { return left + right; }

    int subtract(int left, int right) { return left - right; }

    int multiply(int left, int right) { return left * right; }

    int divide(int left, int right) { return left / right; }
};
