#include <iostream>
#include <vector>

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
    ~Node() { delete next; }
};

class Solution
{
public:
    bool isPalindrome(Node *head)
    {
        std::vector<int> vec = listToVector(head);
        for (size_t i = 0; i < vec.size() / 2; i++)
        {
            if (vec[i] != vec[vec.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<int> listToVector(Node *head)
    {
        std::vector<int> result;

        Node *temp = head;
        while (temp)
        {
            result.push_back(temp->val);
            temp = temp->next;
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}