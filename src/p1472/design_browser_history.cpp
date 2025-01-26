#include <string>
#include <vector>

struct Node
{
    std::string value;
    Node *prev, *next;

    Node() : value(""), prev(nullptr), next(nullptr) {}
    Node(std::string value) : value(value), prev(nullptr), next(nullptr) {}
    Node(std::string value, Node *prev, Node *next) : value(value), prev(prev), next(next) {}
};

class BrowserHistory
{
public:
    BrowserHistory(std::string homepage)
    {
        current = new Node(homepage);
    }

    void visit(std::string url)
    {
        Node *to_delete = current->next, *original = current;
        current->next = new Node(url);
        current = current->next;
        current->prev = original;
    }

    std::string back(int steps)
    {
        int steps_traveled = 0;
        while (current->prev && steps_traveled < steps)
        {
            current = current->prev;
            steps_traveled++;
        }
        return current->value;
    }

    std::string forward(int steps)
    {
        int steps_traveled = 0;
        while (current->next && steps_traveled < steps)
        {
            current = current->next;
            steps_traveled++;
        }
        return current->value;
    }

    std::string toString()
    {
        std::string result;
        result.append("List: [");

        Node *temp = current;
        while (temp->prev)
        {
            temp = temp->prev;
        }

        while (temp->next)
        {
            result.append(temp->value);
            result.append(", ");
            temp = temp->next;
        }

        result.append("]");
        return result;
    }

private:
    Node *current;
};