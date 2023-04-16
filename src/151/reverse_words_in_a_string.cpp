#include <iostream>
#include <stack>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string result, temp;
        std::stack<std::string> words;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else if (temp != "") {
                words.push(temp);
                temp = "";
            }
        }
        if (temp != "") {words.push(temp);}

        while (!words.empty()) {
            result += (words.top() + " ");
            words.pop();
        }
        result.erase(result.end()-1);
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
