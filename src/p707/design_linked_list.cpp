#include <iostream>

struct Node
{
    int val;
    Node *prev, *next;

    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int val) : val(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *prev, Node *next) : val(val), prev(prev), next(next) {}
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
        int length = getLength();
        if (index >= length)
        {
            return -1;
        }

        Node *temp = *head;

        for (int i = 0; i < index; i++)
        {
            if (!temp)
            {
                return -1;
            }
            temp = temp->next;
        }

        return temp->val;
    }

    void addAtHead(int val)
    {
        bool added = tryToAddFirstNode(val);
        if (added)
        {
            return;
        }

        Node *new_head = new Node(val, nullptr, *head);
        Node **new_head_pointer = new Node *(new_head);
        (*head)->prev = new_head;

        head = new_head_pointer;
    }

    void addAtTail(int val)
    {
        bool added = tryToAddFirstNode(val);
        if (added)
        {
            return;
        }

        Node *new_tail = new Node(val);
        Node **new_tail_pointer = new Node *(new_tail);
        new_tail->prev = *tail;
        (*tail)->next = new_tail;

        tail = new_tail_pointer;
    }

    void addAtIndex(int index, int val)
    {
        // TODO: can guard clauses be simplified?
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        int length = getLength();

        if (index == length)
        {
            addAtTail(val);
            return;
        }

        if (index > length)
        {
            return;
        }

        Node *temp = *head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        Node *original_prev = temp->prev;
        Node *to_add = new Node(val, original_prev, temp);

        temp->prev = to_add;
        original_prev->next = to_add;
    }

    void deleteAtIndex(int index)
    {
        int length = getLength();

        // invalid index
        if (index >= length)
        {
            return;
        }

        // make list empty if length is 1
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
            return;
        }

        // delete head
        if (index == 0)
        {
            Node *to_delete = *head;
            Node *new_head = (*head)->next;
            Node *new_next = new_head->next;
            *head = new_head;
            (*head)->next = new_next;
            (*head)->prev = nullptr;
            delete to_delete;

            return;
        }

        // delete tail
        if (index == length - 1)
        {
            Node *to_delete = *tail;
            Node *new_tail = (*tail)->prev;
            Node *new_prev = new_tail->prev;
            *tail = new_tail;
            (*tail)->prev = new_prev;
            (*tail)->next = nullptr;
            delete to_delete;

            return;
        }

        // general case
        Node *to_delete = *head;
        for (int i = 0; i < index; i++)
        {
            to_delete = to_delete->next;
        }

        Node *prev = to_delete->prev;
        Node *next = to_delete->next;

        prev->next = next;
        next->prev = prev;
        delete to_delete;
    }

    bool tryToAddFirstNode(int val)
    {
        if (!head)
        {
            Node *new_head = new Node(val);
            Node **new_head_pointer = new Node *(new_head);

            head = new_head_pointer;
            tail = head;
            return true;
        }

        return false;
    }

    void printList()
    {
        Node *temp = *head;
        std::cout << "List: [";
        while (temp && temp->next)
        {
            std::cout << temp->val << ", ";
            temp = temp->next;
        }
        std::cout << (temp ? temp->val : ' ') << "]" << std::endl;
    }

    int getLength()
    {
        if (!head)
        {
            return 0;
        }

        Node *temp = *head;
        int length = 0;
        while (temp)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }

private:
    Node **head, **tail;
};
