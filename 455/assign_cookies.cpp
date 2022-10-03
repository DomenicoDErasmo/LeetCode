#include <iostream>
#include <vector>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int result = 0;
        for (size_t i = 0; i < g.size(); i++) {
            int smallest = smallestCookiePos(g[i], s);
            if (smallest != -1) {
                result++;
                s[smallest] = 0;
            }
        }
        return result;
    }
private:
    int smallestCookiePos(int greed, std::vector<int>& cookies) {
        int smallest = -1;
        for (size_t i = 0; i < cookies.size(); i++) {
            if (cookies[i] >= greed && (smallest == -1 || cookies[i] < cookies[smallest])) {
                smallest = i;
            }
        }
        return smallest;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}