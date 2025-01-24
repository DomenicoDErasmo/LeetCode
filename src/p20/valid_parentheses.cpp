#include <string>
#include <vector>

class Stack
{

public:
  Stack() { stack = {}; }

  bool empty() { return stack.empty(); }

  char peek()
  {
    char result;
    if (empty())
    {
      return '\0';
    }

    result = stack.back();
    return result;
  }

  char pop()
  {
    char result = peek();

    if (result != '\0')
    {
      stack.pop_back();
    }

    return result;
  }

  void push(char val) { stack.push_back(val); }

private:
  std::vector<char> stack;
};

class Solution
{
public:
  bool isValid(std::string s)
  {
    Stack stack;
    for (auto ch : s)
    {
      if (ch == '}' && stack.peek() == '{' ||
          ch == ')' && stack.peek() == '(' ||
          ch == ']' && stack.peek() == '[')
      {
        stack.pop();
      }
      else if (ch == '[' || ch == '(' || ch == '{')
      {
        stack.push(ch);
      }
      else
      {
        return false;
      }
    }
    return stack.empty();
  }
};

int main()
{
  Solution solution;
  solution.isValid("()[]{})");
  return 0;
}
