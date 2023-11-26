#include <iostream>
#include <vector>
#include <sstream>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        long v1 = 0, v2 = 0;
        std::vector<long> v1_nums = buildVersions(version1), v2_nums = buildVersions(version2);

        int i = 0;
        while (v1 == v2 && i < v1_nums.size() && i < v2_nums.size()) {
            v1 += v1_nums[i];
            v2 += v2_nums[i];
            i++;
        }

        if (v1 != v2) {return parseFromVersions(v1, v2);}

        if (i < v1_nums.size()) {v1 = buildRemaining(v1, v1_nums, i);}
        if (i < v2_nums.size()) {v2 = buildRemaining(v2, v2_nums, i);}
        
        return parseFromVersions(v1, v2);
    }
private:
    std::vector<long> buildVersions(const std::string& version) {
        std::vector<long> result;
        std::istringstream version_ss(version);
        std::string version_token;
        while (std::getline(version_ss, version_token, '.')) {
            result.push_back(std::stol(version_token));
        }
        return result;
    }
    int parseFromVersions(int v1, int v2) {
        if (v1 > v2) {return 1;}
        else if (v1 < v2) {return -1;}
        else {return 0;}
    }
    int buildRemaining(int sum, const std::vector<long>& nums, int start) {
        for (int i = start; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}