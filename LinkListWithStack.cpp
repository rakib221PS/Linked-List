#include <iostream>
#include <stdexcept>
struct Node
{
    int value;
    Node *next;

    Node(int _value, Node *_next = nullptr) : value(_value),
                                              next(_next)
    {
    }
};

class Stack
{
    Node *head = nullptr;
    Node *copy = nullptr;

public:
    Stack() : head(nullptr) {}
    void push(int x)
    {
        head = new Node(x, head);
    }

    bool empty() const
    {
        return head == nullptr;
    }

    int top() const
    {
        if (empty())
        {
            throw std::runtime_error("top on an empty stack");
        }
        return head->value;
    }

    void pop()
    {
        if (empty())
        {
            throw std::runtime_error("pop on an empty stack");
        }
        pop_unsafe();
    }

    void clear()
    {
        while (!empty())
        {
            pop_unsafe();
        }
    }
    // method for print value from linked list
    void printList()
    {
        if (empty())
        {
            throw std::runtime_error("Empty stack");
        }
        if (copy != nullptr)
        {
            delete copy;
        }
        copy = head;

        while (copy != nullptr)
        {
            std::cout << copy->value << " ";
            copy = copy->next;
        }
    }

    // nth value from stack
    int nth(int x)
    {
        if (copy != nullptr)
        {
            delete copy;
        }
        copy = head;

        int count = 0;
        while (copy != nullptr)
        {
            if (count == x)
            {
                return copy->value;
            }
            count++;
            copy = copy->next;
        }
        throw std::runtime_error("Under flow or overflow");
    }

    ~Stack()
    {
        clear();
    }

    // Stack(const Stack &original) : head(nullptr)
    // {
    //     if (!original.empty())
    //     {
    //         head = new Node(original.head->value);
    //         Node *src = original.head->next;
    //         Node *dst = head;

    //         while (src != nullptr)
    //         {
    //             dst->next = new Node(src->value);
    //             dst = dst->next;
    //             src = src->next;
    //         }
    //     }
    // }

    Stack operator+(const int x)
    {
        push(x);
    }
    // Stack &operator=(Stack cpy) {
    //     std::swap(cpy.head, head);
    //     return *this;
    // }
    Stack &operator=(const Stack &original)
    {
        if (!original.empty() && this != &original)
        {
            if (head != nullptr)
            {
                delete head;
            }
            head = original.head;
        }

        return *this;
    }

private:
    void pop_unsafe()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
};
int main()
{
    Stack LinkedList, anotherLinkedList;
    // insert number of element in stack
    for (int i = 3; i > 0; i--)
    {
        LinkedList.push(i);
    }
    LinkedList.pop();
    for (int i = 3; i > 0; i--)
    {
        anotherLinkedList.push(-i);
    }

    // std::cout << LinkedList.nth(4);
    // LinkedList.printList();
    std::cout << std::endl;
    // Stack copyLinkedList(anotherLinkedList);
    // copyLinkedList.printList();
    std::cout << std::endl;
    LinkedList = anotherLinkedList;
    // add operator to add data in stack
    // LinkedList + 1;
    LinkedList.printList();
    std::cout << std::endl;
    anotherLinkedList.printList();
    std::cout << std::endl;
    return 0;
}