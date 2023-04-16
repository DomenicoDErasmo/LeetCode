#include <iostream>
#include <vector>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string result;
        
        // split by slashes
        std::vector<std::string> sub_paths = buildSubPaths(path);
        std::vector<std::string> raw_result;
        
        // if .., pop from vector, if ., continue, else push onto vector
        for (size_t i = 0; i < sub_paths.size(); i++) {
            if (sub_paths[i] == ".") {
                continue;
            } else if (sub_paths[i] == "..") {
                if (raw_result.size() >= 1) {
                    raw_result.pop_back();
                }
            } else {
                raw_result.push_back(sub_paths[i]);
            }
        }
        
        // recombine everything on vector, don't add a slash after the last one (so do / + vector[i])
        for (size_t i = 0; i < raw_result.size(); i++) {
            result += ("/" + raw_result[i]);
        }
        
        // in case there was nothing in raw_result, we still want the root
        if (result.length() == 0) {result = "/";}
        
        return result;
    }
private:
    std::vector<std::string> buildSubPaths(const std::string& path) {
        std::vector<std::string> result;
        int i = 0;
        while (i < path.length()) {
            if (path[i] == '/') {
                // if char is a /, continue
                i++;
            } else {
                // else, build a string and keep pushing onto it until the next /, then append to the stack
                std::string subpath = "";
                while (i < path.length() && path[i] != '/') {
                    subpath += path[i];
                    i++;
                }
                result.push_back(subpath);
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}