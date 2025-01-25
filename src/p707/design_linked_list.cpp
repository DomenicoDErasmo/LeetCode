#include <iostream>
#include <string>

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

        Node *temp = getNodeAtIndex(index);
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

        Node *new_tail = new Node(val, *tail, nullptr);
        Node **new_tail_pointer = new Node *(new_tail);
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

        Node *temp = getNodeAtIndex(index);

        Node *original_prev = temp->prev;
        Node *to_add = new Node(val, original_prev, temp);

        temp->prev = to_add;
        original_prev->next = to_add;
    }

#define DELETE_AT_END(end, field, other_field) \
    Node *to_delete = *end;                    \
    Node *new_end = (*end)->field;             \
    Node *new_opposite = new_end->field;       \
    *end = new_end;                            \
    (*end)->field = new_opposite;              \
    (*end)->other_field = nullptr;             \
    delete to_delete;

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
            DELETE_AT_END(head, next, prev);

            return;
        }

        // delete tail
        if (index == length - 1)
        {
            DELETE_AT_END(tail, prev, next);

            return;
        }

        // general case
        Node *to_delete = getNodeAtIndex(index);

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

    std::string toString()
    {
        std::string result;

        Node *temp = *head;
        result.append("List: [");
        while (temp && temp->next)
        {
            result.append(std::to_string(temp->val));
            result.append(", ");
            temp = temp->next;
        }
        result.append(temp ? std::to_string(temp->val) : " ");
        result.append("]\n");

        return result;
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

    Node *getNodeAtIndex(int index)
    {
        Node *temp = *head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

private:
    Node **head, **tail;
};
