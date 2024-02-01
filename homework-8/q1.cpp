#include <iostream>
#include <string>

class Node
{
public:
    std::string data;
    Node *next;
    Node(std::string s, Node *n = nullptr) : data{s}, next{n} {}
};

class Queue
{
private:
    Node *front;
    Node *back;
public:
    Queue();
    ~Queue();
    bool is_empty();
    void push_back(const std::string&);
    std::string pop_front();
    void print_queue();
    void operator=(const Queue&) = delete;
    Queue(const Queue&) = delete;
};

/*
Initialize an empty queue with no elements.
*/
Queue::Queue()
{
    front = nullptr;
    back = nullptr;
}

/*
Return true if the queue has no elements, otherwise return false.
*/
bool Queue::is_empty()
{
    return front == nullptr;
}

/*
Create a node with data s and add it to the end of the queue.
Then update front and back.
*/
void Queue::push_back(const std::string& s)
{
    Node *new_node = new Node(s);
    
    /*
    If the queue is empty then the new element will be the front and the back.
    Else add it to the end and it becomes the last element.
    */
    if (is_empty())
    {
        front = new_node;
        back = new_node;
    }
    else
    {
        back->next = new_node;
        back = new_node;
    }
}

/*
Remove a node from the front of the queue and return its data. If the queue is
empty then do nothing to the queue and return an empty string.
*/
std::string Queue::pop_front()
{
    if (is_empty())
    {
        return "";
    }

    std::string data = front->data;
    Node *temp = front;
    front = front->next;
    delete temp;
    return data;
}

/*
Print the data currently stored in the queue.
*/
void Queue::print_queue()
{
    // Current element in the queue.
    Node *current = front;

    // Iterate through the queue and print every element.
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    
    std::cout << std::endl;
}

/*
Deallocate all of the elements in the queue.
*/
Queue::~Queue()
{
    while (!is_empty())
    {
        pop_front();
    }
}

int main()
{
    Queue x;
    x.push_back("A");
    x.push_back("B");
    x.push_back("C");
    x.print_queue();

    x.pop_front();
    x.push_back("D");
    x.push_back("E");
    x.pop_front();
    x.print_queue();

    /*
    This should print:
    A B C
    C D E
    */

    return 0;
}