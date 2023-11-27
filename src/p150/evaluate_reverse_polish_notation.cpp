#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <functional>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<std::string> nums;
        for (int i = 0; i < tokens.size(); i++) {
            std::string token = tokens[i];
            if (isOperator(token)) {
                std::function<long(long, long)> op = operatorFromString(token);

                long second = std::stol(nums.top());
                nums.pop();
                long first = std::stol(nums.top());
                nums.pop();

                nums.push(std::to_string(op(first, second)));
            } else {
                nums.push(token);
            }
        }
        return std::stoi(nums.top());
    }
private:
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    std::function<long(long, long)> operatorFromString(const std::string& op) {
        if (op == "+") {return std::plus<long>();} 
        else if (op == "-") {return std::minus<long>();}
        else if (op == "*") {return std::multiplies<long>();}
        else {return std::divides<long>();}
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
