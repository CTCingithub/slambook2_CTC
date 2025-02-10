#include <vector>
#include <cassert>
#include <iostream>
#include <string>

template <typename T>
class Stack
{
private:
    std::vector<T> elems; // elements
public:
    void push(T const &elem); // push element
    void pop();               // pop element
    T const &top() const;     // return top element
    bool empty() const
    {
        return elems.empty();
    } // return whether the stack is empty
};

template <typename T>
void Stack<T>::push(T const &elem)
{
    elems.push_back(elem); // append copy of passed elem
}

template <typename T>
void Stack<T>::pop()
{
    assert(!elems.empty());
    elems.pop_back(); // remove last element
}

template <typename T>
T const &Stack<T>::top() const
{
    assert(!elems.empty());
    return elems.back(); // return copy of last element
}

int main()
{
    Stack<int> intStack;            // stack of ints
    Stack<std::string> stringStack; // stack of strings

    // manipulate int stack
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.pop();
    std::cout << intStack.top() << '\n';

    // manipulate string stack
    stringStack.push("hello");
    stringStack.push("world");
    stringStack.empty();
    stringStack.push("a");
    std::cout << stringStack.top() << '\n';
    stringStack.pop();
}