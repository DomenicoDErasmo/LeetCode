#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> combine(int n, int k) {
		std::vector<std::vector<int>> result;
		int i = 0;
		std::vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}