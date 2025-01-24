#include <vector>

class MinStack
{
public:
    MinStack()
    {
        stack = {};
        min = {};
    }

    void push(int val)
    {
        stack.push_back(val);
        if (min.empty())
        {
            min.push_back(val);
        }
        else
        {
            min.push_back(std::min(val, min.back()));
        }
    }

    void pop()
    {
        stack.pop_back();
        min.pop_back();
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return min.back();
    }

private:
    std::vector<int> stack;
    std::vector<int> min;
};