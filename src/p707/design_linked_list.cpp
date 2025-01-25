#include <iostream>

struct Node
{
    int val;
    Node *prev, *next;

    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int val) : val(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *prev, Node *next) : val(val), prev(nullptr), next(nullptr) {}
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index)
    {
        printList();

        return 0;
    }

    void addAtHead(int val)
    {
        bool added = tryToAddFirstNode(val);
        if (added)
        {
            return;
        }

        Node *new_head = new Node(val, nullptr, head);
        head->prev = new_head;
        &head = new_head;
    }

    void addAtTail(int val)
    {
        bool added = tryToAddFirstNode(val);
        if (added)
        {
            return;
        }

        Node *new_tail = new Node(val, tail, nullptr);
        tail->next = new_tail;
        tail = new_tail;
    }

    void addAtIndex(int index, int val)
    {
    }

    void deleteAtIndex(int index)
    {
    }

    bool tryToAddFirstNode(int val)
    {
        if (!head)
        {
            head = new Node(val, nullptr, nullptr);
            tail = head;
            return true;
        }

        return false;
    }

    void printList()
    {
        Node *temp = head;
        std::cout << "List: [";
        while (temp && temp->next)
        {
            std::cout << temp->val << ", ";
            temp = temp->next;
        }
        std::cout << (temp ? temp->val : ' ') << "]" << std::endl;
    }

private:
    Node *head, *tail;
};
