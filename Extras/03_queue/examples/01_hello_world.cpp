#include <cassert>
#include <iostream>
#include <queue>

int main(int argc, char *argv[])
{
    std::queue<double> q;

    q.push(0.0);
    q.push(0.1);
    q.push(0.2);
    q.push(0.3);

    assert(q.front() == 0.0);
    assert(q.back() == 0.3);
    assert(q.size() == 4);

    q.pop(); // remove the front element 0.0
    assert(q.size() == 3);

    std::cout << "q: ";
    for (; !q.empty(); q.pop())
    {
        std::cout << q.front() << " ";
    }
    std::cout << std::endl;
    assert(q.size() == 0);
}