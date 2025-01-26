#include <vector>

struct Node
{
    int value;
    Node *next;

    Node() : value(0), next(nullptr) {}
    Node(int value) : value(value), next(nullptr) {}
    Node(int value, Node *next) : value(value), next(next) {}
};

class Queue
{
public:
    Queue() : head(nullptr), tail(nullptr) {}

    void enqueue(int value)
    {
        if (!head)
        {
            head = new Node(value);
            tail = head;
            size++;
            return;
        }
        tail->next = new Node(value);
        tail = tail->next;
        size++;
    }

    int dequeue()
    {
        if (!head)
        {
            return -1;
        }

        int result = head->value;
        size--;

        Node *to_delete = head;
        head = head->next;

        to_delete->next = nullptr;
        delete to_delete;

        return result;
    }

    int front()
    {
        if (!head)
        {
            return -1;
        }
        return head->value;
    }

    int getSize()
    {
        return size;
    }

private:
    Node *head, *tail;
    int size;
};

class Stack
{
public:
    Stack() : stack({}) {}

    int peek()
    {
        return stack.back();
    }

    int pop()
    {
        int result = peek();
        stack.pop_back();
        return result;
    }

    void push(int value)
    {
        stack.push_back(value);
    }

private:
    std::vector<int> stack;
};

class Solution
{
public:
    int countStudents(std::vector<int> &students, std::vector<int> &sandwiches)
    {
        Queue queue = fromStudents(students);
        Stack stack = fromSandwiches(sandwiches);

        int result = queue.getSize();
        int visited = 0;
        while (visited < queue.getSize())
        {
            int student_preference = queue.dequeue();
            int sandwich = stack.peek();

            if (student_preference == sandwich)
            {
                stack.pop();
                visited = 0;
                result--;
            }
            else
            {
                queue.enqueue(student_preference);
                visited++;
            }
        }
        return result;
    }

private:
    Queue fromStudents(std::vector<int> &students)
    {
        Queue queue;

        for (int i = 0; i < students.size(); i++)
        {
            queue.enqueue(students[i]);
        }

        return queue;
    }

    Stack fromSandwiches(std::vector<int> &sandwiches)
    {
        Stack stack;

        for (int i = sandwiches.size() - 1; i >= 0; i--)
        {
            stack.push(sandwiches[i]);
        }

        return stack;
    }
};
