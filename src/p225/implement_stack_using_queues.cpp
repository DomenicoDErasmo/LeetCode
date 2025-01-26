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
    void enqueue(int value)
    {
        size++;

        if (!head)
        {
            head = new Node(value);
            tail = head;
            return;
        }

        tail->next = new Node(value);
        tail = tail->next;
    }

    int front()
    {
        if (!head)
        {
            return -1;
        }

        return head->value;
    }

    int dequeue()
    {
        int to_return = front();
        size--;

        Node *to_delete = head;
        head = head->next;

        to_delete->next = nullptr;
        delete to_delete;

        return to_return;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

private:
    Node *head, *tail;
    int size;
};

class MyStack
{
public:
    MyStack()
    {
        queue = Queue();
    }

    void push(int x)
    {
        int size = queue.getSize();
        queue.enqueue(x);
        for (int i = 0; i < size; i++)
        {
            int toShuffle = queue.dequeue();
            queue.enqueue(toShuffle);
        }
    }

    int pop()
    {
        return queue.dequeue();
    }

    int top()
    {
        return queue.front();
    }

    bool empty()
    {
        return queue.isEmpty();
    }

private:
    Queue queue;
};